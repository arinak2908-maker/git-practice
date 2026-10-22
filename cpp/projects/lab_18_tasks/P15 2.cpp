#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

double SIN(double x, double eps = 1e-12) {
    double s = 0.0, t = x;
    int k;
    for (k = 1; fabs(t) > eps; k++) {
        //fabs - Не важно, положительное число t или отрицательное — дай мне его размер без знака!
        //для вещ чисел и показывает насколько(т.е измеряет сам размер)
        s += t;
        t *= (-x * x) / ((2 * k) * (2 * k + 1));
    }
    return s;
}

int main() {
    setlocale(LC_ALL, ".1251");

    cout << "sin(0) = " << SIN(0) << endl;
    cout << "sin(pi) = " << SIN(M_PI) << endl;
    cout << "sin(pi/2) = " << SIN(M_PI / 2) << endl;
    cout << "sin(pi/4) = " << SIN(M_PI / 4) << endl;
    cout << "sin(pi/6) = " << SIN(M_PI / 6)  << endl;


    cout << endl;
    system("pause");
}