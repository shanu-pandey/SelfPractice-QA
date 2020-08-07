/*
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. 
The boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)
*/
#pragma once
#include <vector>
#include "DataStructures.h"

namespace Tree
{
	class BoundaryOfTree
	{
	public:
		static std::vector<int> GetBoundaryElements(BinaryTree* i_root);
	};
}


void BoundaryLeft(BinaryTree* i_node, std::vector<int>& i_boundary)
{
	if (i_node == nullptr)
		return;

	if (i_node->m_left != nullptr)
	{
		i_boundary.push_back(i_node->data);
		BoundaryLeft(i_node->m_left, i_boundary);
	}
	else if (i_node->m_right != nullptr)
	{
		i_boundary.push_back(i_node->data);
		BoundaryLeft(i_node->m_right, i_boundary);
	}
}

void BoundaryRight(BinaryTree* i_node, std::vector<int>& i_boundary)
{
	if (i_node == nullptr)
		return;

	if (i_node->m_right != nullptr)
	{
		BoundaryRight(i_node->m_right, i_boundary);
		i_boundary.push_back(i_node->data);		
	}
	else if (i_node->m_left != nullptr)
	{
		BoundaryRight(i_node->m_left, i_boundary);
		i_boundary.push_back(i_node->data);		
	}
}

void BoundaryLeaves(BinaryTree* i_node, std::vector<int>& i_boundary)
{
	if (i_node == nullptr)
		return;

	BoundaryLeaves(i_node->m_left, i_boundary);
	if (i_node->m_left == nullptr && i_node->m_right == nullptr)
	{
		i_boundary.push_back(i_node->data);
	}
	BoundaryLeaves(i_node->m_right, i_boundary);
	
}

std::vector<int> Tree::BoundaryOfTree::GetBoundaryElements(BinaryTree* i_root)
{
	std::vector<int> boundary;
	if (i_root == nullptr)
		return boundary;

	boundary.push_back(i_root->data);

	BoundaryLeft(i_root->m_left, boundary);
	BoundaryLeaves(i_root->m_left, boundary);
	BoundaryLeaves(i_root->m_right, boundary);
	BoundaryRight(i_root->m_right, boundary);

	return boundary;
}