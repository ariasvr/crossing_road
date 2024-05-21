#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<conio.h>
#include<time.h>
#include<thread>
#include<mutex>
#include<fstream>
#include<algorithm>
using namespace std;
void gotoxy(int x, int y);
void Nocursortype();
void printboard();
void printinf(char c);
void movemenu(char c, int& y);
void movemusic(char c, bool& music);
void printmusic(char c, bool& music);
void printmenu(char c, bool& newgame, bool& loadgame, bool& highscoregame, bool& music, bool& quit);
void printquit(char c, bool& exit);
void printover(bool& music);
void printwin(bool& music);
struct nguoichoi
{
	string name;
	int score;
	int level;
};
bool compare(const nguoichoi& a, const nguoichoi& b);
void newhighscore(nguoichoi temp,vector<nguoichoi>&player);
void gethighscore(vector<nguoichoi>&player);
void printhighscore(vector<nguoichoi>& player);




