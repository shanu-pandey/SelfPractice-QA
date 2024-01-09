#include <string>
#include <list>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"


using namespace std;


void ReadFile(string filename, std::list<std::string>& lines)
{
	lines.clear();
	std::ifstream file(filename);
	std::string s;
	while (getline(file, s))
		lines.push_back(s);
}

int main()
	{
		//day 1
		{
			//list<string> tempInput = { "8fivenvvtrlj","eighthree", "sevenine", "twone", "3rndntwoseven", "boneight6tworgxffournine", "htbvm1grtsgdgbl" };
			//list<string> tempInput = { "two1nine", "eightwothree", "abcone2threexyz", "xtwone3four", "4nineeightseven2", "zoneight234", "7pqrstsixteen" };
			/*list<string> lines;
			ReadFile("Input\\inputD1.txt", lines);
			int sum1 = AoC::Day1::GetSumCalibrationValue_Part1(lines);
			int sum2 = AoC::Day1::GetSumCalibrationValue_Part2(lines);

			cout << "Sum2: " << sum2 << endl;*/
		}

		//day 2
		{
			/*list<string> lines;
			ReadFile("Input\\inputD2.txt", lines);
			int sum = AoC::Day2::GetSumGameIds(lines);
			int powSum = AoC::Day2::GetSumGameIds_Part2(lines);
			cout << "Sum2: " << sum << endl;*/
		}

		//day 3
		{
			vector<string> input = { "467..114..","...*......", "..35..633.", "......#...", "617*......", ".....+.58.", "..592.....", "......755.", "...$.*....", ".664.598.." };
			list<string> lines;
			ReadFile("Input\\inputD3.txt", lines);
			vector<string>ip(lines.begin(), lines.end());
			int sum = AoC::Day3::GetSum(ip);
			//int sum2 = AoC::Day1::GetSumCalibrationValue_Part2(lines);
			cout << "Sum: " << sum << endl;

		}

		return 0;
	}

