/*
题目：
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到
第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1
（需要区分大小写）.（从0开始计数）
*/

#include "head.h"

using namespace std;

int FirstNotRepeatingChar(string str)
{
	map<char, int> res;
	for (int i = 0; i < str.size() - 1; i++)
	{
		res[str[i]]++;
	}
	for (int i = 0; i, str.size(); i++)
		if (res[str[i]] == 1)
			return i;
	return  -1;
}