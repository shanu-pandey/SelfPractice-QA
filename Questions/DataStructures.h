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
};
