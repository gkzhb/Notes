#include <iostream>
#include <vector>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 using std::vector;

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
	public:
	struct LNode :public ListNode {
		// val represents the Length of the list
		ListNode *list;	// the list that LNode points at
		LNode(ListNode *x) : ListNode(0), list(x) {}
	};
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		ListNode *llist=NULL, *olist = NULL, *last, *next; // llist: original list head,
											   // olist (ordered list): points to a list head whose
											   // 		lists are in the order of the list length

		if (lists.empty())
			return NULL;
		// construct the llist without knowing the length of each list
		for (vector<ListNode *>::const_iterator i = lists.begin(); i != lists.end();i++)	 
			if (NULL!=*i)
				if (NULL==llist) {
					llist = new LNode(*i);
					last = llist;
				}
				else {
					last->next = new LNode(*i);
					last = last->next;
				}
		if (NULL==llist)
			return NULL;
		last = NULL;

		// While there are at least 2 lists, merge 2 lists and add the new lists into the olist
		while (NULL != llist->next)
		{
			next = llist->next;
			*((LNode*)llist) = merge2Lists((LNode*)llist, (LNode*)llist->next);
			if (NULL==olist) {
				olist = new LNode(NULL);
				olist->next = llist;
			}
			else {
				if (olist->next == llist || olist->next == next)
					olist->next = next->next;
					ListNode *i = olist;
				while (NULL != i->next && llist->val > i->next->val)
					i = i->next;
				llist->next = i->next;
				i->next = llist;
			}
			if (0 == next->val)
				if (NULL==next->next)
					llist = olist->next;
				else {
					llist = next->next;
					if (NULL==llist->next)
						llist->next = olist->next;
				}
			else
				llist = olist->next;
			delete next;
		}
		return ((LNode*)llist)->list;
	}

	LNode merge2Lists(LNode *a, LNode *b)
	{
		LNode head(NULL);
		ListNode *i=a->list, *j=b->list, *p, *last;
		int count = 1;
		if (i->val>j->val) {
			head.list = j;
			j = j->next;
		} else {
			head.list = i;
			i = i->next;
		}
		last = head.list;

		while (NULL!=i||NULL!=j) 
			if (NULL!=i && NULL!=j) 
				if (i->val>j->val) {
					last->next = j;
					last = j;
					j = j->next;
					count++;
				} else {
					last->next = i;
					last = i;
					i = i->next;
					count++;
				}
			else {
				if (NULL==i)
					last->next = j;
				else
					last->next = i;
				i = NULL;
				for (j = last->next; NULL != j; j = j->next)
					count++;
			}

		head.val = count;
		return head;
	}
};

ListNode *createList(int a)
{
	int n;
	ListNode *last=NULL, *head;
	for (int i = 0; i < a;i++) {
		std::cin >> n;
		if (NULL==last)
			last = head = new ListNode(n);
		else {
			last->next = new ListNode(n);
			last = last->next;
		}
	}
	return head;
}

int main(void) {
	vector<ListNode *> data;
	data.push_back(createList(3));
	data.push_back(createList(3));
	data.push_back(createList(2));
	Solution a;
	ListNode *head = a.mergeKLists(data);
	for (ListNode *i = head; i != NULL;i=i->next,delete head) {
		std::cout << i->val << ' ';
		head = i;
	}
	std::cout << std::endl;

	return 0;
}