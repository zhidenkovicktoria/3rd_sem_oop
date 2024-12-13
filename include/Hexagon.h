#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <vector>

class Hexagon : public Figure {
public:
    Hexagon(const std::vector<std::pair<double, double>>& vertices);

    std::pair<double, double> getGeometricCenter() const override;
    double getArea() const override;

    Figure* clone() const override;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::vector<std::pair<double, double>> vertices;

    // Добавляем конструктор копирования и перемещения
    Hexagon(const Hexagon& other) = default;
    Hexagon(Hexagon&& other) noexcept = default;
};

#endif // HEXAGON_H
