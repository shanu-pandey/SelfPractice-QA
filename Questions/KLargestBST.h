//Find the k largest element in a binary search tree.  

#pragma once
#include <vector>
#include <iostream>

struct BinaryTree
{
	int data;
	BinaryTree* m_left;
	BinaryTree* m_right;

	BinaryTree() : data(0), m_left(nullptr), m_right(nullptr)
	{}

	BinaryTree(int i_data): data(i_data), m_left(nullptr), m_right(nullptr)
	{}
};

namespace Tree
{
	class KLargestBST
	{
	public:
		static int GetKLarget(BinaryTree* i_root, int i_k);
		static BinaryTree* GetATree(int i_rootValue);
	};
}

void InOrder(BinaryTree* i_root, std::vector<int>& i_map)
{
	//left root right
	if (i_root == nullptr)
		return;

	InOrder(i_root->m_left, i_map);
	i_map.push_back(i_root->data);
	InOrder(i_root->m_right, i_map);
}
BinaryTree* Tree::KLargestBST::GetATree(int i_rootValue)
{
	BinaryTree* root = new BinaryTree(i_rootValue);		//2
	root->m_left = new BinaryTree(i_rootValue - 1);		//1

	root->m_right = new BinaryTree(i_rootValue + 3);	//5	
	root->m_right->m_left = new BinaryTree(i_rootValue + 1);	//3
	root->m_right->m_left->m_right = new BinaryTree(i_rootValue + 2);	//4
	
	root->m_right->m_right = new BinaryTree(i_rootValue + 5);			//7
	root->m_right->m_right->m_left = new BinaryTree(i_rootValue + 4);	//6
	root->m_right->m_right->m_right = new BinaryTree(i_rootValue + 9);	//11

	root->m_right->m_right->m_right->m_left = new BinaryTree(i_rootValue + 7);	//9
	root->m_right->m_right->m_right->m_left->m_left = new BinaryTree(i_rootValue + 6);	//6
	root->m_right->m_right->m_right->m_left->m_right = new BinaryTree(i_rootValue + 8);	//6

	root->m_right->m_right->m_right->m_right = new BinaryTree(i_rootValue + 10);	//12
	root->m_right->m_right->m_right->m_right->m_right = new BinaryTree(i_rootValue + 12);	//14
	root->m_right->m_right->m_right->m_right->m_right->m_left = new BinaryTree(i_rootValue + 11);	//13

	return root;

}
int Tree::KLargestBST::GetKLarget(BinaryTree* i_root, int i_k)
{
	int klargest = -1;
	std::vector<int> nodeMap;
	InOrder(i_root, nodeMap);
	int total = nodeMap.size();
	if (i_k > total)
		return klargest;

	klargest = nodeMap[total - i_k];
	return klargest;
}

