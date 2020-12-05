#pragma once
#include "firstWindowsProject.h"
#define BLUE_COLOR  RGB(0,0,255)
HBRUSH hbrush = CreateSolidBrush(BLUE_COLOR);
bool falling = false;
class Point {
public:
	Point(int x, int y) { X = x;Y = y; }
	virtual ~Point(){}
	virtual void squaresShow(HDC hdc) = 0;
	virtual void fall(HDC hdc) = 0;
	virtual void right(HDC hdc) = 0;
	virtual void left(HDC hdc) = 0;
	virtual void up(HDC hdc) = 0;
	virtual void down(HDC hdc) = 0;
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
		SelectObject(hdc, hbrush);
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;
			squaresShow(hdc);
		}
		else
			return;
			
	}
	void right(HDC hdc) {
		X = X + 20;
		squaresShow(hdc);
	}
	void left(HDC hdc) {
		X = X - 20;
		squaresShow(hdc);
	}
	void down(HDC hdc) {
		Y = Y + 40;
		squaresShow(hdc);
	}
	void up(HDC hdc) {
		falling = false;
	}
protected:
	int x, y;
};

//stick
class Stick :public Point
{
public:
	Stick(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		SelectObject(hdc, hbrush);
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
		Rectangle(hdc, X, Y + 3 * a, X + b, Y + b + 3 * a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;
			squaresShow(hdc);
		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;
		squaresShow(hdc);
	}
	void left(HDC hdc) {
		X = X - 20;
		squaresShow(hdc);
	}
	void down(HDC hdc) {
		Y = Y + 40;
		squaresShow(hdc);
	}
	void up(HDC hdc) {
		falling = false;
	}
protected:
	int x, y;
};

//Z
class Z :public Point
{
public:
	Z(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		SelectObject(hdc, hbrush);
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
		Rectangle(hdc, X + 2 * a, Y + a, X + b + 2 * a, Y + b + a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;
			squaresShow(hdc);
		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;
		squaresShow(hdc);
	}
	void left(HDC hdc) {
		X = X - 20;
		squaresShow(hdc);
	}
	void down(HDC hdc) {
		Y = Y + 40;
		squaresShow(hdc);
	}
	void up(HDC hdc) {
		falling = false;
	}

protected:
	int x, y;
};


//S
class S :public Point
{
public:
	S(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		SelectObject(hdc, hbrush);
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + 2 * a, Y, X + b + 2 * a, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;
			squaresShow(hdc);
		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;
		squaresShow(hdc);
	}
	void left(HDC hdc) {
		X = X - 20;
		squaresShow(hdc);
	}
	void down(HDC hdc) {
		Y = Y + 40;
		squaresShow(hdc);
	}
	void up(HDC hdc) {
		falling = false;
	}

protected:
	int x, y;
};




//L
class L :public Point
{
public:
	L(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		SelectObject(hdc, hbrush);
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
		Rectangle(hdc, X + a, Y + 2 * a, X + b + a, Y + b + 2 * a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;
			squaresShow(hdc);
		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;
		squaresShow(hdc);
	}
	void left(HDC hdc) {
		X = X - 20;
		squaresShow(hdc);
	}
	void down(HDC hdc) {
		Y = Y + 40;
		squaresShow(hdc);
	}
	void up(HDC hdc) {
		falling = false;
	}

protected:
	int x, y;
};

//J
class J :public Point
{
public:
	J(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		SelectObject(hdc, hbrush);
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X, Y + a, X + b, Y + b + a);
		Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
		Rectangle(hdc, X - a, Y + 2 * a, X + b - a, Y + b + 2 * a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;
			squaresShow(hdc);
		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;
		squaresShow(hdc);
	}
	void left(HDC hdc) {
		X = X - 20;
		squaresShow(hdc);
	}
	void down(HDC hdc) {
		Y = Y + 40;
		squaresShow(hdc);
	}
	void up(HDC hdc) {
		falling = false;
	}

protected:
	int x, y;
};


//T
class T :public Point
{
public:
	T(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc)
	{
		SelectObject(hdc, hbrush);
		Rectangle(hdc, X, Y, X + b, Y + b);
		Rectangle(hdc, X + a, Y, X + b + a, Y + b);
		Rectangle(hdc, X + 2 * a, Y, X + b + 2 * a, Y + b);
		Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;
			squaresShow(hdc);
		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;
		squaresShow(hdc);
	}
	void left(HDC hdc) {
		X = X - 20;
		squaresShow(hdc);
	}
	void down(HDC hdc) {
		Y = Y + 40;
		squaresShow(hdc);
	}
	void up(HDC hdc) {
		falling = false;
	}

protected:
	int x, y;
};

