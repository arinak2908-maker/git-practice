#pragma once                      // Защита от повторного включения файла
#include <iostream>               // Подключаем библиотеку для ввода/вывода

using std::cin;                   // Используем cin из пространства std
using std::cout;                  // Используем cout из пространства std
using std::endl;                  // Используем endl из пространства std

// Функция для преобразования числа в массив бит
void convertToBinary(unsigned short number, unsigned char binaryArray[16]) {
    // "Преобразуем число в двоичное представление"
    // Проходим по всем 16 битам
    for (int i = 0; i < 16; ++i) {
        // Сдвигаем число на i бит вправо и смотрим на младший бит
        binaryArray[i] = (number >> i) & 1;
    }
}

// Функция для вывода битового представления числа
void printBinary16(const unsigned char binaryArray[16]) {
    // "Выводим биты начиная со старшего (15-го) до младшего (0-го)"
    for (int i = 15; i >= 0; --i) {
        cout << (int)binaryArray[i];  // Выводим бит как число (0 или 1)
        if (i % 8 == 0 && i != 0) {
            cout << " ";  // Разделитель между байтами (каждые 8 бит)
        }
    }
}

// Функция для сложения двух двоичных чисел
void binaryAddition(const unsigned char a[16], const unsigned char b[16],
    unsigned char result[17], bool& overflow) {
    unsigned char carry = 0;  // "Перенос" при сложении
    overflow = false;         // Флаг переполнения изначально false

    // "Складываем биты по одному, начиная с младших"
    for (int i = 0; i < 16; ++i) {
        // "Суммируем биты из обоих чисел и перенос с предыдущего шага"
        unsigned char sum = a[i] + b[i] + carry;

        // "Определяем текущий бит результата (сумма mod 2)"
        result[i] = sum % 2;

        // "Определяем новый перенос (целая часть от деления суммы на 2)"
        carry = sum / 2;
    }

    // "Сохраняем оставшийся перенос как 17-й бит"
    result[16] = carry;
    // "Если есть перенос из 16-го бита - произошло переполнение"
    overflow = (carry == 1);
}

