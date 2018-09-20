#include"Complex.h"
#include<stdexcept>

using std::istream;		using std::ostream;
istream &operator>>(istream &in, Complex &x)
{
	in >> x.re >> x.im;
	return in;
}
ostream &operator<<(ostream &out, const Complex &x)
{
	if (x.re&&x.im)
	{
		out << '(' << x.re;
		if (x.im < 0)
			out << x.im << 'i';
		else
			if (1 != x.im)
				out << '+' << x.im << 'i';
			else
				out << '+' << 'i';
		out << ')';
	}
	else
		if (x.re)
			out << x.re;
		else
			if (0==x.im)
				out << 0;
			else
				if (1 != x.im)
					out << x.im << 'i';
				else
					out << 'i';
		

	return out;
}

Complex operator-(const Complex &x)
{
	return Complex(-x.re,-x.im);
}
Complex Complex::operator+=(Complex &x)
{
	re += x.re;
	im += x.im;
	return *this;
}
Complex Complex::operator-=(Complex &x)
{
	re -= x.re;
	im -= x.im;
	return *this;
}
Complex operator+(const Complex &x, const Complex &y)
{
	return Complex(x.re + y.re, x.im + y.im);
}
Complex operator-(const Complex &x, const Complex &y)
{
	return x + (-y);
}
Complex operator*(const Complex &x, const Complex &y)
{
	return Complex(x.re*y.re - x.im*y.im, x.re*y.im + x.im*y.re);
}
Complex operator/(const Complex &x, const Complex &y)
{
	double tmp = y.re*y.re + y.im*y.im;
	if (0 == tmp)
		throw std::runtime_error("Divide ZERO!");
	return Complex((x.re*y.re + x.im*y.im) / tmp, (x.im*y.re - x.re*y.im) / tmp);
}