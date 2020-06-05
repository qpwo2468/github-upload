/*
题目：
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）

思路：
  1.首先建立一个辅助栈，如果栈为空，压入pusV的front, pushV推进一个，
     然后比较栈顶元素是否与popV的front元素相等，如果不相等继续从pushV
	 压入栈，相等就弹出，popV推进一个， 依次类推，如果最后栈顶的元素不等于
	 popV的front， 而pushV已经没有元素，说明这不是出栈序列
*/

#include "head.h"

using namespace std;

//自己写的
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	stack<int> s1;
	auto pushIt = pushV.begin();
	auto popIt = popV.begin();
	if (pushV.size() == 0 && popV.size() == 0) return true;
	while (popIt != popV.end())
	{
		if (s1.size() == 0 || (s1.top() != *popIt && pushIt != pushV.end()))
		{
			s1.push(*pushIt);
			pushIt++;
		}
		if (s1.top() == *popIt)
		{
			s1.pop();
			popIt++;
		}
		if (s1.size() != 0 && s1.top() != *popIt && pushIt == pushV.end())
			return false;
	}
	return true;
}

//网上比较好的
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	if (pushV.size() == 0) return false;
	vector<int> stack;
	for (int i = 0, j = 0; i < pushV.size();)
	{
		stack.push_back(pushV[i++]);
		while (j < popV.size() && stack.back() == popV[j])
		{
			stack.pop_back();
			j++;
		}
	}
	return stack.empty();
}

int main(void)
{
	vector<int> p1{ 1, 2, 3, 4, 5 };
	vector<int> p2{ 1, 5, 3, 4, 5 };

	cout << IsPopOrder(p1, p2);
	return 0;
}
