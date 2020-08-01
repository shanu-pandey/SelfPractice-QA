/*
Given a list of positive integers nums and an int target, return indices of the two numbers such that they add up to a target - 30.

Conditions:
You will pick exactly 2 numbers.
You cannot pick the same element twice.
If you have muliple pairs, select the pair with the largest number.

Example 1:
Input: nums = [1, 10, 25, 35, 60], target = 90
Output: [2, 3]
Explanation:
nums[2] + nums[3] = 25 + 35 = 60 = 90 - 30

Example 2:
Input: nums = [20, 50, 40, 25, 30, 10], target = 90
Output: [1, 5]
Explanation:
nums[0] + nums[2] = 20 + 40 = 60 = 90 - 30
nums[1] + nums[5] = 50 + 10 = 60 = 90 - 30
You should return the pair with the largest number.
*/
#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>

namespace Array
{
	class LargestPairWithSum
	{
	public:
		static std::pair<int, int> GetLargestPair(int i_numbers[], int i_size, int i_target);
	};
}


std::pair<int, int> Array::LargestPairWithSum::GetLargestPair(int i_numbers[], int i_size, int i_target)
{
	std::pair<int, int> result;
	if (i_target < 0 || i_size == 0) 
		return result;
	
	int largest = INT_MIN;
	int tempTarget = i_target - 30;
	
	//vector vs hash map comes down to searching time complexity vs space complexity
	//serch time complexity is much less in unordered_map as compared to vector
	std::unordered_map<int, int> pos;
	for (int i = 0; i < i_size; i++) {
		int comp = tempTarget - i_numbers[i];
		if ((i_numbers[i] > largest || comp > largest) && pos.find(comp) != pos.end()) {
			result = std::make_pair(comp, i_numbers[i]);
			largest = std::max(i_numbers[i], comp);
		}
		pos[i_numbers[i]] = i;
	}
	return result;
}
