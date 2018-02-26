#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

Node* InsertTail(Node *head, int data)
{
	Node* curr = new Node();
	Node* newNode = new Node();
	newNode->data = data;

	curr = head;
	if (head != NULL)
	{
		while (curr->next != NULL)
			curr = curr->next;

		curr->next = newNode;
	}
	else
	{
		head = newNode;
		newNode->next = NULL;
	}
	return head;
}

Node* InsertHead(Node *head, int data)
{
	Node* curr = new Node();
	Node* newNode = new Node();
	newNode->data = data;

	curr = newNode;
	if (head != NULL)
		curr->next = head;

	return curr;
}

Node* InsertAtPosition(Node *head, int data, int position)
{
	int currentPosition = 0;
	Node* curr = new Node();
	Node* prev = new Node();
	Node* newNode = new Node();
	newNode->data = data;	

	curr = head;
	prev = curr;
	if (head != NULL)
	{
		while (curr->next != NULL && currentPosition != position)
		{
			prev = curr;
			curr = curr->next;
			currentPosition++;
		}
		if (position == 0)
		{
			head = newNode;
			head->next = prev;
		}
		else
		{
			newNode->next = curr;
			prev->next = newNode;
		}
	}
	else
	{
		head = newNode;
		newNode->next = NULL;
	}
	return head;
}

int lengthOfLongestSubstring(string s)
	{
		if (s.length() < 1)
			return 0;
		std::vector<int> indexVector;
		indexVector.push_back(0);
		int result = 1;
		int output = 1;
		bool ifExists = false;
		for (int i = 1; i < s.length(); i++)
		{
			ifExists = false;
			for (int j = 0; j < indexVector.size(); j++)
			{
				if (s[i] == s[indexVector[j]])
				{


					for (int k = j; k >= 0; k--)
					{
						indexVector.erase(indexVector.begin());

					}


					indexVector.push_back(i);

					ifExists = true;
					break;
				}
			}
			if (!ifExists)
			{
				indexVector.push_back(i);

			}

			if (indexVector.size() > result)
				result = indexVector.size();
		}
		return result;
	}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> merged;
		int i = 0;
		int j = 0;
		double median = 0.0;

		if (nums1.size() == 0 && nums2.size() == 0)
			return median;
		else if (nums1.size() == 0)
			merged = nums2;
		else if (nums2.size() == 0)
			merged = nums1;
		else
		{
			while (merged.size() != nums1.size() + nums2.size())
			{
				if (nums1[i] > nums2[j])
				{
					merged.push_back(nums2[j]);
					j++;
					if (j == nums2.size())
					{
						for (int k = i; k < nums1.size(); k++)
							merged.push_back(nums1[k]);

						break;
					}
				}
				else
				{
					merged.push_back(nums1[i]);
					i++;
					if (i == nums1.size())
					{
						for (int k = j; k < nums2.size(); k++)
							merged.push_back(nums2[k]);

						break;
					}
				}
			}
		}
		if (merged.size() % 2 == 0)
			median = (double)(merged[merged.size() / 2] + merged[merged.size() / 2 - 1]) / 2;
		else
			median = merged[(merged.size() - 1) / 2];

		return median;
	}

int KindergardenAdventures()
{
	int o_ID = 0;
	int n;
	int tempTime;
	int failed = 0;
	int pass = 0;
	vector<int> time;
	vector<int> fail;
	cout << "Enter number of students";
	cin >> n;

	for (int i = 0; i < n;i++)
	{
		cout << "Enter time for student-" << i;
		cin >> tempTime;
		time.push_back(tempTime);
	}

	o_ID = 1;

	for (int i = 0; i < n; i++)
	{ 
		tempTime = i;
		fail.push_back(0);
		for (int j = 0; j < n; j++)
		{
			if (time[tempTime++] > j)
			{
				fail[i]++;
			}
			if (tempTime >= n)
				tempTime = 0;
		}			
	}

	for (int i = 1; i < n; i++)
	{
		if (fail[i] < fail[o_ID-1])
			o_ID = i + 1;
	}

	return o_ID;
}

bool IsPalindrome(string s)
{
	for (int i = 0; i < s.length()/2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

string longestPalindrome(string s) {
	string o_palindrome = "";

	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i+1; j < s.length(); j++)
		{
			if (IsPalindrome(s.substr(i, j)))
			{
				o_palindrome = s.substr(i, j);
			}
		}
	}
	return o_palindrome;
}



