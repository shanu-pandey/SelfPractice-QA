/*
Given an m x n matrix, return true if the matrix is Toeplitz.Otherwise, return false.
A matrix is Toeplitz if every diagonal from top - left to bottom - right has the same elements.

Example 1:
Input: matrix = [[1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2]]
Output : true
Explanation :
    In the above grid, the diagonals are :
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2 :

Input : matrix = [[1, 2], [2, 2]]
Output : false
Explanation :
   The diagonal "[1, 2]" has different elements.

Constraints :
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 20
    0 <= matrix[i][j] <= 99
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>

namespace Array_2D
{
    class GameOfLife
    {
    public:
        static void GameOfLIfeInPlace(std::vector<std::vector<int>>& matrix);

    private:
        static bool IsInBounds(std::vector<std::vector<int>>& board, int rowOffset, int collOffset);
        static int GetNeighbors(std::vector<std::vector<int>>& board, int row, int column);
    };
}

bool Array_2D::GameOfLife::IsInBounds(std::vector<std::vector<int>>& board, int rowOffset, int collOffset)
{
    int row = board.size();
    int col = board[0].size();

    if (rowOffset >= 0 && rowOffset < row && collOffset >= 0 && collOffset < col)
        return true;

    return false;
}

int Array_2D::GameOfLife::GetNeighbors(std::vector<std::vector<int>>& board, int row, int column)
{
    std::vector<std::vector<int>> neighbors = { {0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,1}, {1,-1}, {-1,-1} };
    int liveNeighbors = 0;

    for (auto& it : neighbors)
    {
        int rowOffset = row + it[0];
        int collOffset = column + it[1];
        if (IsInBounds(board, rowOffset, collOffset))
        {
            if (board[rowOffset][collOffset] == 1 || board[rowOffset][collOffset] == 3)
                liveNeighbors++;
        }
    }
    return liveNeighbors;
}

void Array_2D::GameOfLife::GameOfLIfeInPlace(std::vector<std::vector<int>>& board)
{
    int row = board.size();
    int column = board[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int neighbours = GetNeighbors(board, i, j);
            if (board[i][j] == 1 && (neighbours < 2 || neighbours > 3))
                board[i][j] = 3;
            else if (board[i][j] == 0 && neighbours == 3)
                board[i][j] = 2;
        }
    }


    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (board[i][j] == 2)
                board[i][j] = 1;
            else if (board[i][j] == 3)
                board[i][j] = 0;
        }
    }
}

