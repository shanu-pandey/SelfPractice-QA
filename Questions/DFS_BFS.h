#pragma once
#include <vector>
#include "DataStructures.h"

namespace Graph
{
	class DFS_BFS
	{
	public:
		static std::vector<int> Get_DFSOrder(GraphStruct* i_graph);
		static std::vector<int> Get_BFSOrder(GraphStruct* i_graph);
	};
}


std::vector<int> Graph::DFS_BFS::Get_DFSOrder(GraphStruct* i_graph)
{
	std::vector<int> result;

	return result;
}

std::vector<int> Graph::DFS_BFS::Get_BFSOrder(GraphStruct* i_graph)
{
	std::vector<int> result;

	return result;
}