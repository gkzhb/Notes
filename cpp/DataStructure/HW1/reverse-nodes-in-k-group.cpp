#include <iostream>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
		if (1 == k)
			return head;
		ListNode *last = NULL, *j, *pos = head;
		int i;
		while (NULL != pos)
		{
			for (j = pos, i = 1; i < k && NULL != j; i++)
				j = j->next;
			if (NULL == j)
			{
				if (last != NULL)
					last->next = pos;
				pos = NULL;
			}
			else
			{
				if (NULL == last)
					head = j;
				else
					last->next = j;
				last = pos;
				ListNode *posNext;
				for (j = pos, i = 1, pos = j->next , posNext = pos->next; i < k; i++)
				{
					pos->next = j;
					j = pos;
					pos = posNext;
					if (NULL != posNext)
						posNext = posNext->next;
				}
				last->next = NULL;
			}
		}

		return head;
	}
};

int main(void)
{
	Solution a;
	int n, k;
	ListNode *pos, *head = NULL, *newPos;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> k;
		newPos = new ListNode(k);
		if (NULL == head)
			head = pos = newPos;
		else
		{
			pos->next = newPos;
			pos = newPos;
		}
	}
	std::cin >> k;
	head = a.reverseKGroup(head, k);
	for (pos = head; NULL != pos; pos = pos->next)
		std::cout << pos->val << ' ';
	std::cout << std::endl;

	return 0;
}