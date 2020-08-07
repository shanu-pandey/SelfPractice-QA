#pragma once
#include <vector>
#include <string>

namespace StringArray
{
	class AutoComplete
	{
	public:
		static std::vector<std::string> GetAllWord(std::vector<std::string> i_dict, std::string i_word);
	};
}

bool Contains(std::string i_src, std::string i_word)
{
	int sz = i_word.length();

	for (int i = 0; i < sz; i++)
	{
		if (i_word[i] != i_src[i])
			return false;
	}

	return true;
}

std::vector<std::string> StringArray::AutoComplete::GetAllWord(std::vector<std::string> i_dict, std::string i_word)
{
	std::vector<std::string> result;
	if (i_word.length() == 0)
		return i_dict;

	for (auto it : i_dict)
	{
		if (Contains(it, i_word))
			result.push_back(it);
	}

	return result;
}