/*
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it in the maximum amount of balanced strings.
Return the maximum amount of split balanced strings.

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
*/


#pragma once
#include <string>
#include <iostream>

namespace StringManipulation
{
	class BalancedStringSplit
	{
	public:
		static int SplitBalancedString(std::string i_str);
	};
}


int StringManipulation::BalancedStringSplit::SplitBalancedString(std::string i_str)
{
	int result = 0;
	int len = i_str.length();

	if (len == 2)
		return 1;

	int balance = 0;
	if (i_str[0] == 'L')
		balance++;
	else
		balance--;

	for (int i = 1; i < len; i++)
	{
		if (i_str[i] == 'L')
			balance++;
		else
			balance--;

		if (balance == 0)
		{
			result++;
			if (i != len - 1)
			{
				if (i_str[i + 1] == 'L')
					balance++;
				else
					balance--;
				i++;
			}
		}
	}
	return result;
}
