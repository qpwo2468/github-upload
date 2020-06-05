/*
题目：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点
（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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