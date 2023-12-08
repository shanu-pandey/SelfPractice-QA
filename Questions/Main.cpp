#include <string>
#include <list>
#include "Day1.h"
#include "Day2.h"


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
			list<string> lines;
			ReadFile("Input\\inputD2.txt", lines);
			int sum = AoC::Day2::GetSumGameIds(lines);
			int powSum = AoC::Day2::GetSumGameIds_Part2(lines);
			cout << "Sum2: " << sum << endl;
		}

		return 0;
	}

