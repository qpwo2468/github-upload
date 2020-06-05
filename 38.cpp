/*
��Ŀ��
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ��
��������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
*/

#include "head.h"

using namespace std;

//1
int maxR = 0;
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL) return 0;
	dfs(pRoot, 0);
	return maxR;
}

void dfs(TreeNode* pRoot, int depth)
{
	if (pRoot == NULL)
	{
		maxR = maxR > depth ? maxR : depth;
	}
	else
	{
		dfs(pRoot->right, depth + 1);
		dfs(pRoot->left, depth + 1);
	}
}

//2
int TreeDepth(TreeNode* pRoot)
{
	if (!pRoot) return 0;
	return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
}