#pragma once
#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
using std::cin;
using std::cout;
using std::endl;

int main() {
	setlocale(LC_ALL, "RU");
	cout << "«адание: ќпределить (с помощью операции sizeof) количество байт," << endl;
	cout << "занимаемых встроенными типами данных(bool, char, short, int, long,"<< endl;
	cout << "long, float, double, long double).\n"<< endl;

	cout << "ќпределение (с помощью операции sizeof) количество байт, занимаемых встроенными типами данных: "<<endl;
	cout << "sizeof(bool): " << sizeof(bool) << " байт" << endl;
	cout << "sizeof(char): " << sizeof(char) << " байт" << endl;
	cout << "sizeof(short): " << sizeof(short) << " байт" << endl;
	cout << "sizeof(int): " << sizeof(int) << " байт" << endl;
	cout << "sizeof(long): " << sizeof(long) << " байт" << endl;
	cout << "sizeof(long long): " << sizeof(long long) << " байт" << endl;
	cout << "sizeof(float): " << sizeof(float) << " байт" << endl;
	cout << "sizeof(double): " << sizeof(double) << " байт" << endl;
	cout << "sizeof(long double): " << sizeof(long double) << " байт" << endl;
	system("pause");
}