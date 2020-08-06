/*
You have an array of logs.  Each log is a space delimited string of words.
For each log, the first word in each log is an alphanumeric identifier.  Then, either:
Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.
Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.
Return the final order of the logs.

Example 1:
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
*/
#pragma once
#include <vector>
#include <algorithm>

namespace StringArray
{
	class ReorderData 
	{
	public:
		static std::vector<std::string> ReorderLogFiles(std::vector<std::string>& i_Logs);
	};
}

std::vector<std::string> StringArray::ReorderData::ReorderLogFiles(std::vector<std::string>& i_Logs)
{
	std::vector<std::string> result;
	std::vector<std::string> temp_numbers;
	std::vector<std::string> temp_words;
	int sz = i_Logs.size();

	if (sz < 2)
		return i_Logs;

	for (auto& it : i_Logs)
	{
		for (int i = 0; i < it.length(); i++)
		{
			if (it[i] == ' ')
			{
				if (it[i + 1] < '0' || it[i + 1] > '9')
				{
					if (temp_words.size() == 0)
						temp_words.push_back(it);
					else
					{
						auto base = it;
						auto s_base = it.find(" ");
						auto sub_base = it.substr(s_base + 1);

						for (int x = 0; x < temp_words.size(); x++)
						{
							auto s_str1 = temp_words[x].find(" ");
							auto sub_str1 = temp_words[x].substr(s_str1+1);	

							if (sub_str1 == sub_base)
							{
								if (temp_words[i].substr(0, s_str1) > base.substr(0, s_base))
								{
									auto temp = temp_words[x];
									temp_words[x] = base;
									sub_base = sub_str1;
									base = temp;
									s_base = s_str1;
								}
							}
							else if (sub_str1 > sub_base)
							{
								auto temp = temp_words[x];
								temp_words[x] = base;
								sub_base = sub_str1;
								base = temp;
							}
						}
						temp_words.push_back(base);
					}
					
				}
				else				
					temp_numbers.push_back(it);

				break;
			}
		}
	}

	for (auto it : temp_words)
		result.push_back(it);

	for (auto it : temp_numbers)
		result.push_back(it);

	return result;
}