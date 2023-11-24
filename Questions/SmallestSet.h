/*
Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. 
If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], one set of numbers that covers all these intervals is {3, 6}.
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

namespace Array_2D
{
    class SmallestSet
    {
    public:
        static std::vector<int> GetSmallestSet(std::vector<std::vector<int>> set);
    };
}

bool compare(std::vector<int>& a, std::vector<int>& b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

std::vector<int> Array_2D::SmallestSet::GetSmallestSet(std::vector<std::vector<int>> set)
{
    std::vector<int> result;

    result.push_back(set[0][0]);
    result.push_back(set[0][1]);

    std::sort(set.begin(), set.end(), compare);

    for (int i = 1; i < set.size(); i++)
    {
        if (set[i][0] > result[1])
        {
            result[0] = result[1];
            result[1] = set[i][0];
        }
        else if (set[i][0] < result[1])
        {
            result[0] = set[i][0];
        }
    }
    return result;
}

