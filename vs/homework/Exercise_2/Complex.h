#ifndef GUARD_Complex_h
#define GUARD_Complex_h

#include<iostream>


class Complex		// ����
{
	friend std::istream &operator>>(std::istream&, Complex&);		// �����������븴��
	friend std::ostream &operator<<(std::ostream&, const Complex&);		// ����������������
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
	double re, im;		// ����ʵ�����鲿
};

std::istream &operator>>(std::istream&, Complex&);
std::ostream &operator<<(std::ostream&, const Complex&);
Complex operator-(const Complex&);
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
#endif