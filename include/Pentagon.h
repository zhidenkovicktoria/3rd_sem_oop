#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <vector>

class Pentagon : public Figure {
public:
    Pentagon(const std::vector<std::pair<double, double>>& vertices);

    std::pair<double, double> getGeometricCenter() const override;
    double getArea() const override;

    Figure* clone() const override;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::vector<std::pair<double, double>> vertices;

    // Добавляем конструктор копирования и перемещения
    Pentagon(const Pentagon& other) = default;
    Pentagon(Pentagon&& other) noexcept = default;
};

#endif // PENTAGON_H
