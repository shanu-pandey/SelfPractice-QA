/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. 

In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>

namespace Array
{
	class MinJumps
	{
	public:
		static int MinJumpsToEnd(std::vector<int>& nums);
	};
}


int Array::MinJumps::MinJumpsToEnd(std::vector<int>& nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int jumps = 0;
    int maxJump = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] + i >= n - 1)
            return ++jumps;

        maxJump = std::max(maxJump, i + nums[i]);

        if (i == end)
        {
            jumps++;
            end = maxJump;
        }
    }
    return -1;
}