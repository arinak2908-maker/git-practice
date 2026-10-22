#pragma once
#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
using std::cin;
using std::cout;
using std::endl;

int main() {
	setlocale(LC_ALL,"RU");
	cout << "Задание: Через пробел вводятся два вещественных числа a и b– коэффициенты" << endl;
	cout << "уравнения ax + b  = 0. Вывести на экран корень уравнения или" << endl;
	cout << "соответствующее диагностическое сообщение.\n" << endl;
	double x, a, b;
	cout << "Введите 2 вещественных числа через пробел: ";
	if (!(cin >> a >> b)) {
		cout << "Ошибка! Введите 2 вещественных числа через пробел."<<endl;
	}
	else if (a == 0 and b == 0) {
		cout << "Уравнение имеет бесконечно много решений.";
	}
	else if (a == 0 or b == 0) {
		cout << "Уравнение не имеет решений."<<endl;
	}
	else {
		x = -b / a;
		cout << x<<endl;
	}
	system("pause");
}