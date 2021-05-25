#pragma once
#include <list>



struct GraphStruct
{
	int m_numVertices;
	std::list<int>* m_pAdjacency;

	GraphStruct() : m_numVertices(0)
	{}

	GraphStruct(int i_numVertices) : m_numVertices(i_numVertices)
	{
		m_pAdjacency = new std::list<int>[i_numVertices];
	}

	void AddEdge(int i_src, int i_target)
	{
		m_pAdjacency[i_src].push_back(i_target);
	}

	static GraphStruct* GetSampleGraph()
	{
		GraphStruct* result = new GraphStruct(4);
		/*result->AddEdge(0, 6);
		result->AddEdge(1, 2);
		result->AddEdge(1, 4);
		result->AddEdge(1, 6);
		result->AddEdge(3, 0);
		result->AddEdge(3, 4);
		result->AddEdge(5, 1);
		result->AddEdge(7, 0);
		result->AddEdge(7, 1);*/

		result->AddEdge(0, 1);
		result->AddEdge(0, 2);
		result->AddEdge(1, 2);
		result->AddEdge(2, 0);
		result->AddEdge(2, 3);
		result->AddEdge(3, 3);
		return result;
	}
};

struct BinaryTree
{
	int data;
	BinaryTree* m_left;
	BinaryTree* m_right;

	BinaryTree() : data(0), m_left(nullptr), m_right(nullptr)
	{}

	BinaryTree(int i_data) : data(i_data), m_left(nullptr), m_right(nullptr)
	{}

	BinaryTree(int i_data, BinaryTree* i_left, BinaryTree* i_right) : data(i_data), m_left(i_left), m_right(i_right)
	{}

	static BinaryTree* GetSampleTree()
	{
		BinaryTree* root = new BinaryTree(20);
		root->m_left = new BinaryTree(8);
		root->m_left->m_left = new BinaryTree(4);
		root->m_left->m_right = new BinaryTree(12);
		root->m_left->m_right->m_left = new BinaryTree(10);
		root->m_left->m_right->m_right = new BinaryTree(14);
		root->m_right = new BinaryTree(22);
		root->m_right->m_right = new BinaryTree(25);
		return root;
	}
};


struct Node
{
	Node* m_pNext;
	int val;	

	Node() : val(0), m_pNext(nullptr)
	{}

	Node(int i_val) : val(i_val), m_pNext(nullptr)
	{}
};

class LinkedList
{
public:
	LinkedList()
	{
		m_pHead = nullptr;
		m_pTail = nullptr;
	}

	void Add(int i_val)
	{
		Node* pNewNode = new Node();
		pNewNode->val = i_val;

		if (m_pHead == nullptr)
		{
			m_pHead = pNewNode;
			m_pTail = pNewNode;
		}
		else
		{
			m_pTail->m_pNext = pNewNode;
			m_pTail = m_pTail->m_pNext;
		}
	}

	bool IfExists(int i_val)
	{
		if (m_pHead == nullptr)
			return false;

		while (m_pHead != nullptr)
		{
			if (m_pHead->val == i_val)
				return true;

			m_pHead = m_pHead->m_pNext;
		}

		return false;
	}

private :
	Node* m_pHead;
	Node* m_pTail;

};