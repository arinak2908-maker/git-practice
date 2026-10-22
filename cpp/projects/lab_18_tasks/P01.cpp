#pragma once
#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
using std::cin;
using std::cout;
using std::endl;

int main() {
	unsigned year;
	setlocale(LC_ALL, "RU");
	cout << "Задание: Пользователь вводит номер года n > 0 (целое беззнаковое число)." << endl;
	cout << "Программа должна определить является ли данный год високосным и вывести" << endl;
	cout << "на экран соответствующее сообщение.\n"<< endl;
	cout << "Введите номер года: ";
	cin >> year;
	if (year % 100==0) {
		if (year % 400 == 0) {
			cout << "Год високосный"<<endl;
		}
		else (cout << "Год не високосный" << endl);
	}

	else {
		if (year % 4 == 0) {
			cout << "Год високосный" << endl;
		}
		else (cout << "Год не високосный" << endl);
	}
	system("pause");
}