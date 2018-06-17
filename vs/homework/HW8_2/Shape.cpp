#include"Shape.h"
std::istream& Shape::read(std::istream& is)
{
	char type;
	is >> type;
	delete sp;
	sp = NULL;
	switch (type)
	{
	case 'T':sp = new Triangle(is); break;
	case 'R':sp = new Rectangle(is); break;
	case 'C':sp = new Circle(is);
	}
	return is;
}

Shape Shape::operator=(Shape& rhs)		// ÖØÔØ¸³ÖµÔËËã
{
	delete this;
	if (rhs.sp)
		sp = rhs.sp->clone();
	else
		sp = NULL;
	return *this;
}