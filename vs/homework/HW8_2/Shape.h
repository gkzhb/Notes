#ifndef GUARD_Shape_h
#define GUARD_Shape_h
#include<iostream>
#include<math.h>
#define PI 3.1415926
class shape_base							// ����
{
	friend class Shape;
public:
	virtual double perimeter() const =0;	// ͼ���ܳ�
	virtual double area() const =0;			// ͼ�����
	virtual ~shape_base() {}
	virtual bool valid()=0;						// �ж�ͼ����Ч
protected:
	virtual shape_base* clone() const=0;		// ��������
};

class Triangle :public shape_base					// ������
{
public:
	double perimeter() const { return a + b + c; }
	double area() const
	{
		double p = perimeter()/2.0;
		return std::sqrt(p*(p - a)*(p - b)*(p - c));
	}
	Triangle(std::istream& is) { is >> a >> b >> c; }
	bool valid() { return a + b > c&&b + c > a&&c + a > b; }
	//~Triangle() {}
	
protected:
	Triangle * clone() const { return new Triangle(*this); }

private:
	double a, b, c;		// �����������߳�
};

class Rectangle :public shape_base					// ����
{
public:
	double perimeter() const { return 2 * (a + b); }
	double area() const { return a * b; }
	Rectangle(std::istream& is) { is >> a >> b; }
	bool valid() { return a > 0 && b > 0; }
	//~Rectangle() {}

protected:
	Rectangle * clone() const { return new Rectangle(*this); }

private:
	double a, b;		// �����εĳ���
};

class Circle :public shape_base						// Բ
{
public:
	double perimeter() const { return 2 * PI * r; }
	double area() const { return PI * r * r; }
	Circle(std::istream& is) { is >> r; }
	bool valid() { return r > 0; }

protected:
	Circle * clone() const { return new Circle(*this); }

private:
	double r;			// Բ�İ뾶
};

class Shape							// ������� ͼ��
{
public:
	Shape() :sp(0) {}
	Shape(std::istream& is) { read(is); }
	~Shape() { delete(sp); }
	Shape operator=(Shape&);

	double perimeter() const 							// �ܳ�
	{ 
		if (sp)
			return sp->perimeter();
		else
			throw std::runtime_error("Empty Shape!");
	}
	double area() const									// ���
	{ 
		if (sp)
			return sp->area();
		else
			throw std::runtime_error("Empty Shape!");
	}					
	bool valid() const									// �ж�ͼ����Ч
	{ 
		if (sp)
			return sp->valid();
		else
			return false;
	}					
	std::istream& read(std::istream& is);

private:
	shape_base * sp;	// shape_base pointer
};
#endif