#ifndef GUARD_Queue_h
#define GUARD_Queue_h

#include<iostream>
#include<memory>

template<class T> class Queue	// ��������
{
private:
	class Node {				// ����Ԫ��(�ڵ�)(˫������)
	public:
		T data;					// ����
		Node *prev,*next;		// ǰ��ָ��
		Node() :prev(NULL), next(NULL) {};		// Ĭ�Ϲ��캯��
	};
	std::allocator<Node> alloc;

public:
	typedef size_t size_type;
	typedef typename Node * iterator;
	typedef typename const Node * const_iterator;
	typedef T value_type;

	Queue();									// Ĭ�Ϲ��캯��
	Queue(const Queue& q);
	~Queue() 										// ������������ȫɾ���б�
	{
		uncreate();
		delete_node(hd);
		delete_node(tl);
	}
	Queue& operator=(const Queue&);					// ���صȺ������

	iterator begin() const { return hd; }			// ���ض���ͷ������(�ڱ�Ԫ��)
	iterator end() const { return tl; }				// ���ض���β������(�ڱ�Ԫ��)
	size_type size() const { return sz; }			// ���ض���Ԫ�ظ���
	T head() const { return hd->next->data; }		// ��ȡ������Ԫ������
	T tail() const { return tl->prev->data; }		// ��ȡ����βԪ������
	bool empty() const { return hd->next == tl; }	// �ж϶����Ƿ�Ϊ��
	bool full() const { return sz == sz_max; }		// �ж϶����Ƿ�����
	void output(void(*out)(T&)) const;				// �����������

	void clear() { uncreate(); }					// ��ն���(��ͷβ�ڱ�Ԫ��)

	void push_back(const T& t) { append(tl->prev,t); }	// ��ӽڵ�(ͬ���)
	void erase(iterator iter);						// ɾ��Ԫ��
	void in(const T& t) { push_back(t); }			// ���
	void out() { erase(hd->next); }					// ����



private:
	size_type sz;		// ����Ԫ�ظ���
	iterator hd;		//	����ͷ������
	iterator tl;		//  ����β������
	const size_type sz_max = 50;	// ����Ԫ������

	void append(iterator iter, const T& t);	// ��tԪ����ӵ������Ԫiter��
	iterator create(const T& t);			// ��T�������ݴ���һ��Ԫ��
	void uncreate();						// ɾ����������Ԫ��(��ͷβ�ڱ�Ԫ��)
	void delete_node(iterator iter);		// �ͷ�iter��ָ�ڵ��ڴ�
	void create(const_iterator begin, const_iterator end);	// ����[begin,end)֮�������
};

template<class T> Queue<T>::Queue():sz(0)
{
	T tmp;
	hd = create(tmp);
	tl = create(tmp);
	hd->next = tl;
	tl->prev = hd;
}

template<class T> Queue<T>::Queue(const Queue& q) 
{
	T tmp;
	hd = create(tmp);
	tl = create(tmp);
	hd->next = tl;
	tl->prev = hd;
	create(q.begin(), q.end());
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
	if (&rhs != this)
	{
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template<class T>
void Queue<T>::uncreate()
{
	iterator i=hd->next,tmp;
	while (tl != i)
	{
		tmp = i;
		i = i->next;
		delete_node(tmp);
	}
	hd->next = tl;
	tl->prev = hd;
}

template<class T>void Queue<T>::append(typename Queue<T>::iterator iter, const T& t)
{
	iterator i = create(t);
	i->next = iter->next;
	i->next->prev = i;
	i->prev = iter;
	iter->next = i;
	sz++;
}

template<class T>void Queue<T>::delete_node(typename Queue<T>::iterator iter)
{
	alloc.destroy(iter);
	alloc.deallocate(iter, (size_type)1);
}


template<class T> typename Queue<T>::iterator Queue<T>::create(const T& t)
{
	iterator i = alloc.allocate((size_type)1);
	Node tmp;
	tmp.data = t;
	alloc.construct(i, tmp);
	return i;
}

template<class T>void Queue<T>::erase(typename iterator iter)
{
	if (iter != hd && iter != tl)
	{
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
		delete_node(iter);
		sz--;
	}

}

template<class T>void Queue<T>::output(void(*out)(T&)) const
{
	const_iterator i;
	for (i = hd->next; i != tl; i = i->next)
	{
		out(i->data);
		std::cout << std::endl;
	}
}

template<class T>
void Queue<T>::create(const_iterator begin, const_iterator end)
{
	clear();
	for (i = begin->next; i != end; i=i->next)
		in(i->data);
}

#endif