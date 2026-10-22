#pragma once
#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
#include <cstdlib>  // Для rand(), srand()
#include <ctime>    // Для time()

using std::cin;
using std::cout;
using std::endl;

void swapi(unsigned& zn1, unsigned& zn2) {
    unsigned zn = zn1;
    zn1 = zn2;
    zn2 = zn;
}

void BubbleSort(unsigned* d_masiv, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {  
            if (d_masiv[j] > d_masiv[j + 1]) {
                swapi(d_masiv[j], d_masiv[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    unsigned sizee;

    cout << "Задание: Написать функцию BubbleSort типа void, которая принимает в" << endl;
    cout << "качестве параметров указатель на динамический массив типа unsigned и" << endl;
    cout << "переменную типа size_t – количество элементов массива, функция должна" << endl;
    cout << "выполнять сортировку массива по возрастанию методом пузырька.\n" << endl;

    cout << "Введите кол-во элементов для массива: ";
    cin >> sizee;

    size_t size = sizee;
    unsigned* d_masiv = new unsigned[size];

    srand(time(0));
    cout << "\nИсходный массив:" << endl;
    for (size_t i = 0; i < size; i++) {
        d_masiv[i] = rand() % 100;  // Числа от 0 до 99
        cout << d_masiv[i] << " ";
    }
    cout << endl << endl;

    // Сортируем
    BubbleSort(d_masiv, size);

    cout << "Отсортированный массив:" << endl;
    for (size_t i = 0; i < size; i++) {
        cout << d_masiv[i] << " ";
    }
    cout << endl << endl;

    delete[] d_masiv;

    system("pause");
}