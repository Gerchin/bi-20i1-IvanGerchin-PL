#include <iostream>

using namespace std;

int main() {
	int* arr;
	int n;
	
	cout << "Input number - ";
	cin >> n;
	cout << endl << endl;

	arr = new int[n];
// заполнение массива
	for (int i = 0; i < n; i++){
		arr[i] = i;
	}

	int* pa = arr; // 0
	int* pla = arr+n-1; // 0

	//pla = &a[0];

	/*for (int i = 0; i < n; i++) {
		*(pla + i) = *(a + i);
	}*/

	for (int i = 0; i < n; i++) {  // вывод массива
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << *pa << " " << *(pla + n - 1) << endl; // вывод указателей
	int temp;
	int k = n / 2 - 1;
	for (int i = 0; i < n / 2; i++) { // перезапись эл. массива
		temp = *(pa + k);
		*(pa + k) = *(pla - i);
		*(pla - i) = temp;
		k--;
	}

	for (int i = 0; i < n; i++) { // вывод массива
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}