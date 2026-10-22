#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

double SIN(double x, double eps = 1e-10) {
    double s = 0.0, t = x;


    int k;
    for (k = 1; fabs(t) > eps; k++) {
        s += t;
        t *= (-x * x) / ((2 * k) * (2 * k + 1));
    }
    return s;
}

int main() {
    setlocale(LC_ALL, ".1251");

    cout << "sin(0) написанный == " << SIN(0) << " \t \t \t \t \t \t sin(0) встроенный == " << sin(0) << "\n";
    cout << "sin(PI/10) написанный == " << SIN(M_PI / 10) << " \t \t \t \t sin(PI/10) встроенный == " << sin(M_PI / 10) << "\n";
    cout << "sin(PI/5) написанный == " << SIN(M_PI / 5) << " \t \t \t \t sin(PI/5) встроенный == " << sin(M_PI / 5) << "\n";
    cout << "sin(PI*3/10) написанный == " << SIN(M_PI * 3 / 10) << " \t \t \t \t sin(PI*/10) встроенный == " << sin(M_PI * 3 / 10) << "\n";
    cout << "sin(PI*2/5) написанный == " << SIN(M_PI * 2 / 5) << " \t \t \t \t sin(PI*2/5) встроенный == " << sin(2 * M_PI / 5) << "\n";
    cout << "sin(PI/2) написанный == " << SIN(M_PI / 2) << " \t \t \t \t \t sin(PI/2) встроенный == " << sin(M_PI / 2) << "\n";
    cout << "sin(PI*3/5) написанный == " << SIN(M_PI * 3 / 5) << " \t \t \t \t sin(PI*3/5) встроенный == " << sin(M_PI * 3 / 5) << "\n";
    cout << "sin(PI*4/5) написанный == " << SIN(M_PI * 4 / 5) << " \t \t \t \t sin(PI*4/5) встроенный == " << sin(M_PI * 4 / 5) << "\n";
    cout << "sin(PI/6) написанный == " << SIN(M_PI / 6) << " \t \t \t \t \t sin(PI/6) встроенный == " << sin(M_PI / 6) << "\n";
    cout << "sin(PI/4) написанный == " << SIN(M_PI / 4) << " \t \t \t \t sin(PI/4) встроенный == " << sin(M_PI / 4) << "\n";
    cout << "sin(PI*11/10) написанный == " << SIN(M_PI * 11 / 10) << " \t \t \t \t sin(PI*11/10) встроенный == " << sin(M_PI * 11 / 10) << "\n";
    cout << "sin(PI*6/5) написанный == " << SIN(M_PI * 6 / 5) << " \t \t \t \t sin(PI*6/5) встроенный == " << sin(M_PI * 6 / 5) << "\n";
    cout << "sin(PI*13/10) написанный == " << SIN(M_PI * 13 / 10) << " \t \t \t \t sin(PI*13/10) встроенный == " << sin(M_PI * 13 / 10) << "\n";
    cout << "sin(PI*7/5) написанный == " << SIN(M_PI * 7 / 5) << " \t \t \t \t sin(PI*7/5) встроенный == " << sin(M_PI * 7 / 5) << "\n";
    cout << "sin(PI*3/2) написанный == " << SIN(M_PI * 3 / 2) << " \t \t \t \t \t sin(PI*3/2) встроенный == " << sin(M_PI * 3 / 2) << "\n";
    cout << "sin(PI*8/5) написанный == " << SIN(M_PI * 8 / 5) << " \t \t \t \t sin(PI*8/5) встроенный == " << sin(M_PI * 8 / 5) << "\n";
    cout << "sin(PI*17/10) написанный == " << SIN(M_PI * 17 / 10) << " \t \t \t \t sin(PI*17/10) встроенный == " << sin(M_PI * 17 / 10) << "\n";
    cout << "sin(PI*9/5) написанный == " << SIN(M_PI * 9 / 5) << " \t \t \t \t sin(PI*9/5) встроенный == " << sin(M_PI * 9 / 5) << "\n";
    cout << "sin(PI*19/10) написанный == " << SIN(M_PI * 19 / 10) << " \t \t \t \t sin(PI*19/10) встроенный == " << sin(M_PI * 19 / 10) << "\n";
    cout << "sin(PI/5) написанный == " << SIN(M_PI / 5) << " \t \t \t \t sin(PI/5) встроенный == " << sin(M_PI / 5) << "\n";


    cout << endl;
    system("pause");
}