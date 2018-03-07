#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <functional>
using namespace std;

namespace Pathfinding
{
	class Graph
	{
		int vertices;
		list<pair<int, int>> *p_AdjacentVertices;

	public:
		Graph();
		Graph(int i_v);
		void addEdge(int i_start, int i_end, int i_weight);
		void Dijkstra(int s);
	};
}

Pathfinding::Graph::Graph()
{
	this->vertices = -9999;
	p_AdjacentVertices = nullptr;
}

Pathfinding::Graph::Graph(int i_totalVertices)
{
	this->vertices = i_totalVertices;
	p_AdjacentVertices = new list<pair<int, int>>[vertices];
}

void Pathfinding::Graph::addEdge(int i_start, int i_end, int i_weight)
{
	p_AdjacentVertices[i_start].push_back(make_pair(i_end, i_weight));
	p_AdjacentVertices[i_end].push_back(make_pair(i_start, i_weight));
}

void Pathfinding::Graph::Dijkstra(int i_start)
{
	/*
	1. Create a priority queue acting as Min Heap (priority_queue(<type, vector<type, comparison<type>))
	2. Create a vector for distance of each node, initialize its value max
	3. Push start to priority queue with its distance as 0.
	4. Get the first element from priority queue and iterate through all its adjacent vertices and update the distance if not shortest path
	5. Repeat previous step until priority queue is empty or all distance have been set
	*/
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQueue;
	vector<int> distance(vertices, 99999);

	distance[i_start] = 0;
	myQueue.push(make_pair(i_start, 0));

	while (!myQueue.empty())
	{
		int x = myQueue.top().second;
		myQueue.pop();

		list<pair<int, int>>::iterator i;
		for (i = p_AdjacentVertices[x].begin(); i != p_AdjacentVertices[x].end(); ++i)
		{
			int vertex = i->first;
			int weight = i->second;

			if (distance[vertex] > distance[x] + weight)
			{
				distance[vertex] = distance[x] + weight;
				myQueue.push(make_pair(distance[vertex], vertex));
			}
		}
	}

	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < vertices; ++i)
		printf("%d \t\t %d\n", i, distance[i]);
}

int main()
{
	int vertices = 9;
	Pathfinding::Graph g(vertices);

	//  making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.Dijkstra(0);

	return 0;
}

