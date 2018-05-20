#ifndef GUARD_max_min_element_h
#define GUARD_max_min_element_h

template <class In>
In max_element(In begin, In end)	// 寻找最大值对应迭代器
{
	In i = begin, j = begin;		// j 记录最大数对应迭代器
	for (i++; i != end; i++)
		if (*i > *j)
			j = i;
	return j;
}

template <class In>
In min_element(In begin, In end)	// 寻找最小值对应迭代器
{
	In i = begin, j = begin;		// j 记录最小数对应迭代器
	for (i++; i != end; i++)
		if (*i < *j)
			j = i;
	return j;
}
#endif