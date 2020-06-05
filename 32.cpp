/*
题目:
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

思路：
  比较相邻两个数结合的结果
  排序判断规则： 设 nums任意两数字的字符串格式 xxx 和 yyy ，则

	若拼接字符串 x+y>y+xx + y > y + xx+y>y+x ，则 m>nm > nm>n ；
	反之，若 x+y<y+xx + y < y + xx+y<y+x ，则 n<mn < mn<m ；

作者：jyd
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
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