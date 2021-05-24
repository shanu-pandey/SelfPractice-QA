/*
You are given two strings s1 and s2 of equal length.
A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.

Input: s1 = "abcd", s2 = "dcba"
Output: false
*/

#pragma once
#include <string>
#include <iostream>

namespace StringManipulation
{
	class StringSwapMakeEqual
	{
	public:
		static bool AreAlmostEqual(std::string i_str1, std::string i_str2);
	};
}


bool StringManipulation::StringSwapMakeEqual::AreAlmostEqual(std::string i_str1, std::string i_str2)
{
	int len1 = i_str1.length();
	int len2 = i_str2.length();

	if (len1 != len2)
		return false;

	int swapCount = 0;
	char swap1;
	char swap2;

	for (int i = 0; i < len1; i++)
	{
		if (i_str1[i] != i_str2[i])
		{
			swapCount++;
			if (swapCount > 2)
			{
				return false;
			}
			else if (swapCount == 1)
			{
				swap1 = i_str1[i];
				swap2 = i_str2[i];
			}
			else
			{
				if (i_str1[i] != swap2 || i_str2[i] != swap1)
					return false;
			}			
		}
	}

	if (swapCount == 1) 
		return false;

	return true;
}