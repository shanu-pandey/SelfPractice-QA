/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

namespace Array_2D
{
    class NonOverlappingIntervals
    {
    public:
        static int EraseOverlapIntervals(std::vector<std::vector<int>>& intervals);
    private:
        static bool CompareDiff(std::vector<int>& a, std::vector<int>& b);
    };
}

bool Array_2D::NonOverlappingIntervals::CompareDiff(std::vector<int>& a, std::vector<int>& b)
{
    return a[1] < b[1];
}

int Array_2D::NonOverlappingIntervals::EraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
    int size = intervals.size();
    if (size < 2)
        return 0;

    sort(intervals.begin(), intervals.end(), CompareDiff);

    int end = intervals[0][1];
    int deletions = 0;

    for (int i = 1; i < size; i++)
    {
        if (intervals[i][0] < end)
            deletions++;
        else
            end = intervals[i][1];
    }

    return deletions;
}

