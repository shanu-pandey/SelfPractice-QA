/*
We are given total possible page numbers that can be referred. We are also given cache (or memory) size (Number of page frames that cache can hold at a time). 
The LRU caching scheme is to remove the least recently used frame when the cache is full and a new page is referenced which is not there in cache.
*/
#pragma once
#include <list>
#include <iostream>
#include <unordered_map>

namespace Cache
{
	class LRUCache
	{
	public:
		LRUCache(int i_size) : m_Size(i_size)
		{}
		void Refer(int i_key);
		inline void PrintCache() {
			for (auto& it : m_KeyList)
				std::cout << it << " ";
		}

	private:
		int m_Size;
		std::list<int> m_KeyList;
		std::unordered_map<int, std::list<int>::iterator> m_KeyRefMap;
	};
}

void Cache::LRUCache::Refer(int i_key)
{
	//if not present in cache
	if (m_KeyRefMap.find(i_key) == m_KeyRefMap.end())
	{
		//cache is full
		if (m_KeyList.size() == m_Size)
		{
			//remove last element
			int last = m_KeyList.back();
			m_KeyList.pop_back();
			m_KeyRefMap.erase(last);
		}
	}
	else
	{
		//present in cache, remove it
		m_KeyList.erase(m_KeyRefMap[i_key]);			
	}
		
	//add the current at the top
	m_KeyList.push_front(i_key);
	m_KeyRefMap[i_key] = m_KeyList.begin();
}