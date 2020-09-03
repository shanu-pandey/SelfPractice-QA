/*
Implement strstr function of C++

strstr
const char * strstr ( const char * str1, const char * str2 );
	  char * strstr (       char * str1, const char * str2 );
Locate substring
Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
The matching process does not include the terminating null-characters, but it stops there.

*/

#pragma once
#include <cstring>
#include <string>

namespace StringManipulation
{
	class StrStr
	{
	public:
		static const char* DoStrStr(const char * i_str1, const char * i_str2);
	};
}

const char* StringManipulation::StrStr::DoStrStr(const char * i_str1, const char * i_str2)
{
	const char *ret;
	ret = nullptr;
	int tempSrc =  0;
	int tempDest = 0;

	while (i_str1[tempSrc])
	{
		if (i_str1[tempSrc] == i_str2[tempDest])
		{
			ret = i_str1 + tempSrc;
			tempSrc++;
			tempDest++;
			while (i_str2[tempDest])
			{
				if (i_str1[tempSrc] == i_str2[tempDest])
				{
					tempDest++;
					tempSrc++;
				}
				else
				{
					ret = nullptr;
					tempDest = 0;
					tempSrc--;
					break;
				}
			}
			if (tempDest > 0)
				return ret;
		}
		else
		{
			tempSrc++;
		}
	}
	return ret;
}


