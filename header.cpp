#include"header.h"

void gotoxy(int x, int y) {
	COORD coord; coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void gethighscore(vector<nguoichoi>& player)									//doc file, laythongtinplayer
{
	player.resize(0);
	fstream f;	nguoichoi temp;
	f.open("luu.txt", ios::in);
	while (!f.eof()) {
		getline(f, temp.name, '-');
		f >> temp.score; temp.score;
		f >> temp.level; temp.level *= -1;
		f.ignore();
		player.push_back(temp);
	}
	f.close();
}

void newhighscore(nguoichoi temp, vector<nguoichoi>& player)					//xuat file
{
	player.push_back(temp); sort(player.begin(), player.end(), compare);
	fstream f; f.open("luu.txt", ios::out);
	for (int i = 0; i < player.size(); i++) {
		f << player[i].name << "-" << player[i].score << "-" << player[i].level;
		if (i != player.size() - 1)f << endl;
	}
	f.close();
}

void printhighscore(vector<nguoichoi>&player)
{
	for (int i = 0; i < 21; i++) { gotoxy(62, 18 + i); cout << "                                                             "; }


	char x1 = 219; char x2 = 220; char x3 = 222; char c = 0;
	for (int j = 0; j < 2; j++) { gotoxy(62, 18 + 3 * j); for (int i = 0; i < 61; i++) { cout << x2; } }
	for (int j = 2; j < 7; j++) { gotoxy(62, 18 + 3 * j); for (int i = 0; i < 60; i++) { cout << '_'; } }
	gotoxy(62, 18 + 18); for (int i = 0; i < 61; i++) { cout << x2; }
	for (int i = 0; i < 18; i++) { gotoxy(62, 19 + i); cout << x1; }
	for (int i = 0; i < 18; i++) { gotoxy(70, 19 + i); cout << x1; }//8
	for (int i = 0; i < 18; i++) { gotoxy(108, 19 + i); cout << x1; }//46
	for (int i = 0; i < 18; i++) { gotoxy(122, 19 + i); cout << x1; }//60


	gotoxy(65, 20);  cout << "TOP";
	gotoxy(65 + 21, 20);  cout << "Player";
	gotoxy(65 + 48, 20);  cout << "Score";
	if (player.size() < 5)
	{
		for (int i = 0; i < player.size(); i++)
		{
			gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1;
			gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i].name;
			gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i].score;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1;
			gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i].name;
			gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i].score;
		}
	}
	
	int dodoi = 0;		//so voi moc 0
	while (c = _getch())
	{
		for (int i = 0; i < 5; i++)
		{
			gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << "   ";
			gotoxy(65 + 10, 20 + 3 * (i + 1)); for (int i = 0; i < 30; i++) { cout << ' '; }
			gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << "     ";
		}
		
		
		if (c == 'w')
		{
			if (player.size() < 5)
			{
				for (int i = 0; i < player.size(); i++)
				{
					gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1;
					gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i].name;
					gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i].score;
				}
			}
			else
			{
				dodoi -= 1;
				if (dodoi < 0) {
					dodoi += 1;
					for (int i = 0; i < 5; i++)
					{
						gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1 + dodoi;
						gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i + dodoi].name;
						gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i + dodoi].score;
					}
				}
				else
				{
					for (int i = 0; i < 5; i++)
					{
						gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1 + dodoi;
						gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i + dodoi].name;
						gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i + dodoi].score;
					}
				}
			}
		}
		if (c == 's')
		{
			if (player.size() < 5)
			{
				for (int i = 0; i < player.size(); i++)
				{
					gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1;
					gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i].name;
					gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i].score;
				}
			}
			else
			{
				dodoi += 1;
				if (dodoi > player.size() - 5)
				{
					dodoi -= 1;
					for (int i = 0; i < 5; i++)
					{
						gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1 + dodoi;
						gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i + dodoi].name;
						gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i + dodoi].score;
					}
				}
				else
				{
					for (int i = 0; i < 5; i++)
					{
						gotoxy(65 + 1, 20 + 3 * (i + 1)); cout << i + 1 + dodoi;
						gotoxy(65 + 10, 20 + 3 * (i + 1)); cout << player[i + dodoi].name;
						gotoxy(65 + 49, 20 + 3 * (i + 1)); cout << player[i + dodoi].score;
					}
				}
			}
			
		}
		if (c == 27) { break; }
	}
}
void printboard()
{
	char x = 219; char t = 220;
	for (int i = 1; i <= 111; i++) { cout << t; }
	for (int i = 1; i < 110; i++) {
		for (int j = 5; j <= 40; j += 5) {
			gotoxy(i, j);
			if (j == 40)cout << t;
			else cout << "_";
		}
	}
	for (int i = 1; i < 41; i++) { gotoxy(0, i); cout << x; }
	for (int i = 1; i < 41; i++) { gotoxy(110, i); cout << x; }
}
void printinf(char c)
{
	char x = 219; char t = 221; char t2 = 222;
	gotoxy(120, 11); for (int i = 0; i < 40; i++) { cout << x; }
	for (int i = 0; i < 15; i++) { gotoxy(120, 12 + i); cout << t << "                                      " << t2; }
	gotoxy(120, 26); for (int i = 0; i < 40; i++) { cout << x; }
	gotoxy(121, 12);  cout << "player: " << "";
	gotoxy(121, 13);  cout << "Level: " << 1;
	gotoxy(121, 14); cout << "Score: " << 0;
	gotoxy(121, 20); cout << "Press key:";
	gotoxy(121, 21); cout << "L: save game";
	gotoxy(121, 22); cout << "M: muted/unmuted";
	gotoxy(121, 23); cout << "P: pause game";
	gotoxy(121, 24); cout << "ESC: exit";
}

