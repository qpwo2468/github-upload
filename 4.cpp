/*
��Ŀ��
	����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
	���������ǰ���������������Ľ���ж������ظ������֡�
	��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
	���ؽ������������ء�

˼·��
	�ҵ����ڵ㣬Ȼ�󻮷����������ݹ�ʵ��
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

		//�������ڵ㣬���ڵ���ǰ������ĵ�һ����
		TreeNode* head = new TreeNode(pre[0]);

		//�ҵ����ڵ���������λ��
		int rootIndex = 0;
		for (int i = 0; i < vinLen; i++)
		{
			if (vin[i] == head->val)
			{
				rootIndex = i;
				break;
			}
		}

		//������������
		for (int i = 0; i < rootIndex; i++)
		{
			left_vin.push_back(vin[i]);
			//ǰ���ǰrootIndex���ڵ���������
			left_pre.push_back(pre[i + 1]);
		}

		for (int i = rootIndex + 1; i < vinLen; i++)
		{
			right_vin.push_back(vin[i]);
			//ǰ���rootIndex����Ľڵ���������
			right_pre.push_back(pre[i]);
		}

		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);

		return head;
	}
};

