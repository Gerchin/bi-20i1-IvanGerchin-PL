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

void fill();
void sum();
void showResult();
 int transfer(char simbol);
 int checkString();

int main() {
	setlocale(0, "");

	do {
		cout << "Введите выражение. (Нажмешь на ENTER при пустой строке и я умру :(  )" << endl;
		getline(cin, userInput);
		if (checkString()){
			system("cls");
			cout << "Введите корректное выражение." << endl;
			system("pause");
		}
		system("cls");
	} while (checkString());

	fill();
	sum();
	showResult();

	/*
	for (int i = 0; i < num1.size(); i++){
		cout << num1[i];
	}
	cout << endl;
	for (int i = 0; i < num2.size(); i++) {
		cout << num2[i];
	}*/

	system("pause");
	return 0;
}

int checkString() {
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

void fill() {
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

int transfer(char simbol) {
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

void sum() {
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

void showResult() {
	for (int i = 0; i < result.size(); i++)
		cout << result[i];
}