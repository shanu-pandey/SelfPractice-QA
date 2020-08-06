/*
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Note:
A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.

Example 1:
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
			 because the last line must be left-justified instead of fully-justified.
			 Note that the second line is also left-justified becase it contains only one word.

Example 3:
Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
		 "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
#pragma once
#include <vector>
#include <algorithm>

namespace StringArray
{
	class TextJustification
	{
	public:
		static std::vector<std::string> FullJustify(std::vector<std::string>& i_Words, int i_MaxWidth);
	};
}

std::vector<std::string> StringArray::TextJustification::FullJustify(std::vector<std::string>& i_Words, int i_MaxWidth)
{
	std::vector<std::string> result;
	int widthRemaining = i_MaxWidth;
	std::vector<std::string> current;
	int totalLength = 0;
	for (auto it = i_Words.begin(); it != i_Words.end(); ++it)
	{					
		if ((*it).length()  <= widthRemaining && widthRemaining >= 0)
		{
			widthRemaining -= ((*it).length() + 1);
			current.push_back((*it));
			totalLength += (*it).length();
		}
		else
		{
			it--;
			if (current.size() == 1)
			{
				std::string cu = current[0];
				for (int i = 0; i < i_MaxWidth - current[0].length(); i++)
					cu += " ";
				result.push_back(cu);
				current.clear();
				totalLength = 0;
				widthRemaining = i_MaxWidth;
			}
			else
			{
				
				int remainingLength = i_MaxWidth - totalLength;
				int positionForSpace = (current.size() - 1);
				std::vector<std::string> currentSpace(positionForSpace, "");
				while (remainingLength != 0)
				{
					for (int i = 0; i < positionForSpace; i++)
					{
						currentSpace[i] += " ";
						remainingLength--;
						if (remainingLength == 0)
							break;
					}
				}
				std::string cu = "";
				for (int i = 0; i < current.size() -1; i++)
				{
					cu += current[i];
					cu += currentSpace[i];
				}
				cu += current[current.size() - 1];
				result.push_back(cu);
				current.clear();
				totalLength = 0;
				widthRemaining = i_MaxWidth;
			}
		}	
	}

	int lengthRemiining = i_MaxWidth;
	std::string cu = "";
	for (auto it : current)
	{
		cu += it;
		lengthRemiining -= it.length();
		if (lengthRemiining > 0)
		{
			cu += " ";
			lengthRemiining--;
		}
	}

	for (int i = 0; i < lengthRemiining; i++)
		cu += " ";

	result.push_back(cu);
	return result;
}