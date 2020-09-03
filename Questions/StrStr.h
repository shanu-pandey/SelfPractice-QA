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


