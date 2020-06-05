/*
题目：
统计一个数字在排序数组中出现的次数。

思路：
 1. 二分找到对应数后前后查找
 2. 分别找到k-0.5 和 k + 0.5的位置，然后获得位置差
*/

#include "head.h"

using namespace std;
//1 
int GetNumberOfK(vector<int> data, int k)
{
	int l = 0, r = data.size() - 1;
	int mid = (l + r) / 2;
	int sum = 0;
	if (data.size() == 0) return 0;
	while (l <= r)
	{
		if (data[mid] == k)
			break;
		else if (data[mid] > k)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
		mid = (l + r) / 2;
	}
	if (data[mid] != k)
		return 0;
	else
	{
		int tmp = mid;
		sum++;
		while (--tmp >= 0)
		{
			if (data[tmp] == k) sum++;
			else break;
		}
		tmp = mid;
		while (++tmp < data.size())
		{
			if (data[tmp] == k) sum++;
			else break;
		}
	}
	return sum;
}

//2
int GetNumberOfK(vector<int> data, int k)
{
	return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
}
int biSearch(vector<int>& data, double num)
{
	int l = 0, r = data.size() - 1;
	int mid = (l + r) / 2;
	int sum = 0;
	//if (data.size() == 0) return 0;
	while (l <= r)
	{
		if (data[mid] == num)
			break;
		else if (data[mid] > num)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
		mid = (l + r) / 2;
	}
	return r;
}
int main(void)
{
	vector<int> num = {  1, 4 };
	cout << GetNumberOfK(num, 1);
}
