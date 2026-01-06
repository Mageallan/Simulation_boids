#include <iostream>
#include "Vec2.h"

int main() {
    using namespace bd;

    std::cout << "=== TEST VEC2 ===\n";

    Vec2<float> a(3.f, 4.f);
    Vec2<float> b(1.f, 2.f);

    // Test affichage
    std::cout << "a = " << a << " (attendu : (3, 4))\n";
    std::cout << "b = " << b << " (attendu : (1, 2))\n";

    // Test addition
    Vec2<float> c = a + b;
    std::cout << "a + b = " << c << " (attendu : (4, 6))\n";

    // Test soustraction
    Vec2<float> d = a - b;
    std::cout << "a - b = " << d << " (attendu : (2, 2))\n";

    // Test multiplication scalaire
    Vec2<float> e = a * 2.f;
    std::cout << "a * 2 = " << e << " (attendu : (6, 8))\n";

    // Test division scalaire
    Vec2<float> f = a / 2.f;
    std::cout << "a / 2 = " << f << " (attendu : (1.5, 2))\n";

    // Test opérateurs composés
    Vec2<float> g = a;
    g += b;
    std::cout << "g += b -> " << g << " (attendu : (4, 6))\n";

    g = a;
    g -= b;
    std::cout << "g -= b -> " << g << " (attendu : (2, 2))\n";

    g = a;
    g *= 3.f;
    std::cout << "g *= 3 -> " << g << " (attendu : (9, 12))\n";

    g = a;
    g /= 2.f;
    std::cout << "g /= 2 -> " << g << " (attendu : (1.5, 2))\n";

    // Test norme
    float n = a.norme();
    std::cout << "norme(a) = " << n << " (attendu : 5)\n";

    // Test normalized
    Vec2<float> h = a.normalized();
    std::cout << "a.normalized() = " << h << " (attendu approx : (0.6, 0.8))\n";

    // Test normalized sur vecteur nul
    Vec2<float> zero(0.f, 0.f);
    Vec2<float> z = zero.normalized();
    std::cout << "zero.normalized() = " << z << " (attendu : (0, 0))\n";

    // Test comparaisons
    std::cout << "a == a ? " << (a == a) << " (attendu : 1)\n";
    std::cout << "a == b ? " << (a == b) << " (attendu : 0)\n";
    std::cout << "a != b ? " << (a != b) << " (attendu : 1)\n";

    return 0;
}
