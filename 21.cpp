/*
��Ŀ��
���������������У���һ�����б�ʾջ��ѹ��˳��
���жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳��
����4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�

˼·��
  1.���Ƚ���һ������ջ�����ջΪ�գ�ѹ��pusV��front, pushV�ƽ�һ����
     Ȼ��Ƚ�ջ��Ԫ���Ƿ���popV��frontԪ����ȣ��������ȼ�����pushV
	 ѹ��ջ����Ⱦ͵�����popV�ƽ�һ���� �������ƣ�������ջ����Ԫ�ز�����
	 popV��front�� ��pushV�Ѿ�û��Ԫ�أ�˵���ⲻ�ǳ�ջ����
*/

#include "head.h"

using namespace std;

//�Լ�д��
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

//���ϱȽϺõ�
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
