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
	int length = i_str.length();
	if (length < 2)
		return true;

	int bitSet = 0;
	for (int i = 0; i < length; i++)
	{
		int bitVal = i_str[i] - 'a';
		bitSet ^= (1 << bitVal);
	}

	if (bitSet != 0)
		return false;

	return true;
}

bool OneAway(string i_str1, string i_str2)
{
	int l1 = i_str1.length();
	int l2 = i_str2.length();

	if (l1 - l2 < -1 || l1 - l2>1)
		return false;

	int edits = 0;
	int i = 0;
	int j = 0;

	while (i < l1 && j < l2)
	{
		if (i_str1[i] != i_str2[j])
		{
			if (edits == 1)
				return false;

			if (l1 > l2)
				i++;
			else if (l1 < l2)
				j++;
			else
			{
				i++;
				j++;
			}
			edits++;
		}
		else
		{
			i++;
			j++;
		}
	}

	if (i < l1 || j < l2)
		edits++;

	return (edits == 1);
	
}

void RotateMatrix(int** i_matrix, int i_size)
{
	for (int i = 0; i < i_size/2; i++)
	{
		for (int j = i; j < i_size-1-i; j++)
		{
			int temp = i_matrix[i][j];
			i_matrix[i][j] = i_matrix[j][i_size - 1 - i];
			i_matrix[j][i_size - 1 - i] = i_matrix[i_size - 1 - i][i_size-1-j];
			i_matrix[i_size - 1 - i][i_size - 1 - j] = i_matrix[i_size - 1 - j][i];
			i_matrix[i_size - 1 - j][i] = temp;
		}
	}
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
	//string input = "ASDFGSDGFAA";
	//bool palindromePermutation = PalindromePermutataion(input);
#pragma endregion

#pragma region String: Palindrom Permutation
	//Given two strings, write a function to check if they are one edit(or zero edits) away
	string input1 = "strange";
	string input2 = "strage";
	bool oneAway = OneAway(input1, input2);
#pragma endregion

#pragma region Rotate Matrix
	/*Given an image represented by an NxN matrix, where each pixel in the image is 4
	bytes, write a method to rotate the image by 90 degrees.Can you do this in place ?*/
	

	int **matrix;
	matrix = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		matrix[i] = new int[5];
	}

	matrix[0][0] = 1;	matrix[0][1] = 2;	matrix[0][2] = 3;	matrix[0][3] = 4;	matrix[0][4] = 5;
	matrix[1][0] = 11;	matrix[1][1] = 12;	matrix[1][2] = 13;	matrix[1][3] = 14;	matrix[1][4] = 15;
	matrix[2][0] = 21;	matrix[2][1] = 22;	matrix[2][2] = 23;	matrix[2][3] = 24;	matrix[2][4] = 25;
	matrix[3][0] = 31;	matrix[3][1] = 32;	matrix[3][2] = 33;	matrix[3][3] = 34;	matrix[3][4] = 35;
	matrix[4][0] = 41;	matrix[4][1] = 42;	matrix[4][2] = 43;	matrix[4][3] = 44;	matrix[4][4] = 45;

	RotateMatrix(matrix, 5);

#pragma endregion


		return 0;
	}

