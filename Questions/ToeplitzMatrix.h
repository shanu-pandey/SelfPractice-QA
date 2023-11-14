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
    class ToeplitzMatrix
    {
    public:
        static bool IsToeplitzMatrix(std::vector<std::vector<int>>& matrix);
    };
}


bool Array_2D::ToeplitzMatrix::IsToeplitzMatrix(std::vector<std::vector<int>>& matrix)
{
    int column = matrix[0].size();
    int row = matrix.size();

    //Row Decrement

    for (int i = row - 2; i >= 0; i--)
    {
        int currVal = matrix[i][0];
        int r = i + 1;
        for (int j = 1; (j < column && r < row); j++)
        {
            if (matrix[r][j] != currVal)
                return false;

            r++;
        }
    }

    //Column Increament

    for (int i = column - 2; i > 0; i--)
    {
        int currVal = matrix[0][i];
        int c = i + 1;
        for (int j = 1; (j < row && c < column); j++)
        {
            if (matrix[j][c] != currVal)
                return false;

            c++;
        }
    }
    return true;
}