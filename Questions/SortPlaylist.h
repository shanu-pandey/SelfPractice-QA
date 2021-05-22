/*
You have access to ranked lists of songs for various users. Each song is represented as an integer, and more preferred songs appear earlier in each list. 
For example, the list [4, 1, 7] indicates that a user likes song 4 the best, followed by songs 1 and 7.
Given a set of these ranked lists, interleave them to create a playlist that satisfies everyone's priorities.

For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}. In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
*/

#pragma once


#pragma once
#include <vector>
#include "DataStructures.h"



namespace Graph
{
	class SortPlaylist
	{
	public:
		SortPlaylist()	
		{
			m_graph = new GraphStruct(0);
		}
		SortPlaylist(std::vector<std::vector<int>> i_playlist) 
		{
			m_graph = new GraphStruct(10);
			for (auto it : i_playlist)			
				for (int i = 0; i < it.size()-1; i++)			
					m_graph->AddEdge(it[i], it[i + 1]);							
		}

		std::vector<int> GetSortedPlaylist(std::vector<std::vector<int>> i_playlist);
		GraphStruct* m_graph;
	};
}


void TopologicalSortHelper(int i_vertex, std::vector<int>& i_visited, std::vector<bool>& i_bVisited, GraphStruct* i_Graph)
{
	i_bVisited[i_vertex] = true;

	for (auto it : i_Graph->m_pAdjacency[i_vertex])
	{
		if (!i_bVisited[it])
			TopologicalSortHelper(it, i_visited, i_bVisited, i_Graph);
	}
	i_visited.push_back(i_vertex);
}

std::vector<int> Graph::SortPlaylist::GetSortedPlaylist(std::vector<std::vector<int>> i_playlist)
{
	std::vector<int> result;
	std::vector<bool> bVisited(10, false);		
	for (int i = 0; i < 10; i++)
	{
		if (!bVisited[i])
			TopologicalSortHelper(i, result, bVisited, m_graph);
	}
	return result;
}