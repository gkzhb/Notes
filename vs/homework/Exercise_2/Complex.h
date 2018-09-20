#ifndef GUARD_Complex_h
#define GUARD_Complex_h

#include<iostream>


class Complex		// 复数
{
	friend std::istream &operator>>(std::istream&, Complex&);		// 从输入流读入复数
	friend std::ostream &operator<<(std::ostream&, const Complex&);		// 将复数输出到输出流
	friend Complex operator-(const Complex&);
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

public:
	Complex() :re(0), im(0) {}
	Complex(double n) :re(n), im(0) {}
	Complex(double real, double imaginary) :re(real), im(imaginary) {}
	Complex operator+=(Complex&);
	Complex operator-=(Complex&);
private:
	double re, im;		// 复数实部与虚部
};

std::istream &operator>>(std::istream&, Complex&);
std::ostream &operator<<(std::ostream&, const Complex&);
Complex operator-(const Complex&);
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
#endif