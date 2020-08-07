/*Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.
		An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
		You may assume all four edges of the grid are all surrounded by water.

		Input: grid = [
		  ["1","1","1","1","0"],
		  ["1","1","0","1","0"],
		  ["1","1","0","0","0"],
		  ["0","0","0","0","0"]
		]
		Output: 1

		Input: grid = [
		  ["1","1","0","0","0"],
		  ["1","1","0","0","0"],
		  ["0","0","1","0","0"],
		  ["0","0","0","1","1"]
		]
		Output: 3		
*/
#pragma once
#include <vector>

namespace Array_2D
{
	class NumberOfIslands
	{
	public:
		static int GetIslandCount(std::vector<std::vector<char>>& i_nums);
	};
}

void CountHelper(std::vector<std::vector<char>>& i_nums, int i, int j)
{
	if (i <0 || j< 0 || i >= i_nums.size() || j>= i_nums[0].size() || i_nums[i][j] != '1')
		return;
	i_nums[i][j] = 'X';

	CountHelper(i_nums, i + 1, j);
	CountHelper(i_nums, i - 1, j);
	CountHelper(i_nums, i, j+1);
	CountHelper(i_nums, i, j-1);

}
int Array_2D::NumberOfIslands::GetIslandCount(std::vector<std::vector<char>>& i_nums)
{
	if (i_nums.size() == 0)
		return 0;
	
	int count = 0;

	for (int i = 0; i < i_nums.size(); i++)
	{
		for (int j = 0; j < i_nums[0].size(); j++)
		{
			if (i_nums[i][j] == '1')
			{
				CountHelper(i_nums, i, j);
				count++;
			}
		}
	}

	return count;
}