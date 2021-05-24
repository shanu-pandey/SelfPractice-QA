/*
Given a string s and an integer array indices of the same length.
The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
Return the shuffled string.

Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.


Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.

Input: s = "aiohn", indices = [3,1,4,2,0]
Output: "nihao"

Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
Output: "arigatou"

Input: s = "art", indices = [1,0,2]
Output: "rat"
*/
#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace StringManipulation
{
	class ShuffleString
	{
	public:
		static std::string RestoreString(std::string i_str1, std::vector<int>& i_indices);
	};
}


std::string StringManipulation::ShuffleString::RestoreString(std::string i_str1, std::vector<int>& i_indices)
{
	std::string result = i_str1;
	int i = 0;
	
	for (auto it : i_indices)	
		result[it] = i_str1[i++];
	
	return result;
}