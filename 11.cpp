/*
��Ŀ��
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
˼·��
	1.�����ֵ�ÿһλ������������ж��Ƿ�Ϊ1
	2.���һ��������Ϊ0����ô�������������һλ��1��������ǰ����������1��
	��ôԭ�������������ұߵ�1�ͻ��Ϊ0��ԭ����1��������е�0������1(������ұߵ�1
	���滹��0�Ļ�)����������λ�������ܵ�Ӱ�졣
*/

#include <iostream>
using namespace std;

/*
	* �ýⷨ�������ʱ������������ѭ����
	* ��Ϊ��������ʱ�������λ������1
	* ����������Ŀ������1�ĸ�������ô����������
	* 1�ˡ�
*/
int NumberOf1(int n)
{
	int flag = 1;
	int count = 0;
	while (n != 0)
	{
		if (flag & n)
			count++;
		n = n >> 1;
	}
	return count;
}


//����
int NumberOf1(int n)
{
	int flag = 1;
	int count = 0;
	while (flag != 0)
	{
		if (flag & n)
			count++;
		flag = flag << 1;
	}
	return count;
}

//���Ž�
int NumberOf1(int n)
{
	int count = 0;
	while (n != 0)
	{
		count++;
		//n-1 ��ʹ���ұߵ�1��Ϊ0��1�����0��Ϊ1��
		//�������벻Ϊ0������ǰ���������ٻ���һ��1
		n = (n - 1) & n;
	}
	return count;
}
int main(void)
{
	cout << NumberOf1(20);
	return 0;
}