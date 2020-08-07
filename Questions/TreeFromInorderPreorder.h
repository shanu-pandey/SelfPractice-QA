/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

	3
   / \
  9  20
	/  \
   15   7
*/
#pragma once
#include <vector>
#include "DataStructures.h"

namespace Tree
{
	class TreeFromInorderPreorder
	{
	public:
		static BinaryTree* BuildTree(std::vector<int>& i_Preorder, std::vector<int>& i_Inorder);
	};
}


BinaryTree* Tree::TreeFromInorderPreorder::BuildTree(std::vector<int>& i_Preorder, std::vector<int>& i_Inorder)
{
	BinaryTree* root = new BinaryTree(0);
	return root;
}