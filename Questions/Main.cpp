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
#include "TreeFromInorderPreorder.h"
#include "PostorderFromInorderPreorder.h"
#include "AutoComplete.h"
#include "NumberOfIslands.h"
#include "BoundaryOfBinaryTree.h"
#include "StrStr.h"
#include "Power.h"
#include "CelebrityProblem.h"
#include "SockPairMatch.h"
#include "CountingValley.h"
#include "SortPlaylist.h"

long howManySwaps(std::vector<int> arr)
{
	int result = 0;
	int size = arr.size();

	if (size < 3)
	{
		if (arr[0] < arr[1])
			return 0;
		else
			return 1;
	}

	std::pair<int, int> arrayPosition[4];

	for (int i = 0; i < size; i++)
	{
		arrayPosition[i].first = arr[i];
		arrayPosition[i].second = i;
	}

	std::sort(arrayPosition, arrayPosition + size);

	std::vector<bool> bVisited(size, false);

	for (int i = 0; i < size; i++)
	{
		if (bVisited[i] || arrayPosition[i].second == i)
			continue;

		int cycle = 0;
		int j = i;
		while (!bVisited[j])
		{
			bVisited[j] = true;
			j = arrayPosition[j].second;
			cycle++;
		}

		if (cycle > 0)
			result = result + cycle - 1;
	}
	return result;
}

long storage(int n, int m, std::vector<int> h, std::vector<int> v)
{
	long result = 1;

	int hSize = h.size();
	int vSize = v.size();

	std::vector<bool>b_hVisited(n, false);
	std::vector<bool>b_vVisited(m, false);

	std::sort(h.begin(), h.begin() + hSize);
	std::sort(v.begin(), v.begin() + vSize);

	int hVol = 1;
	int vVol = 1;
	b_hVisited[h[0]] = true;
	b_vVisited[v[0]] = true;

	for (int i = 1; i < hSize; i++)
	{
		int currentVol = 1;
		if (b_hVisited[h[i] - 1])
		{
			currentVol++;
			//b_hVisited[h[i]] = true;
		}
		else
		{
			if (currentVol > hVol)
				hVol = currentVol;

			currentVol = 1;
		}
		b_hVisited[h[i]] = true;
	}

	for (int i = 1; i < vSize; i++)
	{
		int currentVol = 1;
		if (b_vVisited[v[i] - 1])
		{
			currentVol++;
			//b_hVisited[h[i]] = true;
		}
		else
		{
			if (currentVol > vVol)
				vVol = currentVol;

			currentVol = 1;
		}
		b_vVisited[v[i]] = true;
	}

	result = (hVol + 1) * (vVol + 1);
	return result;

}


