#pragma once
#include <list>
#include <map>
#include <ostream>
#include <iostream>

namespace Cache
{
	template <typename key_type, typename value_type>
	class MRUCache
	{
	public:	
		const int maxLength;
		MRUCache(int iMaxLength) : maxLength(iMaxLength) { }
		inline value_type FetchItem(key_type key) { return __fetch_item(key); }
		virtual ~MRUCache() { Clear(); }

		/**
		 * clear the cache.
		 * for every item contained, HandleItemRelease is called.
		 */
		virtual void Clear() { __clear(); }


	protected:
		virtual void HandleItemRelease(key_type key, value_type value) { };
		virtual value_type HandleNonExistingKeyFetch(key_type key) = 0;

	private:
		
		typedef struct _Entry
		{
			key_type key;
			value_type value;
		} Entry;

		typedef std::list<Entry> EntryList;
		EntryList listOfEntries;

		/**
		 * for fast search in the cache.
		 * this map contains pointers to iterators in EntryList.
		 */
		typedef std::map<key_type, void*> ItrPtrMap;
		ItrPtrMap mapOfListIteratorPtr;

		value_type __fetch_item(key_type key)
		{
			Entry entry;
			EntryList::iterator* ptrItr = (EntryList::iterator*) mapOfListIteratorPtr[key];
			if (!ptrItr)
			{
				if ((int)listOfEntries.size() >= maxLength)
				{
					Entry lruEntry = listOfEntries.back();
					HandleItemRelease(lruEntry.key, lruEntry.value);
					listOfEntries.pop_back();
					delete mapOfListIteratorPtr[lruEntry.key];
					mapOfListIteratorPtr.erase(lruEntry.key);
				}

				entry.value = HandleNonExistingKeyFetch(key);
				entry.key = key;
				listOfEntries.push_front(entry);

				EntryList::iterator* ptrItr = new EntryList::iterator();
				*ptrItr = listOfEntries.begin();
				mapOfListIteratorPtr[key] = ptrItr;
			}
			else
			{
				entry = *(*ptrItr);
				listOfEntries.erase(*ptrItr);
				listOfEntries.push_front(entry);
				*ptrItr = listOfEntries.begin();
			}
			return entry.value;
		}

		virtual void __clear()
		{
			for (ItrPtrMap::iterator i = mapOfListIteratorPtr.begin();
				i != mapOfListIteratorPtr.end(); i++)
			{
				void* ptrItr = i->second;
				EntryList::iterator* pItr = (EntryList::iterator*) ptrItr;
				HandleItemRelease((*pItr)->key, (*pItr)->value);
				delete ptrItr;
			}
			listOfEntries.clear();
			mapOfListIteratorPtr.clear();
		}
	};


	char* HARD_DISK[] =
	{
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine", "ten"
	};
	class TestCache : public MRUCache<int, char*>
	{
	public:
		TestCache(int iMaxLength) : MRUCache<int, char*>(iMaxLength) { }
	protected:
		virtual void HandleItemRelease(int key, char* value)
		{
			std::cout << "[DEBUG] key \"" << key
				<< "\" removed" << std::endl;
		}
		virtual char* HandleNonExistingKeyFetch(int key)
		{
			std::cout << "[DEBUG] key \""
				<< key << "\" fetched" << std::endl;
			return HARD_DISK[key];
		}
	};
}