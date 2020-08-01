//Given a Directed Graph. Find any Topological Sorting of that Graph.

#pragma once
#include <list>

struct GraphStruct
{
	int m_numVertices;
	std::list<int>* m_pAdjacency;

	GraphStruct() : m_numVertices(0), m_pAdjacency(nullptr)
	{}

	GraphStruct(int i_numVertices) : m_numVertices(i_numVertices), m_pAdjacency(nullptr)
	{}

	void AddEdge(int i_src, int i_target)
	{
		m_pAdjacency[i_src].push_back(i_target);
	}

	static GraphStruct* GetSampleGraph()
	{
		GraphStruct* result = new GraphStruct(6);

		return result;
	}
};

namespace Graph
{
	class TopologicalSort
	{
	public:
		static std::list<int> GetTopologicalSort(GraphStruct* i_graph);
	};
}

std::list<int> Graph::TopologicalSort::GetTopologicalSort(GraphStruct* i_graph)
{
	std::list<int> result;

	return result;
}