#define TEST

#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;

typedef unsigned int uint;

map<char, int> TET = {{'I', 0}, {'J', 1}, {'L', 2}, {'O', 3}, {'S', 4}, {'T', 5}, {'Z', 6}}; // tetrominoes

class Line // describe each line of the playing field
{
  public:
	typedef vector<char>::size_type size_type;
	static uint wid; // the width of the playing field
	static void setWidth(uint width) { wid = width; }
	char &operator[](uint n) { return dt[n]; } 
	const char &operator[](uint n) const { return dt[n]; }
	Line() : num(0), dt(wid, 0) {}
	bool isFull() const { return wid == num; }
	vector<char> dt; // describe the state of each square block
	uint num;		 // the number of occupied square block
};
uint Line::wid;

class PlayingField
{
  public:
	typedef vector<Line *>::size_type size_type;
	uint height() { return dt.size(); }
	void push_back(uint n)		// add n new lines
	{
		for (uint i = 0; i < n; i++)
			dt.push_back(new Line());
	}
	void erase(uint n)		// delete Line n
	{
		delete dt[n];
		dt.erase(dt.begin() + n);
	}
	~PlayingField()
	{
		for (uint i = 0; i < dt.size(); i++)
			delete dt[i];
	}
	Line &operator[](uint n) { return *dt[n]; }
	const Line &operator[](uint n) const { return *dt[n]; }
  private:
	vector<Line *> dt;
};


class Shape // describe the shape of tetrominoes
{
  public:
	Shape() {}
	Shape(vector<vector<bool>> shape) : dt(shape) {}
	vector<vector<bool>> dt;
};

class NShape // a better way to describe the shape
{
  public:
	vector<vector<char>> dt;
	NShape() {}
	NShape(const Shape &x)
	{
		int i, j;
		vector<char> tmp;
		width = x.dt[0].size();
		height = x.dt.size();
		for (i = 0; i < x.dt[0].size(); i++)
		{
			dt.push_back(tmp);
			for (j = 0; j < x.dt.size() && x.dt[j][i] == 0; j++)
				;
			dt[i].push_back(char(j));
			for (; j < x.dt.size() && x.dt[j][i] == 1; j++)
				;
			dt[i].push_back(char(j - dt[i][0]));
		}
	}
	uint width, height;
};

Shape shp[7][4]; // shp[Shape][Rotation]
NShape nshp[7][4];

void buildConst()
{
	vector<char> tmp = {0, 1};

	// I
	for (uint i = 0; i < 4; i++)
	{
		nshp[0][0].dt.push_back(tmp);
		nshp[0][3].dt.push_back(tmp);
	}
	tmp[1] = 4;
	nshp[0][1].dt.push_back(tmp);
	nshp[0][3].dt.push_back(tmp);

	// J
	tmp[1] = 2;
	nshp[1][0].dt.push_back(tmp);
	tmp[1] = 1;
	nshp[1][0].dt.push_back(tmp);
	nshp[1][0].dt.push_back(tmp);
	tmp[1] = 3;
	nshp[1][1].dt.push_back(tmp);
	tmp[0] = 2;
	tmp[1] = 1;
	nshp[1][1].dt.push_back(tmp);
	tmp[0] = 1;
	nshp[1][2].dt.push_back(tmp);
	nshp[1][2].dt.push_back(tmp);
	tmp[0] = 0;
	tmp[1] = 2;
	nshp[1][2].dt.push_back(tmp);
	tmp[1] = 1;
	nshp[1][3].dt.push_back(tmp);
	tmp[1] = 3;
	nshp[1][3].dt.push_back(tmp);

	// L
	tmp[1] = 1;
	nshp[2][0].dt.push_back(tmp);
	nshp[2][0].dt.push_back(tmp);
	tmp[1] = 2;
	nshp[2][0].dt.push_back(tmp);
	tmp[1] = 3;
	nshp[2][1].dt.push_back(tmp);
	tmp[1] = 1;
	nshp[2][1].dt.push_back(tmp);
	tmp[1] = 2;
	nshp[2][2].dt.push_back(tmp);
	tmp[0] = 1;
	tmp[1] = 1;
	nshp[2][2].dt.push_back(tmp);
	nshp[2][2].dt.push_back(tmp);
	tmp[0] = 2;
	nshp[2][3].dt.push_back(tmp);
	tmp[0] = 0;
	tmp[1] = 3;
	nshp[2][3].dt.push_back(tmp);

	// O
	tmp[1] = 2;
	nshp[3][0].dt.push_back(tmp);
	nshp[3][0].dt.push_back(tmp);
	nshp[3][1].dt = nshp[3][0].dt;
	nshp[3][2].dt = nshp[3][0].dt;
	nshp[3][3].dt = nshp[3][0].dt;

	// S
	tmp[1] = 1;
	nshp[4][0].dt.push_back(tmp);
	tmp[1] = 2;
	nshp[4][0].dt.push_back(tmp);
	tmp[0] = 1;
	tmp[1] = 1;
	nshp[4][0].dt.push_back(tmp);
	tmp[1] = 2;
	nshp[4][1].dt.push_back(tmp);
	tmp[0] = 0;
	nshp[4][1].dt.push_back(tmp);
	nshp[4][2].dt = nshp[4][0].dt;
	nshp[4][3].dt = nshp[4][1].dt;

	// T
	tmp[1] = 1;
	nshp[5][0].dt.push_back(tmp);
	tmp[1] = 2;
	nshp[5][0].dt.push_back(tmp);
	tmp[1] = 1;
	nshp[5][0].dt.push_back(tmp);
	tmp[1] = 3;
	nshp[5][1].dt.push_back(tmp);
	tmp[0] = 1;
	tmp[1] = 1;
	nshp[5][1].dt.push_back(tmp);
	nshp[5][2].dt.push_back(tmp);
	tmp[0] = 0;
	tmp[1] = 2;
	nshp[5][2].dt.push_back(tmp);
	tmp[0] = 1;
	tmp[1] = 1;
	nshp[5][2].dt.push_back(tmp);
	nshp[5][3].dt.push_back(tmp);
	tmp[0] = 0;
	tmp[1] = 3;
	nshp[5][3].dt.push_back(tmp);

	// Z
	tmp[0] = 1;
	tmp[1] = 1;
	nshp[6][0].dt.push_back(tmp);
	tmp[0] = 0;
	tmp[1] = 2;
	nshp[6][0].dt.push_back(tmp);
	tmp[1] = 1;
	nshp[6][0].dt.push_back(tmp);
	tmp[1] = 2;
	nshp[6][1].dt.push_back(tmp);
	tmp[0] = 1;
	nshp[6][1].dt.push_back(tmp);
	nshp[6][3].dt = nshp[6][1].dt;
	nshp[6][2].dt = nshp[6][0].dt;
}

