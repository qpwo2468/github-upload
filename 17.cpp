/*
题目：输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）

思路：
     1. 先搜索，看是否能在A树中找到B树的根节点
	 2. 如果找到了就比较子树节点是否相同
特殊点：
	1. 当节点 BBB 为空：说明树 BBB 已匹配完成（越过叶子节点），因此返回 truetruetrue ；
    2. 当节点 AAA 为空：说明已经越过树 AAA 叶子节点，即匹配失败，返回 falsefalsefalse ；
    3. 当节点 AAA 和 BBB 的值不同：说明匹配失败，返回 falsefalsefalse ；

作者：jyd
链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/mian-shi-ti-26-shu-de-zi-jie-gou-xian-xu-bian-li-p/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
	//如果节点值不相等，就搜索左右子树
	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	
}