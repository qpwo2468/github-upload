/*
��Ŀ��
ͳ��һ�����������������г��ֵĴ�����

˼·��
 1. �����ҵ���Ӧ����ǰ�����
 2. �ֱ��ҵ�k-0.5 �� k + 0.5��λ�ã�Ȼ����λ�ò�
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
