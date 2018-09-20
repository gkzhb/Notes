#ifndef GUARD_Table_h
#define GUARD_Table_h

#include <iostream>

class Desktop		// 桌面
{
public:
	Desktop(double l = 0, double w = 0, const char *c = "") :length(l), width(w), color(c) {}
	double getLength() const { return length; }
	double getWidth() const { return width; }
	const char *getColor() const { return color; }

private:
	double length, width;		// 桌面的长和宽
	const char *color;			// 桌面的颜色
};

class Leg			// 桌腿
{
public:
	Leg(double h = 0, const char *c = "") : height(h), color(c) {}
	double getHeight() const { return height; }
	const char *getColor() const { return color; }

private:
	double height;				// 桌腿的高度
	const char *color;			// 桌腿的颜色
};

class Table			// 桌子
{
	friend std::ostream &operator<<(std::ostream &os, const Table &t);
public:
	Table(const Desktop &t, const Leg ls[]);
private:
	Desktop dt;		// 桌子的桌面
	Leg lg[4];		// 桌子的四条桌腿
};

std::ostream &operator<<(std::ostream &os, const Table &t);		// 重载<<

#endif
