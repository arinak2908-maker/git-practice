#pragma once
#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
using std::cin;
using std::cout;
using std::endl;

void swapi() {
	unsigned int zn1, zn2;
	cout << "Введите первое число: ";
	cin >> zn1;
	cout << "Введите второе число: ";
	cin >> zn2;
	unsigned zn = zn1;
	zn1 = zn2;
	zn2 = zn;
	cout << "\nТеперь \nПервое число: " << zn1 <<endl<< "Второе число: " << zn2 << endl;
}

void swapf() {
	float zn1, zn2;
	cout << "\nВведите первое число с плавающей точкой: ";
	cin >> zn1;
	cout << "Введите второе число с плавающей точкой: ";
	cin >> zn2;
	zn1 = zn1 + zn2;
	zn2 = zn1 - zn2;
	zn1 = zn1 - zn2;
	cout << "\nТеперь \nПервое число: " << zn1 << endl << "Второе число: " << zn2 << endl;
}

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Задание: Написать функцию swap, которая меняет местами значения" << endl;
	cout << "переменных, переданных в неё в качестве параметров.Замечание: далее будем" << endl;
	cout << "использовать эту функцию в задачах сортировки, поэтому следует написать" << endl;
	cout << "две функции swapi(для обмена значений переменных типа unsigned int) и" << endl;
	cout << "swapf(для переменных типа float).\n" << endl;
	
	swapi();
	swapf();

	system("pause");
}