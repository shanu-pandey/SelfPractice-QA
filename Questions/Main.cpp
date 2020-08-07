#pragma once
#include "EncodeInPlace.h"
#include "KLargestBST.h"
#include "PairEqualSum.h"
#include "LargestPairWithSum.h"
#include "TopologicalSort.h"
#include "DFS_BFS.h"
#include "132Pattern.h"
#include "WordPattern.h"
#include "KMostFrequentWords.h"
#include "BattleshipsInABoard.h"
#include "TextJustification.h"
#include "ReorderData.h"
#include "MRUCache.h"
#include "LRUCache.h"
#include "ValidParentheses.h"

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
		std::vector<int> nums = { 1,2,3,6,47,96,544 };
		bool b132Pattern = Array::Pattern132::IfExists_132(nums);
	}

	//Given a pattern and a string str, find if str follows the same pattern.
	{
		bool result = StringManipulation::WordPattern::IfFollowsPattern("", "dog cat dog");
	}

	//Given a non-empty list of words, return the k most frequent elements.
	{
		std::vector<std::string> words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is", "day" };
		std::vector<std::string> result = Array::KMostFrequentWords::TopKFrequentWords(words, 3);
	}

	//Battleships in a board
	{
		std::vector<std::vector<char>> board = { {'X','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'} };
		int count = Array_2D::BattleshipInBoard::CountBattleships(board);
	}

	//Text Justification
	{
		std::vector<std::string> words = { "ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country" };
		int maxWords = 16;
		std::vector<std::string> result = StringArray::TextJustification::FullJustify(words, maxWords);
	}

	//Reorder Log Files
	{
		std::vector<std::string> log = { "dig1 8 1 5 1","let1 zart can","dig2 3 6","let2 own kit dig","let3 art zero" };
		std::vector<std::string> result = StringArray::ReorderData::ReorderLogFiles(log);
	}

	//LRU Cache
	{
		Cache::LRUCache ca(4);
		ca.Refer(1);
		ca.Refer(2);
		ca.Refer(3);
		ca.Refer(1);
		ca.Refer(4);
		ca.Refer(1);
		ca.PrintCache();
	}

	//Valid parentheses
	{
		bool result = Stack::ValidParentheses::IsValid("{[]}");
	}
	return 0;
}