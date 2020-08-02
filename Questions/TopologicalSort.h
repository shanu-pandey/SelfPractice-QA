//Given a Directed Graph. Find any Topological Sorting of that Graph.

#pragma once
#include <vector>
#include "DataStructures.h"



namespace Graph
{
	class TopologicalSort
	{
	public:
		static std::vector<int> GetTopologicalSort(GraphStruct* i_graph);
	};
}

void TopologicalSortHelper(int i_vertex, bool* i_p_bVisited, std::vector<int>& visitOrderStack, GraphStruct* i_graph)
{
	i_p_bVisited[i_vertex] = true;
	for (auto it : i_graph->m_pAdjacency[i_vertex])
	{
		if (!i_p_bVisited[it])
			TopologicalSortHelper(it, i_p_bVisited, visitOrderStack, i_graph);
	}
	visitOrderStack.push_back(i_vertex);
}

std::vector<int> Graph::TopologicalSort::GetTopologicalSort(GraphStruct* i_graph)
{
	int numVertices = i_graph->m_numVertices;
	bool* p_bVisited = new bool[numVertices];
	std::vector<int> visitOrderStack;
	for (int i = 0; i < numVertices; i++)
		p_bVisited[i] = false;


	for (int i = 0; i < numVertices; i++)
	{
		if (!p_bVisited[i])
			TopologicalSortHelper(i, p_bVisited, visitOrderStack, i_graph);
	}

	return visitOrderStack;
}

