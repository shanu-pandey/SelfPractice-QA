/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>

namespace Graph
{
	class CourseSchedule2
	{
	public:
        static std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);
    private:
        static void dfs(std::vector<int>* graph, std::stack<int>& s, std::vector<bool>& visited, int n);
        static  std::vector<int> TopoWithCycle(std::vector<int>* graph, std::stack<int>& s, int n);
        static void AddEdge(int u, int v, std::vector<int>* graph);
	};
}

void  Graph::CourseSchedule2::AddEdge(int u, int v, std::vector<int>* graph)
{
    graph[u].push_back(v);
}

void  Graph::CourseSchedule2::dfs(std::vector<int>* graph, std::stack<int>& s, std::vector<bool>& visited, int n)
{
    visited[n] = true;
    for (auto it : graph[n])
    {
        if (!visited[it])
            dfs(graph, s, visited, it);
    }
    s.push(n);
}

std::vector<int>  Graph::CourseSchedule2::TopoWithCycle(std::vector<int>* graph, std::stack<int>& s, int n)
{
    std::vector<std::pair<int, int>> pos;
    std::vector<int> res;
    int index = 0;
    while (s.size() > 0)
    {
        pos.push_back(std::make_pair(s.top(), index));
        s.pop();
        index++;
    }

    for (int i = 0; i < n; i++)
    {
        for (auto it : graph[i])
        {
            if (pos[i] > pos[it])
                return res;
        }
    }
    return std::vector<int>();
}

std::vector<int> Graph::CourseSchedule2::findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    std::vector<int> graph[2];
    std::vector<int> result;
    std::vector<bool> visited(numCourses, false);
    std::stack<int> s;

    for (auto it : prerequisites)
    {
        AddEdge(it[1], it[0], graph);
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
            dfs(graph, s, visited, i);
    }

    return (TopoWithCycle(graph, s, numCourses));
        
}