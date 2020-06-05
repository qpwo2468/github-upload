/*
��Ŀ��
    ���������Ķ�����������任ΪԴ�������ľ���
˼·��

*/

#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 

void Mirror(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->left != NULL || pRoot->right != NULL)
	{
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		struct TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
	}
	else
		return;
}