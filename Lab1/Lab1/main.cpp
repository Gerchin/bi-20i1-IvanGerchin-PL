#include<iostream>
#include<ctime>
#include<Windows.h>

using namespace std;

void loading();

void main() {
	setlocale(0, "");
	srand(static_cast<unsigned int>(time(nullptr)));
	bool flag = true;

	int balance = 1000;
	int betBalance;
	int bet;
	int casinoBet;

	do{
		casinoBet = (rand() % 21) + 1;

		cout << "�������� ������ !!!" << endl << endl;
		cout << "������ - " << balance << endl;
		cout << "������ - ";
		cin >> betBalance; cout << endl;
		cout << "�������� ����� �� 1 �� 21 -- ";
		cin >> bet; cout << endl;

		balance = balance - betBalance;

		cout << endl;
		loading();
		system("cls");

		//cout << balance; system("pause");

		if (bet == casinoBet - 1 || bet == casinoBet - 2 || bet == casinoBet + 1 || bet == casinoBet + 2) {
			betBalance = betBalance * 2;
			cout << "�������� �2 !" << endl;
			balance = balance + betBalance;
			system("pause");
		}
		else if (bet == casinoBet) {
			betBalance = betBalance * 4;
			cout << "�������� �4 !" << endl;
			balance = balance + betBalance;
			system("pause");
		}
		else {
			cout << "������ �� ������ :(" << endl;
			system("pause");
		}

		
		if (balance <= 0) {
			flag = false;
			cout << "�� ��������!!! ������ ����� ����� ������ :)" << endl;
			system("pause");
		}
		if (balance >= 2000) {
			flag = false;
			cout << "����������! �� �������!" << endl;
			system("pause");
		}
		
		system("cls");
	} while (flag == true);
}

void loading() {
	string a1 = { "������� ��������." };
	string a2 = { "������� ��������.." };
	string a3 = { "������� ��������..." };

	for (int i = 0; i < 5; i++) {
		system("cls");
		cout << a1;
		Sleep(90);
		system("cls");
		cout << a2;
		Sleep(90);
		system("cls");
		cout << a3;
		Sleep(90);
	}
}