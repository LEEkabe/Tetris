#pragma once
#include "firstWindowsProject.h"
#define BLUE_COLOR  RGB(0,0,255)
HBRUSH hbrush = CreateSolidBrush(BLUE_COLOR);
bool falling = false;
class Point {
public:
	Point(int x, int y) { X = x;Y = y; }
	virtual ~Point(){}
	virtual void squaresShow(HDC hdc,int type) = 0;
	virtual void fall(HDC hdc) = 0;
	virtual void right(HDC hdc) = 0;
	virtual void left(HDC hdc) = 0;
	virtual void up(HDC hdc) = 0;
	virtual void down(HDC hdc) = 0;
	int changeType(int type) {
		type = (type == 4) ? type - 3 : type + 1;
		return type;
	}
protected:
	int X, Y;
	const int a = 20, b = 21;
};


//bigsquare
class Bigsquare :public Point
{
public:
	Bigsquare(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc,int type)
	{
		    SelectObject(hdc, hbrush);
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X + a, Y, X + b + a, Y + b);
			Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
	}
	void  fall(HDC hdc) {
		if (falling == true)
			Y = Y + 20;
		else
			return;
			
	}
	void right(HDC hdc) {
		X = X + 20;
		
	}
	void left(HDC hdc) {
		X = X - 20;
		
	}
	void down(HDC hdc) {
		Y = Y + 40;
		
	}
	void up(HDC hdc) {
		if (falling == true)
		{
			Y = Y;
			falling = false;
		}
		else
			Y = Y;
	}
protected:
	int x, y;
};

//stick
class Stick :public Point
{
public:
	Stick(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc,int type)
	{
		SelectObject(hdc, hbrush);
		if (type == 1 || type == 3)
		{
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
			Rectangle(hdc, X, Y + 3 * a, X + b, Y + b + 3 * a);
		}
		else
		{
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X+a, Y , X + b+a, Y + b );
			Rectangle(hdc, X + 2 * a, Y , X + b + 2 * a, Y + b );
			Rectangle(hdc, X + 3 * a, Y , X + b + 3 * a, Y + b );
		}
	}
	void  fall(HDC hdc) {
		if (falling == true)
			Y = Y + 20;
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;
		
	}
	void left(HDC hdc) {
		X = X - 20;
		
	}
	void down(HDC hdc) {
		Y = Y + 40;
		
	}
	void up(HDC hdc) {
		if (falling == true)
		{
			Y = Y;
			falling = false;
		}
		else
			Y = Y;
	}
protected:
	int x, y;
};

//Z
class Z :public Point
{
public:
	Z(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc,int type)
	{
		SelectObject(hdc, hbrush);
		if (type == 1 || type == 3)
		{
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X + a, Y, X + b + a, Y + b);
			Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
			Rectangle(hdc, X + 2 * a, Y + a, X + b + 2 * a, Y + b + a);
		}
		else
		{
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X , Y + a, X + b , Y + b + a);
			Rectangle(hdc, X + a, Y , X + b + a, Y + b );
			Rectangle(hdc, X +  a, Y - a, X + b + a, Y + b - a);
		}
	}
	void  fall(HDC hdc) {
		if (falling == true)
			Y = Y + 20;
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;

	}
	void left(HDC hdc) {
		X = X - 20;

	}
	void down(HDC hdc) {
		Y = Y + 40;

	}
	void up(HDC hdc) {
		if (falling == true)
		{
			Y = Y;
			falling = false;
		}
		else
			Y = Y;
	}
	

protected:
	int x, y;
};


