/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.


Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Example 3:
Input: matrix = [[1]]
Output: [[1]]

Example 4:
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]

Constraints:
matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/
#pragma once
#include <vector>
#include <algorithm>

namespace Array_2D
{
	class RotateMatrix
	{
	public:
		static void RotateClockwise(std::vector<std::vector<int>>& i_Board);
		static void RotateCounterClockwise(std::vector<std::vector<int>>& i_Board);
		static void Print(std::vector<std::vector<int>>& i_Board);
	};
}

void Array_2D::RotateMatrix::Print(std::vector<std::vector<int>>& i_Board)
{
	int sz = i_Board.size();

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			std::cout << i_Board[i][j] << " "; 
		}
		std::cout << std::endl;
	}
}


void Array_2D::RotateMatrix::RotateClockwise(std::vector<std::vector<int>>& i_Board)
{
	int sz = i_Board.size();

	//Transpose
	for (int i = 0; i < sz ; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::swap(i_Board[i][j], i_Board[j][i]);
		}
	}

	//swap columns
	for (int i = 0; i < sz ; i++)
	{
		for (int j = 0; j < sz/2; j++)
		{
			std::swap(i_Board[i][j], i_Board[i][sz - j - 1]);
		}
	}
}



void Array_2D::RotateMatrix::RotateCounterClockwise(std::vector<std::vector<int>>& i_Board)
{
	int sz = i_Board.size();

	//Transpose
	for (int i = 0; i < sz ; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::swap(i_Board[i][j], i_Board[j][i]);
		}
	}

	//swap rows
	for (int i = 0; i < sz ; i++)
	{
		for (int j = 0; j < sz/2; j++)
		{
			std::swap(i_Board[i][j], i_Board[sz - i - 1][j]);
		}
	}
}