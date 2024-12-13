#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"
#include <vector>

class Octagon : public Figure {
public:
    Octagon(const std::vector<std::pair<double, double>>& vertices);

    std::pair<double, double> getGeometricCenter() const override;
    double getArea() const override;

    Figure* clone() const override;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::vector<std::pair<double, double>> vertices;

    // Добавляем конструктор копирования и перемещения
    Octagon(const Octagon& other) = default;
    Octagon(Octagon&& other) noexcept = default;
};

#endif // OCTAGON_H
