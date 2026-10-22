#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int integer1, integer2,sum, product, difference;
	cout << "Введите число 1: ";
	cin >> integer1;
	cout << "Введите число 2: ";
	cin >> integer2;
	sum = integer1 + integer2;
	product = integer1*integer2;
	difference = integer1-integer2;
	cout << "Сумма равна: "<< sum<<endl;
	cout << "Прозвдение чисел равно: " << product << endl;
	cout << "Разность чисел "<< integer1<<" и "<<integer2<<" равна "<<difference<<endl;
	system("pause");
}