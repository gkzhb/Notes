#ifndef _GUARD_Student_info_h
#define _GUARD_Student_info_h

#include<iostream>
#include<string>
#include<vector>

class Core 
{
	friend class Student_info;

public:
	Core() : midterm(0), final(0) {}
	Core(std::istream& is) { read(is); }
	std::string name() const;
	virtual std::istream& read(std::istream&);		// 从输入流读取数据
	virtual double grade() const;					// 计算成绩
	virtual ~Core() {}
	
protected:
	std::istream& read_common(std::istream&);
	double midterm, final;							// 期中、期末成绩
	std::vector<double> homework;					// 作业成绩
	virtual Core* clone() const { return new Core(*this); }		// 复制自身

private:
	std::string n;		// 记录姓名
};

class Grad :public Core
{
public:
	Grad():thesis(0) {}
	Grad(std::istream& is) { read(is); }
	double grade() const;							// 计算成绩
	std::istream& read(std::istream&);				// 从输入流读取数据

protected:
	Grad * clone() const { return new Grad(*this); }		// 复制自身

private:
	double thesis;									// 论文成绩
};



class Student_info
{
public:
	Student_info() :cp(0) {}
	Student_info(std::istream& is) :cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator =(const Student_info&);
	~Student_info() { delete cp; }

	// 操作
	std::istream& read(std::istream&);

	std::string name() const	// 获取姓名
	{
		if (cp)
			return cp->name();
		else
			throw std::runtime_error("uninitialized Student");
	}

	double grade() const		// 计算成绩
	{
		if (cp)
			return cp->grade();
		else
			throw std::runtime_error("uninitialized Student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2)		// 按姓名排序
	{
		return s1.name() < s2.name();
	}

private:
	Core * cp;
};

#endif
