/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

#pragma once
#include"DataStructures.h"


namespace DS_LinkedList
{
	class ReverseLinkedListInPlace
	{
	public:
		static void ReverseInPlace(Node* i_head);		
	};
}

void DS_LinkedList::ReverseLinkedListInPlace::ReverseInPlace(Node* i_head)
{
	if (i_head == nullptr || i_head->m_pNext == nullptr)
		return;

	Node* pNext = nullptr;
	Node* pPrev = nullptr;
	Node* pCurr = i_head;

	while (pCurr)
	{ 
		pNext = pCurr->m_pNext;
		pCurr->m_pNext = pPrev;
		pPrev = pCurr;
		pCurr = pNext;		
	}

	i_head = pPrev;
}