#include "Pentagon.h"
#include <cmath>
#include <numeric>

Pentagon::Pentagon(const std::vector<std::pair<double, double>>& vertices) : vertices(vertices) {}

std::pair<double, double> Pentagon::getGeometricCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vertex : vertices) {
        x_sum += vertex.first;
        y_sum += vertex.second;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

double Pentagon::getArea() const {
    double area = 0.0;
    int j = vertices.size() - 1;
    for (int i = 0; i < vertices.size(); i++) {
        area += (vertices[j].first + vertices[i].first) * (vertices[j].second - vertices[i].second);
        j = i;
    }
    return std::abs(area) / 2.0;
}

Figure* Pentagon::clone() const {
    return new Pentagon(*this);
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon with vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Pentagon::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 5; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}
