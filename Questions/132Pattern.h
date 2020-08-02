/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. 
Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Example 1:
Input: [1, 2, 3, 4]			
Output: False
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: [3, 1, 4, 2]
Output: True
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:
Input: [-1, 3, 2, 0]
Output: True
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>

namespace Array
{
	class Pattern132
	{
	public:
		static bool IfExists_132(std::vector<int>& i_numbers);
	};
}


bool Array::Pattern132::IfExists_132(std::vector<int>& i_numbers)
{
	int sz = i_numbers.size();
	if (sz < 3)
		return false;

	std::vector<int> minVal(sz);
	minVal[0] = i_numbers[0];

	for (int i = 1; i < sz; i++)
		minVal[i] = std::min(minVal[i - 1], i_numbers[i]);

	std::stack<int> numPosStack;

	for (int i = sz - 1; i > 0; i--)
	{
		while (!numPosStack.empty() && i_numbers[numPosStack.top()] < i_numbers[i])
		{
			if (i_numbers[numPosStack.top()] > minVal[i-1])
				return true;

			numPosStack.pop();
		}
		numPosStack.push(i);
	}
	return false;
}