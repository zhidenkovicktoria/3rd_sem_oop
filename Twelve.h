#ifndef TWELVE_H
#define TWELVE_H

#include <vector>
#include <stdexcept>
#include <string>
#include <initializer_list>

// Класс Twelve для работы с беззнаковыми целыми двенадцатиричными числами
class Twelve {
public:
    // Конструктор по умолчанию
    Twelve();

    // Конструктор, инициализирующий массив заданным количеством элементов
    Twelve(const size_t & n, unsigned char t = 0);

    // Конструктор, инициализирующий массив списком инициализации
    Twelve(const std::initializer_list<unsigned char> &t);

    // Конструктор, инициализирующий массив строкой
    Twelve(const std::string &t);

    // Конструктор копирования
    Twelve(const Twelve& other);

    // Конструктор перемещения
    Twelve(Twelve&& other) noexcept;

    // Деструктор
    ~Twelve() noexcept;

    // Оператор присваивания копированием
    Twelve& operator=(const Twelve& other);

    // Оператор присваивания перемещением
    Twelve& operator=(Twelve&& other) noexcept;

    // Оператор сложения
    Twelve operator+(const Twelve& other) const;

    // Оператор вычитания
    Twelve operator-(const Twelve& other) const;

    // Оператор сложения с присваиванием
    Twelve& operator+=(const Twelve& other);

    // Оператор вычитания с присваиванием
    Twelve& operator-=(const Twelve& other);

    // Оператор равенства
    bool operator==(const Twelve& other) const;

    // Оператор неравенства
    bool operator!=(const Twelve& other) const;

    // Оператор меньше
    bool operator<(const Twelve& other) const;

    // Оператор больше
    bool operator>(const Twelve& other) const;

    // Оператор меньше или равно
    bool operator<=(const Twelve& other) const;

    // Оператор больше или равно
    bool operator>=(const Twelve& other) const;

    // Метод для преобразования числа в строку
    std::string toString() const;

private:
    // Вектор для хранения цифр числа
    std::vector<unsigned char> digits;

    // Исходная строка, если была передана в конструктор
    std::string originalString;

    // Метод для нормализации числа (удаление ведущих нулей)
    void normalize();

    // Метод для добавления цифры в число
    void addDigit(unsigned char digit);

    // Метод для преобразования символа в цифру
    static unsigned char toDigit(char c);

    // Метод для преобразования цифры в символ
    static char toChar(unsigned char digit);
};

#endif // TWELVE_H
