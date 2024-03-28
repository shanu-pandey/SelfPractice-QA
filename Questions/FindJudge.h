/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.



Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1


Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>

namespace Graph
{
    class FindJudge
    {
    public:
        static int FindJudgeCount(int n, std::vector<std::vector<int>>& trust);
    };
}

int Graph::FindJudge::FindJudgeCount(int n, std::vector<std::vector<int>>& trust)
{

    std::vector<std::vector<int>> trustedBy(3);
    std::vector<std::vector<int>> trusts(3);
    int judge = -1;

    for (auto it : trust)
    {
        trustedBy[it[1]].push_back(it[0]);
        trusts[it[0]].push_back(it[1]);
    }

    for (int i = 1; i < n; i++)
    {
        int sz = trustedBy[i].size();
        if (sz == n - 1)
        {
            if (trusts[i].size() == 0)
            {
                if (judge == -1)
                    judge = i;
                else
                    return -1;
            }
        }  
    }
    return judge;

}
