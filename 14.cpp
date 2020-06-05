/*
输入一个链表，输出该链表中倒数第k个结点

*/

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(nullptr) {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	ListNode* FindKthToTail(ListNode * pListHead, unsigned int k) {
    if (pListHead == NULL || k == 0)
		return NULL;
	ListNode* quick = pListHead;
	ListNode* slow = pListHead;
	int n = 1;
	while (quick->next != NULL && n < k)
	{
		quick = quick->next;
		n++;
	}
	while (quick->next != NULL)
	{
		quick = quick->next;
		slow = slow->next;
	}
	return (n == k ? slow : NULL);
	
}
