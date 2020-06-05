/*
题目：
输入一个复杂链表（每个节点中有节点值，以及两个指针，
一个指向下一个节点，另一个特殊指针random指向一个随机节点），
请对此链表进行深拷贝，并返回拷贝后的头结点。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/


#include "head.h"

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode* next, * random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};
//旧节点:新结点
map<RandomListNode*, RandomListNode*> temp;
RandomListNode* Clone(RandomListNode* pHead)
{
    if (pHead == NULL) return NULL;
    
    return dfs(pHead);
}

RandomListNode* dfs(RandomListNode* node)
{
    if (node == NULL) return NULL;
    if (temp[node] != NULL) return temp[node];
    
    RandomListNode* newNode = new RandomListNode(node->label);
    temp[node] = newNode;
    newNode->next = dfs(node->next);
    newNode->random = dfs(node->random);

    return newNode;
}

RandomListNode* bfs(RandomListNode* node)
{
    queue<RandomListNode*>nodeQueue;
    temp[node] = new RandomListNode(node->label);
    nodeQueue.push(node);

    while (!nodeQueue.empty())
    {
        int size = nodeQueue.size();
        for (int i = 0; i < size; i++)
        {
            RandomListNode* q = nodeQueue.front();
            if (q->next)
            {
                if (!temp[q->next])
                {
                    temp[q->next] = new RandomListNode(q->next->label);
                    nodeQueue.push(q->next);
                }
                temp[q]->next = temp[q->next];
            }
            if (q->random)
            {
                if (!temp[q->random])
                {
                    temp[q->random] = new RandomListNode(q->random->label);
                    nodeQueue.push(q->random);
                }
                temp[q]->random = temp[q->random];
               
            }
        }    
    }
    return temp[node];
}