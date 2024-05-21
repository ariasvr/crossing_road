#pragma once
#include"header.h"
class people {
private:
	int x;
	int y;
	bool state;
	vector<string> a = {//4,4
		" o",
		"\\|/",
		" |",
		"/|\\"
	};
public:
	void set(int xp, int yp) { x = xp; y = yp; }
	int getx() { return x; }int gety() { return y; }
	void setstate(bool x) { state = x; }bool getstate() { return state; }
	void collisioncar(vector<object*> t)
	{
		for (int i = 0; i < t.size(); i++)
		{
			if (x > t[i]->getx() - 5 && x < t[i]->getx() + 16) { state = 1; break; }			//4 la nguoi, 16 la xe
			else state = 0;
		}
	}
	void collisionplane(vector<object*> t)
	{
		for (int i = 0; i < t.size(); i++)
		{
			if (x > t[i]->getx() - 5 && x < t[i]->getx() + 15) { state = 1; break; }			//4 la nguoi, 15 la may bay
			else state = 0;
		}
	}
	void collisionbee(vector<object*> t)
	{
		for (int i = 0; i < t.size(); i++)
		{
			if (x > t[i]->getx() - 5 && x < t[i]->getx() + 14) { state = 1; break; }			//4 la nguoi, 14 la may bay
			else state = 0;
		}
	}
	void print() {
		for (int i = 0; i < 4; i++) {
			gotoxy(x, 5 * y + 1 + i);
			if (i == 0) { cout << " o"; }
			if (i == 1) { cout << "\\|/"; }
			if (i == 2) { cout << " |"; }
			if (i == 3) { cout << "/|\\"; }
		}
	}
	void movepp(char c)
	{
		switch (c) {
		case 'w': {if (y > 0 && y <= 7)y--; break; }
		case 'a': {if (x > 2 && x <= 106)x--; break; }
		case 's': {if (y >= 0 && y < 7)y++; break; }
		case 'd': {if (x >= 2 && x < 106)x++; break; }
		default: {break; }
		}
	}
	void xoa()
	{
		for (int i = 0; i < 4; i++) {
			gotoxy(x, 5 * y + 1 + i);
			if (i == 0) { cout << "   "; }
			if (i == 1) { cout << "   "; }
			if (i == 2) { cout << "   "; }
			if (i == 3) { cout << "   "; }
		}
	}
	void move(char c) {
		xoa();
		movepp(c);  print();
	}

};