#define LOCAL
#ifdef LOCAL
#include <iostream>


// define data structures here
#endif


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