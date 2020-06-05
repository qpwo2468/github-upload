/*
��Ŀ��
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬
һ��ָ����һ���ڵ㣬��һ������ָ��randomָ��һ������ڵ㣩��
��Դ������������������ؿ������ͷ��㡣
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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
//�ɽڵ�:�½��
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