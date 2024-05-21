#include"car.h"
#include"plane.h"
#include"people.h"
#include"bee.h"
#include"object.h"
using std::cout;
mutex m;
bool isrunning = 1; people p;
//bool music = 1;
bool d1 = false; //lane 3
bool d2 = false; //lane 4
bool d3 = false; //lane 1
bool d4 = false; //lane 6
bool d5 = false; //lane 2
bool d6 = false; //lane 5
string name;
int score = 0;
int level = score % 300 + 1;
char c = 0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
LPCTSTR pszSound = TEXT("playing.wav");
bool newgame = 0;
bool loadgame=0;
bool highscore=0;
bool music=0;
bool quit=0;

vector<nguoichoi>player;
mutex m2; 
void exitgame(thread* t) {
	//system("cls");
	isrunning = false;
	t->join();
}

void ThreadFunc(vector<vector<object*>> a) {
	while (isrunning) {
		//…thực hiện in ra màn hình console những đối tượng trong trò chơi
		
		m.lock();

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (isrunning == 1) {
					m2.lock();
					if (p.gety() == 4)
					{
						p.collisioncar(a[1]);
						if (p.getstate() == 1) { system("cls");  /*Sleep(50);*/ isrunning = 0; }

					}//people dang o hang thu 4
					if (p.gety() == 3)
					{
						p.collisioncar(a[0]);
						if (p.getstate() == 1) { system("cls");  /*Sleep(50);*/ isrunning = 0; }

					}//people dang o hang thu 3
					m2.unlock();
				}
				
				//lane34
				if (i == 0 && j < 2 && d3 == true && isrunning == 1){a[i][j]->movephai();}
				else if (i == 1 && d4 == true && isrunning == 1){a[i][j]->movetrai();}
			}
		}

		m.unlock();
		Sleep(50);
	}
	if (p.getstate() == 1) { PlaySound(0,0,0);  printover(music); }
}
void ThreadFunc2(vector<vector<object*>> a) {
	while (isrunning) {
		//…thực hiện in ra màn hình console những đối tượng trong trò chơi

		m.lock();

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (isrunning == 1)
				{
					m2.lock();
					if (p.gety() == 1)
					{
						p.collisionplane(a[0]);
						if (p.getstate() == 1) { system("cls"); isrunning = 0; }

					}//people dang o hang thu 1
					if (p.gety() == 3)
					{
						p.collisionplane(a[1]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 3
					if (p.gety() == 4)
					{
						p.collisioncar(a[2]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 4
					if (p.gety() == 6)
					{
						p.collisioncar(a[3]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 6
					m2.unlock();
				}
				
				//lane1346
				if (i == 0 && j < 2 && d1 == true && isrunning == 1){a[i][j]->movephai();}
				else if (i == 1 && d3 == true && isrunning == 1){a[i][j]->movetrai();}
				else if (i == 2 && d4 == true && isrunning == 1){a[i][j]->movephai();}
				else if (i == 3 && d6 == true && isrunning == 1){a[i][j]->movetrai();}
			}
		}

		m.unlock();
		Sleep(30);
	}
	if (p.getstate() == 1) { PlaySound(0, 0, 0); printover(music); }
}

void ThreadFunc3(vector<vector<object*>> a) {
	while (isrunning) {
		//…thực hiện in ra màn hình console những đối tượng trong trò chơi

		m.lock();

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (isrunning == 1)
				{
					m2.lock();
					if (p.gety() == 1)
					{
						p.collisionplane(a[0]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 1
					if (p.gety() == 2)
					{
						p.collisionbee(a[1]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 2
					if (p.gety() == 3)
					{
						p.collisionbee(a[2]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 3
					if (p.gety() == 4)
					{
						p.collisioncar(a[3]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 4
					if (p.gety() == 5)
					{
						p.collisioncar(a[4]);
						if (p.getstate() == 1) { system("cls");  isrunning = 0; }

					}//people dang o hang thu 5
					if (p.gety() == 6)
					{
						p.collisioncar(a[5]);
						if (p.getstate() == 1) { system("cls"); isrunning = 0; }

					}//people dang o hang thu 6
					m2.unlock();
				}
				
				//lane123456
				if (i == 0 && j < 2 && d1 == true && isrunning == 1){a[i][j]->movephai();}
				else if (i == 1 && d2 == true && isrunning == 1){a[i][j]->movetrai();}
				else if (i == 2 && j < 2 && d3 == true && isrunning == 1){a[i][j]->movephai();}
				else if (i == 3 && d4 == true && isrunning == 1){a[i][j]->movephai();}
				else if (i == 4 && d5 == true && isrunning == 1){a[i][j]->movetrai();}
				else if (i == 5 && j < 2 && d6 == true && isrunning == 1){a[i][j]->movephai();}
			}
		}

		m.unlock();
		Sleep(20);
	}
	if (p.getstate() == 1) { PlaySound(0,0,0); printover(music); }
}
void den1() {//3
	while (isrunning) {
		m.lock();
		if (d1 == true) {
			d1 = false;
			SetConsoleTextAttribute(h, 12);
			gotoxy(112, 7);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		else {
			d1 = true;
			SetConsoleTextAttribute(h, 10);
			gotoxy(112, 7);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		m.unlock();
		Sleep(2000);
	}
}
void den2() {//4
	while (isrunning) {
		m.lock();
		if (d2 == true) {
			d2 = false;
			SetConsoleTextAttribute(h, 12);
			gotoxy(112, 12);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		else {
			d2 = true;
			SetConsoleTextAttribute(h, 10);
			gotoxy(112, 12);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		m.unlock();
		Sleep(4000);
	}
}
void den3() {//1
	while (isrunning) {
		m.lock();
		if (d3 == true) {
			d3 = false;
			SetConsoleTextAttribute(h, 12);
			gotoxy(112, 17);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		else {
			d3 = true;
			SetConsoleTextAttribute(h, 10);
			gotoxy(112, 17);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		m.unlock();
		Sleep(3000);
	}
}
void den4() {//6
	while (isrunning) {
		m.lock();
		if (d4 == true) {
			d4 = false;
			SetConsoleTextAttribute(h, 12);
			gotoxy(112, 22);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		else {
			d4 = true;
			SetConsoleTextAttribute(h, 10);
			gotoxy(112, 22);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		m.unlock();
		Sleep(5000);
	}
}
void den5() {//2
	while (isrunning) {
		m.lock();
		if (d5 == true) {
			d5 = false;
			SetConsoleTextAttribute(h, 12);
			gotoxy(112, 27);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		else {
			d5 = true;
			SetConsoleTextAttribute(h, 10);
			gotoxy(112, 27);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		m.unlock();
		Sleep(1000);
	}
}
void den6() {//5
	while (isrunning) {
		m.lock();
		if (d6 == true) {
			d6 = false;
			SetConsoleTextAttribute(h, 12);
			gotoxy(112, 32);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		else {
			d6 = true;
			SetConsoleTextAttribute(h, 10);
			gotoxy(112, 32);	if (isrunning == 1)cout << (char)219;
			SetConsoleTextAttribute(h, 240);
		}
		m.unlock();
		Sleep(2500);
	}
}




int main()
{
	system("color F0"); bool exit = 0;//bien xac dinh thoat ra man hinh menu
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	Nocursortype();
	int xp = 54, yp = 7; p.set(xp, yp); 
	//mang 2 chieu
	vector<vector<object*>>row34 = {
		{new car(-9,3) ,new car(-58,3)},					//phai
		{new car(150,4),new car(120,4),new car(100,4)}			//trai
	};
	vector<vector<object*>>row1346 = {
		{new plane(-8,1) ,new plane(-38,1),},				//phai
		{new plane(115,3),new plane(140,3),new plane(190,3)},		//trai
		{new car(-5,4) ,new car(-25,4),new car(-65,4)},		//phai
		{new car(110,6) ,new car(145,6),new car(185,6)}		//trai
	};
	vector<vector<object*>>row123456 = {
		{new plane(-8,1) ,new plane(-38,1)},						//phai
		{new bee(115,2),new bee(140,2),new bee(190,2)},				//trai
		{new bee(-5,3) ,new bee(-25,3)},						//phai
		{new car(-20,4) ,new car(-50,4),new car(-80,4)},			//phai
		{new car(110,5) ,new car(145,5),new car(185,5)},			//trai
		{new car(-15,6) ,new car(-50,6)}						//phai
	};

	
	gethighscore(player);						//lay thong tin nhung nguoi choi truoc do, luu vao vector<nguoichoi>player

//---------------------------------------------------------------------------------


	while (1)
	{


		printmenu(c, newgame, loadgame, highscore, music, quit);



		if (newgame == 1)
		{
			
			level = 1; score = 0;
			isrunning = 1;
			//-----
			system("cls");
			char x = 220; char t = 221; char t2 = 222; char x2 = 223;
			gotoxy(55, 20); for (int i = 0; i < 70; i++) { cout << x; }
			for (int i = 0; i < 4; i++) { gotoxy(55, 21 + i); cout << t << "                                                                    " << t2; }
			gotoxy(57, 21 + 1); cout << "Please enter your name: ";
			gotoxy(55, 24); for (int i = 0; i < 70; i++) { cout << x2; }
			gotoxy(82, 21 + 1); cin >> name;							//Enter your name
			system("cls");
			//-------
			
			if(music==1)PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
			if (level == 1) {
				printboard();
				printinf(c);;
				gotoxy(121, 12);  cout << "player: " << name;
				p.print();
				thread t1(ThreadFunc, row34);
				thread t2(den3);
				thread t3(den4);
				while (c = _getch()) {
					if (isrunning == 1) { m.lock(); if (isrunning == 1)p.move(c); m.unlock(); }
					else if (isrunning == 0) { exitgame(&t1); exitgame(&t2); exitgame(&t3);  d3 = d4 = 0; p.set(54, 7); break; }
					if (c == 27)										//bam nut ESC
					{					
						m.lock(); printquit(c, exit); m.unlock();
						if (exit == 1) { PlaySound(0, 0, 0); system("cls"); exitgame(&t1); exitgame(&t2); exitgame(&t3);  d3 = d4 = 0; p.set(54, 7); break; }
					}
					if (c == 'p' || c == 'P')
					{
						m.lock();
						gotoxy(0, 46);
						system("pause");
						m.unlock();
					}
					if (c == 'm' || c == 'M') {
						if (music == 1) { music = 0; PlaySound(0,0,0); }
						else { music = 1; PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
						}
					}
					if (p.gety() == 0)
					{
						m.lock(); p.xoa();
						vector<string> h = {//4,4
								" o",
								"\\|/",
								" |",
								"/|\\"
						};
						score += 100;
						gotoxy(121, 14); cout << "Score: " << score;
						m.unlock();

						if (score % 300 == 0)
						{
							level += 1;
							exitgame(&t1); exitgame(&t2); exitgame(&t3);
							break;
						}
						m.lock();
						if (score == 100 || score == 400 || score == 700)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113, 1 + i); cout << h[i]; }
						}
						if (score == 200 || score == 500 || score == 800)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5, 1 + i); cout << h[i]; }
						}
						if (score == 300 || score == 600 || score == 900)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5 + 5, 1 + i); cout << h[i]; }
						}
						p.set(54, 7); p.print();
						m.unlock();
					}
				}
				system("cls");
			}

			if (level == 2) {
				isrunning = true;
				printboard();
				printinf(c);
				gotoxy(121, 12);  cout << "player: " << name;
				gotoxy(121, 14); cout << "Score: " << score;
				p.set(xp, yp); p.print();
				gotoxy(121, 13);  cout << "Level: " << level;

				thread t1(ThreadFunc2, row1346);
				thread t2(den1);
				thread t3(den3);
				thread t4(den4);
				thread t5(den6);
				//thread t6(den5);
				//thread t7(den6);
				c = 's';
				while (c = _getch()) {
					if (isrunning == 1) { m.lock(); if (isrunning == 1)p.move(c); m.unlock(); }
					else if (isrunning == 0) { exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);  d1 = d3 = d4 = d6 = 0; p.set(54, 7); break; }
					if (c == 27)										//bam nut ESC
					{
						m.lock(); printquit(c, exit); m.unlock();
						if (exit == 1) { PlaySound(0, 0, 0); system("cls"); exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);  d1 = d3 = d4 = d6 = 0; p.set(54, 7); break; }
					}
					if (c == 'p' || c == 'P')
					{
						m.lock();
						gotoxy(0, 46);
						system("pause");
						m.unlock();
					}
					if (c == 'm' || c == 'M') {
						if (music == 1) { music = 0; PlaySound(0, 0, 0); }
						else {
							music = 1; PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
						}
					}
					if (p.gety() == 0)
					{
						m.lock(); p.xoa();
						vector<string> h = {//4,4
								" o",
								"\\|/",
								" |",
								"/|\\"
						};
						score += 100;
						gotoxy(121, 14); cout << "Score: " << score;
						m.unlock();
						if (score % 300 == 0)
						{
							level += 1;
							exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);
							break;
						}
						m.lock();

						if (score == 100 || score == 400 || score == 700)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113, 1 + i); cout << h[i]; }
						}
						if (score == 200 || score == 500 || score == 800)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5, 1 + i); cout << h[i]; }
						}
						if (score == 300 || score == 600 || score == 900)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5 + 5, 1 + i); cout << h[i]; }
						}
						p.set(54, 7); p.print();
						m.unlock();
					}
				}
				system("cls");
			}

			if (level == 3) {
				isrunning = true;
				printboard();
				printinf(c);
				gotoxy(121, 12);  cout << "player: " << name;
				gotoxy(121, 14); cout << "Score: " << score;
				p.set(xp, yp); p.print();
				gotoxy(121, 13);  cout << "Level: " << level;

				thread t1(ThreadFunc3, row123456);
				thread t2(den1);
				thread t3(den2);
				thread t4(den3);
				thread t5(den4);
				thread t6(den5);
				thread t7(den6);
				c = 0;
				while (c = _getch()) {
					if (isrunning == 1) { m.lock(); if (isrunning == 1)p.move(c); m.unlock(); }
					else if (isrunning == 0) { exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5); exitgame(&t6); exitgame(&t7);  d1 = d2 = d3 = d4 = d5 = d6 = 0; p.set(54, 7); break; }
					if (c == 27)										//bam nut ESC
					{
						m.lock(); printquit(c, exit); m.unlock();
						if (exit == 1) { PlaySound(0, 0, 0); system("cls"); exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);  exitgame(&t6); exitgame(&t7); ; d1 = d2 = d3 = d4 = d5 = d6 = 0; p.set(54, 7); break; }
					}
					if (c == 'p' || c == 'P')
					{
						m.lock();
						gotoxy(0, 46);
						system("pause");
						m.unlock();
					}
					if (c == 'm' || c == 'M') {
						if (music == 1) { music = 0; PlaySound(0, 0, 0); }
						else {
							music = 1; PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
						}
					}
					if (p.gety() == 0)
					{
						m.lock(); p.xoa();
						vector<string> h = {//4,4
								" o",
								"\\|/",
								" |",
								"/|\\"
						};
						score += 100;
						gotoxy(121, 14); cout << "Score: " << score;
						m.unlock();

						if (score % 300 == 0)
						{
							level += 1;
							exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5); exitgame(&t6); exitgame(&t7);
							break;
						}
						m.lock();
						if (score == 100 || score == 400 || score == 700)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113, 1 + i); cout << h[i]; }
						}
						if (score == 200 || score == 500 || score == 800)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5, 1 + i); cout << h[i]; }
						}
						if (score == 300 || score == 600 || score == 900)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5 + 5, 1 + i); cout << h[i]; }
						}
						p.set(xp, yp); p.print();
						m.unlock();
					}
				}
				system("cls");
			}
			if (level == 4) { PlaySound(0,0,0); printwin(music); }
			newgame = 0;
			//Cap nhat thong tin nguoi choi moi o phan Newgame
			nguoichoi moi = { name,score,level };
			newhighscore(moi, player);
		}
		if (highscore == 1)
		{
			printhighscore(player);
			system("cls");
			highscore = 0;
		}

		if (loadgame == 1)
		{
			
			isrunning = 1;
			//-----
			system("cls");
			char x = 220; char t = 221; char t2 = 222; char x2 = 223;
			gotoxy(55, 20); for (int i = 0; i < 70; i++) { cout << x; }
			for (int i = 0; i < 4; i++) { gotoxy(55, 21 + i); cout << t << "                                                                    " << t2; }
			gotoxy(57, 21 + 1); cout << "Please enter your name: ";
			gotoxy(55, 24); for (int i = 0; i < 70; i++) { cout << x2; }
			gotoxy(82, 21 + 1); cin >> name;							//Enter your name

			for (int i = 0; i < player.size(); i++)
			{
				if (name == player[i].name) { level = player[i].level; score = player[i].score; break; }
			}
			system("cls");
			//-------

			if (music == 1)PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
			if (level == 1) {
				printboard();
				printinf(c);;
				gotoxy(121, 12);  cout << "player: " << name;
				p.print();
				thread t1(ThreadFunc, row34);
				thread t2(den3);
				thread t3(den4);
				while (c = _getch()) {
					if (isrunning == 1) { m.lock(); if (isrunning == 1)p.move(c); m.unlock(); }
					else if (isrunning == 0) { exitgame(&t1); exitgame(&t2); exitgame(&t3);  d3 = d4 = 0; p.set(54, 7); break; }
					if (c == 27)										//bam nut ESC
					{
						m.lock(); printquit(c, exit); m.unlock();
						if (exit == 1) { PlaySound(0, 0, 0); system("cls"); exitgame(&t1); exitgame(&t2); exitgame(&t3);  d3 = d4 = 0;  p.set(54, 7); break; }
					}
					if (c == 'p' || c == 'P')
					{
						m.lock();
						gotoxy(0, 46);
						system("pause");
						m.unlock();
					}
					if (c == 'm' || c == 'M') {
						if (music == 1) { music = 0; PlaySound(0, 0, 0); }
						else {
							music = 1; PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
						}
					}
					if (p.gety() == 0)
					{
						m.lock(); p.xoa();
						vector<string> h = {//4,4
								" o",
								"\\|/",
								" |",
								"/|\\"
						};
						score += 100;
						gotoxy(121, 14); cout << "Score: " << score;
						m.unlock();

						if (score % 300 == 0)
						{
							level += 1;
							exitgame(&t1); exitgame(&t2); exitgame(&t3);
							break;
						}
						m.lock();
						if (score == 100 || score == 400 || score == 700)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113, 1 + i); cout << h[i]; }
						}
						if (score == 200 || score == 500 || score == 800)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5, 1 + i); cout << h[i]; }
						}
						if (score == 300 || score == 600 || score == 900)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5 + 5, 1 + i); cout << h[i]; }
						}
						p.set(54, 7); p.print();
						m.unlock();
					}
				}
				system("cls");
			}

			if (level == 2) {
				isrunning = true;
				printboard();
				printinf(c);
				gotoxy(121, 12);  cout << "player: " << name;
				gotoxy(121, 14); cout << "Score: " << score;
				p.set(xp, yp); p.print();
				gotoxy(121, 13);  cout << "Level: " << level;

				thread t1(ThreadFunc2, row1346);
				thread t2(den1);
				thread t3(den3);
				thread t4(den4);
				thread t5(den6);
				//thread t6(den5);
				//thread t7(den6);
				c = 's';
				while (c = _getch()) {
					if (isrunning == 1) { m.lock(); if (isrunning == 1)p.move(c); m.unlock(); }
					else if (isrunning == 0) { exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);  d1 = d3 = d4 = d6 = 0; p.set(54, 7); break; }
					if (c == 27)										//bam nut ESC
					{
						m.lock(); printquit(c, exit); m.unlock();
						if (exit == 1) { PlaySound(0, 0, 0); system("cls"); exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);  d1 = d3 = d4 = d6 = 0; p.set(54, 7); break; }
					}
					if (c == 'p' || c == 'P')
					{
						m.lock();
						gotoxy(0, 46);
						system("pause");
						m.unlock();
					}
					if (c == 'm' || c == 'M') {
						if (music == 1) { music = 0; PlaySound(0, 0, 0); }
						else {
							music = 1; PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
						}
					}
					if (p.gety() == 0)
					{
						m.lock(); p.xoa();
						vector<string> h = {//4,4
								" o",
								"\\|/",
								" |",
								"/|\\"
						};
						score += 100;
						gotoxy(121, 14); cout << "Score: " << score;
						m.unlock();
						if (score % 300 == 0)
						{
							level += 1;
							exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);
							break;
						}
						m.lock();

						if (score == 100 || score == 400 || score == 700)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113, 1 + i); cout << h[i]; }
						}
						if (score == 200 || score == 500 || score == 800)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5, 1 + i); cout << h[i]; }
						}
						if (score == 300 || score == 600 || score == 900)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5 + 5, 1 + i); cout << h[i]; }
						}
						p.set(54, 7); p.print();
						m.unlock();
					}
				}
				system("cls");
			}

			if (level == 3) {
				isrunning = true;
				printboard();
				printinf(c);
				gotoxy(121, 12);  cout << "player: " << name;
				gotoxy(121, 14); cout << "Score: " << score;
				p.set(xp, yp); p.print();
				gotoxy(121, 13);  cout << "Level: " << level;

				thread t1(ThreadFunc3, row123456);
				thread t2(den1);
				thread t3(den2);
				thread t4(den3);
				thread t5(den4);
				thread t6(den5);
				thread t7(den6);
				c = 0;
				while (c = _getch()) {
					if (isrunning == 1) { m.lock(); if (isrunning == 1)p.move(c); m.unlock(); }
					else if (isrunning == 0) { exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5); exitgame(&t6); exitgame(&t7); d1 = d2 = d3 = d4 = d5 = d6 = 0; p.set(54, 7); break; }
					if (c == 27)										//bam nut ESC
					{
						m.lock(); printquit(c, exit); m.unlock();
						if (exit == 1) { PlaySound(0, 0, 0); system("cls"); exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5);  exitgame(&t6); exitgame(&t7); d1 = d2 = d3 = d4 = d5 = d6 = 0; p.set(54, 7);break; }
					}
					if (c == 'p' || c == 'P')
					{
						m.lock();
						gotoxy(0, 46);
						system("pause");
						m.unlock();
					}
					if (c == 'm' || c == 'M') {
						if (music == 1) { music = 0; PlaySound(0, 0, 0); }
						else {
							music = 1; PlaySound(pszSound, NULL, SND_ASYNC | SND_LOOP);
						}
					}
					if (p.gety() == 0)
					{
						m.lock(); p.xoa();
						vector<string> h = {//4,4
								" o",
								"\\|/",
								" |",
								"/|\\"
						};
						score += 100;
						gotoxy(121, 14); cout << "Score: " << score;
						m.unlock();

						if (score % 300 == 0)
						{
							level += 1;
							exitgame(&t1); exitgame(&t2); exitgame(&t3); exitgame(&t4); exitgame(&t5); exitgame(&t6); exitgame(&t7);
							break;
						}
						m.lock();
						if (score == 100 || score == 400 || score == 700)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113, 1 + i); cout << h[i]; }
						}
						if (score == 200 || score == 500 || score == 800)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5, 1 + i); cout << h[i]; }
						}
						if (score == 300 || score == 600 || score == 900)
						{
							for (int i = 0; i < 4; i++) { gotoxy(113 + 5 + 5, 1 + i); cout << h[i]; }
						}
						p.set(xp, yp); p.print();
						m.unlock();
					}
				}
				system("cls");
			}
			if (level == 4) { PlaySound(0,0,0); printwin(music); }
			//cap nhat
			for (int i = 0; i < player.size(); i++)
			{
				if (name == player[i].name) { player[i].level = level; player[i].score = score; }
			}
			sort(player.begin(), player.end(), compare);
			fstream f; f.open("luu.txt", ios::out);
			for (int i = 0; i < player.size(); i++) {
				f << player[i].name << "-" << player[i].score << "-" << player[i].level;
				if (i != player.size() - 1)f << endl;
			}
			f.close();

			loadgame = 0;
		}
		if (quit == 1) { break; }
	}


	system("cls");
	gotoxy(0,1); cout << "END!";

	//Giai phong vung nho
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0&&j<2||i==1)
			{
				delete row34[i][j];
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j < 2 || i == 1 || i == 2 || i == 3)
			{
				delete row1346[i][j];
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j < 2 || i == 1 || i == 2 && j < 2 || i == 3 || i == 4 || i == 5 && j < 2)
			{
				delete row123456[i][j];
			}
		}
	}
}
