/*
题目：
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。

*/

#include "head.h"

using namespace std;

//切割左右子树，右子树比根节点小，左子树比根节点大
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

//单调栈思路
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