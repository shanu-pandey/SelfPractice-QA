/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

#pragma once
#include <cstring>
#include <string>
#include <vector>

namespace StringManipulation
{
	class AllAnagrams
	{
	public:
		static std::vector<int> FindAnagrams(std::string s, std::string p);
	private:
		static bool IsAnagram(std::vector<int>& s1, std::vector<int>& s2);
	};
}

bool StringManipulation::AllAnagrams::IsAnagram(std::vector<int>& s1, std::vector<int>& s2)
{
    for (int i = 0; i < 26; i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

std::vector<int> StringManipulation::AllAnagrams::FindAnagrams(std::string s, std::string p)
{
    std::vector<int> res;
    int sL = s.length();
    int pL = p.length();

    if (pL > sL)
        return res;

    std::vector<int> sVec(26, 0);
    std::vector<int> pVec(26, 0);

    for (auto& it : p)
        pVec[it - 'a']++;

    int i = 0;
    int currStart = 0;

    while (i < sL)
    {
        sVec[s[i] - 'a']++;
        if (i - currStart == pL - 1)
        {
            if (IsAnagram(sVec, pVec))
                res.push_back(currStart);

            sVec[s[currStart] - 'a']--;
            currStart++;
        }
        i++;
    }

    return res;
}



