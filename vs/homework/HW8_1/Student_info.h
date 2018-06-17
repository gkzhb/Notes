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
	virtual std::istream& read(std::istream&);		// ����������ȡ����
	virtual double grade() const;					// ����ɼ�
	virtual ~Core() {}
	
protected:
	std::istream& read_common(std::istream&);
	double midterm, final;							// ���С���ĩ�ɼ�
	std::vector<double> homework;					// ��ҵ�ɼ�
	virtual Core* clone() const { return new Core(*this); }		// ��������

private:
	std::string n;		// ��¼����
};

class Grad :public Core
{
public:
	Grad():thesis(0) {}
	Grad(std::istream& is) { read(is); }
	double grade() const;							// ����ɼ�
	std::istream& read(std::istream&);				// ����������ȡ����

protected:
	Grad * clone() const { return new Grad(*this); }		// ��������

private:
	double thesis;									// ���ĳɼ�
};



class Student_info
{
public:
	Student_info() :cp(0) {}
	Student_info(std::istream& is) :cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator =(const Student_info&);
	~Student_info() { delete cp; }

	// ����
	std::istream& read(std::istream&);

	std::string name() const	// ��ȡ����
	{
		if (cp)
			return cp->name();
		else
			throw std::runtime_error("uninitialized Student");
	}

	double grade() const		// ����ɼ�
	{
		if (cp)
			return cp->grade();
		else
			throw std::runtime_error("uninitialized Student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2)		// ����������
	{
		return s1.name() < s2.name();
	}

private:
	Core * cp;
};

#endif
