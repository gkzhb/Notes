#ifndef GUARD_accumulate_h
#define GUARD_accumulate_h

template <class T,class In>
void accumulate(In begin, In end,T &ans)	// �ۼ�[begin,end)֮���������ָ�������
{
	for (In i = begin; i != end; i++)
		ans += *i;							// �ۼ�T���ͱ���
}
#endif