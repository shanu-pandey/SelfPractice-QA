/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.
Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Example 1:
Input: [1, 2, 3, 4]
Output: False
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: [3, 1, 4, 2]
Output: True
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:
Input: [-1, 3, 2, 0]
Output: True
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/

#pragma once
#include <vector>
#include <algorithm>
#include <stack>

namespace Array
{
	class MinJumps
	{
	public:
		static int MinJumpsToEnd(int arr[], int n);
	};
}


int Array::MinJumps::MinJumpsToEnd(int arr[], int n)
{
    if (n == 1)
        return 1;

    int jumps = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + 1 + i >= n)
            return ++jumps;

        int currJumpVal = arr[i];
        int max = arr[i];
        int maxIndex = i + max;
        for (int j = i + 1; j <= currJumpVal + i; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
                maxIndex = j;
            }
        }
        jumps++;
        i = maxIndex;
    }
    return -1;
}