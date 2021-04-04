/*
An avid hiker keeps meticulous records of their hikes. 
During the last hike that took exactly 'steps' steps, for every step it was noted if it was an uphill (U), or a downhill (D) step.
Hikes always start and end at sea level, and each step up or down represents a 1 unit change in altitude. \
We define the following terms:
	A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
	A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level..

Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.

Example:

Input
8
UDDDUDUU

Output
1

Explanation
If we represent _ as sea level, a step up as /, and a step down as \, the hike can be drawn as:
_/\      _
   \    /
	\/\/
The hiker enters and leaves one valley.


*/
#pragma once
#include <string>

namespace Array
{
	class CountingValley
	{
	public:
		static int CountValley(int i_steps, std::string i_path);
	};
}

int Array::CountingValley::CountValley(int i_steps, std::string i_path)
{
	int valley = 0;
	int count = 0;
	char first = 'D';
	
	for (auto& i : i_path)
	{
		if (count == 0)
			first = i;

		if (i == 'U')					
			count++;					
		else				
			count--;
		
		if (count == 0)		
			if (first == 'D')
				valley++;
		
	}
	return valley;
}