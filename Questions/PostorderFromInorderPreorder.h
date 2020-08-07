/*
Given Inorder and Preorder traversals of a binary tree, print Postorder traversal.

Example:
Input:
Inorder in[] = {4, 2, 5, 1, 3, 6}
Preorder pre[] = {1, 2, 4, 5, 3, 6}

Output:
Postorder = {4, 5, 2, 6, 3, 1}
Trversals in the above example represents following tree
		 1
	  /    \
	 2       3
   /   \      \
  4     5      6
*/

#pragma once
#include <vector>
#include "DataStructures.h"

namespace Tree
{
	class PostorderFromInorderPreorder
	{
	public:
		static std::vector<int> GetPostorder(std::vector<int>& i_Inorder, std::vector<int>& i_Preorder);
	};
}

int GetRoot(int* i_Inorder, int i_val, int i_sz)
{
	for (int i = 0; i < i_sz; i++)
	{
		if (i_Inorder[i] == i_val)
			return i;
	}
	return -1;
}

void PostorderHelper(int i_InStart, int i_InEnd, std::vector<int>& i_Inorder, std::vector<int>& i_Preorder, std::vector<int>& i_Postorder)
{
	
}

std::vector<int> Tree::PostorderFromInorderPreorder::GetPostorder(std::vector<int>& i_Inorder, std::vector<int>& i_Preorder)
{	
	if (i_Preorder.size() == 1)	
		return i_Preorder;

	std::vector<int> postorder;
			
	PostorderHelper(0, i_Inorder.size()-1, i_Inorder, i_Preorder, postorder);
	return postorder;
}