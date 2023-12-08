#include <string>
#include <list>
#include "Day1.h"


using namespace std;

int main()
	{
	//day 1
		{
			list<string> tempInput = { "8fivenvvtrlj","eighthree", "sevenine", "twone", "3rndntwoseven", "boneight6tworgxffournine", "htbvm1grtsgdgbl" };
			//list<string> tempInput = { "two1nine", "eightwothree", "abcone2threexyz", "xtwone3four", "4nineeightseven2", "zoneight234", "7pqrstsixteen" };
			list<string> lines;
			AoC::Year2023::ReadFile(lines);
			int sum1 = AoC::Year2023::GetSumCalibrationValue_Part1(lines);
			int sum2 = AoC::Year2023::GetSumCalibrationValue_Part2(lines);

			cout << "Sum2: " << sum2 << endl;
		}

		return 0;
	}

