//Find all pairs of an integer array whose sum is equal to a given number

#pragma once
#include <vector>

namespace Array
{
	class PairEqualSum
	{
	public:
		static std::vector<std::pair<int, int>> GetAllSumPair(int i_numbers[], int i_size, int i_sum);
	};
}

std::vector<std::pair<int, int>> Array::PairEqualSum::GetAllSumPair(int* i_numbers, int i_size, int i_sum)
{
	std::vector<std::pair<int, int>> result;

	for (int i = 0; i < i_size-1; i++)
	{
		for (int j = i + 1; j < i_size; j++)
		{
			if (i_numbers[i] + i_numbers[j] == i_sum)
				result.push_back(std::make_pair(i_numbers[i], i_numbers[j]));
		}
	}
	return result;
}