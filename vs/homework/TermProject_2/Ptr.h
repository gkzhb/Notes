#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

template<class T> class Ptr		// 引用计数句柄
{
public:
	Ptr() :p(0), refptr(new std::size_t(1)) {}
	Ptr(T* t) :p(t), refptr(new std::size_t(1)) {}
	Ptr(const Ptr& h) :p(h.p), refptr(h.refptr)
	{
		++*refptr;
	}
	Ptr& operator=(const Ptr&);
	~Ptr();

	operator bool() const { return p; }
	T& operator*() const
	{
		if (p)
			return *p;
		throw std::runtime_error("unbound Ptr");
	}
	T* operator->() const
	{
		if (p)
			return p;
		throw std::runtime_error("unbound Ptr");
	}

	void make_unique()
	{
		if (*refptr != 1)
		{
			--*refptr;
			refptr = new size_t(1);
			p = p ? clone() : 0;
		}
	}

private:
	T *p;					// 数据指针
	std::size_t *refptr;	// 引用计数指针
};

template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	++*rhs.refptr;
	if (--*refptr == 0)
	{
		delete refptr;
		delete p;
	}
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template<class T> Ptr<T>::~Ptr()
{
	if (--*refptr == 0)
	{
		delete refptr;
		delete p;
	}
}

template<class T> T* clone(const T* tp)
{
	return tp->clone();
}

template<>
std::vector<char>* clone(const std::vector<char>* vp)
{
	return new std::vector<char>(*vp);
}

#endif