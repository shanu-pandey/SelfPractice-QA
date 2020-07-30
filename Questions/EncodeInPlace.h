//Encode "aaabbcddddd" to "a3b2cd5" in place, can only use constant extra memory.

#pragma once
#include <string>
#include <iostream>
 
namespace StringManipulation
{
	class EncodeInPlace
	{
	public:
		static std::string Encode(std::string i_str);
	};
}


std::string StringManipulation::EncodeInPlace::Encode(std::string i_str)
{
	std::string result;
	int count = 1;
	char current = i_str[0];
	for (int i = 1; i < i_str.length(); i++)
	{
		char next = i_str[i];
		if (next == current)
		{
			count++;
		}
		else
		{
			result += current;
			if (count != 1)
				result += std::to_string(count);
			count = 1;
			current = next;
		}
	}
	result += current;
	if (count != 1)
		result += std::to_string(count);
	return result;
}

