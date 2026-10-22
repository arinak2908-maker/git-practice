#pragma once                      // Защита от повторного включения файла
#include <iostream>               // Подключаем библиотеку для ввода/вывода
#include <iomanip>                // Подключаем для форматирования вывода
#include <math.h>                 // Подключаем математическую библиотеку
#define _USE_MATH_DEFINES        // Разрешаем использовать математические константы

using std::cin;                   // Используем cin из пространства std
using std::cout;                  // Используем cout из пространства std
using std::endl;                  // Используем endl из пространства std
using std::setw;                  // Для установки ширины вывода
using std::fixed;                 // Для фиксированного формата чисел
using std::setprecision;          // Для установки точности вывода

// Прототип функции SIN(x) из задачи 15
double SIN(double x);
const double PI = 3.141592653589793;

// Прототип функции для сравнения синусов
void compareSinValues();

int main() {
    setlocale(LC_ALL, ".1251");   // Устанавливаем русскую кодировку для вывода текста

    cout << "Задание: Используя результаты предыдущей задачи (функцию SIN(x)), ";
    cout << "вычислить и вывести на экран значение функции SIN(x) в 20 точках ";
    cout << "отрезка [0; 2π]. Сравнить значения функции SIN(x) со значениями ";
    cout << "стандартной функции sin x (для работы с ней следует подключить ";
    cout << "библиотеку math.h), вычисленной в тех же точках.\n" << endl;

    // Вызываем функцию для сравнения значений
    compareSinValues();

    cout << endl;
    system("pause"); // Ожидаем нажатия клавиши перед закрытием окна
    return 0;        // Завершаем программу
}

// ============================================================
// РЕАЛИЗАЦИЯ ФУНКЦИИ SIN(x) из задачи 15
// ============================================================
double SIN(double x) {
    // 1. "Приводим аргумент к диапазону [-pi, pi]"
    double two_pi = 2.0 * PI;
    x = fmod(x, two_pi);
    if (x > PI) {
        x -= two_pi;
    }
    else if (x < -PI) {
        x += two_pi;
    }

    // 2. "Задаем точность вычислений"
    const double epsilon = 1e-12;

    // 3. "Инициализируем переменные для вычисления ряда"
    double term = x;             // Первое слагаемое: x
    double sum = term;           // Текущая сумма
    double x_squared = x * x;    // x2 для рекуррентной формулы
    int k = 0;                   // Номер текущего слагаемого

    // 4. "Вычисляем сумму ряда Тейлора"
    while (fabs(term) > epsilon) {
        k++;
        // Вычисляем следующее слагаемое через предыдущее
        term = -term * x_squared / ((2.0 * k) * (2.0 * k + 1.0));
        sum += term;
    }

    // 5. "Возвращаем результат"
    return sum;
}

// ============================================================
// ФУНКЦИЯ ДЛЯ СРАВНЕНИЯ SIN(x) и sin(x) в 20 точках
// ============================================================
void compareSinValues() {
    // 1. "Создаем 20 точек на отрезке [0, 2pi]"
    const int num_points = 20;                // Количество точек
    const double start = 0.0;                 // Начало отрезка
    const double end = 2.0 * PI;            // Конец отрезка (2pi)
    const double step = (end - start) / (num_points - 1);  // Шаг между точками

    // 2. "Настраиваем формат вывода"
    cout << fixed << setprecision(10);        // 10 знаков после запятой
    cout << "Сравнение значений SIN(x) и sin(x) на отрезке [0, 2pi]:" << endl;
    cout << "=====================================================" << endl;
    cout << setw(12) << "x" << setw(20) << "SIN(x)"
        << setw(20) << "sin(x)" << setw(20) << "Разница" << endl;
    cout << "-----------------------------------------------------" << endl;

    // 3. "Вычисляем значения в каждой точке и выводим результаты"
    double max_diff = 0.0;      // Максимальная разница
    double total_diff = 0.0;    // Суммарная разница
    int point_num = 1;          // Номер точки (для вывода)

    for (int i = 0; i < num_points; i++) {
        // Вычисляем x для текущей точки
        double x = start + i * step;

        // Вычисляем синус двумя способами
        double my_sin = SIN(x);     // Наша функция
        double std_sin = sin(x);    // Стандартная функция

        // Вычисляем разницу
        double diff = fabs(my_sin - std_sin);

        // Обновляем статистику
        if (diff > max_diff) {
            max_diff = diff;
        }
        total_diff += diff;

        // Выводим значения для текущей точки
        cout << "Точка " << setw(2) << point_num << ": ";
        cout << setw(12) << x << setw(20) << my_sin
            << setw(20) << std_sin << setw(20) << diff << endl;

        point_num++;
    }

    // 4. "Выводим статистику"
    double avg_diff = total_diff / num_points;  // Средняя разница

    cout << "\nСтатистика сравнения:" << endl;
    cout << "=====================" << endl;
    cout << "Максимальная разница: " << max_diff << endl;
    cout << "Средняя разница: " << avg_diff << endl;
    cout << "Суммарная разница: " << total_diff << endl;

    // 5. "Выводим дополнительную информацию о точках"
    cout << "\nДополнительная информация:" << endl;
    cout << "==========================" << endl;
    cout << "Количество точек: " << num_points << endl;
    cout << "Начало отрезка: 0" << endl;
    cout << "Конец отрезка: " << end << " (2pi)" << endl;
    cout << "Шаг между точками: " << step << endl;

    // 6. "Выводим значения в особых точках для проверки"
    cout << "\nПроверка в особых точках:" << endl;
    cout << "========================" << endl;
    cout << setw(12) << "x" << setw(20) << "SIN(x)"
        << setw(20) << "sin(x)" << setw(20) << "Разница" << endl;
    cout << "-----------------------------------------------------" << endl;

    // Специальные точки, где значение синуса известно точно
    double special_points[] = { 0, PI / 6, PI / 4, PI / 3, PI / 2,
                               2 * PI / 3, 3 * PI / 4, 5 * PI / 6, PI,
                               7 * PI / 6, 5 * PI / 4, 4 * PI / 3, 3 * PI / 2,
                               5 * PI / 3, 7 * PI / 4, 11 * PI / 6, 2 * PI };

    const int num_special = sizeof(special_points) / sizeof(special_points[0]);

    for (int i = 0; i < num_special; i++) {
        double x = special_points[i];
        double my_sin = SIN(x);
        double std_sin = sin(x);
        double diff = fabs(my_sin - std_sin);

        cout << setw(12) << x << setw(20) << my_sin
            << setw(20) << std_sin << setw(20) << diff << endl;
    }
}