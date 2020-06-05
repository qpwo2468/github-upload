/*
��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ��
��ps������Լ��������������һ�������ӽṹ��

˼·��
     1. �����������Ƿ�����A�����ҵ�B���ĸ��ڵ�
	 2. ����ҵ��˾ͱȽ������ڵ��Ƿ���ͬ
����㣺
	1. ���ڵ� BBB Ϊ�գ�˵���� BBB ��ƥ����ɣ�Խ��Ҷ�ӽڵ㣩����˷��� truetruetrue ��
    2. ���ڵ� AAA Ϊ�գ�˵���Ѿ�Խ���� AAA Ҷ�ӽڵ㣬��ƥ��ʧ�ܣ����� falsefalsefalse ��
    3. ���ڵ� AAA �� BBB ��ֵ��ͬ��˵��ƥ��ʧ�ܣ����� falsefalsefalse ��

���ߣ�jyd
���ӣ�https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/mian-shi-ti-26-shu-de-zi-jie-gou-xian-xu-bian-li-p/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 

bool isSub(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL && pRoot2) return false;
	if (pRoot2 == NULL) return true;
	if (pRoot1->val != pRoot2->val) return false;

	return isSub(pRoot1->left, pRoot2->left) && isSub(pRoot1->right, pRoot2->right);
	
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL) return false;
	if (pRoot1 == NULL && pRoot2) return false;
	
	if (pRoot1->val == pRoot2->val)
		if (isSub(pRoot1, pRoot2))
			return true;
	//����ڵ�ֵ����ȣ���������������
	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	
}