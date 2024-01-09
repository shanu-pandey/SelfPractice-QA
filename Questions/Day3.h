/*
The engine schematic (your puzzle input) consists of a visual representation of the engine. There are lots of numbers and symbols you don't really understand, but apparently any number adjacent to a symbol, even diagonally, is a "part number" and should be included in your sum. (Periods (.) do not count as a symbol.)

Here is an example engine schematic:

467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
In this schematic, two numbers are not part numbers because they are not adjacent to a symbol: 114 (top right) and 58 (middle right). Every other number is adjacent to a symbol and so is a part number; their sum is 4361.

Of course, the actual engine schematic is much larger. What is the sum of all of the part numbers in the engine schematic?

--- Part Two ---
The missing part wasn't the only issue - one of the gears in the engine is wrong. A gear is any * symbol that is adjacent to exactly two part numbers. 
Its gear ratio is the result of multiplying those two numbers together.
This time, you need to find the gear ratio of every gear and add them all up so that the engineer can figure out which gear needs to be replaced.

Consider the same engine schematic again:

467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
In this schematic, there are two gears. The first is in the top left; it has part numbers 467 and 35, so its gear ratio is 16345. 
The second gear is in the lower right; its gear ratio is 451490. 
(The * adjacent to 617 is not a gear because it is only adjacent to one part number.) Adding up all of the gear ratios produces 467835.

What is the sum of all of the gear ratios in your engine schematic?

*/

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <iostream>
#include <map>


namespace AoC
{
    class Day3
    {
    public:
        static int GetSum(std::vector<std::string> input);
        static int GetSum_Part2(std::vector<std::string> input);
    private:
        static int AoC::Day3::GetNeighborCount(std::vector<std::string> input, int it, int i, int itSize, int size);
        static int  AoC::Day3::GetFullNum(std::string line, int index);
        static bool isValidNumber(int num, std::vector<std::string> input, int it, int i, int len, bool isLast);
        static int GetGearRatio(std::vector<std::string> input, int it, int i);
    };
}

bool isValid(int it, int itIndex, int i, int index, int itSize, int size)
{
    if (it + itIndex < 0 || it + itIndex > itSize)
        return false;

    if (i + index < 0 || i + index > size)
        return false;
}

int AoC::Day3::GetNeighborCount(std::vector<std::string> input, int it, int i, int itSize, int size)
{
    std::vector<int> neighbors = { -1, 0, 1 };
    int count = 0;

    for (auto neighbor : neighbors)
    {
        int line = neighbor;
        bool wordFound = false;
        for (auto word : neighbors)
        {
            if (isValid(it, line, i, word, itSize, size))
            {
                if (input[it + line][i + word] >= 48 && input[it + line][i + word] <= 57 && !wordFound)
                {
                    count++;
                    wordFound = true;
                }
                else
                    wordFound = false;
            }
        }
    }

    return count;
}


int  AoC::Day3::GetGearRatio(std::vector<std::string> input, int it, int i)
{
    int sum = 0;
    int count = 0;
    return sum;
}

int  AoC::Day3::GetFullNum(std::string input, int index)
{
    int sum = 0;

    return sum;
}


bool  AoC::Day3::isValidNumber(int num, std::vector<std::string> input, int it, int i, int len, bool isLast)
{
    bool res = false;

    if (it == 0)
    {
        std::string adjacent = input[1];
        len += 2;
        if (isLast)
            len -= 1;
        while (len > 0 && i>0)
        {
            if ((adjacent[i] != '.') &&
                (adjacent[i] < 48 || adjacent[i] > 57))
            {
                return true;
            }
            i--;
            len--;
        }
    }
    else if (it == input.size()-1)
    {
        std::string adjacent = input[it-1];
        len += 2;
        while (len > 0 && i > 0)
        {
            if ((adjacent[i] != '.') &&
                (adjacent[i] < 48 || adjacent[i] > 57))
            {
                return true;
            }
            i--;
            len--;
        }
    }
    else
    {
        std::string adjacent1 = input[it - 1];
        std::string adjacent2 = input[it + 1];
        len += 2;
        while (len > 0 && i > 0)
        {
            if ((adjacent1[i] != '.') &&
                (adjacent1[i] < 48 || adjacent1[i] > 57))
            {
                return true;
            }

            if ((adjacent2[i] != '.') &&
                (adjacent2[i] < 48 || adjacent2[i] > 57))
            {
                return true;
            }
            i--;
            len--;
        }
    }

    return res;

}

int AoC::Day3::GetSum(std::vector<std::string> input)
{
    int sum = 0;
    int sz = input.size();

    for (int it =0; it< sz; it++)
    {
        int currSize = input[it].length();
        bool bInc = false;
        int currNum = 0;
        int currNumLen = 0;
        for (int i = 0; i < currSize; i++)
        {
            if (input[it][i] >= 48 && input[it][i] <= 57)
            {
                currNum = currNum * 10 + input[it][i] - '0';
                currNumLen++;
            }
            else if (input[it][i] == '.')
            {
                if (currNum > 0)
                {
                    if (bInc)
                    {
                        sum += currNum;
                    }
                    else if (isValidNumber(currNum, input, it, i, currNumLen, false))
                    {
                        sum += currNum;
                    }
                }
                /*if (bInc)
                {
                    sum += currNum;
                }
                else if (currNum > 0)
                {
                    if (isValidNumber(currNum, input, it, i, currNumLen))
                    {
                        sum += currNum;
                    }
                }*/
                currNum = 0;
                currNumLen = 0;
                bInc = false;
            }
            else
            {
                if (currNum > 0)
                {
                    sum += currNum;
                    currNum = 0;
                    currNumLen = 0;
                }
                bInc = true;
            }
        }
        if (currNum > 0)
        {
            if (bInc)
            {
                sum += currNum;
            }
            else if (isValidNumber(currNum, input, it, currSize-1, currNumLen, true))
            {
                sum += currNum;
            }
        }
    }

    return sum;
}

int AoC::Day3::GetSum_Part2(std::vector<std::string> input)
{
    int sum = 0;
    int sz = input.size();

    for (int it = 0; it < sz; it++)
    {
        int currSize = input[it].length();
        bool bInc = false;
        int currNum = 0;
        int currNumLen = 0;
        for (int i = 0; i < currSize; i++)
        {
            if (input[it][i] == '*')
            {
                sum += GetGearRatio(input, it, i);
            }
        }
    }

    return sum;
}