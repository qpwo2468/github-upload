/*
��Ŀ��
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ�
��һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1
����Ҫ���ִ�Сд��.����0��ʼ������
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