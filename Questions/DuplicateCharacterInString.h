/*
Write a program to find repeated characters in a String. 
For example, if given input to your program is "Java", it should print all duplicates characters 
i.e. characters appear more than once in String and their count like a = 2 because of character 'a' has appeared twice in String "Java"
*/

#pragma once
#include <string>
#include <iostream>
#include <map>
namespace StringManipulation
{
	class DuplicateCharacterInString
	{
	public:
		static std::map<char, int> DuplicateWithCount(std::string i_str);
	};
}


std::map<char, int> StringManipulation::DuplicateCharacterInString::DuplicateWithCount(std::string i_str)
{
	std::map<char, int> result;

	for (int i = 0; i < i_str.length(); i++)
	{
		result[i_str[i]]++;
	}
	return result;
}