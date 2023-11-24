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
#include <string>

namespace Array_2D
{
    class WordSearch
    {
    public:
        static bool Exist(std::vector<std::vector<char>>& board, std::string word);

    private:
        static bool WordExists(std::vector<std::vector<char>>& board, int i, int j, std::string word, int wordIndex);
    };
}

bool Array_2D::WordSearch::Exist(std::vector<std::vector<char>>& board, std::string word)
{
    int row = board.size();
    int column = board[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (board[i][j] == word[0])
            {
                if (WordExists(board, i, j, word, 1))
                    return true;
            }
        }
    }
    return false;
}

bool Array_2D::WordSearch::WordExists(std::vector<std::vector<char>>& board, int i, int j, std::string word, int wordIndex)
{
    if (wordIndex == word.length())
        return true;

    char next = word[wordIndex];
    char temp = board[i][j];
    board[i][j] = '0';

    if (i > 0 && board[i - 1][j] == next)
        WordExists(board, i - 1, j, word, wordIndex + 1);
    else if (j > 0 && board[i][j - 1] == next)
        WordExists(board, i, j - 1, word, wordIndex + 1);
    else if (i < board.size() - 1 && board[i + 1][j] == next)
        WordExists(board, i + 1, j, word, wordIndex + 1);
    else if (j < board[0].size() && board[i][j + 1] == next)
        WordExists(board, i, j + 1, word, wordIndex + 1);
    else
        return false;

    board[i][j] = temp;
    
}