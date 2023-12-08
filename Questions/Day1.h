/*
*Something is wrong with global snow production, and you've been selected to take a look. 
For example:
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.
Consider your entire calibration document. What is the sum of all of the calibration values?

--- Part Two ---
Your calculation isn't quite right. 
It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".
Equipped with this new information, you now need to find the real first and last digit on each line. 
For example:
two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

What is the sum of all of the calibration values?
*/

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <iostream>

namespace AoC
{
    class Year2023
    {
    public:
        static int GetSumCalibrationValue_Part1(std::list<std::string> doc);
        static int GetSumCalibrationValue_Part2(std::list<std::string> doc);
    private:
        static int GetNumber(std::string word, int index);
        static int GetNumberFromBack(std::string word, int index);

    };
}

int AoC::Year2023::GetSumCalibrationValue_Part1(std::list<std::string> doc)
{
    int sum = 0;

    for (auto& it : doc)
    {
        int start = 0;
        int end = it.length() - 1;

        while (start <= end)
        {
            if (it[start] >= 48 && it[start] <= 57)
            {
                start = it[start] - '0';
                break;
            }
            start++;
        }

        while (end >= 0)
        {
            if (it[end] >= 48 && it[end] <= 57)
            {
                end = it[end] - '0';
                break;
            }
            end--;
        }
        sum += start * 10 + end;
    }
    return sum;
}


int AoC::Year2023::GetSumCalibrationValue_Part2(std::list<std::string> doc)
{
    int sum = 0;

    for (auto& it : doc)
    {
        int start = 0;
        int end = it.length() - 1;

        while (start <= end)
        {
            if (it[start] >= 48 && it[start] <= 57)
            {
                start = it[start] - '0';
                break;
            }
            else
            {
                int t = GetNumber(it, start);
                if (t != -1)
                {
                    start = t;
                    break;
                }
               
            }
            start++;
        }

        while (end >= 0)
        {
            if (it[end] >= 48 && it[end] <= 57)
            {
                end = it[end] - '0';
                break;
            }
            else 
            {
                int t = GetNumberFromBack(it, end);
                if (t != -1)
                {
                    end = t;
                    break;
                }
            }
            end--;
        }
        std::cout << "start: " << start << " end: " << end << std::endl;
        sum += start * 10 + end;
    }
    return sum;
}


int AoC::Year2023::GetNumber(std::string word, int index)
{
    std::vector<std::vector<std::string>> numbers = { { "one", "two", "six" }, {"four", "five", "nine" }, { "three", "seven", "eight" } };
    std::vector<std::vector<int>> intMap = { { 1,2,6 }, { 4,5,9 }, { 3,7,8 } };
    
    if (index + 5 < word.length())
    {
        int sz = 3;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (word.substr(index, sz) == numbers[i][j])
                {
                   // word[index] = '0' + intMap[i][j];
                   // memset(&word[index+1], 'x', 4);
                    return intMap[i][j];

                }
                    
            }
            sz++;
        }
    }
    else if (index + 4 < word.length())
    {
        int sz = 3;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (word.substr(index, sz) == numbers[i][j])
                {
                  //  word[index] =  '0'+ intMap[i][j];
                   // memset(&word[index+1], 'x', 3);
                    return intMap[i][j];
                }

            }
            sz++;
        }
    }
    else if (index + 3 < word.length())
    {
        for (int j = 0; j < 3; j++)
        {
            if (word.substr(index, 3) == numbers[0][j])
            {
              //  word[index] = '0'+ intMap[0][j];
              //  memset(&word[index+1], 'x', 2);
                return intMap[0][j];
            }
        }
    }
    return -1;
}

int AoC::Year2023::GetNumberFromBack(std::string word, int index)
{
    std::vector<std::vector<std::string>> numbers = { { "one", "two", "six" }, {"four", "five", "nine" }, { "three", "seven", "eight" } };
    std::vector<std::vector<int>> intMap = { { 1,2,6 }, { 4,5,9 }, { 3,7,8 } };

    if (index - 4 >= 0 )
    {
        int sz = 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (word.substr(index+1-sz, sz) == numbers[i][j])
                    return intMap[i][j];

            }
            sz++;
        }
    }
    else if (index - 3  >= 0)
    {
        int sz = 3;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (word.substr(index+1-sz, sz) == numbers[i][j])
                    return intMap[i][j];

            }
            sz++;
        }
    }
    else if (index - 2 >= 0)
    {
        for (int j = 0; j < 3; j++)
        {
            if (word.substr(index+1-3, 3) == numbers[0][j])
                return intMap[0][j];
        }
    }
    return -1;
}


