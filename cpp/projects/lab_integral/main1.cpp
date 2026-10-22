#include <iostream>
// для вывода (cout)
#define _USE_MATH_DEFINES
#include <math.h>
// для sin, sqrt, pow

#include "quad1.h"
// подключаем наши методы интегрирования

using namespace std;
// чтобы не писать std::


double f1(double x) {
    // функция x^2
    return x * x;
}

double f2(double x) {
    // функция sqrt(2 - x^2)
    return sqrt(2 - x * x);
}

double f3(double x) {
    // функция sin(x)
    return sin(x);
}



int main() {
    setlocale(LC_ALL, "RUSSIAN");

    size_t n;
    // сюда будут записываться числа разбиений

    double J;
    // значение интеграла

    double eps;
    // точность



    cout << "Интеграл sin(x) на [0, pi]\n\n";
    // вывод заголовка



    for (int i = 1; i <= 12; ++i) {
        // цикл по точности: 10^-1 ... 10^-12

        eps = pow(10, -i);
        // вычисляем eps = 10^-i



        cout << "eps = " << eps << endl;
        // вывод текущей точности



        J = left_rect(f3, 0, M_PI, eps, n);
        // считаем методом левых прямоугольников

        cout << "Left      J = " << J << "   N = " << n << endl;
        // вывод результата



        J = mid_rect(f3, 0, M_PI, eps, n);
        // метод средних прямоугольников

        cout << "Mid       J = " << J << "   N = " << n << endl;



        J = trapezoid(f3, 0, M_PI, eps, n);
        // метод трапеций

        cout << "Trapezoid J = " << J << "   N = " << n << endl;



        J = simpson(f3, 0, M_PI, eps, n);
        // метод Симпсона

        cout << "Simpson   J = " << J << "   N = " << n << endl;


        cout << "-----------------------------\n";

    }

    return 0;
    // завершение программы
}