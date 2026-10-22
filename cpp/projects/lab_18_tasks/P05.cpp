#pragma once
#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
using std::cin;
using std::cout;
using std::endl;

int main() {
	setlocale(LC_ALL, "RU");
	double A[3],B[3],C[3];
	cout << "Задание: Ввести с клавиатуры координаты трёхмерных векторов A и B" << endl;
	cout << "(координаты векторов хранить в двух статических массивах).Вычислить и" << endl;
	cout << "вывести на экран координаты вектора C = A x B.\n" << endl;
	
	cout << "Введите A(x): ";
	cin >> A[0];
	cout << "Введите A(y) : ";
	cin >> A[1];
	cout << "Введите A(z): ";
	cin >> A[2];

	cout << "\nВведите B(x): ";
	cin >> B[0];
	cout << "Введите B(y): ";
	cin >> B[1];
	cout << "Введите B(z): ";
	cin >> B[2];

	cout << "\nКоординаты C = (" << A[1] * B[2] - A[2] * B[1] << ", " << -(A[0] * B[2] - A[2] * B[0]) << ", " << A[0] * B[1] - A[1] * B[0] << ")\n ";
	
	system("pause");
}