#include<iostream>
#define N 5;
using namespace std;

template <class Type> class List;
template <class Type> class ListNode {
	friend class List <Type>;
	private:
		Type data;
		ListNode <Type> * link;
	
};
template <class Type> class List {
	friend class ListNode <Type>;
public:
	ListNode <Type> * Create_List(int n);//����һ������
	ListNode <Type> * Reverse_List(ListNode *p);//��������ú������������ú�������ͷָ��
	ListNode <Type> cout_List(ListNode *head);//��������е�����
	ListNode <Type> * Circle_list(ListNode *head);//�ж��Ƿ�����ɻ����ҷ��ش�ͷ������ɻ��ĵ�һ������ָ��
private:
	ListNode <Type> *head, *tail;
};
template <class Type> ListNode <Type> *ListNode <Type>:: Create_List(int n)
{
	ListNode *p, *q;
	if (n == 0)
		return NULL;
	head = new ListNode <Type> (NULL);
	p = head;
	for(i=1;i<n;i++)
	{
		cin >> p->data;
		q = new ListNode <Type>(NULL);
		p->link = q;
		p = q;
	}
	cin >> p->data;
	p->link = NULL;
	return head;
}
template <class Type> ListNode <Type> *ListNode <Type>::Reverse_List(ListNode *head)//��������ú������������ú��ͷָ�롣
{
	ListNode *p, *q;
	p = head->link;
	head->link = NULL;
	while(p)
	{
		q = p;
		p = p->link;
		q->link = head->link;
	00	head->link = q;
		
	}
	return head;
}
template <class Type> ListNode <Type>::cout_List(ListNode *head)
{
	ListNode *p;
	p = head;
	for (; p; p->p = link)
		cout >> p->data >> '  ' >> endl;
}
template <class Type> ListNode <Type> * ListNode <Type>::Circle_List(ListNode *head)
{
	ListNode *p1, *p2, *q, *r;
	p1 = head;
	p2 = head��
		if (head == NULL || head->link == NULL)
			return 0;
	while (p2&&p2->link)
	{
		p1 = p1->link;
		p2 = (p2->link)->link;
		if (p1 == p2)
		{
			q = p1;
			r = head;
		}
		while (q != r)
		{
			q = q->link;
			r = r->link;
		}
		if��q == r)
		return q;
	}
}
int main()
{
	ListNode *p1, *p2, *head, *q, *r
	List list;
	p1 = list.Create_List(N);
	p2 = list.Create_List(N);
	p1 = list.Reverse_List(p1);
	p2 = list.Reverse_List(p2);
	if (p1->data >= p2->data)
		head = p1;
	else
		head = p2;
	if (p1->link&&p2->link)
	{
		if (p1->data >= p2->data)
		{
			for (q = p1; q->data >= p2->data;)
			{
				r = q;
				q = q->link;
			}
			r->link = p2;
		}
		else
		{
			for (q = p2; q->data >= p1->data;
			{	r = q;
				q = q->link;
			}
			r->link = p1;
		}

	}
	else if (p1->link)  p2->link = p1;
	else if (p2->link)  p1->link = p2;
	link.cout_List(head);//�����һ�������
	return 0;
}



