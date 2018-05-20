#ifndef GUARD_max_min_element_h
#define GUARD_max_min_element_h

template <class In>
In max_element(In begin, In end)	// Ѱ�����ֵ��Ӧ������
{
	In i = begin, j = begin;		// j ��¼�������Ӧ������
	for (i++; i != end; i++)
		if (*i > *j)
			j = i;
	return j;
}

template <class In>
In min_element(In begin, In end)	// Ѱ����Сֵ��Ӧ������
{
	In i = begin, j = begin;		// j ��¼��С����Ӧ������
	for (i++; i != end; i++)
		if (*i < *j)
			j = i;
	return j;
}
#endif