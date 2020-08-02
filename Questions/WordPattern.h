/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false
*/

#pragma once
#include <string>
#include <map>

namespace StringManipulation
{
	class WordPattern
	{
	public:
		static bool IfFollowsPattern(std::string i_pattern, std::string i_str);
	};
}


bool StringManipulation::WordPattern::IfFollowsPattern(std::string i_pattern, std::string i_str)
{
	int patternLen = i_pattern.length();
	int wordLen = i_str.length();	

	if (patternLen > wordLen || patternLen == 0 ||wordLen == 0)
		return false;

	int currentIndex = 0;
	std::string temp = "";
	std::map<char, std::string> map;

	for (int i = 0; i < patternLen; i++)
	{		
		for (int j = currentIndex; j < wordLen; j++)
		{
			if (i_str[j] == ' ')
			{
				currentIndex = j + 1;
				if (temp != "")
				{
					//if key already present
					if (map.find(i_pattern[i]) != map.end())
					{
						if (temp != map[i_pattern[i]])
							return false;
					}

					//if value already present
					for (auto it = map.begin(); it != map.end(); ++it)
					{
						if (it->second == temp)
						{
							if (it->first != i_pattern[i])
								return false;
						}
					}							
					map[i_pattern[i]] = temp;
					temp = "";
					break;
				}				
			}
			else
			{
				temp += i_str[j];
			}
		}
	}
	
	//if key already present
	if (map.find(i_pattern[patternLen-1]) != map.end())
	{
		if (temp != map[i_pattern[patternLen-1]])
			return false;
	}

	//if value already present
	for (auto it = map.begin(); it != map.end(); ++it)
	{
		if (it->second == temp)
		{
			if (it->first != i_pattern[patternLen-1])
				return false;
		}
	}
	return true;
}