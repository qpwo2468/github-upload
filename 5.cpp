/*
��Ŀ��
	������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������
	�����е�Ԫ��Ϊint���͡�

˼·��
    pushʱֱ�ӽ���ѹ��stack1�У�
	popʱ��stack1����������stack2�в�����stack2��ջ��Ԫ��
	(����stack2ʱ�ж��Ƿ�Ϊ�գ���Ϊ��ֱ�ӵ���ջ����Ϊ�վʹ�stack1�е���)
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