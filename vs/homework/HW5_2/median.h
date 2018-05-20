#ifndef GUARD_median_h
#define GUARD_median_h

// `median.h'--final version
#include <algorithm>
#include <stdexcept>

template <class T>		// Ä£°åº¯Êýmedian¼ÆËã
T median(const std::vector<T> vec_ori)
{
	typedef vector<T>::size_type vec_sz;
	std::vector<T> vec(vec_ori);

	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

#endif

