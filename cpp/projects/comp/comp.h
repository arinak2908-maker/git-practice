#pragma once  // Директива предотвращения повторного включения файла

// Подключаем необходимые библиотеки
#include <iostream>   // Для оператора вывода <<
#include <cmath>      // Для математических функций: sqrt, atan2, M_PI
#include<corecrt_math_defines.h>

/*
 Комплексное число хранится как пара вещественных чисел:
 - x: вещественная часть (real part)
 - y: мнимая часть (imaginary part)
 */
class comp {
private:
    // ЗАКРЫТАЯ СЕКЦИЯ: поля данных 
    // Доступны только внутри класса - инкапсуляция данных
    float x;  // Вещественная часть комплексного числа
    float y;  // Мнимая часть комплексного числа

public:
    // ОТКРЫТАЯ СЕКЦИЯ: интерфейс класса 

    /*
     Конструктор с параметрами по умолчанию
     Вещественная часть (по умолчанию 0.0)
     Мнимая часть (по умолчанию 0.0)
     
     Позволяет создавать объекты тремя способами:
     - comp z;           -> z = (0, 0)
     - comp z(5.0f);     -> z = (5, 0)
     - comp z(3.0f, 2.0f) -> z = (3, 2)
     */
    comp(float r = 0.0f, float i = 0.0f) : x(r), y(i) {}

    //Простые функции для получения данных
    // Вещественная часть числа 
    float Re() const { return x; }

    // Мнимая часть числа 
    float Im() const { return y; }

    /* Вычисляет модуль комплексного числа |z| = sqrt(x**2 + y**2)
     Неотрицательное вещественное число - модуль
     Пример: для z = (3, 4) модуль = sqrt(9+16) = 5
     */
    float mod() const {
        return std::sqrt(x * x + y * y);
    }

    /*
     Вычисляет аргумент комплексного числа φ принадлежит [0, 2pi)
     Угол в радианах от 0 до 2pi
     Аргумент - это угол между положительной вещественной осью
     и вектором, представляющим комплексное число.
     Используем atan2 для корректной работы во всех квадрантах.
     */
    float arg() const {
        // atan2(y, x) возвращает угол в диапазоне (-pi, pi]
        // Преобразуем к диапазону [0, 2pi)
        float angle = std::atan2(y, x);//считаем угол
        if (angle < 0.0f) {//если угол отрицательный
            angle += 2.0f * static_cast<float>(M_PI);//делаем его положительным
        }
        return angle;
    }

    /*
     Возвращает комплексно-сопряжённое число
     Число с той же вещественной частью и противоположной мнимой
     Для z = x + i*y сопряжённое: z* = x - i*y
     Пример: cnj((3, 2)) -> (3, -2)
     меняется знак у мнимой части
     */
    comp cnj() const {
        return comp(x, -y);
    }

    // === Унарные операторы ===

    //Унарный плюс: возвращает копию числа (без изменений) 
    comp operator+() const {
        return *this;
    }

    /*
     Унарный минус: меняет знак обеих частей
     -z = (-x, -y)
     */
    comp operator-() const {
        return comp(-x, -y);
    }

    // === Бинарные арифметические операторы ===

    /*
      Сложение: (x1,y1) + (x2,y2) = (x1+x2, y1+y2)
     */
    comp operator+(const comp& z) const {
        return comp(x + z.x, y + z.y);
    }

    //Вычитание: (x1,y1) - (x2,y2) = (x1-x2, y1-y2)
    
    comp operator-(const comp& z) const {
        return comp(x - z.x, y - z.y);
    }

    //Умножение: (x1+iy1)(x2+iy2) = (x1x2-y1y2) + i(x1y2+y1x2)
     
    comp operator*(const comp& z) const {
        return comp(x * z.x - y * z.y, x * z.y + y * z.x);
    }

   //Деление: z1/z2=z1*z2*/|z2|**2
    comp operator/(const comp& z) const {
        float m2 = z.x * z.x + z.y * z.y;  // квадрат модуля
        if (m2 == 0.0f) {
            throw std::runtime_error("Division by zero complex number");
        }
        return comp((x * z.x + y * z.y) / m2,
            (y * z.x - x * z.y) / m2);
    }

    // === Операторы для работы с вещественным числом слева: float,  comp ===
    // Объявлены как дружественные, чтобы иметь доступ к приватным полям

    //Сложение: r + z = (r+x, y) 
    friend comp operator+(float f, const comp& z);

    //Вычитание: r - z = (r-x, -y) 
    friend comp operator-(float f, const comp& z);

    //Умножение: r * z = (r*x, r*y) 
    friend comp operator*(float f, const comp& z);

    //Деление: r / z = r · (1/z) 
    friend comp operator/(float f, const comp& z);

    /*
     Дружественная функция для вывода в поток
     Формат: (вещественная_часть,мнимая_часть)
     Пример: выводит в формате (3,2)
     для числа 3+2i
     */
    friend std::ostream& operator<<(std::ostream& os, const comp& z);
};

// ============================================================================
// РЕАЛИЗАЦИЯ ДРУЖЕСТВЕННЫХ ФУНКЦИЙ (вне класса)
// ============================================================================

//Сложение вещественного числа и комплексного: 5.0 + (3,2) = (8,2) 
inline comp operator+(float f, const comp& z) {
    return comp(f + z.x, z.y);
}

//Вычитание: 5.0 - (3,2) = (2,-2) мнимая часть меняет знак!!
inline comp operator-(float f, const comp& z) {
    return comp(f - z.x, -z.y);  // Внимание: меняем знак мнимой части!
}

//Умножение: 2.0 * (3,4) = (6,8) 
inline comp operator*(float f, const comp& z) {
    return comp(f * z.x, f * z.y);
}

//Деление: 10.0 / (2,0) = (5,0) 
inline comp operator/(float f, const comp& z) {
    return comp(f, 0.0f) / z;  // Преобразуем вещественное к комплексному и делим
}

/*
 Оператор вывода в поток
 Формат строго по заданию: (вещественная,мнимая)
 (3,2) будет как (3,2)
 */
inline std::ostream& operator<<(std::ostream& os, const comp& z) {
    os << '(' << z.x << ',' << z.y << ')';
    return os;  // Возвращаем поток для поддержки цепочки вызовов: cout << z1 << z2;
}
