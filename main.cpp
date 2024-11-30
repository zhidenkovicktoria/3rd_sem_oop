#include <iostream>
#include "Twelve.h"

int main() {
    try {
        // Создание объектов класса Twelve
        Twelve num1("1A");
        Twelve num2("2B");

        // Вывод исходных чисел
        std::cout << "num1: " << num1.toString() << std::endl;
        std::cout << "num2: " << num2.toString() << std::endl;

        // Сложение
        Twelve sum = num1 + num2;
        std::cout << "num1 + num2: " << sum.toString() << std::endl;

        // Присваивание с операцией
        num1 += num2;
        std::cout << "num1 += num2: " << num1.toString() << std::endl;


    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
