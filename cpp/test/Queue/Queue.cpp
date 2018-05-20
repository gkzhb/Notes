#include "Queue.h"

template<class T>
void Queue<T>::uncreate()
{
	iterator tmp;
	while (NULL != hd)
	{
		tmp = hd++;
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

 template<class T>
 typename Queue<T>::iterator& Queue<T>::operator++(void)
{
	this = this->next;
	return this;
}


template<class T>
typename Queue<T>::iterator Queue<T>::operator++(int)
{
	iterator tmp = this;
	this++;
	return tmp;
}

template<class T> typename Queue<T>::iterator Queue<T>::create(const T& t)
{
	iterator i = alloc.allocate((size_type)1);
	Node tmp;
	tmp.data = t;
	tmp.next = NULL;
	alloc.construct(i, tmp);
	return i;
}

template<class T>void Queue<T>::erase(iterator iter)
{
	if (iter == hd)
	{
		iter++;
		delete_node(hd);
		hd = iter;
	}
	else
	{
		iterator i = hd;
		while (i -> next != iter)
			i++;
		i->next = iter->next;
		delete_node(iter);
	}
	sz--;
}

