// #define LOCAL
#ifdef LOCAL
#include <iostream>


// define data structures here
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		int i;
		ListNode *left, *lnext, *j = new ListNode(0), *last, *next;
		j->next = head;
		head = j;
		for (i = 0; i < m - 1; i++)
			j = j->next;
		left = j;
		last = lnext = j = j->next;
		next = j->next;
		i++;
		i++;
		for (; i <= n; i++)
		{
			j = next;
			next = j->next;
			j->next = last;
			last = j;
		}
		left->next = j;
		lnext->next = next;
		j = head->next;
		delete head;
		return j;
	}
};

#ifdef LOCAL
int main(){
    Solution a;
    int m, n, x;
    ListNode *head = new ListNode(0), *j = head;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        j->next = new ListNode(x);
        j = j->next;
    }
	std::cin >> m >> n;
	j = head->next;
	delete head;
	head = a.reverseBetween(j, m, n);
	for (j = head; NULL != j; j = j->next)
		std::cout << j->val << ' ';
    std::cout << std::endl;
    return 0;
}
#endif