int main()
	{
#pragma region Question1: Longest substring without repeating characters
		/*
		Given a string, find the length of the longest substring without repeating characters.
		Examples:
		Given "abcabcbb", the answer is "abc", which the length is 3.
		Given "bbbbb", the answer is "b", with the length of 1.
		Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
		*/
		string s = "pwwkew";
		int i = lengthOfLongestSubstring(s);

#pragma endregion

#pragma region Question2: Median of two sorted array
		/*
		There are two sorted arrays nums1 and nums2 of size m and n respectively.
		Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

		Example 1:
		nums1 = [1, 3]
		nums2 = [2]
		The median is 2.0

		Example 2:
		nums1 = [1, 2]
		nums2 = [3, 4]
		The median is (2 + 3)/2 = 2.5
		*/
		vector<int> a = { 1, 8, 16, 40 };
		vector<int> b = { 2, 3, 5, 9, 11, 17 };
		double median = findMedianSortedArrays(a, b);
#pragma endregion

#pragma region Question3: Insert node at TAIL of linked list
		/*
		You are given the pointer to the head node of a linked list and an integer to add to the list.
		Create a new node with the given integer. 
		Insert this node at the TAIL of the linked list and return the head node of the linked list formed after inserting this new node.
		The given head pointer may be null, meaning that the initial list is empty.
		*/

		Node* p = new Node();
		p->data = 1;
		p->next = nullptr;

		Node* p2 = new Node();
		p2->data = 2;
		p2->next = p;

		Node* p3 = new Node();
		p3->data = 3;
		p3->next = p2;

		Node* res = InsertTail(p3, 4);
#pragma endregion
		
#pragma region Question4: Insert node at HEAD of a linked list
		/*
		You are given the pointer to the head node of a linked list and an integer to add to the list.
		Create a new node with the given integer.
		Insert this node at the HEAD of the linked list and return the head node of the linked list formed after inserting this new node.
		The given head pointer may be null, meaning that the initial list is empty.
		*/
		res = InsertHead(p3, 4);
#pragma endregion

#pragma region Question5: Insert node at specific position in a linked list
		/*
		You’re given the pointer to the head node of a linked list, an integer to add to the list and the position at which the integer must be inserted. 
		Create a new node with the given integer, insert this node at the desired position and return the head node. 
		A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. 
		The head pointer given may be null meaning that the initial list is empty.
		*/
		res = InsertAtPosition(p3, 12, 2);
#pragma endregion

#pragma region Question6: Kindergarden Adventures (Fix Time Complexity)
		/*
		Meera teaches a class of  students, and every day in her classroom is an adventure. Today is drawing day!
		The students are sitting around a round table, and they are numbered from  to  in the clockwise direction. 
		This means that the students are numbered , and students  and  are sitting next to each other.
		After letting the students draw for a certain period of time, Meera starts collecting their work to ensure she has time to review all the
		drawings before the end of the day.
		However, some of her students aren't finished drawing! Each student  needs  extra minutes to complete their drawing.
		Meera collects the drawings sequentially in the clockwise direction, starting with student ID , and it takes her exactly minute to review each drawing.
		This means that student  gets  extra minutes to complete their drawing, student  gets  extra minute, student  gets  extra minutes, and so on.
		Note that Meera will still spend minute for each student even if the drawing isn't ready.
		Given the values of , help Meera choose the best possible  to start collecting drawings from, such that the number of students
		able to complete their drawings is maximal. Then print  on a new line. If there are multiple such IDs, select the smallest one.

		Input Format
		The first line contains a single positive integer, , denoting the number of students in the class.
		The second line contains  space-separated integers describing the respective amounts of time that each student needs to finish their drawings (i.e., ).
		
		Output Format
		Print an integer denoting the ID number, , where Meera should start collecting the drawings such that a maximal number of students can complete their drawings.
		If there are multiple such IDs, select the smallest one.

		Sample Input
		3
		1 0 0
		Output
		2
		*/
		//int result = KindergardenAdventures();
#pragma endregion

#pragma region Question7: Longest Palindrome
		/*
		Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

		Example:
		Input: "babad"
		Output: "bab"
		Note: "aba" is also a valid answer.

		Example:
		Input: "cbbd"
		Output: "bb"
		*/
		string palindrome = longestPalindrome("ASDFGGFDSA");
#pragma endregion

		return 0;
	}

