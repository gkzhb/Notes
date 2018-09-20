#include<iostream>
#include<vector>
#include<string>
#include<iomanip>//setprecision(n)
#include<ios>//streamsize
#include<stdexcept>
#include<algorithm>//sort

//计算家庭作业向量中的中值
double median(std::vector<double> vec)
{
	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");
	std::sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
//根据比例计算总成绩 
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
//依据一个学生所有成绩返回计算总成绩 
double grade(double midterm, double final, const std::vector<double>& hw){

	if (hw.size() == 0)
		throw std::domain_error("strdent has done no homework");
	return grade(midterm, final, median(hw));
}
//读入一个学生的家庭作业
std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	std::cout << "请逐个输入该学生的家庭作业成绩：";
	if (in)
	{
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

class Core {
public:
	Core() :midterm(0), final(0) {
		std::cout << "<<<Core默认构造函数！>>>" << std::endl;
	}
	Core(std::istream& is) {
		read(is);
		std::cout << "<<<Core输入构造函数！>>>" << std::endl;
	}
	virtual ~Core() {
		std::cout << "<<<Core虚拟析构函数！>>>" << std::endl;
	}
	std::string name() const { return n; }//read name
	virtual std::istream& read(std::istream& in) {
		std::cout << "<<<Core.read>>>" << std::endl;
		read_common(in);
		read_hw(in, homework);
		return in;
	}
	virtual double grade() const {
		std::cout << "<<<Core.grade>>>" << std::endl;
		return ::grade(midterm, final, homework);
	}
	friend class Student_info;
protected:
	std::istream& read_common(std::istream& in) {
		//读出学生的姓名与考试成绩并储存起来
		std::cout << "<<<Core.read_common>>>" << std::endl;
		in >> n >> midterm >> final;
		return in;
	}
	double midterm, final;
	std::vector<double> homework;
	virtual Core* clone() const {
		return new Core(*this);
	}
private:
	std::string n;//name
};

class Grad :public Core {
public:
	Grad() :thesis(0) {
		std::cout << "<<<Grad默认构造函数！>>>" << std::endl;
	}
	Grad(std::istream& is) {
		std::cout << "<<<Grad输入构造函数！>>>" << std::endl;
		read(is);
	}
	double grade() const {
		std::cout << "<<<Grad.grade>>>" << std::endl;
		if (thesis == -1) {
			std::cout << "没有论文成绩！" << std::endl;
			return Core::grade();
		}
		return Core::grade() + thesis;
	}
	std::istream& read(std::istream& in) {
		std::cout << "<<<Grad.read>>>" << std::endl;
		read_common(in);
		in >> thesis;
		read_hw(in, homework);
		return in;
	}
private:
	double thesis;
	Grad* clone() const{
		return new Grad(*this);
	}
};

class Student_info {
public:
	//constructor and replicating function
	Student_info() :cp(0) {
		std::cout << "<<<Student_info默认构造函数！>>>" << std::endl;
	}
	Student_info(std::istream& is) :cp(0) {
		std::cout << "<<<Student_info输入构造函数！>>>" << std::endl;
	}
	Student_info(const Student_info& s) :cp(0) {
		if (s.cp) cp = s.cp->clone();
	}
	Student_info& operator=(const Student_info& s) {
		if (&s != this) {
			delete cp;
			if (s.cp)
				cp = s.cp->clone();
			else
				cp = 0;
		}
		return *this;
	}
	~Student_info() {
		std::cout << "<<<Student默认析构函数！>>>" << std::endl;
		delete cp;
	}
	std::istream& read(std::istream& is) {
		delete cp;
		char ch;
		std::cout << "Press 'u' or 'U' to input university student's data, else postgraduate's" << std::endl;
		is >> ch;
		if (ch == 'U') {
			cp = new Core(is);
		}
		else {
			cp = new Grad(is);
		}
		return is;
	}

	std::string name() const {
		std::cout << "<<<Student_info.name()>>>" << std::endl;
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized Students");
	}
	double grade() const {
		std::cout << "<<<Student_info.grade()>>>" << std::endl;
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized Students");
	}
	static bool compare(const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}
private:
	Core * cp;
};

bool compare_name(const Core& c1, const Core& c2){
	return c1.name() < c2.name();
}
bool compare_grades(const Core& c1, const Core& c2) {
	return c1.grade() < c2.grade();
}
bool compare_name_ptrs(const Core*cp1, const Core*cp2) {
	return compare_name(*cp1, *cp2);
}


int main() {
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;
	//read and store data
	while (record.read(std::cin)) {
		if (record.name().size() > maxlen)
			maxlen = record.name().size();
		students.push_back(record);
	}
	//sort
	std::sort(students.begin(), students.end(), Student_info::compare);
	//output students' name and grade
	for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		std::cout << std::setw(maxlen + 1) << students[i].name();
		try {
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade << std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
