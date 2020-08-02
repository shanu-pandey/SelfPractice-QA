/*
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
	Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
	with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

namespace Array
{
	class KMostFrequentWords
	{
	public:
		static std::vector<std::string> TopKFrequentWords(std::vector<std::string>& i_words, int i_k);
	};
}
\
static bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b)
{
	return a.second > b.second || (a.second == b.second && a.first < b.first);
}

std::vector<std::string> Array::KMostFrequentWords::TopKFrequentWords(std::vector<std::string>& i_words, int i_k)
{
	std::vector<std::string> result;
	result.reserve(i_k);
	std::map<std::string, int> frequencyMap;
	std::vector<std::pair<std::string, int>> sortByFrequencyVector;

	for (auto it : i_words)	
		frequencyMap[it]++;	

	sortByFrequencyVector.reserve(frequencyMap.size());
	for (auto it : frequencyMap)
		sortByFrequencyVector.push_back(std::make_pair(it.first, it.second));

	std::sort(sortByFrequencyVector.begin(), sortByFrequencyVector.end(), cmp);

	for (int i = 0; i < i_k; i++)
		result.push_back(sortByFrequencyVector[i].first);

	return result;
}