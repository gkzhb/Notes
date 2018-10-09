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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *last = head, *i = head, *j;
        int datum;
        head = new ListNode(0);
        head->next = last;
        last = head;
        while (NULL != i)
            if (i != head && NULL != i->next && i->val == i->next->val)
            {
                datum = i->val;
                while (NULL != i && i->val == datum)
                {
                    j = i;
                    i = i->next;
                    delete j;
                }
                last->next = i;
            }
            else
            {
                last = i;
                i = i->next;
            }
        return head->next;
    }
};

#ifdef LOCAL
int main(){
    Solution a;
    int n, x;
    ListNode *head = new ListNode(0), *j = head;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        j->next = new ListNode(x);
        j = j->next;
    }
    j = head->next;
    delete head;
    head = a.deleteDuplicates(j);
    for (j = head; NULL != j; j = j->next)
        std::cout << j->val << ' ';
    std::cout << std::endl;
    return 0;
}
#endif