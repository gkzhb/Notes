#ifndef GUARD_Queue_h
#define GUARD_Queue_h

#include<memory>

template<class T> class Queue	// ��������
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
	
	iterator begin() const { return hd; }			// ���ض���ͷ������
	//const_iterator begin() const { return hd; }	
	iterator end() const { return NULL; }			// ���ض���ĩԪ�غ�һ��������
	//const_iterator end() const { return tl; }
	size_type size() const { return sz; }	// ���ض���Ԫ�ظ���
	/*iterator& operator ++(void)				// ����ǰ����
	{
		this = this->next;
		return this;
	}
	iterator operator ++(int)				// ���غ�����
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
	size_type sz;		// ����Ԫ�ظ���
	iterator hd;		//	������Ԫ��
	iterator tl;		//  ����ĩԪ��

	void append(iterator iter, const T& t);	// ��tԪ����ӵ������Ԫiter��
	iterator create(const T& t);
	void uncreate();						// ɾ����������Ԫ��
	void delete_node(iterator iter);		// �ͷ�iter��ָ�ڵ��ڴ�

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