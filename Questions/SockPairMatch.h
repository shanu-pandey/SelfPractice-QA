/*
There is a large pile of socks that must be paired by color. 
Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.

Example
n=7
ar[] = {1,2,1,2,1,2,3}
There is one pair of color 1 and one of color 2. There are three odd socks left, one of each color. The number of pairs is 2.
*/
#pragma once
#include <vector>

namespace Array
{
	class SockPairMatch
	{
		static int SockMerchant(int i_n, std::vector<int> i_array);
	};
}

int Array::SockPairMatch::SockMerchant(int i_n, std::vector<int> i_array) 
{
	int pairs = 0;
	bool found[100] = { false };
	for (auto it : i_array)
	{
		if (found[it])
		{
			pairs++;
			found[it] = false;
		}
		else
			found[it] = true;
	}

	return pairs;
}