//----------------------------------------------------------------------------


void movemenu(char c, int& y)
{
	switch (c)
	{
	case 'w': {y--; break; }
	case 's': {y++; break; }
			/*case 13:
			{

				break;
			}*/
	default: {break; }

	}
}
void movemusic(char c, bool& music)
{
	switch (c)
	{
	case 'a': {music = 1; break; }
	case 'd': {music = 0; break; }
	default: {break; }
	}
}

void printmusic(char c, bool& music)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char bat[5][19] = {
		" nnnnnn  nnn    nn",
		"nn    nn nnnn   nn",
		"nn    nn nn nn  nn",
		"nn    nn nn  nn nn",
		" nnnnnn  nn   nnnn"
	};

	char tat[5][25] = {
		" ffffff  fffffff fffffff",
		"ff    ff ff      ff",
		"ff    ff fffff   fffff",
		"ff    ff ff      ff",
		" ffffff  ff      ff"
	};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 19; j++) {
			if (bat[i][j] == 'n')bat[i][j] = (char)219;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 25; j++) {
			if (tat[i][j] == 'f')tat[i][j] = (char)219;
		}
	}
	bool checkmusic = 1; char l = 221;



	gotoxy(60, 22); cout << " "; for (int i = 1; i < 70; i++) { cout << (char)220; }
	for (int i = 1; i <= 11; i++) {
		gotoxy(60, 22 + i);
		cout << (char)222;
		cout << "                                  ";
		cout << (char)222;
		cout << "                                  ";
		cout << (char)221;
	}
	gotoxy(60, 22 + 12); cout << " "; for (int i = 1; i < 70; i++) { cout << (char)223; }
	if (music == 1) {
		for (int i = 0; i < 5; i++) {
			gotoxy(69, 26 + i);
			for (int j = 0; j < 19; j++) {
				SetConsoleTextAttribute(h, 250);
				cout << bat[i][j];
				SetConsoleTextAttribute(h, 240);
			}
		}
		for (int i = 0; i < 5; i++) {
			gotoxy(102, 26 + i);
			for (int j = 0; j < 25; j++) {
				SetConsoleTextAttribute(h, 240);
				cout << tat[i][j];
				SetConsoleTextAttribute(h, 240);
			}
		}
	}
	else if (music == 0) {
		for (int i = 0; i < 5; i++) {
			gotoxy(69, 26 + i);
			for (int j = 0; j < 19; j++) {
				SetConsoleTextAttribute(h, 240);
				cout << bat[i][j];
				SetConsoleTextAttribute(h, 240);
			}
		}
		for (int i = 0; i < 5; i++) {
			gotoxy(102, 26 + i);
			for (int j = 0; j < 25; j++) {
				SetConsoleTextAttribute(h, 244);
				cout << tat[i][j];
				SetConsoleTextAttribute(h, 240);
			}
		}
	}

	while (c = _getch())
	{
		if (c != 13) {
			gotoxy(60, 22); cout << " "; for (int i = 1; i < 70; i++) { cout << (char)220; }
			for (int i = 1; i <= 11; i++) {
				gotoxy(60, 22 + i);
				cout << (char)222;
				cout << "                                  ";
				cout << (char)222;
				cout << "                                  ";
				cout << (char)221;
			}
			gotoxy(60, 22 + 12); cout << " "; for (int i = 1; i < 70; i++) { cout << (char)223; }

			if (c == 'a') {
				for (int i = 0; i < 5; i++) {
					gotoxy(69, 26 + i);
					for (int j = 0; j < 19; j++) {
						SetConsoleTextAttribute(h, 250);
						cout << bat[i][j];
						SetConsoleTextAttribute(h, 240);
					}
				}
				for (int i = 0; i < 5; i++) {
					gotoxy(102, 26 + i);
					for (int j = 0; j < 25; j++) {
						SetConsoleTextAttribute(h, 240);
						cout << tat[i][j];
						SetConsoleTextAttribute(h, 240);
					}
				}music = 1;
			}
			else if (c == 'd') {
				for (int i = 0; i < 5; i++) {
					gotoxy(69, 26 + i);
					for (int j = 0; j < 19; j++) {
						SetConsoleTextAttribute(h, 240);
						cout << bat[i][j];
						SetConsoleTextAttribute(h, 240);
					}
				}
				for (int i = 0; i < 5; i++) {
					gotoxy(102, 26 + i);
					for (int j = 0; j < 25; j++) {
						SetConsoleTextAttribute(h, 244);
						cout << tat[i][j];
						SetConsoleTextAttribute(h, 240);
					}
				}music = 0;
			}
		}
		else break;
	}

}
void printmenu(char c, bool& newgame, bool& loadgame, bool& highscore, bool& music, bool& quit )
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<string> k = {
		" hhhhhh hhhhhh   hhhhhh  hhhhhhh hhhhhhh     hhhhhhhh hh   hh hhhhhhh     hhhhhh   hhhhhh   hhhhh  hhhhhh",
		"hh      hh   hh hh    hh hh      hh             hh    hh   hh hh          hh   hh hh    hh hh   hh hh   hh",
		"hh      hhhhhh  hh    hh hhhhhhh hhhhhhh        hh    hhhhhhh hhhhh       hhhhhh  hh    hh hhhhhhh hh   hh",
		"hh      hh   hh hh    hh      hh      hh        hh    hh   hh hh          hh   hh hh    hh hh   hh hh   hh",
		" hhhhhh hh   hh  hhhhhh  hhhhhhh hhhhhhh        hh    hh   hh hhhhhhh     hh   hh  hhhhhh  hh   hh hhhhhh"
	};
	for (int i = 0; i < k.size(); i++)
	{
		gotoxy(40, i + 4);
		for (int j = 0; j < k[i].length(); j++)
		{
			if (k[i][j] == 'h') { SetConsoleTextAttribute(h, 17); }
			cout << k[i][j];
			SetConsoleTextAttribute(h, 240);
		}
		cout << endl;
	}



	char menu[5][13] = {
		"New game",
		"Load game",
		"High score",
		"Sound",
		"Quit",
	};
	for (int i = 0; i < 5; i++) {
		gotoxy(90, 25 + 2 * i);
		cout << menu[i] << endl;
	}
	int i = 0; int luu = 0;
	while (c = _getch())
	{
		
		if (c != 13)
		{
			luu = i;
			movemenu(c, i);
			if (i < 0) { i = 4; }
			if (i > 4) { i = 0; }
			gotoxy(90, 25 + 2 * i);
			SetConsoleTextAttribute(h, 249);
			cout << menu[i];
			SetConsoleTextAttribute(h, 240);
			gotoxy(90, 25 + 2 * luu); cout << menu[luu];
		}
		else
		{
			if (i == 3)
			{
				printmusic(c, music);
				for (int i = 0; i < 9; i++) {
					gotoxy(70, 22 + 2 * i);
					for (int j = 0; j <= 50; j++) {
						cout << " ";
					}
					cout << endl;
				}
				system("cls");


				for (int i = 0; i < k.size(); i++)
				{
					gotoxy(40, i + 4);
					for (int j = 0; j < k[i].length(); j++)
					{
						if (k[i][j] == 'h')SetConsoleTextAttribute(h, 17);
						cout << k[i][j]; SetConsoleTextAttribute(h, 240);
					}
					cout << endl;
				}
				for (int i = 0; i < 5; i++) {
					gotoxy(90, 25 + 2 * i);
					cout << menu[i] << endl;
				}
				//i = 0;
			}
			
			if (i == 0) { newgame = 1; break; }
			if (i == 1) { loadgame = 1; break; }
			if (i == 2) { highscore = 1; break; }
			if (i == 4) { quit = 1; break; }
			
		}
		if(music==1 && (c == 'w' || c == 's'))PlaySound(TEXT("movemenu.wav"), NULL, SND_SYNC);
		//gotoxy(0, 30);
	}
}

