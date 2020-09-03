/*
Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

#pragma once

namespace Recursion
{
	class Power
	{
	public:
		static double MyPow(double i_num, int i_pow);
	};
}


double Recursion::Power::MyPow(double i_num, int i_pow)
{
	double temp;
	if (i_pow == 0)
		return 1;
	if (i_pow == 1)
		return i_num;

	temp = MyPow(i_num, i_pow / 2);

	if (i_pow % 2 == 0)
		return temp * temp;
	else
	{
		if (i_pow > 0)
			return temp * temp * i_num;
		else
			return (temp * temp) / i_num;
	}
}