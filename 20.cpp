/*
��Ŀ��
 ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
ע�⣺��֤�����в��ᵱջΪ�յ�ʱ�򣬶�ջ����pop()����min()����top()������
*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> s1, s2;

void push(int value)
{
    s1.push(value);
    if (s2.size() == 0 || value < s2.top())
        s2.push(value);
}

void pop()
{
    
    if (s1.top() == s2.top())
        s2.pop();
    s1.pop();
}

int top()
{
    return s1.top();
}

int min()
{
    return s2.top();
}