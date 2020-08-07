/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/
#pragma once
#include <string>
#include <stack>

namespace Stack
{
	class ValidParentheses
	{
	public:
		static bool IsValid(std::string i_str);
	};
}


bool CheckParentheses(char i_left, char i_right)
{
	if (i_left == '(' && i_right == ')')
		return true;
	if (i_left == '[' && i_right == ']')
		return true;
	if (i_left == '{' && i_right == '}')
		return true;

	return false;
}

bool Stack::ValidParentheses::IsValid(std::string i_str)
{	
	if (i_str.length() < 2)
		return false;

	std::stack<char> visited;

	for (int i = 0; i < i_str.length(); i++)
	{
		if (visited.empty())
			visited.push(i_str[i]);
		else
		{
			if (i_str[i] == '[' || i_str[i] == '{' || i_str[i] == '(')
				visited.push(i_str[i]);
			else if (!CheckParentheses(visited.top(), i_str[i]))
				return false;
			else
				visited.pop();
		}
	}
	if (visited.empty())
		return true;
	return false;
}
