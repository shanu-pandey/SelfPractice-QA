/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]

Constraints:
The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
*/

#pragma once
#include"DataStructures.h"



namespace DS_LinkedList
{
	class RemoveZeroSumConsecutiveNode
	{
	public:
		static Node* RemoveZeroSumSublists(Node* i_head);
	};
}

Node* DS_LinkedList::RemoveZeroSumConsecutiveNode::RemoveZeroSumSublists(Node* i_head)
{	
	if (i_head == nullptr || i_head->m_pNext == nullptr)
		return i_head;

	Node* result = new Node();
	int currSum;
	
	Node* pCurr = i_head;
	Node* pPrev = new Node();
	pPrev->m_pNext = i_head;
	result = pPrev;
	
	currSum = 0;

	while (i_head)
	{
		currSum = 0;
		bool bChange = false;
		while (i_head)
		{
			currSum += i_head->val;
			if (currSum == 0)
			{
				pPrev->m_pNext = i_head->m_pNext;
				bChange = true;
				break;
			
			}
			i_head = i_head->m_pNext;
		}
		if (bChange)
		{
			i_head = pPrev->m_pNext;
		}
		else
		{
			pPrev = pPrev->m_pNext;
			i_head = pPrev->m_pNext;
		}
	}
	return result->m_pNext;
}