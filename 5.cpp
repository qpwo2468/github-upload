/*
题目：
	用两个栈来实现一个队列，完成队列的Push和Pop操作。
	队列中的元素为int类型。

思路：
    push时直接将数压入stack1中，
	pop时将stack1所有数弹入stack2中并返回stack2的栈顶元素
	(弹入stack2时判断是否为空，不为空直接弹出栈顶，为空就从stack1中弹入)
*/

#include <stack>
#include <iostream>

using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int node)
{
	stack1.push(node);
}

int pop()
{
	int result;
	if (stack2.size() == 0)
	{
		while (stack1.size() > 0)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	
	result = stack2.top();
	stack2.pop();

	return result;
}