/*
��Ŀ��
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����
һֱ��Ҷ����������Ľ���γ�һ��·����

˼·��
https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/mian-shi-ti-34-er-cha-shu-zhong-he-wei-mou-yi-zh-5/
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

vector<int> path;
vector<vector<int>> res;

vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
{
	
	recur(root, expectNumber);
	return res;
}

void recur(TreeNode *root, int tar)
{
	if (root == NULL) return;
	path.push_back(root->val);
	tar -= root->val;
	if (tar == 0 && root->left == NULL && root->right == NULL)
		res.push_back(path);
	recur(root->left, tar);
	recur(root->right, tar);
	path.pop_back();
}