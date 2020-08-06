/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

Example:
X..X
...X
...X
In the above board there are 2 battleships.

Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
*/
#pragma once
#include <vector>

namespace Array_2D
{
	class BattleshipInBoard
	{
	public:
		static int CountBattleships(std::vector<std::vector<char>>& i_Board);
	};
}

void BattleshipHelper(std::vector<std::vector<char>>& i_Board, int i, int j, int i_Row, int i_Column)
{
	if (i >= i_Row || j >= i_Column || i < 0 || j < 0 || i_Board[i][j] != 'X')
		return;

	i_Board[i][j] = 'V';

	BattleshipHelper(i_Board, i - 1, j, i_Row, i_Column);
	BattleshipHelper(i_Board, i + 1, j, i_Row, i_Column);
	BattleshipHelper(i_Board, i, j - 1, i_Row, i_Column);
	BattleshipHelper(i_Board, i, j + 1, i_Row, i_Column);
}

int Array_2D::BattleshipInBoard::CountBattleships(std::vector<std::vector<char>>& i_Board)
{
	int result = 0;
	if (i_Board.size() == 0)
		return 0;

	int row = i_Board.size();
	int col = i_Board[0].size();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j!= col; j++)
		{
			if (i_Board[i][j] == 'X')
			{
				BattleshipHelper(i_Board, i, j, row, col);
				result++;
			}
		}
	}
	return result;
}