/*
��Ŀ:
����һ�����������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

˼·��
  �Ƚ�������������ϵĽ��
  �����жϹ��� �� nums���������ֵ��ַ�����ʽ xxx �� yyy ����

	��ƴ���ַ��� x+y>y+xx + y > y + xx+y>y+x ���� m>nm > nm>n ��
	��֮���� x+y<y+xx + y < y + xx+y<y+x ���� n<mn < mn<m ��

���ߣ�jyd
���ӣ�https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
*/

#include "head.h"

using namespace std;

bool comp(int a, int b)
{
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(b) + to_string(a);
	return s1 < s2;
}


string PrintMinNumber(vector<int> numbers)
{
	sort(numbers.begin(), numbers.end(), comp);
	string str;
	for (int i = 0; i < numbers.size(); i++)
	{
		str += to_string(numbers[i]);
	}
	return str;
}

int main(void)
{
	vector<int> num = {3, 32, 321 };
	cout << PrintMinNumber(num);
	return 0;
}