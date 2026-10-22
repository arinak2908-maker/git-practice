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

void BubbleSort(unsigned* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swapi(arr[j], arr[j + 1]);
}

int main() {
    setlocale(LC_ALL, "RU");
    unsigned n;

    cout << "С клавиатуры вводится целое беззнаковое число n (15 <= n <= 60)." << endl;
    cout << "Программа должна создать динамический массив из n случайных целых" << endl;
    cout << "чисел, лежащих в диапазоне от 10 до 99. Используя результаты решения задач" << endl;
    cout << "6 и 7, отсортировать массив по возрастанию и вывести на экран его элементы" << endl;
    cout << "(каждый элемент с новой строки).\n" << endl;

    cout << "Введите число от 15 до 60: ";
    cin >> n;

    if (n < 15 or n > 60, cout << "Ошибка! Надо ввести число от 15 до 60\n") {
        system("pause");
        return 1;
    }
    unsigned* arr = new unsigned[n];
    srand(time(0));

    for (size_t i = 0; i < n; i++)
        arr[i] = rand() % 90 + 10;

    BubbleSort(arr, n);

    for (size_t i = 0; i < n; i++)
        cout << arr[i] << endl;

    delete[] arr;
    system("pause");
}