class Score
{
  public:
	uint getScore() { return data; }
	void clear()
	{ data = 0; }
	void add(uint x)
	{
		switch(x)
		{
		  case 1:
			data += 100;
			break;
		  case 2:
			data += 250;
			break;
		  case 3:
			data += 400;
			break;
		  case 4:
			data += 1000;
		}
	}
  private:
	static uint data;
} pt;	// Score Points
uint Score::data;

void movePosition(PlayingField &a, const NShape *ptr, uint x, uint &y)
{
	bool flag;
	const NShape &s = *ptr;
	while (true)
	{
		flag = true;
		for (uint i = 0; i < ptr->width; i++)
			if ((y + s.dt[i][0] < a.height() && 1 == a[y + s.dt[i][0]][x + i]) || (y + s.dt[i][0] + 1 < a.height() && 1 == a[y + s.dt[i][0] + 1][x + i]))
			{
				flag = false;
				break;
			}
		if (flag)
			break;
		else
			y++;
	}
}

uint putTetromino(PlayingField &a, vector<uint> &h, NShape *ptr, uint x, uint y)
{
	if (a.height() < y + ptr->height)
		a.push_back(y + ptr->height - a.height());
	for (uint i = 0; i < ptr->width; i++)
	{
		h[x + i] = y + ptr->dt[i][0] + ptr->dt[i][1] - 1;
		for (uint j = 0; j < ptr->dt[i][1]; j++)
		{
#ifdef TEST
			if (1 == a[y + ptr->dt[i][0] + j][x + i])
				cout << "ERROR!" << endl;
#endif
			a[y + ptr->dt[i][0] + j][x + i] = 1;
			a[y + ptr->dt[i][0] + j].num ++;
		}
	}
	uint ret = 0;
	for (uint i = 0; i < ptr->height; i++)
		if (a[y + i - ret].isFull())
		{
			a.erase(y + i - ret);
			ret++;
		}
	for (vector<uint>::size_type i = 0; i < h.size(); i++)
	{
		h[i] = h[i] > ret ? h[i] - ret : 0;
		while (h[i] > 0 && 0 == a[h[i]][i])
			h[i]--;
	}
	return ret;
}

void printa(PlayingField &a, vector<uint> &h)
{
	cout << endl;
	PlayingField::size_type i = a.height();
	do
	{
		i--;
		for (Line::size_type j = 0; j < Line::wid; j++)
			cout << int(a[i][j]) << ' ';
		cout << endl;
	} while (0 != i);
	cout << endl;
	for (vector<uint>::size_type j = 0; j < h.size(); j++)
		cout << h[j] << ' ';
	cout << endl;
}

void score(uint width, uint n)
{
	vector<uint> h(width, 0);
	char c;
	NShape *ptr;
	PlayingField a;
	uint pos, rotate, y;
	Line::setWidth(width);
	pt.clear();
	for (uint i = 0; i < n; i++)
	{
		cin >> c >> pos >> rotate;
#ifdef TEST
		cout << c << ' ' << pos << ' ' << rotate << endl;
#endif
		ptr = &nshp[TET[c]][rotate / 90];
		y = h[pos];
		for (uint j = 1; j < ptr->width; j++)
			if (h[pos + j] > y)
				y = h[pos + j];
		y = 0 == y ? 0 : y - 1;
		movePosition(a, ptr, pos, y);
		pt.add(putTetromino(a, h, ptr, pos, y));
#ifdef TEST
		printa(a, h);
#endif
	}
#ifdef TEST
	cout << endl;
#endif
	cout << pt.getScore() << endl;
	for (vector<uint>::size_type i = 0; i < h.size(); i++)
		if (0 != h[i])
			cout << h[i] + 1 << ' ';
		else
			if (0 == a.height() || 0 == a[0][i])
				cout << '0' << ' ';
			else
				cout << '1' << ' ';
	cout << endl;
}

int main(void)
{
	buildConst();
	uint t, width, n;
	std::cin >> t;
	for (uint i = 0; i < t; i++)
	{
		cin >> width >> n;
		cout << "Case #" << i + 1 << ':' << endl;
		score(width, n);
	}
	return 0;
}