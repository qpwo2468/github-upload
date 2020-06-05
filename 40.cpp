/*
��Ŀ��
һ�����������������������֮�⣬���������ֶ����������Ρ�
��д�����ҳ�������ֻ����һ�ε����֡�

*/

#include "head.h"

using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
{
	map<int, int> res;
	int n1, n2;
	int flag = 0;
	if (data.size() <= 1)
	{
		num1 = NULL;
		num2 = NULL;
	}
	for (auto i : data) res[i]++;
	for (auto i = res.begin(); i != res.end(); i++)
	{
		if (i->second == 1 && flag == 0)
		{
			n1 = i->first;
			flag = 1;
		}
		else if (i->second == 1 && flag == 1)
		{
			n2 = i->first;
			flag++;
		}
		else continue;
	}
	*num1 = flag >= 1 ? n1 : NULL;
	*num2 = flag >= 2 ? n2 : NULL;
}

//λ���㣬��ͬ�������Ϊ0��0���κ��������Ȼ��ԭ������
vector<int> FindNumsAppearOnce(vector<int> data)
{
	int s = 0;
	for (int num : data) s ^= num;
	int k = s & (-s);
	vector<int> rs(2, 0);
	for (int num : data)
	{
		if (num & k)  rs[0] ^= num;
		else rs[1] ^= num;
	}
	return rs;
}
