#pragma once
#include "EncodeInPlace.h"
#include "KLargestBST.h"


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
	return 0;
}