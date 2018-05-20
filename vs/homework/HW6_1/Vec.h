#ifndef GUARD_Vec_h
#define GUARD_Vec_h
#include <memory>

#define max(A,B) (((A)>(B))?(A):(B))
template<class T>
class Vec
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }		// ����n��tԪ��
	Vec(const Vec& v) { create(v.begin(), v.end()); }					// copy constructor
	Vec& operator=(const Vec&);											// ���ظ�ֵ�����
	~Vec() { uncreate(); }
	
	T& operator[](size_type i) { return data[i]; }						// ����[]
	const T& operator[](size_type i) const {return data[i]; }

	void push_back(const T& t)											// ���������������t
	{
		if (avail == limit)
			grow();
		unchecked_append(t);
	}
	void clear() { uncreate(); }										// �����������
	
	size_type size() const { return avail - data; }						// ��������Ԫ�ظ���
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }
	bool empty() const { return data == avail; }						// �ж������Ƿ�Ϊ��

private:
	iterator data,avail,limit;											// ���ݿ�ͷ�����һ���ѳ�ʼ��Ԫ�غ�һλ���ڴ����һ��Ԫ�غ�һλ

	std::allocator<T> alloc;

	void create();														// ����������
	void create(size_type, const T&);									// ���������ͬԪ�ص�����
	void create(const_iterator, const_iterator);						// �������������ݴ�������

	void uncreate();													// ɾ���������ݲ��ͷ�[data,limit)�ڴ�

	void grow();														// ����������Ϊ2��
	void unchecked_append(const T&);									// �������T��δ��������Ƿ�������
};

template<class T> void Vec<T>::create()
{
	data = limit = avail = NULL;
}

template<class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

template<class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template<class T> void Vec<T>::uncreate()
{
	if (data)
	{
		iterator i = avail;
		while (i != data)
			alloc.destroy(--i);
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = NULL;
}

template<class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

template<class T> void Vec<T>::grow()
{
	size_type new_size = max(2 * (limit - data), (ptrdiff_t)1);

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);
	uncreate();
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template<class T> Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	if (&rhs != this)
	{
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}
#endif