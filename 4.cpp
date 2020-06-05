/*
题目：
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
	则重建二叉树并返回。

思路：
	找到根节点，然后划分左右子树递归实现
*/

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		int vinLen = vin.size();
		if (vinLen == 0)
			return NULL;

		vector<int> left_pre, right_pre, left_vin, right_vin;

		//创建根节点，根节点是前序遍历的第一个数
		TreeNode* head = new TreeNode(pre[0]);

		//找到根节点在中序中位置
		int rootIndex = 0;
		for (int i = 0; i < vinLen; i++)
		{
			if (vin[i] == head->val)
			{
				rootIndex = i;
				break;
			}
		}

		//划分左右子树
		for (int i = 0; i < rootIndex; i++)
		{
			left_vin.push_back(vin[i]);
			//前序的前rootIndex个节点是左子树
			left_pre.push_back(pre[i + 1]);
		}

		for (int i = rootIndex + 1; i < vinLen; i++)
		{
			right_vin.push_back(vin[i]);
			//前序的rootIndex后面的节点是右子树
			right_pre.push_back(pre[i]);
		}

		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);

		return head;
	}
};

