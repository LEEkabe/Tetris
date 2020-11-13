#pragma once
#include "firstWindowsProject.h"


class Point {
public:
	Point(int x, int y) { X = x;Y = y; }
	virtual ~Point(){}
	virtual void squaresShow(HDC hdc) = 0;

protected:
	int X, Y;
	const int a = 20, b = 21;
};


//bigsquare
class Bigsquare :public Point
{
public:
	Bigsquare(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
	}
};

//stick
class Stick :public Point
{
public:
	Stick(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
		Rectangle(hdc, X, Y + 3 * a, X + b, Y + b + 3 * a);
	}
};

//Z
class Z :public Point
{
public:
	Z(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
		Rectangle(hdc, X + 2 * a, Y + a, X + b + 2 * a, Y + b + a);
	}
};


//S
class S :public Point
{
public:
	S(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + 2 * a, Y, X + b + 2 * a, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
	}
};




//L
class L :public Point
{
public:
	L(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
		Rectangle(hdc, X + a, Y + 2 * a, X + b + a, Y + b + 2 * a);
	}
};

//J
class J :public Point
{
public:
	J(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
		Rectangle(hdc, X - a, Y + 2 * a, X + b - a, Y + b + 2 * a);
	}
};


//T
class T :public Point
{
public:
	T(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + 2 * a, Y, X + b + 2 * a, Y + b);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
	}
};

