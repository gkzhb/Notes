#include"Student_info.h"
#include"grade.h"

using std::string;		using std::istream;

/*bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}*/

istream& read_hw(istream& in, std::vector<double>& hw)		// 从输入流读取作业成绩
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}

string Core::name() const
{
	return n;
}
double Core::grade() const
{
	return ::grade(midterm, final, homework);
}
istream& Core::read_common(istream& in)
{
	in >> n >> midterm >> final;
	return in;
}
istream& Core::read(istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

istream& Grad::read(istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}
double Grad::grade() const
{
	return Core::grade() > thesis ? thesis : Core::grade();
}

istream& Student_info::read(istream& is)
{
	delete cp;
	char ch;
	is >> ch;
	if ('U' == ch)
		cp = new Core(is);
	else
		cp = new Grad(is);
	return is;
}
Student_info::Student_info(const Student_info& s) :cp(0)
{
	if (s.cp)
		cp = s.cp->clone();
}
Student_info& Student_info::operator=(const Student_info& s)
{
	if (&s != this)
	{
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}