/*
��Ŀ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������

*/

#include "head.h"

using namespace std;


//��������
int NumberOf1Between1AndN_Solution(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		string str = to_string(i);
		int p = str.find("1");
		while (p != str.npos)
		{
			sum++;
			p++;
			p = str.find("1", p);
		}
			
	}
	return sum;
}

//2
int NumberOf1Between1AndN_Solution(int n)
{
	int digit = 1, res = 0;
	int high = n / 10, cur = n % 10, low = 0;
	while (high != 0 || cur != 0)
	{
		if (cur == 0) res += high * digit;
		else if (cur == 1) res += high * digit + low + 1;
		else res += (high + 1) * digit;
		low += cur * digit;
		cur = high % 10;
		high /= 10;
		digit *= 10;
	}
	return res;
}