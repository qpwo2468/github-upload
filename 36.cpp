/*
��Ŀ��
�������������ҳ����ǵĵ�һ��������㡣��ע����Ϊ�����������������Դ���������ݵ���ʾ����������ʽ��ʾ�ģ���֤������������ȷ�ģ�
*/

#include "head.h"

using namespace std;

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	map<ListNode*, int>res;
	while (pHead1 != NULL)
	{
		res[pHead1] = 1;
		pHead1 = pHead1->next;
	}
	while (pHead2 != NULL)
	{
		if (res[pHead2] == 1)
			return pHead2;
		pHead2 = pHead2->next;
	}

	return NULL;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* node1 = pHead1;
	ListNode* node2 = pHead2;
	while (node1 != node2)
	{
		node1 = node1 != NULL ? node1->next : pHead2;
		node2 = node2 != NULL ? node2->next : pHead1;
	}
	return node1;
}