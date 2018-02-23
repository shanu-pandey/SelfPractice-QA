#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert(Node *head, int data)
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

#pragma region Question3: Insert node at tail of linked list
		/*
		You are given the pointer to the head node of a linked list and an integer to add to the list.
		Create a new node with the given integer. 
		Insert this node at the tail of the linked list and return the head node of the linked list formed after inserting this new node.
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

		Node* res = Insert(p3, 4);
#pragma endregion
		
		return 0;
	}

