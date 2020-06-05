/*
��Ŀ��
����һ�ö��������ж��Ƿ�Ϊƽ�������

˼·:
 1. ��ȡÿ���ڵ����ȱȽϴ�С
 2. �������ϱ��������������ĸ߶ȣ��ж��Ƿ����ƽ�������
*/

#include "head.h"

using namespace std;

//1 
bool IsBalanced_Solution(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return true;
	return abs(maxDepth(pRoot->left) - maxDepth(pRoot->right)) <= 1
		&& IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

int maxDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	return 1 + max(maxDepth(pRoot->left), maxDepth(pRoot->right));
}

//2
bool IsBalanced_Solution(TreeNode* pRoot)
{
	return getDepth(pRoot) != -1;
}

int getDepth(TreeNode* pRoot)
{
	if (pRoot == NULL) return 0;
	int left = getDepth(pRoot->left);
	if (left == -1) return -1;
	int right = getDepth(pRoot->right);
	if (right == -1) return -1;
	return abs(left - right) > 1 ? -1 : 1 + max(left, right);
}