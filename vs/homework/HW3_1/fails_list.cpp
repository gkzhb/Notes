#include "Student_info.h"
#include "fails_list.h"

typedef std::list<Student>::iterator iter_s;

bool npass(iter_s x)			// �ж�ѧ���ɼ��Ƿ񲻼���
{
	return x->final < 60.0;
}

std::list<Student> extract_fails(std::list<Student> &x)
{
	std::list<Student> fails;
	iter_s i = x.begin();
	while (i != x.end())
		if (npass(i))		// �ж�ѧ���ɼ��Ƿ񲻼���
		{							// ѧ���ɼ�������
			fails.push_back(*i);
			i = x.erase(i);
		}
		else
			i++;					// ѧ���ɼ����񣬱���
	return fails;
}