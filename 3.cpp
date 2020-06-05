/*
题目：
  输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

思路：
    1. 使用栈保存链表，然后存入vector
    2. 使用递归操作(写法简单，但不推荐，容易爆)
    3. 直接存入vector, 然后反转
    4. 反转链表存入vector
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(nullptr) {}
};

//1
vector<int> printListFromTailToHead(ListNode* head)
{
    stack<int> data;
    vector<int> result;

    while (head != NULL)
    {
        data.push(head->val);
        head = head->next;
    }

    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        result.push_back(data.top());
        data.pop();
    }

    return result;
}

//2
vector<int >result;
vector<int> printListFromTailToHead(ListNode* head)
{
    if (head != NULL)
    {
        if(head->next != NULL)
            printListFromTailToHead(head->next);
        result.push_back(head->val);
    }
   
    return result;
}


//3
vector<int> printListFromTailToHead(ListNode* head)
{
    vector<int> result;
    while (head != NULL)
    {
        result.push_back(head->val);
        head = head->next;
    }

    for (int i = 0; i < result.size() / 2; i++)
    {
        int temp = result[i];
        result[i] = result[result.size() - i - 1];
        result[result.size() - i - 1] = temp;
    }
    return result;
}


//4
vector<int> printListFromTailToHead(ListNode* head)
{
    vector<int> result;
    struct ListNode* newHead;
    struct ListNode* temp;
    struct ListNode* node = NULL;

    while (head != NULL)
    {
        temp = head->next;
        newHead = head;
        newHead->next = node;
        node = newHead;
        head = temp;
    }
    while (newHead != NULL)
    {
        result.push_back(newHead->val);
        newHead = newHead->next;
    }
    return result;
}
