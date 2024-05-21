#pragma once
#include"header.h"
class object
{
public:
	virtual int getx() = 0;
	virtual int gety() = 0;
	virtual void print() = 0;
	virtual void xoa() = 0;
	virtual void print2() = 0;
	virtual void xoa2() = 0;
	virtual void  moveright() = 0;
	virtual void  moveleft() = 0;
	virtual void  movephai() = 0;
	virtual void  movetrai() = 0;
};