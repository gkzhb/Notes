#ifndef GUARD_Shape_h
#define GUARD_Shape_h

#include<iostream>
#include<math.h>
#define PI 3.1415926
class Shape
{
public:
	virtual double perimeter() const =0;	// 图形周长
	virtual double area() const =0;			// 图形面积
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
	double a, b, c;		// 三角形三条边长
};

class Rectangle :public Shape
{
public:
	double perimeter() const { return 2 * (a + b); }
	double area() const { return a * b; }
	Rectangle(std::istream& is) { is >> a >> b; }
private:
	double a, b;		// 长方形的长宽
};

class Circle :public Shape
{
public:
	double perimeter() const { return 2 * PI * r; }
	double area() const { return PI * r * r; }
	Circle(std::istream& is) { is >> r; }
private:
	double r;			// 圆的半径
};
#endif