/*
��Ŀ��
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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