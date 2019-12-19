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


int Factorial(int n)
{
	if (n > 1)
		return n * Factorial(n - 1);
	else
		return 1;
}

vector<vector<int>> Combine(int n, int k) 
{
	vector<vector<int>> result;
	if (k > n)
		return result;

	int total = Factorial(n) / (Factorial(k)*Factorial(n - k));
	result.reserve(total);
	for (int i = 1; i <= total; i++)
	{

	}

	for (int i = 1; i <= k; i++)
	{
		vector<int> temp;
		temp.push_back(i);
		for (int j = 0; j < n; j++)
		{
			temp.push_back(i + j);
		}
	}
}

Node* ReverseBetween(Node* head, int m, int n)
{
	Node* prev = nullptr;
	Node* curr = head;
	Node* next = nullptr;
	int i = 1;
	while (curr != nullptr)
	{
		if (i > m && i <= n)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			i++;
		}
		else if (i > n)
			break;
		else
		{
			prev = curr;
			curr = curr->next;
			i++;
		}
	}
	return head;
}


vector<int> GetConnections(int src, vector<int> &T)
{
	vector<int> paths;

	for (int i = 1; i < T.size(); i++)
	{
		if (T[i] == src)
			paths.push_back(i);
	}
	return paths;
}


void GetCost(int curr, vector<int> roads, int cost, bool bTicketUsed, vector<int>& T, int& maxCost)
{
	if (cost > maxCost)
		maxCost = cost;
	for (auto it : roads)
	{
		if (it % 2 != 0)
		{
			if (bTicketUsed)
			{
				bTicketUsed = false;
				return;
			}
			else
				bTicketUsed = true;
		}
		GetCost(it, GetConnections(it, T), cost + 1, bTicketUsed, T, maxCost);
	}
}


int solution(vector<int> &T)
{	
	int maxCost = 1;
	GetCost(0, GetConnections(0, T), 1, false, T, maxCost);
	return maxCost;
}


void Reverse(char* start, char* end)
{
	char temp;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*start++ = *end;
		*end-- = temp;
	}
}

void ReverseWordsInPlace(char* input)
{
	char* begin = input;
	char* temp = input;

	while (*temp)
	{
		temp++;
		if (*temp == '/0')
		{
			Reverse(begin, temp);
		}
		else if (*temp == ' ')
		{
			Reverse(begin, temp - 1);
			begin = temp + 1;
		}
	}
	Reverse(input, temp - 1);
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
	//std::vector<int> res = DuplicateNumbers(a,18);
#pragma endregion

#pragma region Reverse a linked list from position m to n in one - pass.
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	
	//Node* rev = reverseBetween(n1, 2, 4);
#pragma endregion
		
	char* input = "This is a test input to test things!";
	ReverseWordsInPlace(input);
	   	return 0;
	}

