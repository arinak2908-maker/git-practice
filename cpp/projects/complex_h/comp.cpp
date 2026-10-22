// main.cpp — реализация класса + функция main
#include "comp.h"

// ========== РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА ==========

// Конструктор: список инициализации :x(r), y(i) — эффективнее присваивания
comp::comp(float r, float i) : x(r), y(i) {}

float comp::mod() const {
    return std::sqrt(x * x + y * y);
}

// arg(): используем atan2 — он корректно определяет квадрант
// Возвращает угол в [0; 2π)
float comp::arg() const {
    float a = std::atan2(y, x);  // диапазон [-π; π]
    return (a < 0) ? a + 2.0f * static_cast<float>(M_PI) : a;
}

comp comp::cnj() const {
    return comp(x, -y);  // сопряжённое: меняем знак мнимой части
}

comp comp::operator+() const { return *this; }
comp comp::operator-() const { return comp(-x, -y); }

comp comp::operator+(const comp& z) const {
    return comp(x + z.x, y + z.y);
}

comp comp::operator-(const comp& z) const {
    return comp(x - z.x, y - z.y);
}

comp comp::operator*(const comp& z) const {
    // (x+iy)*(u+iv) = (xu-yv) + i(xv+yu)
    return comp(x * z.x - y * z.y, x * z.y + y * z.x);
}

comp comp::operator/(const comp& z) const {
    // z1/z2 = z1 * conj(z2) / |z2|²
    float m2 = z.x * z.x + z.y * z.y;  // квадрат модуля
    if (m2 == 0.0f) throw "Division by zero";
    return comp(
        (x * z.x + y * z.y) / m2,
        (y * z.x - x * z.y) / m2
    );
}

// ========== FRIEND-ФУНКЦИИ (реализация снаружи) ==========

comp operator+(float f, const comp& z) { return comp(f + z.x, z.y); }
comp operator-(float f, const comp& z) { return comp(f - z.x, -z.y); }
comp operator*(float f, const comp& z) { return comp(f * z.x, f * z.y); }
comp operator/(float f, const comp& z) { return comp(f, 0.0f) / z; }

// Вывод: формат (вещественная,мнимая) — как в задании
std::ostream& operator<<(std::ostream& os, const comp& z) {
    os << '(' << z.x << ',' << z.y << ')';
    return os;  // возвращаем поток для цепочки: cout << a << b;
}

// ========== ФУНКЦИЯ quadrant (из задания №2) ==========
int quadrant(const comp& z) {
    float x = z.x, y = z.y;
    const float EPS = 1e-6f;  // погрешность для float-сравнений

    if (std::abs(x) < EPS && std::abs(y) < EPS) return 0;
    if (std::abs(x) < EPS) return (y > 0) ? -2 : -4;
    if (std::abs(y) < EPS) return (x > 0) ? -1 : -3;
    if (x > 0 && y > 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x < 0 && y < 0) return 3;
    return 4;  // x>0, y<0
}

// ========== MAIN: тесты + вычисление w ==========
int main() {
    // --- Тест quadrant() из задания ---
    std::cout << "=== Test quadrant() ===\n";
    comp z;
    z = comp(0, 0);  std::cout << quadrant(z) << '\n';  // 0
    z = comp(1, 0);  std::cout << quadrant(z) << '\n';  // -1
    z = comp(1, 1);  std::cout << quadrant(z) << '\n';  // 1
    z = comp(0, 1);  std::cout << quadrant(z) << '\n';  // -2
    z = comp(-1, 1); std::cout << quadrant(z) << '\n';  // 2
    z = comp(-1, 0); std::cout << quadrant(z) << '\n';  // -3
    z = comp(-1, -1); std::cout << quadrant(z) << '\n';  // 3
    z = comp(0, -1); std::cout << quadrant(z) << '\n';  // -4
    z = comp(1, -1); std::cout << quadrant(z) << '\n';  // 4

    // --- Вычисление выражения w (ваша формула) ---
    std::cout << "\n=== Вычисление w ===\n";

    // Задайте значения a, b, c (пример):
    comp a(1.0f, 2.0f);   // 1 + 2i
    comp b(3.0f, -1.0f);  // 3 - i
    comp c(0.5f, 0.5f);   // 0.5 + 0.5i

    // Ваша формула:
    // w = 1 / b.con() + 3 * ((2 * a - 3 * b) / (5 - c.con() * (4 - c))) + (b * c.con()) * 0.5f;
    comp w =
        1.0f / b.cnj() +
        3.0f * ((2.0f * a - 3.0f * b) / (5.0f - c.cnj() * (4.0f - c))) +
        (b * c.cnj()) * 0.5f;

    std::cout << "w = " << w << '\n';
    std::cout << "|w| = " << w.mod() << '\n';
    std::cout << "arg(w) = " << w.arg() << " rad\n";

    system("pause");
    return 0;
}