/*
* You play several games and record the information from each game (your puzzle input). 
Each game is listed with its ID number (like the 11 in Game 11: ...) followed by a semicolon-separated list of subsets of cubes that were revealed from the bag (like 3 red, 5 green, 4 blue).

For example, the record of a few games might look like this:
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

In game 1, three sets of cubes are revealed from the bag (and then put back again). 
The first set is 3 blue cubes and 4 red cubes; the second set is 1 red cube, 2 green cubes, and 6 blue cubes; the third set is only 2 green cubes.

The Elf would first like to know which games would have been possible if the bag contained only 12 red cubes, 13 green cubes, and 14 blue cubes?

In the example above, 
Games 1, 2, and 5 would have been possible if the bag had been loaded with that configuration. 
Game 3 would have been impossible because at one point the Elf showed you 20 red cubes at once.
Game 4 would also have been impossible because the Elf showed you 15 blue cubes at once. 
If you add up the IDs of the games that would have been possible, you get 8.

Determine which games would have been possible if the bag had been loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes. 
What is the sum of the IDs of those games?

--- Part Two ---

Again consider the example games from earlier:

Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
In game 1, the game could have been played with as few as 4 red, 2 green, and 6 blue cubes. If any color had even one fewer cube, the game would have been impossible.
Game 2 could have been played with a minimum of 1 red, 3 green, and 4 blue cubes.
Game 3 must have been played with at least 20 red, 13 green, and 6 blue cubes.
Game 4 required at least 14 red, 3 green, and 15 blue cubes.
Game 5 needed no fewer than 6 red, 3 green, and 2 blue cubes in the bag.
The power of a set of cubes is equal to the numbers of red, green, and blue cubes multiplied together. The power of the minimum set of cubes in game 1 is 48. In games 2-5 it was 12, 1560, 630, and 36, respectively. Adding up these five powers produces the sum 2286.

For each game, find the minimum set of cubes that must have been present. What is the sum of the power of these sets?
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
    class Day2
    {
    public:
        static const int RED = 12;
        static const int GREEN = 13;
        static const int BLUE = 14;
        static int GetSumGameIds(std::list<std::string> input);
        static int GetSumGameIds_Part2(std::list<std::string> input);
    };
}

int AoC::Day2::GetSumGameIds(std::list<std::string> input)
{
    int sum = 0;
    for (auto it : input)
    {
        int len = it.length();
        int i = 5;
        int game = 0;
        bool bGameValid = true;
        int currColor = -1;
        int currColorCount = 0;
        int colors[3] = { 0,0,0 };            //0=red, 1=green, 2=blue
        while (i < len)
        {
            if (it[i] >= 48 && it[i] <= 57)
            {
                if (currColor == -1)
                {
                    game = game * 10 + it[i] - '0';
                }
                else
                {
                    currColorCount = currColorCount * 10 + (it[i] - '0');
                }
            }
            else if (it[i] == ':')
                currColor = 3;
            else if (it[i] == ';')
            {
                if (colors[0] > RED || colors[1] > GREEN || colors[2] > BLUE)
                {
                    bGameValid = false;
                    break;
                }
                else
                {
                    colors[0] = 0;
                    colors[1] = 0;
                    colors[2] = 0;
                }
            }
            else if (it[i] == 'r')
            {
                i += 2;
                colors[0] = currColorCount;
                currColorCount = 0;
            }
            else if (it[i] == 'g')
            {
                i += 4;
                colors[1] = currColorCount;
                currColorCount = 0;
            }
            else if (it[i] == 'b')
            {
                i += 3;
                colors[2] = currColorCount;
                currColorCount = 0;
            }
            i++;
        }
        if (bGameValid)
        {
            if (colors[0] <= RED && colors[1] <= GREEN && colors[2] <= BLUE)
            {
                std::cout << "Game: " << game << " is valid" << std::endl;
                sum += game;
            }
        }
    }

    return sum;
}


int AoC::Day2::GetSumGameIds_Part2(std::list<std::string> input)
{
    int sum = 0;
    for (auto it : input)
    {
        int len = it.length();
        int i = 5;
        int game = 0;
        bool bGameValid = true;
        int currColor = -1;
        int currColorCount = 0;
        int colors[3] = { 0,0,0 };            //0=red, 1=green, 2=blue
        while (i < len)
        {
            if (it[i] >= 48 && it[i] <= 57)
            {
                if (currColor == -1)
                {
                    game = game * 10 + it[i] - '0';
                }
                else
                {
                    currColorCount = currColorCount * 10 + (it[i] - '0');
                }
            }
            else if (it[i] == ':')
                currColor = 3;
           /* else if (it[i] == ';')
            {
                if (colors[0] > RED || colors[1] > GREEN || colors[2] > BLUE)
                {
                    bGameValid = false;
                    break;
                }
                else
                {
                    colors[0] = 0;
                    colors[1] = 0;
                    colors[2] = 0;
                }
            }*/
            else if (it[i] == 'r')
            {
                i += 2;
                colors[0] = std::max(colors[0], currColorCount);
                currColorCount = 0;
            }
            else if (it[i] == 'g')
            {
                i += 4;
                colors[1] = std::max(colors[1], currColorCount);
                currColorCount = 0;
            }
            else if (it[i] == 'b')
            {
                i += 3;
                colors[2] = std::max(colors[2], currColorCount);
                currColorCount = 0;
            }
            i++;
        }
        int pow = (colors[0] * colors[1] * colors[2]);
        std::cout << "Power: " << pow << std::endl;
        colors[0] = 0;
        colors[1] = 0;
        colors[2] = 0;
        sum += pow;
    }
    return sum;
}