// Функция для преобразования массива бит обратно в число
unsigned short convertToDecimal(const unsigned char binaryArray[16]) {
    unsigned short result = 0;  // Начинаем с 0

    // "Проходим по всем битам и собираем число"
    for (int i = 0; i < 16; ++i) {
        if (binaryArray[i] == 1) {
            // "Если бит равен 1, добавляем соответствующую степень двойки"
            result |= (1 << i);
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, ".1251");   // Устанавливаем русскую кодировку для вывода текста

    cout << "Задание: Написать алгоритм сложения 16-разрядных двоичных чисел. ";
    cout << "Для этого использовать «школьный» алгоритм сложения в столбик. ";
    cout << "Биты (двоичные цифры) слагаемых хранить в двух 16-элементных массивах типа unsigned char. ";
    cout << "Проверить работу программы: ввести два числа типа unsigned short. ";
    cout << "Получить их двоичное представление – для этого использовать результаты задачи №14. ";
    cout << "Выполнить алгоритм. Результат преобразовать в обычное десятичное число и вывести на экран ";
    cout << "(тем самым проверив правильность работы вашего алгоритма). ";
    cout << "Замечание. Предусмотреть возможность переполнения.\n" << endl;

    // 1. "Вводим два числа для сложения"
    unsigned short num1, num2;
    cout << "Введите первое число (unsigned short): ";
    cin >> num1;
    cout << "Введите второе число (unsigned short): ";
    cin >> num2;

    // 2. "Преобразуем числа в двоичное представление"
    unsigned char binary1[16] = { 0 };  // Массив для битов первого числа
    unsigned char binary2[16] = { 0 };  // Массив для битов второго числа

    convertToBinary(num1, binary1);
    convertToBinary(num2, binary2);

    // 3. "Выводим двоичное представление чисел"
    cout << "\nДвоичное представление чисел:" << endl;
    cout << "Первое число: ";
    printBinary16(binary1);
    cout << " (десятичное: " << num1 << ")" << endl;

    cout << "Второе число: ";
    printBinary16(binary2);
    cout << " (десятичное: " << num2 << ")" << endl;

    // 4. "Выполняем сложение двоичных чисел"
    unsigned char result[17] = { 0 };  // Массив для результата (16 бит + 1 бит переполнения)
    bool overflow = false;           // Флаг переполнения

    binaryAddition(binary1, binary2, result, overflow);

    // 5. "Выводим результат сложения (17 бит)"
    cout << "\nРезультат сложения (17 бит): ";
    for (int i = 16; i >= 0; --i) {
        cout << (int)result[i];
        if (i == 16) cout << " ";  // Пробел после бита переполнения
        else if (i % 8 == 0 && i != 0) cout << " ";  // Пробелы между байтами
    }
    cout << endl;

    // 6. "Преобразуем результат обратно в десятичное число"
    unsigned char result16[16] = { 0 };  // Только младшие 16 бит
    for (int i = 0; i < 16; ++i) {
        result16[i] = result[i];
    }

    unsigned short decimalResult = convertToDecimal(result16);

    cout << "\nРезультат (16 младших бит): ";
    printBinary16(result16);
    cout << " (десятичное: " << decimalResult << ")" << endl;

    // 7. "Проверяем переполнение"
    if (overflow) {
        cout << "Флаг переполнения: ДА (произошло переполнение)" << endl;
        cout << "Полный результат (с учетом переполнения): "
            << (unsigned int)(decimalResult + (1 << 16)) << endl;
    }
    else {
        cout << "Флаг переполнения: НЕТ (переполнения не было)" << endl;
    }

    // 8. "Проверяем правильность работы алгоритма"
    unsigned int expected = (unsigned int)num1 + (unsigned int)num2;
    cout << "\nПроверка: " << num1 << " + " << num2 << " = " << expected << endl;

    if (overflow) {
        cout << "Результат сложения (без учета переполнения): "
            << (expected & 0xFFFF) << endl;
        cout << "Правильный результат (с переполнением): " << expected << endl;

        if ((expected & 0xFFFF) == decimalResult) {
            cout << "Алгоритм работает правильно (переполнение учтено)!" << endl;
        }
        else {
            cout << "Ошибка в алгоритме!" << endl;
        }
    }
    else {
        cout << "Результат сложения: " << decimalResult << endl;
        if (decimalResult == expected) {
            cout << "Алгоритм работает правильно!" << endl;
        }
        else {
            cout << "Ошибка в алгоритме!" << endl;
        }
    }

    // 9. "Пример сложения с переполнением"
    cout << "\nПример сложения с переполнением (необязательная часть):" << endl;
    cout << "65535 + 1 = 65536, но в unsigned short помещается только 0" << endl;

    unsigned short test1 = 65535;
    unsigned short test2 = 1;
    unsigned char test_binary1[16] = { 0 };
    unsigned char test_binary2[16] = { 0 };

    convertToBinary(test1, test_binary1);
    convertToBinary(test2, test_binary2);

    unsigned char test_result[17] = { 0 };
    bool test_overflow = false;

    binaryAddition(test_binary1, test_binary2, test_result, test_overflow);

    cout << "65535 в двоичном: ";
    printBinary16(test_binary1);
    cout << endl;

    cout << "1 в двоичном:     ";
    printBinary16(test_binary2);
    cout << endl;

    cout << "Результат сложения: ";
    for (int i = 16; i >= 0; --i) {
        cout << (int)test_result[i];
        if (i == 16) cout << " ";
    }
    cout << endl;

    cout << "Переполнение: " << (test_overflow ? "ДА" : "НЕТ") << endl;

    cout << endl;
    system("pause"); // Ожидаем нажатия клавиши перед закрытием окна
}