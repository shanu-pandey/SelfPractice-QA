#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace Pathfinding
{
	class Graph
	{
		int V;
		list<pair<int, int>> *nodes;

	public:
		Graph();
		Graph(int i_v);
		void addEdge(int i_start, int i_end, int i_weight);
		void Dijkstra(int s);
	};
}

Pathfinding::Graph::Graph()
{
	this->V = -99;
	nodes = nullptr;
}
Pathfinding::Graph::Graph(int i_value)
{
	this->V = i_value;
	nodes = new list<pair<int, int>>[V];
}

void Pathfinding::Graph::addEdge(int i_start, int i_end, int i_weight)
{
	nodes[i_start].push_back(make_pair(i_end, i_weight));
	nodes[i_end].push_back(make_pair(i_start, i_weight));
}

void Pathfinding::Graph::Dijkstra(int i_start)
{

}

