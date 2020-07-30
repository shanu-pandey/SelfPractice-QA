#pragma once
#include "EncodeInPlace.h"


int main()
{
	std::string str = "aaabbcdddd";
	std::string result = StringManipulation::EncodeInPlace::Encode(str);
	std::cout << result;
	return 0;
}