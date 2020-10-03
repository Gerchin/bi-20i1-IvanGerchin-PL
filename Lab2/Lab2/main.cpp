#include<iostream>
#include<ctime>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<Windows.h>

using namespace std;

void mapGeneration(int heigth,int width);
void moveNumbers();
//void renderMap();

const int width = 4;
const int heigth = 4;
int map[heigth][width];

int main() {
	setlocale(0, "");

	/*
	for (int i = 0; i < heigth; i++)
	{
		for (int k = 0; k < width; k++)
		{
			map[i][k] = 0;
		}
	}*/

	

	do {
		mapGeneration(heigth, width);
		moveNumbers();
		system("cls");
			//system("pause");
	} while (true);

	//mapGeneration(heigth, width);

	//system("pause");
	return 0;
}

void mapGeneration(int heigth, int width) {  //спавнит двойки и рендерит карту

	srand(static_cast<unsigned int>(time(nullptr)));

	int randNumber1;
	int randNumber2;

	int nx1 = (rand() % 4) + 1;
	Sleep(9);
	int nx2 = (rand() % 4) + 1;
	Sleep(11);
	int ny1 = (rand() % 4) + 1;
	Sleep(2);
	int ny2 = (rand() % 4) + 1;

	map[ny1 - 1][nx1 - 1] = 2;
	map[ny2 - 1][nx2 - 1] = 2;
	
	
	for (int i = 0; i < heigth; i++)
	{
		for (int k = 0; k < width; k++)
		{
				cout << map[i][k];
		}
		cout << endl;
	}
	/*cout << endl << "(" << nx1 << ";" << ny1 << ")";
	cout << endl << "(" << nx2 << ";" << ny2 << ")";*/
}

void renderMap() {
	
}

void moveNumbers() { //двигает цифры но пока очень сырое
		switch (_getch()) {
		case 72:
			//std::cout << "\nup";
			for (int i = 0; i < heigth; i++)
			{
				
				for (int k = 0; k < width; k++){
					bool acces = true;

					if (map[0][k] > 1) {
						map[i + 1][k] = 0;
						acces = false;
					}

					if (map[i][k] > 1 && acces == true) {
						map[0][k] = map[i][k];
						if(map[0][k] == map[i][k])  // позже скажу почему if
							map[i][k] = 0;
					}
				}
			};
			break;
		case 80:
			for (int i = 0; i < heigth; i++)
			{
				if (i == heigth - 1)
					break;

				for (int k = 0; k < width; k++)
				{
					if (map[i][k] > 1) {
						map[heigth - 1][k] = map[i][k];
						if (map[heigth - 1][k] == map[i][k])
							map[i][k] = 0;
					}
					
				}
			};
			//std::cout << "\ndown";
			break;
		case 75:
			//std::cout << "\nleft";
			for (int i = 0; i < heigth; i++)
			{
				for (int k = 0; k < width; k++){
					bool acces = true;

					if (map[i][0] > 1) {
						map[i][k + 1] = 0;
						acces = false;
					}

					if (map[i][k] > 1 && acces == true) {
						map[i][0] = map[i][k];
							if (map[i][0] == map[i][k])
								map[i][k] = 0;
					}
				}
			}; break;
		case 77:
			for (int i = 0; i < heigth; i++)
			{
				for (int k = 0; k < width; k++)
				{
					if (k == width - 1)
						break;

					if (map[i][k] > 1) {
						map[i][width - 1] = map[i][k];
						if (map[i][width - 1] == map[i][k])
							map[i][k] = 0;
					}
					
				}
			};
			//std::cout << "\nright";
			break;
		}
}