//S
class S :public Point
{
public:
	S(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc,int type)
	{
		SelectObject(hdc, hbrush);
		if (type==1||type==3)
		{
			Rectangle(hdc, X + a, Y, X + b + a, Y + b);
			Rectangle(hdc, X + 2 * a, Y, X + b + 2 * a, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
		}
		else
		{
			Rectangle(hdc, X , Y, X + b , Y + b);
			Rectangle(hdc, X + a, Y+2*a, X + b +  a, Y + b+2*a);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
		}
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;

		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;

	}
	void left(HDC hdc) {
		X = X - 20;

	}
	void down(HDC hdc) {
		Y = Y + 40;

	}
	void up(HDC hdc) {
		if (falling == true)
		{
			Y = Y;
			falling = false;
		}
		else
			Y = Y;
	}
	

protected:
	int x, y;
};




//L
class L :public Point
{
public:
	L(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc,int type)
	{
		SelectObject(hdc, hbrush);
		switch (type)
		{
		case 1:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
			Rectangle(hdc, X + a, Y + 2 * a, X + b + a, Y + b + 2 * a);
			break;
		case 2:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X +  a, Y , X + b + a, Y + b );
			Rectangle(hdc, X +2*a, Y , X + b+2*a , Y + b );
			break;
		case 3:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X+a, Y , X + b+a, Y + b );
			Rectangle(hdc, X+a, Y +  a, X + b+a, Y + b +  a);
			Rectangle(hdc, X + a, Y + 2 * a, X + b + a, Y + b + 2 * a);
			break;
		case 4:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X+a, Y , X + b+a, Y + b );
			Rectangle(hdc, X+2*a, Y , X + b + 2 * a, Y + b );
			Rectangle(hdc, X +2* a, Y - a, X + b +2* a, Y + b - a);
			break;
		default:
			break;
		}
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;

		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;

	}
	void left(HDC hdc) {
		X = X - 20;

	}
	void down(HDC hdc) {
		Y = Y + 40;

	}
	void up(HDC hdc) {
		if (falling == true)
		{
			Y = Y;
			falling = false;
		}
		else
			Y = Y;
	}
	

protected:
	int x, y;
};

//J
class J :public Point
{
public:
	J(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc,int type)
	{
		SelectObject(hdc, hbrush);
		switch (type)
		{
		case 1:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
			Rectangle(hdc, X - a, Y + 2 * a, X + b - a, Y + b + 2 * a);
			break;
		case 2:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X+a, Y +  a, X + b, Y + b +  a);
			Rectangle(hdc, X +2* a, Y + a, X + b +2*a, Y + b +  a);
			break;
		case 3:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X + a, Y , X + b+a, Y + b );
			Rectangle(hdc, X, Y +  a, X + b, Y + b +  a);
			Rectangle(hdc, X , Y + 2 * a, X + b , Y + b + 2 * a);
			break;
		case 4:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X + a, Y, X + b + a, Y + b);
			Rectangle(hdc, X+2*a, Y, X + b+2*a, Y + b);
			Rectangle(hdc, X+2*a, Y +  a, X + b+2*a, Y + b +  a);
			break;
		default:
			break;
		}
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;

		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;

	}
	void left(HDC hdc) {
		X = X - 20;

	}
	void down(HDC hdc) {
		Y = Y + 40;

	}
	void up(HDC hdc) {
		if (falling == true)
		{
			Y = Y;
			falling = false;
		}
		else
			Y = Y;
	}
	

protected:
	int x, y;
};


//T
class T :public Point
{
public:
	T(int x, int y) :Point(x, y) {};

	void squaresShow(HDC hdc,int type)
	{
		SelectObject(hdc, hbrush);
		switch (type)
		{
		case 1:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X + a, Y, X + b + a, Y + b);
			Rectangle(hdc, X + 2 * a, Y, X + b + 2 * a, Y + b);
			Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
			break;
		case 2:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X , Y+a, X + b , Y + b+a);
			Rectangle(hdc, X , Y+2*a, X + b , Y + b+2*a);
			Rectangle(hdc, X - a, Y + a, X + b - a, Y + b + a);
			break;
		case 3:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X+a, Y, X + b+a, Y + b);
			Rectangle(hdc, X + 2 * a, Y , X + b + 2 * a, Y + b );
			Rectangle(hdc, X + a, Y -a, X + b +a, Y + b - a);
			break;
		case 4:
			Rectangle(hdc, X, Y, X + b, Y + b);
			Rectangle(hdc, X, Y + a, X + b, Y + b + a);
			Rectangle(hdc, X, Y + 2 * a, X + b, Y + b + 2 * a);
			Rectangle(hdc, X + a, Y + a, X + b + a, Y + b + a);
			break;
		default:
			break;
		}
	}
	void  fall(HDC hdc) {
		if (falling == true)
		{
			Y = Y + 20;

		}
		else
			return;

	}
	void right(HDC hdc) {
		X = X + 20;

	}
	void left(HDC hdc) {
		X = X - 20;

	}
	void down(HDC hdc) {
		Y = Y + 40;

	}
	void up(HDC hdc) {
		if (falling == true)
		{
			Y = Y;
			falling = false;
		}
		else
			Y = Y;
	}

protected:
	int x, y;
};

