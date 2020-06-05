/*
题目：
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
*/

#include <iostream>

using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
}; 

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL) return pHead2;
	if (pHead2 == NULL) return pHead1;
	if (pHead1->val <= pHead2->val)
	{
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
	else
	{
		pHead2->next = Merge(pHead1, pHead2->next);
		return pHead2;
	}
}


ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* newHead, *Head;
	Head = newHead = NULL;
	if (pHead1 == NULL) return pHead2;
	if (pHead2 == NULL) return pHead1;
	
	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->val < pHead2->val)
		{
			if (Head == NULL)
			{
				newHead = Head = pHead1;
			}
			else
			{
				newHead->next = pHead1;
				newHead = newHead->next;
			}
			pHead1 = pHead1->next;
		}
		else
		{
			if (Head == NULL)
			{
				newHead = Head = pHead2;
			}
			else
			{
				newHead->next = pHead2;
				newHead = newHead->next;
			}
			pHead2 = pHead2->next;
		}
	}
	if(pHead1 != NULL)
	{
		newHead->next = pHead1;
	}
	if (pHead2 != NULL)
	{
		newHead->next = pHead2;
	}
	return Head;
}

int main(void)
