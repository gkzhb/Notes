#ifndef GUARD_Queue_h
#define GUARD_Queue_h

#include<iostream>
#include<memory>

template<class T> class Queue	// 队列容器
{
private:
	class Node {				// 队列元素(节点)(双向链表)
	public:
		T data;					// 数据
		Node *prev,*next;		// 前后指针
		Node() :prev(NULL), next(NULL) {};		// 默认构造函数
	};
	std::allocator<Node> alloc;

public:
	typedef size_t size_type;
	typedef typename Node * iterator;
	typedef typename const Node * const_iterator;
	typedef T value_type;

	Queue();									// 默认构造函数
	Queue(const Queue& q);
	~Queue() 										// 析构函数，完全删除列表
	{
		uncreate();
		delete_node(hd);
		delete_node(tl);
	}
	Queue& operator=(const Queue&);					// 重载等号运算符

	iterator begin() const { return hd; }			// 返回队列头迭代器(哨兵元素)
	iterator end() const { return tl; }				// 返回队列尾迭代器(哨兵元素)
	size_type size() const { return sz; }			// 返回队列元素个数
	T head() const { return hd->next->data; }		// 读取队列首元素数据
	T tail() const { return tl->prev->data; }		// 读取队列尾元素数据
	bool empty() const { return hd->next == tl; }	// 判断队列是否为空
	bool full() const { return sz == sz_max; }		// 判断队列是否已满
	void output(void(*out)(T&)) const;				// 输出队列数据

	void clear() { uncreate(); }					// 清空队列(除头尾哨兵元素)

	void push_back(const T& t) { append(tl->prev,t); }	// 添加节点(同入队)
	void erase(iterator iter);						// 删除元素
	void in(const T& t) { push_back(t); }			// 入队
	void out() { erase(hd->next); }					// 出队



private:
	size_type sz;		// 队列元素个数
	iterator hd;		//	队列头迭代器
	iterator tl;		//  队列尾迭代器
	const size_type sz_max = 50;	// 队列元素上限

	void append(iterator iter, const T& t);	// 将t元素添加到链表表元iter后
	iterator create(const T& t);			// 用T类型数据创建一个元素
	void uncreate();						// 删除队列所有元素(除头尾哨兵元素)
	void delete_node(iterator iter);		// 释放iter所指节点内存
	void create(const_iterator begin, const_iterator end);	// 复制[begin,end)之间的数据
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