#include <iostream>
#include "DynamicArray.h"

int main() {
    using namespace bd;

    DynamicArray<int> arr;

    std::cout << "Capacité initiale : " << arr.capacity() << "\n";

    // Test push_back
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    std::cout << "Taille après push_back : " << arr.size() << " (attendu : 3)\n";

    // Test operator[]
    std::cout << "arr[0] = " << arr[0] << " (attendu : 10)\n";
    std::cout << "arr[1] = " << arr[1] << " (attendu : 20)\n";
    std::cout << "arr[2] = " << arr[2] << " (attendu : 30)\n";

    // Test resize automatique
    for (int i = 0; i < 20; ++i) {
        arr.push_back(i);
    }

    std::cout << "Taille après ajout de 20 éléments : " << arr.size() << "\n";
    std::cout << "Nouvelle capacité : " << arr.capacity() << " (doit être > 10)\n";

    // Test exception
    try {
        std::cout << arr[999] << "\n"; // doit lancer une exception
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception capturée : " << e.what() << "\n";
    }

    return 0;
}
