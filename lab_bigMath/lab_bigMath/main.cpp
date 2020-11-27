#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<Windows.h>

using namespace std;

string      userInput;
vector<int> num1;
vector<int> num2;
vector<int> result;

//void welcomeMessage();
void fill();
void sum();
void subtraction();
void showResult();

 int transfer(char simbol);
 int checkString();

int main() {
	setlocale(LC_ALL, "Russian");

	//welcomeMessage();

		do {
			cout << "Введите выражение. (Нажмешь на ENTER при пустой строке и я умру :(  )" << endl;
			getline(cin, userInput);
			if (checkString()) {
				system("cls");
				cout << "Введите корректное выражение." << endl;
				system("pause");
			}
			system("cls");
		} while (checkString());

	fill();
	subtraction();
	//sum();
	showResult();

	cout << endl;
	for (int i = 0; i < num1.size(); i++) {
		cout << num1[i];
	}
	cout << endl;
	for (int i = 0; i < num2.size(); i++) {
		cout << num2[i];
	}

	system("pause");
	return 0;
}

/*void welcomeMessage() {
	string welcome = { "Добро пожаловать в мой супер крутой калькулятор" };

	for (int i = 0; i < welcome.length(); i++) {
		cout << welcome[i];
		Sleep(50);
	}
	Sleep(1000);
	system("cls");
}*/

int checkString() { // проверка на правильность введенных символов
	int counter = 0;

	for (int i = 0; i < userInput.length(); i++) {
		if (userInput[i] != '+' && userInput[i] != '-' && userInput[i] != '*' && userInput[i] != '/' && userInput[i] != '^' && userInput[i] != ' ') {
			if (transfer(userInput[i]) == 10)
				counter++;
		}
	}
	if (counter > 0)
		return true;
	else
		return false;
}

void fill() { // заполенение векторов значениями, которые ввёл юзер
	int flag = 0;

	for (int i = 0; i < userInput.length(); i++) {
		if (userInput[i] != '+' && userInput[i] != '-' && userInput[i] != '*' && userInput[i] != '/' && userInput[i] != '^' && userInput[i] != ' ') {
			if (flag == 0)
				num1.push_back(transfer(userInput[i]));
			else
				num2.push_back(transfer(userInput[i]));
		}
		if (userInput[i] == '+' || userInput[i] == '-' || userInput[i] == '*' || userInput[i] == '/' || userInput[i] == '^')
			flag++;
	}
}

int transfer(char simbol) { // перевод символов в числа
	     if (simbol == '0')
		return 0;
	else if (simbol == '1')
		return 1;
	else if (simbol == '2')
		return 2;
	else if (simbol == '3')
		return 3;
	else if (simbol == '4')
		return 4;
	else if (simbol == '5')
		return 5;
	else if (simbol == '6')
		return 6;
	else if (simbol == '7')
		return 7;
	else if (simbol == '8')
		return 8;
	else if (simbol == '9')
		return 9;
	else
		return 10;
}

void sum() { // операция суммы
	int flag = 0;

	if (num1.size() > num2.size()) {
		for (int i = num1.size() - num2.size(); i > 0; i--) {
			num2.insert(num2.begin(), 0);
		}
	}
	else if (num2.size() > num1.size()) {
		for (int i = num2.size() - num1.size(); i > 0; i--) {
			num1.insert(num1.begin(), 0);
		}
	}

	for (int i = num1.size() - 1; i >= 0; i--) {
		result.insert(result.begin(), (num1[i] + num2[i] + flag) % 10);

		if (i == 0 && num1[i] + num2[i] + flag > 9)
			result.insert(result.begin(), 1);
		
		if ((num1[i] + num2[i] + flag) > 9)
			flag = 1;
		else
			flag = 0;
	}
}

void subtraction() {
	int flag = 0;
	
	if (num1.size() > num2.size()) {
		for (int i = num1.size() - num2.size(); i > 0; i--) {
			num2.insert(num2.begin(), 0);
		}
	}
	else if (num2.size() > num1.size()) {
		for (int i = num2.size() - num1.size(); i > 0; i--) {
			num1.insert(num1.begin(), 0);
		}
	}

	for (int i = num1.size() - 1; i >= 0; i--) {
		if (num1[i] < num2[i]) {
			result.insert(result.begin(), (num1[i] + 10) - num2[i]);
			int j = i;
			while (j > 0) {
				if (num1[j - 1] != 0) {
					num1[j - 1] = num1[j - 1] - 1;
					break;
				}
				else
					j--;
			}
		}
		else {
			result.insert(result.begin(), num1[i] - num2[i]);
		}
	}
}

void showResult() { // вывод конечного результата
	for (int i = 0; i < result.size(); i++)
		cout << result[i];
}