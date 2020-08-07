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


BinaryTree* BuildTreeHelper( int i_InStart, int i_InEnd, std::vector<int>& i_Preorder, std::vector<int>& i_Inorder)
{
	static int preStart = 0;
	if (preStart > i_Preorder.size() - 1 || i_InStart > i_InEnd)
		return nullptr;

	BinaryTree* root = new BinaryTree(i_Preorder[preStart]);
	preStart++;

	if (i_InStart == i_InEnd)
		return root;

	int newRoot = 0;
	for (int i = i_InStart; i <= i_InEnd; i++)
	{
		if (i_Inorder[i] == root->data)
			newRoot = i;
	}

	root->m_left = BuildTreeHelper(i_InStart, newRoot - 1, i_Preorder, i_Inorder);
	root->m_right = BuildTreeHelper(newRoot+1, i_InEnd, i_Preorder, i_Inorder);

	return root;
}

BinaryTree* Tree::TreeFromInorderPreorder::BuildTree(std::vector<int>& i_Preorder, std::vector<int>& i_Inorder)
{
	if (i_Preorder.size() == 1)
		return new BinaryTree(i_Preorder[0]);

	BinaryTree* root = BuildTreeHelper(0, i_Inorder.size() - 1, i_Preorder, i_Inorder);
	return root;
}