int main()
{		
	//1. Encode "aaabbcddddd" to "a3b2cd5" in place, can only use constant extra memory.
	{
		std::string str = "aaabbcdddd";
		std::string result = StringManipulation::EncodeInPlace::Encode(str);
	}

	//2. Find the k largest element in a binary search tree.  
	{
		int result = Tree::KLargestBST::GetKLarget(Tree::KLargestBST::GetATree(2), 1);
	}

	//3. Find all pairs of an integer array whose sum is equal to a given number
	{
		int a[] = { 1,1,2,3,5,5,6,7,8,9,10,10,11,11,12,12,12,12 };	
		int sz = sizeof(a) / sizeof(int);
		std::vector<std::pair<int, int>> pairs = Array::PairEqualSum::GetAllSumPair(a, sz, 17);
	}

	//4. Find pair with largest number whose sume is equal to target-30
	{
		int a[] = { 20, 50, 40, 25, 30, 10 };
		int sz = sizeof(a) / sizeof(int);
		std::pair<int, int> pair = Array::LargestPairWithSum::GetLargestPair(a, sz, 90);
	}

	//5. Given a Directed Graph. Find any Topological Sorting of that Graph.
	{
		std::vector<int> result = Graph::TopologicalSort::GetTopologicalSort(GraphStruct::GetSampleGraph());
	}

	//6. DFS BFS of Graph
	{
		std::vector<int> bfs = Graph::DFS_BFS::Get_BFSOrder(GraphStruct::GetSampleGraph(), 2);
		std::vector<int> dfs = Graph::DFS_BFS::Get_DFSOrder(GraphStruct::GetSampleGraph(), 2);
	}

	//7. 132 Pattern
	{
		std::vector<int> nums = { 1,2,3,6,47,96,544 };
		bool b132Pattern = Array::Pattern132::IfExists_132(nums);
	}

	//8. Given a pattern and a string str, find if str follows the same pattern.
	{
		bool result = StringManipulation::WordPattern::IfFollowsPattern("", "dog cat dog");
	}

	//9. Given a non-empty list of words, return the k most frequent elements.
	{
		std::vector<std::string> words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is", "day" };
		std::vector<std::string> result = Array::KMostFrequentWords::TopKFrequentWords(words, 3);
	}

	//10. Battleships in a board
	{
		std::vector<std::vector<char>> board = { {'X','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'} };
		int count = Array_2D::BattleshipInBoard::CountBattleships(board);
	}

	//11. Text Justification
	{
		std::vector<std::string> words = { "ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country" };
		int maxWords = 16;
		std::vector<std::string> result = StringArray::TextJustification::FullJustify(words, maxWords);
	}

	//12. Reorder Log Files
	{
		std::vector<std::string> log = { "dig1 8 1 5 1","let1 zart can","dig2 3 6","let2 own kit dig","let3 art zero" };
		std::vector<std::string> result = StringArray::ReorderData::ReorderLogFiles(log);
	}

	//13. LRU Cache
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

	//14. Valid parentheses
	{
		bool result = Stack::ValidParentheses::IsValid("{[]}");
	}

	//15. Tree from Inorder and Preorder
	{
		std::vector<int> preorder = { 1, 2, };// 20, 15, 7 };
		std::vector<int> inorder = { 2, 1 };// 15, 20, 7};

		BinaryTree* tree = Tree::TreeFromInorderPreorder::BuildTree(preorder, inorder);
	}

	//16. Tree from Inorder and Preorder
	{
		std::vector<int> preorder = { 4, 2, 5, 1, 3, 6 };
		std::vector<int> inorder = { 1, 2, 4, 5, 3, 6 };		
		std::vector<int> postorder = Tree::PostorderFromInorderPreorder::GetPostorder(inorder, preorder);
	}

	//17. Auto Complete
	{
		std::vector<std::string> result = StringArray::AutoComplete::GetAllWord({ "abasdad", "abhsdsadas", "adfasfds", "dfsdgfsf", "ababa", "" }, "ab");
	}

	//18. Number of Islands
	{
		std::vector<std::vector<char>> island = { {'1','1','0','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
		};
		int count = Array_2D::NumberOfIslands::GetIslandCount(island);
	}

	//19. Boundary of Binary Tree
	{
		std::vector<int> boundary = Tree::BoundaryOfTree::GetBoundaryElements(BinaryTree::GetSampleTree());
	}

	//20. strstr implementation
	{
		const char* str1 = "mississippi";
		const char* str2 = "issip";

		const char* res = StringManipulation::StrStr::DoStrStr(str1, str2);
	}

	//21. Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
	{
		double res = Recursion::Power::MyPow(2.0, 10);
	}

	//22. Celebrity Problem
	{			
		Array_2D::CelebrityProblem* celebrity = new Array_2D::CelebrityProblem;
		int result = celebrity->FindCelebrity(4);
	}

	//23. Count Sock Pair Probelm
	{
		int n =7;
		std::vector<int>socks = { 1,2,1,2,1,2,3 };

		int pairs = Array::SockPairMatch::SockMerchant(n, socks);
	}

	//24. Counting Valley
	{
		int steps = 8;
		std::string path = "UDDDUDUU";

		int valley = Array::CountingValley::CountValley(steps, path);
	}

	//25. Sort Playlist
	{
		std::vector<std::vector<int>> input = { {1, 7, 3, 8}, {4, 2, 1, 6, 7, 9}, {0, 3, 9, 5} };
		Graph::SortPlaylist* p_sortPlaylist = new Graph::SortPlaylist(input);
		std::vector<int> result = p_sortPlaylist->GetSortedPlaylist(input);
	}

	return 0;
}