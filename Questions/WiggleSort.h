/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]


Constraints:
1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.

*/
#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace Array
{
	class WiggleSort
	{
	public:
		static void DoWiggleSort(std::vector<int> nums);
	};
}

void Array::WiggleSort::DoWiggleSort(std::vector<int> nums)
{
    int len = nums.size();
    if (len < 2)
        return;

    std::vector<int> sol;// = new std::vector<int>();
    sol.reserve(len);
    std::sort(nums.begin(), nums.end());
    int backIndex = len - 1;
    int start = 1;

    while (start < len)
    {
        sol[start] = nums[backIndex];
        start += 2;
        backIndex--;
    }

    start = 0;
    while (start < len)
    {
        sol[start] = nums[backIndex];
        backIndex--;
        start += 2;
    }

    for (int i = 0; i < len; i++)
        nums[i] = sol[i];
}