//------------------------------------------------------------highscore

bool compare(const nguoichoi& a, const nguoichoi& b)
{
	return a.score > b.score;	//biggest first
}



void printquit(char c, bool& exit)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char x = 219; char t = 221; char t2 = 222;

	gotoxy(120, 28); for (int i = 0; i < 40; i++) { cout << x; }
	for (int i = 0; i < 8; i++) { gotoxy(120, 29 + i); cout << t << "                                      " << t2; }
	gotoxy(120, 36); for (int i = 0; i < 40; i++) { cout << x; }
	gotoxy(120 + 1, 29 + 1); cout << "          Exit and save game";
	gotoxy(125, 31); for (int i = 0; i < 10; i++) { cout << "_"; }
	for (int i = 0; i < 3; i++) { gotoxy(124, 32 + i); cout << "|          |"; }
	gotoxy(125, 34); for (int i = 0; i < 10; i++) { cout << "_"; }

	gotoxy(125, 31); for (int i = 0; i < 10; i++) { cout << "_"; }
	for (int i = 0; i < 3; i++) { gotoxy(124, 32 + i); cout << "|          |"; }
	gotoxy(125, 34); for (int i = 0; i < 10; i++) { cout << "_"; }
	gotoxy(124, 33); cout << "|"; cout << "    YES   "; cout << "|";


	gotoxy(145, 31); for (int i = 0; i < 10; i++) { cout << "_"; }
	for (int i = 0; i < 3; i++) { gotoxy(144, 32 + i); cout << "|          |"; }
	gotoxy(145, 34); for (int i = 0; i < 10; i++) { cout << "_"; }
	gotoxy(144, 33);
	cout << "|";
	SetConsoleTextAttribute(h, 252);
	cout << "    NO    ";
	SetConsoleTextAttribute(h, 240);
	cout << "|";



	while (c = _getch())
	{
		if (c == 13 && exit == 1)
		{
			system("cls");
			cout << "Tro choi ket thuc";
			break;
		}
		if (c == 13 && exit == 0)
		{
			gotoxy(120, 28); for (int i = 0; i < 40; i++) { cout << ' '; }
			for (int i = 0; i < 8; i++) { gotoxy(120, 29 + i); cout << "                                        "; }
			gotoxy(120, 36); for (int i = 0; i < 40; i++) { cout << ' '; }
			break;
		}
		if (c == 'a')
		{
			gotoxy(125, 31); for (int i = 0; i < 10; i++) { cout << "_"; }
			for (int i = 0; i < 3; i++) { gotoxy(124, 32 + i); cout << "|          |"; }
			gotoxy(125, 34); for (int i = 0; i < 10; i++) { cout << "_"; }
			gotoxy(124, 33);
			cout << "|";
			SetConsoleTextAttribute(h, 250);
			cout << "    YES   ";
			SetConsoleTextAttribute(h, 240);
			cout << "|";


			gotoxy(145, 31); for (int i = 0; i < 10; i++) { cout << "_"; }
			for (int i = 0; i < 3; i++) { gotoxy(144, 32 + i); cout << "|          |"; }
			gotoxy(145, 34); for (int i = 0; i < 10; i++) { cout << "_"; }
			gotoxy(144, 33); cout << "|"; cout << "    NO    "; cout << "|";
			exit = 1;
		}
		if (c == 'd')
		{
			gotoxy(125, 31); for (int i = 0; i < 10; i++) { cout << "_"; }
			for (int i = 0; i < 3; i++) { gotoxy(124, 32 + i); cout << "|          |"; }
			gotoxy(125, 34); for (int i = 0; i < 10; i++) { cout << "_"; }
			gotoxy(124, 33); cout << "|"; cout << "    YES   "; cout << "|";


			gotoxy(145, 31); for (int i = 0; i < 10; i++) { cout << "_"; }
			for (int i = 0; i < 3; i++) { gotoxy(144, 32 + i); cout << "|          |"; }
			gotoxy(145, 34); for (int i = 0; i < 10; i++) { cout << "_"; }
			gotoxy(144, 33);
			cout << "|";
			SetConsoleTextAttribute(h, 252);
			cout << "    NO    ";
			SetConsoleTextAttribute(h, 240);
			cout << "|";
			exit = 0;
		}
	}
}



