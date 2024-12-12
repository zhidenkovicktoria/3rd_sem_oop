#include "Hexagon.h"
#include <cmath>
#include <numeric>

Hexagon::Hexagon(const std::vector<std::pair<double, double>>& vertices) : vertices(vertices) {}

std::pair<double, double> Hexagon::getGeometricCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vertex : vertices) {
        x_sum += vertex.first;
        y_sum += vertex.second;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

double Hexagon::getArea() const {
    double area = 0.0;
    int j = vertices.size() - 1;
    for (int i = 0; i < vertices.size(); i++) {
        area += (vertices[j].first + vertices[i].first) * (vertices[j].second - vertices[i].second);
        j = i;
    }
    return std::abs(area) / 2.0;
}

Figure* Hexagon::clone() const {
    return new Hexagon(*this);
}

void Hexagon::print(std::ostream& os) const {
    os << "Hexagon with vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Hexagon::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 6; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}
