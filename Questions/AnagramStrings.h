/*
Two String is called anagram, if they contains the same characters but on different order e.g. army and mary, stop and pots, etc. 
Anagrams are actually a mix-up of characters in String. 
*/

#pragma once
#include <string>
#include <iostream>
#include <map>
namespace StringManipulation
{
	class AnagramString
	{
	public:
		static bool IfAnagram(std::string i_str1, std::string i_str2);
	};
}


bool StringManipulation::AnagramString::IfAnagram(std::string i_str1, std::string i_str2)
{
	int len1 = i_str1.length();
	int len2 = i_str2.length();

	if (len1 != len2)
		return false;

	std::map<char, int> anagram;

	for (int i = 0; i < len1; i++)
	{
		anagram[i_str1[i]]++;
		anagram[i_str2[i]]++;
	}

	for (auto it : anagram)
	{
		if (it.second % 2 != 0)
			return false;
	}

	return true;
}