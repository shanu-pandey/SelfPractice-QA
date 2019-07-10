#include <stdio.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

bool HasUnique_ArrayDS(string i_str)
{
	bool temp[26] = { false };
	int length = i_str.length();
	if (length < 2)
		return true;
	for (int i = 0; i < length; i++)
	{
		int index = i_str[i] - 'a';
		if (temp[index] == true)
			return false;
		else
			temp[index] = true;
	}
	return true;
}
bool HasUnique_NoDS(string i_str)
{
	int length = i_str.length();
	if (length < 2)
		return true;

	int checker = 0;
	for (int i = 0; i < length; i++)
	{
		int val = i_str[i] - 'a';

		if ((checker &(1 << val)) > 0)
			return false;

		checker |= (1 << val);
	}
	return true;
}

int main()
	{
#pragma region String: IsUnique
	/*Implement an algorithm to determine if a string has all unique characters. 
	What if you cannot use additional data structures?*/
	string input = "qawsedrftgy";
	bool res = HasUnique_ArrayDS(input);
	res = HasUnique_NoDS(input);
#pragma endregion

#pragma region String: IsUnique
	/*Implement an algorithm to determine if a string has all unique characters.
	What if you cannot use additional data structures?*/
	string input = "qawsedrftgy";
	bool res = HasUnique_ArrayDS(input);
	res = HasUnique_NoDS(input);
#pragma endregion


		return 0;
	}

