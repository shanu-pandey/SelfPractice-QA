#pragma once
#include "EncodeInPlace.h"
#include "KLargestBST.h"
#include "PairEqualSum.h"


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
		std::vector<std::pair<int, int>> pairs = Array::PairEqualSum::GetAllSumPair(a, 17);
	}
	return 0;
}