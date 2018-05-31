#ifndef GUARD_Shape_h
#define GUARD_Shape_h

#include<iostream>
#include<math.h>
#define PI 3.1415926
class Shape
{
public:
	virtual double perimeter() const =0;	// ͼ���ܳ�
	virtual double area() const =0;			// ͼ�����
};

class Triangle :public Shape
{
public:
	double perimeter() const { return a + b + c; }
	double area() const
	{
		double p = perimeter()/2.0;
		return std::sqrt(p*(p - a)*(p - b)*(p - c));
	}
	Triangle(std::istream& is) { is >> a >> b >> c; }
private:
	double a, b, c;		// �����������߳�
};

class Rectangle :public Shape
{
public:
	double perimeter() const { return 2 * (a + b); }
	double area() const { return a * b; }
	Rectangle(std::istream& is) { is >> a >> b; }
private:
	double a, b;		// �����εĳ���
};

class Circle :public Shape
{
public:
	double perimeter() const { return 2 * PI * r; }
	double area() const { return PI * r * r; }
	Circle(std::istream& is) { is >> r; }
private:
	double r;			// Բ�İ뾶
};
#endif