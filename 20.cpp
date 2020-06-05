/*
题目：
 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
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