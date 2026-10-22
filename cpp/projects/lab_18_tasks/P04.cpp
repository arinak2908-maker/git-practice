#pragma once
#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
using std::cin;
using std::cout;
using std::endl;

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Задание: Задать символьный статический массив A, хранящий строку «мама мыла " << endl;
	cout << "раму» и определить с помощью операции sizeof его размер в байтах.Создать " << endl;
	cout << "динамический массив B с элементами типа char и скопировать в него " << endl;
	cout << "элементы массива A.Определить с помощью операции sizeof размер массива " << endl;
	cout << "B; сравнить полученный результат с результатом выполнения sizeof для " << endl;
	cout << "массива A.\n"<<endl;
	char A[] = "мама мыла раму";
	cout <<"Статический массив A: "<<" мама мыла раму"<<endl<<"Размер (sizeof) массива A : " << sizeof(A)<<" байт" << endl;
	char* B = new char[sizeof(A)];
	for (int i = 0; i < sizeof(A); i++) {
		B[i] = A[i];
	}
	cout << "Динамический массив B: " <<endl<< "Размер (sizeof) массива B : " << sizeof(B) << " байт" << endl;
	cout << "Сравнение статического и динамического массива:" << endl << " A = " << sizeof(A) <<" байт " << endl << " B = " << sizeof(B) << " байт " << endl;
	delete [] B;
	system("pause");
}