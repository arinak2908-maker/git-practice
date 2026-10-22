#pragma once                      // Защита от повторного включения файла
#include <iostream>               // Подключаем библиотеку для ввода/вывода

using std::cin;                   // Используем cin из пространства std
using std::cout;                  // Используем cout из пространства std
using std::endl;                  // Используем endl из пространства std

// Функция для вывода битового представления числа 
template<typename T>
void printBinary(T value, int byteCount) {
    // Проходим по всем байтам (от старшего к младшему)
    for (int byte = byteCount - 1; byte >= 0; --byte) {
        // Проходим по всем битам в байте (от старшего к младшему)
        for (int bit = 7; bit >= 0; --bit) {
            // Сдвигаем значение, чтобы получить нужный бит
            // Сначала сдвигаем на (byte * 8 + bit) бит вправо, чтобы нужный бит стал младшим
            // Затем применяем маску 1 (побитовое И) для получения значения этого бита
            if ((value >> (byte * 8 + bit)) & 1) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        // Разделяем байты пробелом (кроме последнего)
        if (byte > 0) {
            cout << ' ';
        }
    }
}

int main() {
    setlocale(LC_ALL, ".1251");   // Устанавливаем русскую кодировку для вывода текста

    cout << "Задание: В программе определить три переменные a1, a2, a4 типа ";
    cout << "unsigned char, unsigned short и unsigned long соответственно. ";
    cout << "С клавиатуры вводится целое число b типа size_t, затем его значение ";
    cout << "присваивается указанным выше переменным. Вывести на экран битовое ";
    cout << "(двоичное) представление переменных a1, a2 и a4. ";
    cout << "Байты (группы из 8 двоичных разрядов) отделять друг от друга пробелами.\n" << endl;

    // 1. "Определяем три переменные разных типов"
    unsigned char a1;      // Переменная размером 1 байт (8 бит)
    unsigned short a2;     // Переменная размером 2 байта (16 бит)
    unsigned long a4;      // Переменная размером 4 байта (32 бита) 

    // 2. "Вводим число b типа size_t"
    size_t b;// создаёт переменную для хранения размеров объектов в памяти
    cout << "Введите целое число b типа size_t: ";
    cin >> b;

    // 3. "Присваиваем значение b всем трем переменным"
    a1 = static_cast<unsigned char>(b);   // Сохраняем только младшие 8 бит

    //static — потому что преобразование происходит во время компиляции (статически)
    //cast — английское "приведение", "преобразование"
    //static_cast - По сути он берёт большое число и отрезает от него кусочек, чтобы он поместился в маленькую переменную.

    a2 = static_cast<unsigned short>(b);  // Сохраняем только младшие 16 бит
    a4 = static_cast<unsigned long>(b);   // Сохраняем значение как есть

    // 4. "Выводим размеры типов данных в байтах"
    cout << "\nРазмеры типов данных в байтах:" << endl;
    cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << endl;
    cout << "sizeof(unsigned short) = " << sizeof(unsigned short) << endl;
    cout << "sizeof(unsigned long) = " << sizeof(unsigned long) << endl;
    cout << "sizeof(size_t) = " << sizeof(size_t) << endl;

    // 5. "Выводим битовое представление каждой переменной"
    cout << "\nБитовое представление:" << endl;

    cout << "a1 = ";
    printBinary(a1, sizeof(a1));
    cout << endl;

    cout << "a2 = ";
    printBinary(a2, sizeof(a2));
    cout << endl;

    cout << "a4 = ";
    printBinary(a4, sizeof(a4));
    cout << endl;

    // 6. "Выводим значения переменных для проверки"
    cout << "\nЗначения переменных:" << endl;
    cout << "a1 (unsigned char) = " << static_cast<int>(a1) << endl;
    cout << "a2 (unsigned short) = " << a2 << endl;
    cout << "a4 (unsigned long) = " << a4 << endl;

    cout << endl;
    system("pause");
}