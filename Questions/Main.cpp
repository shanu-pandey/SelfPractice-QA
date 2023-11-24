#pragma once
#include <iostream>
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
#include "StringReverseInPlace.h"
#include "DuplicateCharacterInString.h"
#include "AnagramStrings.h"
#include "BalancedStringSplit.h"
#include "StringSwapMakeEqual.h"
#include "ShuffleString.h"
#include "ReverseLinkedListInPlace.h"
#include "RemoveZeroSumConsecutiveNode.h"
#include "LinkedListCycle.h"
#include "RotateMatrix.h"
#include "MinJumps.h"
#include "ToeplitzMatrix.h"
#include "GameOfLife.h"
#include "WiggleSort.h"
#include "WordSearch.h"

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

	//26. Reverse String in Place
	{
		std::string str = "reversethis";
		StringManipulation::ReverseInPLace::ReverseInPlace(str);
		StringManipulation::ReverseInPLace::ReverseInPlace(str);
	}

	//26. Duplicate character in String with Count
	{
		std::string str = "what is the duplicate count";
		std::map<char, int> result = StringManipulation::DuplicateCharacterInString::DuplicateWithCount(str);
	}

	//26. Anagram Strings
	{
		std::string str1 = "asda";
		std::string str2 = "asds";
		bool result = StringManipulation::AnagramString::IfAnagram(str1, str2);
	}

	//27. Balanced String Split
	{
		std::string str = "RLLLLRRRLR";
		int result = StringManipulation::BalancedStringSplit::SplitBalancedString(str);
	}

	//28. Single Swap to Make String Equal
	{
		std::string str1 = "bank";
		std::string str2 = "knab";
		bool result = StringManipulation::StringSwapMakeEqual::AreAlmostEqual(str1, str2);
	}

	//29. Shuffle String
	{
		std::string str1 = "codeleet";
		std::vector<int> indices = { 4,5,6,7,0,2,1,3 };
		std::string result = StringManipulation::ShuffleString::RestoreString(str1, indices);
	}

	//30. Reverse Linked List in Place
	{
		Node* n1 = new Node(1);
		Node* n2 = new Node(2);
		Node* n3 = new Node(3);
		Node* n4 = new Node(4);
		Node* n5 = new Node(5);
		n1->m_pNext = n2;
		n2->m_pNext = n3;
		n3->m_pNext = n4;
		n4->m_pNext = n5;		

		DS_LinkedList::ReverseLinkedListInPlace::ReverseInPlace(n1);	
	}

	//31. Remove Zero Sum Consecutive Nodes
	{
		Node* n1 = new Node(1);
		Node* n2 = new Node(2);
		Node* n3 = new Node(3);
		Node* n4 = new Node(-3);
		Node* n5 = new Node(5);
		n1->m_pNext = n2;
		n2->m_pNext = n3;
		n3->m_pNext = n4;
		n4->m_pNext = n5;

		Node* result = DS_LinkedList::RemoveZeroSumConsecutiveNode::RemoveZeroSumSublists(n1);
	}

	//32. Linked List Cycle
	{
		Node* n1 = new Node(3);
		Node* n2 = new Node(2);
		Node* n3 = new Node(0);
		Node* n4 = new Node(-4);		
		n1->m_pNext = n2;
		n2->m_pNext = n3;
		n3->m_pNext = n4;
		n4->m_pNext = n2;

		Node* result = DS_LinkedList::LinkedListCycle::DetectCycle(n1);
	}

	//33. Rotate Matrix
	{
		std::vector<std::vector<int>> board = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
		std::cout << "-----------Original----------------" << std::endl;
		Array_2D::RotateMatrix::Print(board);

		std::cout << "-----------Clockwise----------------" << std::endl;
		Array_2D::RotateMatrix::RotateClockwise(board);
		Array_2D::RotateMatrix::Print(board);

		board = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };


		std::cout << "-----------Counter Clockwise----------------" << std::endl;
		Array_2D::RotateMatrix::RotateCounterClockwise(board);
		Array_2D::RotateMatrix::Print(board);
	}

	//33. Min Jumps
	{
		int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
		int n = 11;
		int result = Array::MinJumps::MinJumpsToEnd(arr, n);

	}

	//33. Toeplitz Matrix
	{
		std::vector<std::vector<int>> matrix = { {11,74,7,93},{40,11,74,7} };
		int n = 11;
		int result = Array_2D::ToeplitzMatrix::IsToeplitzMatrix(matrix);

	}

	//33. Game of Life
	{
		std::vector<std::vector<int>> matrix = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
		Array_2D::GameOfLife::GameOfLIfeInPlace(matrix);
	}

	//33. Wiggle Sort
	{
		/*std::vector<int> arr = { 1, 3, 2, 2, 3, 1 };
		Array::WiggleSort::DoWiggleSort(arr);*/
	}
	
	
	//33. Word Existst
	{
		std::vector<std::vector<char>> board = {{ 'A','B','C','E' }, { 'S','F','C','S' }, { 'A','D','E','E' } };
		bool result = Array_2D::WordSearch::Exist(board, "ABCCED");
	}
	

	return 0;
}