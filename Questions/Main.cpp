#include <stdio.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>



using namespace std;

struct Node
{
	int value;
	Node* next;
	Node()
	{
		value = 0;
		next = nullptr;
	}
	Node(int val) : value(val), next(nullptr){}
};

int MissingNumber(int i_array[], int i_size)
{
	int sum = (i_size * (i_size + 1)) / 2;
	int currentSum = 0;
	for (int i = 0; i < i_size; i++)
		currentSum += i_array[i];

	return sum-currentSum;
}

std::vector<int> DuplicateNumbers(int i_array[], int i_size)
{	
	std::vector<int> result;
	std::set<int> unique;
	std::pair<std::set<int>::iterator, bool> insertPair;
	for (int i = 0; i < i_size; i++)
	{
		insertPair = unique.insert(i_array[i]);

		if (insertPair.second == false)
		{
			result.push_back(i_array[i]);
		}
	}

	return result;
}

std::vector<std::vector<int>> PairEqualSum(int i_array[], int i_size)
{
	std::vector<std::vector<int>> result;
	std::set<int> unique;
	std::pair<std::set<int>::iterator, bool> insertPair;
	for (int i = 0; i < i_size; i++)
	{
		
	}

	return result;
}


int main()
	{
#pragma region How do you find the missing number in a given integer array of 1 to 100 ?
	//int a1[] = { 1,2,3,5,6,7,8,9,10 };
	//int res = MissingNumber(a1, 10);
#pragma endregion

#pragma region How do you find the duplicate number on a given integer array?
	//int a[] = { 1,1,2,3,5,5,6,7,8,9,10,10,11,11,12,12,12,12 };
	//std::vector<int> res = DuplicateNumbers(a2,18);
#pragma endregion

#pragma region How do you find all pairs of an integer array whose sum is equal to a given number?
	int a[] = { 1,1,2,3,5,5,6,7,8,9,10,10,11,11,12,12,12,12 };
	std::vector<int> res = DuplicateNumbers(a,18);
#pragma endregion


		return 0;
	}

