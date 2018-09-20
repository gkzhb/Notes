#ifndef GUARD_Table_h
#define GUARD_Table_h

#include <iostream>

class Desktop		// ����
{
public:
	Desktop(double l = 0, double w = 0, const char *c = "") :length(l), width(w), color(c) {}
	double getLength() const { return length; }
	double getWidth() const { return width; }
	const char *getColor() const { return color; }

private:
	double length, width;		// ����ĳ��Ϳ�
	const char *color;			// �������ɫ
};

class Leg			// ����
{
public:
	Leg(double h = 0, const char *c = "") : height(h), color(c) {}
	double getHeight() const { return height; }
	const char *getColor() const { return color; }

private:
	double height;				// ���ȵĸ߶�
	const char *color;			// ���ȵ���ɫ
};

class Table			// ����
{
	friend std::ostream &operator<<(std::ostream &os, const Table &t);
public:
	Table(const Desktop &t, const Leg ls[]);
private:
	Desktop dt;		// ���ӵ�����
	Leg lg[4];		// ���ӵ���������
};

std::ostream &operator<<(std::ostream &os, const Table &t);		// ����<<

#endif
