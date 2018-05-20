#ifndef GUARD_Queue_h
#define GUARD_Queue_h

#include<memory>

template<class T> class Queue	// 队列容器
{
private:
	class Node {
	public:
		T data;
		Node* next;
	};
	std::allocator<Node> alloc;

public:
	typedef size_t size_type;
	typedef typename Node * iterator;
	//typedef typename const Node * const_iterator;
	typedef T value_type;

	Queue() :hd(NULL),sz(0) { }
	~Queue() { uncreate(); }
	
	iterator begin() const { return hd; }			// 返回队列头迭代器
	//const_iterator begin() const { return hd; }	
	iterator end() const { return NULL; }			// 返回队列末元素后一个迭代器
	//const_iterator end() const { return tl; }
	size_type size() const { return sz; }	// 返回队列元素个数
	/*iterator& operator ++(void)				// 重载前增量
	{
		this = this->next;
		return this;
	}
	iterator operator ++(int)				// 重载后增量
	{
		iterator tmp = this;
		this++;
		return tmp;
	}*/
	//void clear() { uncreate(); }

	void push_back(const T& t)
	{
		append(tl,t);
		if (NULL != tl->next)
			tl=tl->next;
	}
	void erase(iterator iter);

private:
	size_type sz;		// 队列元素个数
	iterator hd;		//	队列首元素
	iterator tl;		//  队列末元素

	void append(iterator iter, const T& t);	// 将t元素添加到链表表元iter后
	iterator create(const T& t);
	void uncreate();						// 删除队列所有元素
	void delete_node(iterator iter);		// 释放iter所指节点内存

};

template<class T>
void Queue<T>::uncreate()
{
	iterator tmp;
	while (NULL != hd)
	{
		tmp = hd;
		hd = hd->next;
		delete_node(tmp);
	}
	tl = NULL;
	sz = 0;
}

template<class T>void Queue<T>::append(typename Queue<T>::iterator iter, const T& t)
{
	iterator i = create(t);
	if (NULL != iter)
	{
		i->next = iter->next;
		iter->next = i;
	}
	else
		hd = tl = i;
	sz++;
}

template<class T>void Queue<T>::delete_node(typename Queue<T>::iterator iter)
{
	alloc.destroy(iter);
	alloc.deallocate(iter, (size_type)1);
}
/*
template<class T>
typename Queue<T>::iterator& Queue<T>::operator++(void)
{
	this = this->next;
	return this;
}*/

/*
template<class T>
typename Queue<T>::iterator Queue<T>::operator++(int)
{
	iterator tmp = this;
	this++;
	return tmp;
}*/

template<class T> typename Queue<T>::iterator Queue<T>::create(const T& t)
{
	iterator i = alloc.allocate((size_type)1);
	Node tmp;
	tmp.data = t;
	tmp.next = NULL;
	alloc.construct(i, tmp);
	return i;
}

template<class T>void Queue<T>::erase(typename iterator iter)
{
	if (iter == hd)
	{
		iter=iter->next;
		delete_node(hd);
		hd = iter;
	}
	else
	{
		iter i = hd;
		while (i > next != iter)
			i++;
		i->next = iter->next;
		delete_node(iter);
	}
	sz--;
}



#endif