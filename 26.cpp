/*
题目：
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

#include "head.h"

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

TreeNode* pre = NULL, * head = NULL;
TreeNode* Convert(TreeNode* root)
{
	if (root == NULL) return NULL;
	
	dfs(root);
	head->left = pre;
	pre->right = head;

	return head;
}

void dfs(TreeNode* cur)
{
	if (cur == NULL) return;
	dfs(cur->left);
	if (pre != NULL) pre->right = cur;
	else head = cur;
	cur->left = pre;
	pre = cur;
	dfs(cur->right);
}