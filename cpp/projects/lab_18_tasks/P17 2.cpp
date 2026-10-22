#pragma once
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

using std::cin;
using std::cout;
using std::endl;

int main() {
    setlocale(LC_ALL, ".1251");
    // Ввод 2 чисел
    unsigned short num1, num2;
    cout << "Введите первое число (от 0 до 65535): ";//до 16 бит
    cin >> num1;
    cout << "Введите второе число (от 0 до 65535): ";
    cin >> num2;

    // Преобразование чисел в двоичные массивы (16 бит каждый)
    unsigned char binary1[16];  // 1 число в двоичном виде
    unsigned char binary2[16];  // 2 число в двоичном виде

    cout << "\nДвоичные представления:\n";

    // Получаем двоичное представление 1 числа
    cout << "A: ";
    for (int i = 15; i >= 0; i--) {
        binary1[15 - i] = (num1 >> i) & 1;
        cout << (int)binary1[15 - i];
    }
    cout << endl;

    // Получаем двоичное представление 2 числа
    cout << "B: ";
    for (int i = 15; i >= 0; i--) {
        binary2[15 - i] = (num2 >> i) & 1;//15>>позиция 
        cout << (int)binary2[15 - i];
    }
    cout << endl;

    // сложение "в столбик"
    unsigned char result[16];  // Результат сложения (16 бит)
    bool carry = false;        // Перенос
    bool overflow = false;     // Флаг переполнения

    // Сложение начинаем с младших разрядов (справа налево)
    for (int i = 15; i >= 0; i--) {
        // Сумма текущих битов + перенос
        // carry ? 1 : 0 если carry == 1 тогда 0
        int sum = binary1[i] + binary2[i] + (carry ? 1 : 0);// carry ? 1:0   если есть перенос с предыдущего разряда, добавляет 1, иначе 0

        // Записываем младший бит суммы в результат
        result[i] = sum & 1;

        // Определяет, нужно ли переносить 1 в следующий разряд:
        carry = (sum >> 1) & 1;
    }

    // Если после сложения всех разрядов остался перенос - переполнение
    overflow = carry;

    // Вывод результата сложения
    cout << "R: ";
    for (int i = 0; i < 16; i++) {
        cout << (int)result[i];
    }
    cout << endl;

    // Преобразование результата обратно в десятичное число
    unsigned short decimalResult = 0;
    for (int i = 0; i < 16; i++) {
        decimalResult = (decimalResult << 1) | result[i];
    }

    // Вывод результатов
    cout << "\nРезультат в десятичной системе:\n";
    cout << num1 << " + " << num2 << " = " << decimalResult;

    if (overflow) {
        cout << " (переполнение!)";
        cout << "\nезультат: ";
        for (int i = 0; i < 16; i++) {
            cout << (int)result[i];
        }
    }

    // Проверка правильности через обычное сложение
    unsigned short expected = num1 + num2;
    cout << "\n\nПроверка: " << num1 << " + " << num2 << " = " << expected % 65536;

    cout << endl;
    system("pause");
}