void printover(bool& music)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char over[5][74] = {//5,74
		" hhhhhh   hhhhh  hhh    hhh hhhhhhh      hhhhhh  hh    hh hhhhhhh hhhhhh",
		"hh       hh   hh hhhh  hhhh hh          hh    hh hh    hh hh      hh   hh",
		"hh   hhh hhhhhhh hh hhhh hh hhhhh       hh    hh hh    hh hhhhh   hhhhhh",
		"hh    hh hh   hh hh  hh  hh hh          hh    hh  hh  hh  hh      hh   hh",
		" hhhhhh  hh   hh hh      hh hhhhhhh      hhhhhh    hhhh   hhhhhhh hh   hh",
	};
	for (int i = 0; i < 5; i++) {
		gotoxy(56, 18 + i);
		for (int j = 0; j < 74; j++) {
			if (over[i][j] == 'h') {
				SetConsoleTextAttribute(h, 244); cout << (char)219; SetConsoleTextAttribute(h, 240);
			}
			else cout << ' ';
		}
	}
	if(music==1)PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
	//system("cls");
}
void printwin(bool& music)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char win[5][54] = {//5,74
		"ww    ww  wwwwww  ww    ww     ww     ww ww www    ww",
		" ww  ww  ww    ww ww    ww     ww     ww ww wwww   ww",
		"  wwww   ww    ww ww    ww     ww  w  ww ww ww ww  ww",
		"   ww    ww    ww ww    ww     ww www ww ww ww  ww ww",
		"   ww     wwwwww   wwwwww       www www  ww ww   wwww",
	};


	for (int i = 0; i < 5; i++) {
		gotoxy(62, 18 + i);
		for (int j = 0; j < 54; j++) {
			if (win[i][j] == 'w') {
				SetConsoleTextAttribute(h, 242); cout << (char)219; SetConsoleTextAttribute(h, 240);
			}
			else cout << ' ';
		}
	}
	if (music == 1)PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
	system("cls");
}