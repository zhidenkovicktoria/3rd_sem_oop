#include <iostream>
#include "binary_representation.h"

int main() {
    int n;
    std::cout << "Введите целое число: ";
    std::cin >> n;

    std::string binaryString = intToBinaryString(n);
    std::cout << "Двоичное представление: " << binaryString << std::endl;

    return 0;
}
