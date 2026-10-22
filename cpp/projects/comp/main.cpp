#include "comp.h"
#include <cmath>
#include <iostream>

int quadrant(const comp& z) {
    float x = z.Re();
    float y = z.Im();
    const float EPS = 1e-6f;

    if (std::abs(x) < EPS && std::abs(y) < EPS) return 0;
    if (std::abs(x) < EPS) return (y > 0) ? -2 : -4;
    if (std::abs(y) < EPS) return (x > 0) ? -1 : -3;
    if (x > 0 && y > 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x < 0 && y < 0) return 3;
    return 4;
}

int main() {
    // Тесты quadrant
    std::cout << "=== Test quadrant() ===\n";
    comp z;
    z = comp(0, 0);  std::cout << quadrant(z) << '\n';
    z = comp(1, 0);  std::cout << quadrant(z) << '\n';
    z = comp(1, 1);  std::cout << quadrant(z) << '\n';
    z = comp(0, 1);  std::cout << quadrant(z) << '\n';
    z = comp(-1, 1); std::cout << quadrant(z) << '\n';
    z = comp(-1, 0); std::cout << quadrant(z) << '\n';
    z = comp(-1, -1); std::cout << quadrant(z) << '\n';
    z = comp(0, -1); std::cout << quadrant(z) << '\n';
    z = comp(1, -1); std::cout << quadrant(z) << '\n';

    // Вычисление w
    std::cout << "\n=== Вычисление w ===\n";
    comp a(1.0f, 2.0f);
    comp b(3.0f, -1.0f);
    comp c(0.5f, 0.5f);

    comp w = 1.0f / b.cnj() +
        3.0f * ((2.0f * a - 3.0f * b) / (5.0f - c.cnj() * (4.0f - c))) +
        (b * c.cnj()) * 0.5f;

    std::cout << "w = " << w << '\n';
    std::cout << "|w| = " << w.mod() << '\n';
    std::cout << "arg(w) = " << w.arg() << " rad\n";

    system("pause");
    return 0;
}