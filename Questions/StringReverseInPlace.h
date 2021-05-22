/*
*Reverse a strig in place
*/

#pragma once
#include <string>
#include <iostream>

namespace StringManipulation
{
	class ReverseInPLace
	{
	public:
		static void ReverseInPlace(std::string& i_str);
	};
}


void StringManipulation::ReverseInPLace::ReverseInPlace(std::string& i_str)
{
	int len = i_str.length();
	for (int i = 0; i < len/2; i++)
	{
		char temp = i_str[i];
		i_str[i] = i_str[len - 1 - i];
		i_str[len-1-i] = temp;
	}
}
