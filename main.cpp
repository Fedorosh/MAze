#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;
int lucas(int n)
{
	if (n == 1) return 2;
	if (n == 2) return 1;
	else return lucas(n - 2) + lucas(n - 1);
}
int x1, x2, z1, z2, check = 0;
void mapka(int** &lol, int &ile)
{
	char g;
	//drawing a map
	for (int i = 0; i < ile; i++)
	{
		for (int j = 0; j < ile; j++)
		{
			if (lol[i][j] == 1) g = 177;
			if (lol[i][j] == 0||lol[i][j] == 2) g = ' ';
			if (lol[i][j] == 3) g = 'X';
			cout << g;
		}
		cout << endl;
	}
}
void menu(int &x)
{
	char g;
	cout << "Witamy w labiryncie!" << endl;
	cout << "Wybierz rozmiar mapy" << endl;
	cout << endl << "1. 6x6   2. 8x8   3. 10x10 " << endl;
	cout << "4. 12x12   5. 14x14";
	//choosing a map
	do {
		g = _getch();
		if (g == '1') x = 0;
		if (g == '2') x = 37;
		if (g == '3') x = 102;
		if (g == '4') x = 203;
		if (g == '5') x = 348;
		if (g != '1'&&g != '2'&&g != '3'&&g != '4'&&g != '5') cout << endl << "Wybierz od 1 do 5!" << endl;
	} while (g != '1'&&g != '2'&&g != '3'&&g != '4'&&g != '5');
	system("cls");
}
void coord(int** &lol, int &ile)
{
	for (int i = 0; i < ile; i++)
	{
		if (lol[0][i] == 0)
		{
			//exit
			x1 = 0;
			z1 = i;
		}
	}
	for (int i = 0; i < ile; i++)
	{
		if (lol[ile - 1][i] == 0)
		{
			//enter
			x2 = ile - 1;
			z2 = i;
		}
	}
}
bool robot1(int** &lol, int a, int x, int y)
{
	if ((x < 0 || x >= a) || (y < 0 || y >= a)) return false;
	if (lol[x][y] == 1 || lol[x][y] == 2) return false;
	if (x == x1 && y == z1) return true;
	lol[x][y] = 2;
	if (robot1(lol, a, x ,y + 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot1(lol, a, x - 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot1(lol, a, x + 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot1(lol, a, x, y - 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	else return false;
}
bool robot2(int** &lol, int a, int x, int y)
{
	if ((x < 0 || x >= a) || (y < 0 || y >= a)) return false;
	if (lol[x][y] == 1 || lol[x][y] == 2) return false;
	if (x == x1 && y == z1) return true;
	lol[x][y] = 2;
	if (robot2(lol, a, x + 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot2(lol, a, x - 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot2(lol, a, x, y + 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot2(lol, a, x, y - 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	else return false;
}
bool robot3(int** &lol, int a, int x, int y)
{
	if ((x < 0 || x >= a) || (y < 0 || y >= a)) return false;
	if (lol[x][y] == 1 || lol[x][y] == 2) return false;
	if (x == x1 && y == z1) return true;
	lol[x][y] = 2;
	if (robot3(lol, a, x, y - 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot3(lol, a, x, y + 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot3(lol, a, x - 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot3(lol, a, x + 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	else return false;
}
bool robot4(int** &lol, int a, int x, int y)
{
	if ((x < 0 || x >= a) || (y < 0 || y >= a)) return false;
	if (lol[x][y] == 1 || lol[x][y] == 2) return false;
	if (x == x1 && y == z1) return true;
	lol[x][y] = 2;
	if (robot4(lol, a, x - 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot4(lol, a, x, y + 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot4(lol, a, x + 1, y) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	if (robot4(lol, a, x, y - 1) == true) { lol[x][y] = 3; check++; system("cls"); mapka(lol, a); Sleep(150); return true; }
	else return false;
}

int main()
{
	srand(time(NULL));
	//declarations
	fstream file;
	int x, y, n, los;
	file.open("file.txt", ios::in);
	//lucas
	cout << "ile chcesz wyrazow lucasa: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << lucas(i) << endl;
	}
	system("pause");
	system("cls");
	//which map has to be loaded
	menu(y);
	for (int i = 1; i <= y; i++)
	{
		int w;
		file >> w;
	}
	file >> x;
	//allocating memory
	int **lol = new int *[x];
	for (int z = 0; z < x; z++)
	{
		lol[z] = new int[x];
	}
	//reading from file
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			file >> lol[i][j];
		}
	}
	file.close();
	file.open("coordinates.txt", ios::out|ios::app);
	//creating a map
	coord(lol, x);
	mapka(lol, x);
	//executing recursion
	los = rand() % 4 + 1;
	if (los == 1)
	{
		if (robot1(lol, x, x2, z2) == true)
		{
			cout << "Liczba wykonanych krokow: " << check;
			file << "Liczba wykonanych krokow: " << check << endl;
		}
	}
	else if (los == 2)
	{
		if (robot2(lol, x, x2, z2) == true)
		{
			cout << "Liczba wykonanych krokow: " << check;
			file << "Liczba wykonanych krokow: " << check << endl;
		}
	}
	else if (los == 3)
	{
		if (robot3(lol, x, x2, z2) == true)
		{
			cout << "Liczba wykonanych krokow: " << check;
			file << "Liczba wykonanych krokow: " << check << endl;
		}
	}
	else if (los == 4)
	{
		if (robot4(lol, x, x2, z2) == true)
		{
			cout << "Liczba wykonanych krokow: " << check;
			file << "Liczba wykonanych krokow: " << check << endl;
		}
	}
	//saving coordinates to file
	file << "Rozmiar labiryntu: " << x << "x" << x << endl;
	for (int i = x - 1; i >= 0; i--)
	{
		for (int j = x -1; j >= 0; j--)
		{
			if (lol[i][j] == 3)
			{
				file << "(" << i << "," << j << ")" << endl;
			}
		}
	}
	file.close();
	//releasing memory
	for (int z = 0; z < x; z++)
	{
		delete[]lol[z];
	}
	delete[]lol;
	cin.get();
	cin.get();
	return 0;
}
