/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.



Example 1:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
Example 2:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.


Constraints:

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>

namespace Graph
{
    class CompleteComponents
    {
    public:
        static int CountCompleteComponents(std::vector<std::vector<int>>& edges, int n);
    };
}

void DFS(std::unordered_map<int, std::vector<int>>& adj, int node, std::vector<bool>& visited, int& res, int& nodeCount)
{
    visited[node] = true;
    nodeCount++;
    res += adj[node].size();
    for (auto& it : adj[node])
    {
        if (!visited[it])
        {
            
            DFS(adj, it, visited, res, nodeCount);
        }
    }
}

int  Graph::CompleteComponents::CountCompleteComponents(std::vector<std::vector<int>>& edges, int n)
{
    std::unordered_map<int, std::vector<int>> adj(n);
    std::vector<bool> visited(n, false);
    for (auto& it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int res = 0;
            int nodeCount = 0;
            DFS(adj, i, visited, res, nodeCount);
            if (res/2 == (nodeCount * (nodeCount - 1) / 2))
                components++;
        }
    }
    return components;

}
