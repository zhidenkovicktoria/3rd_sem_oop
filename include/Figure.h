#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>
#include <vector>

class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<double, double> getGeometricCenter() const = 0;
    virtual double getArea() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);

    virtual Figure* clone() const = 0;

    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;

    bool operator==(const Figure& other) const;

protected:
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    // Добавляем конструктор копирования и перемещения
    Figure(const Figure& other) = default;
    Figure(Figure&& other) noexcept = default;

    // Добавляем конструктор по умолчанию
    Figure() = default;
};

#endif // FIGURE_H
