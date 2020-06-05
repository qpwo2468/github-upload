/*
题目：
输入一棵二叉树，判断是否为平衡二叉树

思路:
 1. 获取每个节点的深度比较大小
 2. 从下往上遍历，返回子树的高度，判断是否符合平衡二叉树
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