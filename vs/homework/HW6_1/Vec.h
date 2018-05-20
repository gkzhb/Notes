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
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }		// 构造n个t元素
	Vec(const Vec& v) { create(v.begin(), v.end()); }					// copy constructor
	Vec& operator=(const Vec&);											// 重载赋值运算符
	~Vec() { uncreate(); }
	
	T& operator[](size_type i) { return data[i]; }						// 重载[]
	const T& operator[](size_type i) const {return data[i]; }

	void push_back(const T& t)											// 向容器中添加数据t
	{
		if (avail == limit)
			grow();
		unchecked_append(t);
	}
	void clear() { uncreate(); }										// 清空向量容器
	
	size_type size() const { return avail - data; }						// 返回容器元素个数
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }
	bool empty() const { return data == avail; }						// 判断容器是否为空

private:
	iterator data,avail,limit;											// 数据开头、最后一个已初始化元素后一位、内存最后一个元素后一位

	std::allocator<T> alloc;

	void create();														// 创建空容器
	void create(size_type, const T&);									// 创建多个相同元素的容器
	void create(const_iterator, const_iterator);						// 用其他容器数据创建容器

	void uncreate();													// 删除所有数据并释放[data,limit)内存

	void grow();														// 容器容量变为2倍
	void unchecked_append(const T&);									// 添加数据T（未检查容器是否已满）
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