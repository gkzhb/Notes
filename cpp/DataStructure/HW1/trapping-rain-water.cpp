#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	class ListNode {
		public:
		  int index;
		  ListNode *next;
		  ListNode(int x) : index(x), next(NULL) {}
	};
	int trap(vector<int> &height)
	{
		if (height.empty())
			return 0;
		height.push_back(0);
		int n = height.size(), i, j, h = 0, max = 0, posi, ans = 0;
		vector<int> top;
		for (i = 0; i < n;h = height[i], i++) 
		{		// top 记录“山峰”位置
			if (height[i]>h && height[i]>=height[i+1])
				top.push_back(i);
			if (height[i]>max) 
			{	// 记录最高高度及在 top 中的位置
				max = height[i];
				posi = top.size() - 1;
			}
		}
		if (top.size()<2)
			return 0;
		ListNode *head = new ListNode(0), *tail, *tmp, *t;
		head->next = new ListNode(top[posi]);
		tail = head->next;
		// 删除山峰中不必要的峰 (栈的方式处理)
		for (i = posi - 1; - 1 != i; i--)
		{
			tmp = new ListNode(top[i]);
			tmp->next = head->next;
			head->next = tmp;
			while (height[top[i]] > height[tmp->next->index])
			{
				t = tmp->next;
				tmp->next = t->next;
				delete t;
			}
		}

		// 统计凹槽空间
		for (ListNode *i = head->next; NULL != i->next; i = i->next)
		{
			h = i->next->index;
			max = height[i->index] > height[h] ? height[h] : height[i->index];
			for (j = i->index + 1; j != h; j++)
				if (max>height[j])
					ans += max - height[j];
		}
		freeList(head);
		head->next = tail;

		for (i = posi + 1; top.size() != i; i++) 
		{
			tmp = new ListNode(top[i]);
			tmp->next = head->next;
			head->next = tmp;
			while (height[top[i]] > height[tmp->next->index])
			{
				t = tmp->next;
				tmp->next = t->next;
				delete t;
			}
		}
		for (ListNode *i = head->next; NULL != i->next; i = i->next)
		{
			h = i->next->index;
			max = height[i->index] > height[h] ? height[h] : height[i->index];
			for (j = i->index - 1; j != h; j--)
				if (max>height[j])
					ans += max - height[j];
		}
		freeList(head);
		delete head;
		delete tail;

		return ans;
	}

	void freeList(ListNode *head)			// 释放链表内存，但保留链表前哨节点和末尾一个节点
	{
		for (ListNode *i = head->next; NULL != i->next; i = i->next, delete head)
			head = i;
	}
};

int main(void)
{
	vector<int> height;
	int n, x;
	std::cin >> n;
	for (int i = 0; i != n; i++)
	{
		std::cin >> x;
		height.push_back(x);
	}
	Solution a;
	std::cout << a.trap(height) << std::endl;

	return 0;
}