#include<iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if (NULL==head || NULL==head->next)
			return head;
		int len = 1;
		ListNode *i = head, *tail;
		while (NULL!=i->next)
		{
			len++;
			i = i->next;
		}
		tail = i;
		k = len - (k % len);
		tail->next = head;
		for (int j = 0; j < k;j++,i = i->next)
			;
		head = i->next;
		i->next = NULL;
		return head;
	}
};

int main(void)
{
	ListNode *head, *last, *tmp;
	last = head = new ListNode(0);
	int k;
	for (int i = 1; i < 6; i++)
	{
		tmp = new ListNode(i);
		last->next = tmp;
		last = tmp;
	}
	std::cin >> k;
	Solution a;
	head = a.rotateRight(head, k);
	for (tmp = head; tmp != NULL;tmp=tmp->next)
		std::cout << tmp->val << ' ';
	std::cout << std::endl;
	return 0;
}