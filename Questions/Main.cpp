#pragma once
#include "EncodeInPlace.h"
#include "KLargestBST.h"
#include "PairEqualSum.h"
#include "LargestPairWithSum.h"
#include "TopologicalSort.h"
#include "DFS_BFS.h"

int main()
{
	//Encode "aaabbcddddd" to "a3b2cd5" in place, can only use constant extra memory.
	{
		std::string str = "aaabbcdddd";
		std::string result = StringManipulation::EncodeInPlace::Encode(str);
	}

	//Find the k largest element in a binary search tree.  
	{
		int result = Tree::KLargestBST::GetKLarget(Tree::KLargestBST::GetATree(2), 1);
	}

	//Find all pairs of an integer array whose sum is equal to a given number
	{
		int a[] = { 1,1,2,3,5,5,6,7,8,9,10,10,11,11,12,12,12,12 };	
		int sz = sizeof(a) / sizeof(int);
		std::vector<std::pair<int, int>> pairs = Array::PairEqualSum::GetAllSumPair(a, sz, 17);
	}

	//Find pair with largest number whose sume is equal to target-30
	{
		int a[] = { 20, 50, 40, 25, 30, 10 };
		int sz = sizeof(a) / sizeof(int);
		std::pair<int, int> pair = Array::LargestPairWithSum::GetLargestPair(a, sz, 90);
	}

	//Given a Directed Graph. Find any Topological Sorting of that Graph.
	{
		std::vector<int> result = Graph::TopologicalSort::GetTopologicalSort(GraphStruct::GetSampleGraph());
	}

	//DFS BFS of Graph
	{
		std::vector<int> bfs = Graph::DFS_BFS::Get_BFSOrder(GraphStruct::GetSampleGraph(), 2);
		std::vector<int> dfs = Graph::DFS_BFS::Get_DFSOrder(GraphStruct::GetSampleGraph(), 2);
	}

	//132 Pattern
	{

	}
	return 0;
}