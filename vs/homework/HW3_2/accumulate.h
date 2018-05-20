#ifndef GUARD_accumulate_h
#define GUARD_accumulate_h

template <class T,class In>
void accumulate(In begin, In end,T &ans)	// 累加[begin,end)之间迭代器所指向的数据
{
	for (In i = begin; i != end; i++)
		ans += *i;							// 累加T类型变量
}
#endif