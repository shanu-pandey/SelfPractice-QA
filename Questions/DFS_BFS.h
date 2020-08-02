#pragma once
#include <vector>
#include <queue>
#include "DataStructures.h"

namespace Graph
{
	class DFS_BFS
	{
	public:
		static std::vector<int> Get_DFSOrder(GraphStruct* i_graph, int i_startVal);
		static std::vector<int> Get_BFSOrder(GraphStruct* i_graph, int i_startVal);
	};
}

void DFSHelper(int i_src, GraphStruct* i_pGraph, std::vector<bool>& i_visited, std::vector<int>& i_result)
{
	i_visited[i_src] = true;
	i_result.push_back(i_src);

	for (auto it : i_pGraph->m_pAdjacency[i_src])
	{
		if (!i_visited[it])
			DFSHelper(it, i_pGraph, i_visited, i_result);
	}
}

std::vector<int> Graph::DFS_BFS::Get_DFSOrder(GraphStruct* i_graph, int i_startVal)
{
	std::vector<int> result;
	result.reserve(i_graph->m_numVertices);
	std::vector<bool> visited(i_graph->m_numVertices, false);
	DFSHelper(i_startVal, i_graph, visited, result);
	return result;
}

std::vector<int> Graph::DFS_BFS::Get_BFSOrder(GraphStruct* i_graph, int i_startVal)
{
	std::vector<int> result;
	result.reserve(i_graph->m_numVertices);
	std::vector<bool> visited(i_graph->m_numVertices, false);
	std::queue<int> toVisitQueue;// (std::queue<int>::container_type(i_graph->m_numVertices));

	toVisitQueue.push(i_startVal);	

	while (!toVisitQueue.empty())
	{
		int current = toVisitQueue.front();
		toVisitQueue.pop();

		if (visited[current])
			continue;

		visited[current] = true;
		result.push_back(current);
		for (auto it : i_graph->m_pAdjacency[current])
			toVisitQueue.push(it);
	}
	

	return result;
}