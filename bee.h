#pragma once
#include"header.h"
#include"object.h"
class bee :public object
{
private:
	int x;
	int y;
	vector<string> a = {//5,14
		"     _   _",
		"    ( \\ | )",
		"    _',\\|/ //",
		"-=((()(_)('')",
		"       //>"
	};
public:
	bee(int a, int b) { x = a; y = b; }
	void set(int xm, int ym) { x = xm; y = ym; }
	int getx() { return x; }int gety() { return y; }

	void print() {
		for (int i = 0; i < 5; i++) {
			gotoxy(x, 5 * y + 1 + i);
			if (i == 0) { cout << "     _   _"; }
			if (i == 1) { cout << "    ( \\ | )"; }
			if (i == 2) { cout << "    _',\\|/ //"; }
			if (i == 3) { cout << "-=((()(_)('')"; }
			if (i == 4) { cout << "_______//>"; }
		}
	}
	void xoa() {
		for (int i = 0; i < 5; i++) {
			gotoxy(x, 5 * y + 1 + i);
			if (i == 0) { cout << "          "; }
			if (i == 1) { cout << "            "; }
			if (i == 2) { cout << "              "; }
			if (i == 3) { cout << "             "; }
			if (i == 4) { cout << "__________"; }
		}
	}
	void print2() {
		for (int i = 0; i < 5; i++) {
			gotoxy(x, 5 * y + 1 + i);
			if (i == 0) { cout << "   _   _"; }
			if (i == 1) { cout << "  ( | / )"; }
			if (i == 2) { cout << "\\\\ \\\|/,'_"; }
			if (i == 3) { cout << "('')(_)()))=-"; }
			if (i == 4) { cout << "___<\\\\"; }
		}
	}
	void xoa2() {
		for (int i = 0; i < 5; i++) {
			gotoxy(x, 5 * y + 1 + i);
			if (i == 0) { cout << "        "; }
			if (i == 1) { cout << "         "; }
			if (i == 2) { cout << "             "; }
			if (i == 3) { cout << "             "; }
			if (i == 4) { cout << "________"; }
		}
	}
	void moveright() {
		x += 1;
		if (x > 110 - 16)x = 1 - 16;
	}
	void moveleft() {
		x -= 1;
		if (x < 0 + 16)x = 110 - 16 + 16 + 16;
	}

	void movephai() {
		if (x > 0 && x < 110 - 16)xoa(); moveright(); if (x > 0 && x < 110 - 16)print();
	}
	void movetrai() {
		if (x > 0 && x < 110 - 16)xoa2(); moveleft(); if (x > 0 && x < 110 - 16)print2();
	}
};