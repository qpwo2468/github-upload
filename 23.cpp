/*
��Ŀ��
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No��
�������������������������ֶ�������ͬ��

*/

#include "head.h"

using namespace std;

//�и������������������ȸ��ڵ�С���������ȸ��ڵ��
bool VerifySquenceOfBST(vector<int> sequence)
{
	return recur(sequence, 0, sequence.size() - 1);
}

bool recur(vector<int> sequence, int i, int j)
{
	if (i >= j) return true;
	int p = i;
	while (sequence[p] < sequence[j]) p++;
	int m = p;
	while (sequence[p] > sequence[j]) p++;
	return p == j && recur(sequence, i, m - 1) && recur(sequence, m, j - 1);
}

//����ջ˼·
bool VerifySquenceOfBST(vector<int> sequence)
{
	stack<int> stack;
	int root = INT_MAX;
	if (sequence.size() == 0) return false;
	for (int i = sequence.size() - 1; i >= 0; i--)
	{
		if (sequence[i] > root) return false;
		while (!stack.empty() && stack.top() > sequence[i])
		{
			root = stack.top();
			stack.pop();
		}
		stack.push(sequence[i]);
	}
	return true;
}