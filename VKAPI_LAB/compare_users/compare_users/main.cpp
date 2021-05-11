#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;

int main() {
	char *str = new char [1024];
    int countStrings=0;
    ifstream u1("D:\\VKAPI_LAB\\testC++\\u1.txt");
    while (!u1.eof())
    {
        u1.getline(str, 1024, '\n');
        countStrings++;
    }
    u1.close();

    cout <<"Count of strings: "<< countStrings << '\n';
    system ("pause");
    return 0;
}