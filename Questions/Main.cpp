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


bool CheckPermutataion(string i_str1, string i_str2)
{
	int l1 = i_str1.length();
	int l2 = i_str2.length();

	if (l1 != l2)
		return false;

	int bitset = 0;
	for (int i = 0; i < l1; i++)
	{
		int bitVal = i_str1[i] - 'a';
		bitset |= (1 << bitVal);
	}

	for (int i = 0; i < l2; i++)
	{
		int bitVal = i_str2[i] - 'a';
		if (((bitset >> bitVal) & 1) < 1)
			return false;
	}

	return true;
}

bool PalindromePermutataion(string i_str)
{
	int l1 = i_str.length();
	return true;
}

int main()
	{
#pragma region String: IsUnique
	/*Implement an algorithm to determine if a string has all unique characters. 
	What if you cannot use additional data structures?
	string input = "qawsedrftgy";
	bool res = HasUnique_ArrayDS(input);
	res = HasUnique_NoDS(input);*/
#pragma endregion

#pragma region String: Check Permutation
	//Given two strings, write a method to decide if one is a permutation of the other.	
	//string input1 = "ASDFGA";
	//string input2 = "AGSFSDA";
	//bool permutation = CheckPermutataion(input1, input2);
#pragma endregion

#pragma region String: Palindrom Permutation
	//Given a string, write a function to check if it is a permutation of a palindrome.

	string input = "ASDFGA";
	bool palindromePermutation = PalindromePermutataion(input);
#pragma endregion

		return 0;
	}

