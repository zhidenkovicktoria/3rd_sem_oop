#include "solution.h"

// Реализация методов для класса Point
template <Scalar T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <Scalar T>
T Point<T>::getX() const {
    return x;
}

template <Scalar T>
T Point<T>::getY() const {
    return y;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

template <Scalar T>
std::istream& operator>>(std::istream& is, Point<T>& point) {
    is >> point.x >> point.y;
    return is;
}

// Реализация методов для класса Figure
template <Scalar T>
Figure<T>& Figure<T>::operator=(const Figure<T>& other) {
    if (this != &other) {
        *this = *other.clone();
    }
    return *this;
}

template <Scalar T>
Figure<T>& Figure<T>::operator=(Figure<T>&& other) noexcept {
    if (this != &other) {
        *this = std::move(*other.clone());
    }
    return *this;
}

template <Scalar T>
bool Figure<T>::operator==(const Figure<T>& other) const {
    return getArea() == other.getArea() && getGeometricCenter() == other.getGeometricCenter();
}

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
    figure.print(os);
    return os;
}

template <Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    figure.read(is);
    return is;
}

// Реализация методов для класса Pentagon
template <Scalar T>
Pentagon<T>::Pentagon(std::vector<std::unique_ptr<Point<T>>> vertices) : vertices(std::move(vertices)) {}

template <Scalar T>
std::pair<T, T> Pentagon<T>::getGeometricCenter() const {
    T x_sum = 0, y_sum = 0;
    for (const auto& vertex : vertices) {
        x_sum += vertex->getX();
        y_sum += vertex->getY();
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

template <Scalar T>
T Pentagon<T>::getArea() const {
    T area = 0;
    int j = vertices.size() - 1;
    for (size_t i = 0; i < vertices.size(); i++) {
        area += (vertices[j]->getX() + vertices[i]->getX()) * (vertices[j]->getY() - vertices[i]->getY());
        j = i;
    }
    return std::abs(area) / 2;
}

template <Scalar T>
Figure<T>* Pentagon<T>::clone() const {
    std::vector<std::unique_ptr<Point<T>>> new_vertices;
    for (const auto& vertex : vertices) {
        new_vertices.emplace_back(std::make_unique<Point<T>>(vertex->getX(), vertex->getY()));
    }
    return new Pentagon(std::move(new_vertices));
}

template <Scalar T>
void Pentagon<T>::print(std::ostream& os) const {
    os << "Pentagon with vertices: ";
    for (const auto& vertex : vertices) {
        os << *vertex << " ";
    }
}

template <Scalar T>
void Pentagon<T>::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 5; ++i) {
        T x, y;
        is >> x >> y;
        vertices.emplace_back(std::make_unique<Point<T>>(x, y));
    }
}

// Реализация методов для класса Hexagon
template <Scalar T>
Hexagon<T>::Hexagon(std::vector<std::unique_ptr<Point<T>>> vertices) : vertices(std::move(vertices)) {}

template <Scalar T>
std::pair<T, T> Hexagon<T>::getGeometricCenter() const {
    T x_sum = 0, y_sum = 0;
    for (const auto& vertex : vertices) {
        x_sum += vertex->getX();
        y_sum += vertex->getY();
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

template <Scalar T>
T Hexagon<T>::getArea() const {
    T area = 0;
    int j = vertices.size() - 1;
    for (size_t i = 0; i < vertices.size(); i++) {
        area += (vertices[j]->getX() + vertices[i]->getX()) * (vertices[j]->getY() - vertices[i]->getY());
        j = i;
    }
    return std::abs(area) / 2;
}

template <Scalar T>
Figure<T>* Hexagon<T>::clone() const {
    std::vector<std::unique_ptr<Point<T>>> new_vertices;
    for (const auto& vertex : vertices) {
        new_vertices.emplace_back(std::make_unique<Point<T>>(vertex->getX(), vertex->getY()));
    }
    return new Hexagon(std::move(new_vertices));
}

template <Scalar T>
void Hexagon<T>::print(std::ostream& os) const {
    os << "Hexagon with vertices: ";
    for (const auto& vertex : vertices) {
        os << *vertex << " ";
    }
}

template <Scalar T>
void Hexagon<T>::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 6; ++i) {
        T x, y;
        is >> x >> y;
        vertices.emplace_back(std::make_unique<Point<T>>(x, y));
    }
}

// Реализация методов для класса Octagon
template <Scalar T>
Octagon<T>::Octagon(std::vector<std::unique_ptr<Point<T>>> vertices) : vertices(std::move(vertices)) {}

template <Scalar T>
std::pair<T, T> Octagon<T>::getGeometricCenter() const {
    T x_sum = 0, y_sum = 0;
    for (const auto& vertex : vertices) {
        x_sum += vertex->getX();
        y_sum += vertex->getY();
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

template <Scalar T>
T Octagon<T>::getArea() const {
    T area = 0;
    int j = vertices.size() - 1;
    for (size_t i = 0; i < vertices.size(); i++) {
        area += (vertices[j]->getX() + vertices[i]->getX()) * (vertices[j]->getY() - vertices[i]->getY());
        j = i;
    }
    return std::abs(area) / 2;
}

template <Scalar T>
Figure<T>* Octagon<T>::clone() const {
    std::vector<std::unique_ptr<Point<T>>> new_vertices;
    for (const auto& vertex : vertices) {
        new_vertices.emplace_back(std::make_unique<Point<T>>(vertex->getX(), vertex->getY()));
    }
    return new Octagon(std::move(new_vertices));
}

template <Scalar T>
void Octagon<T>::print(std::ostream& os) const {
    os << "Octagon with vertices: ";
    for (const auto& vertex : vertices) {
        os << *vertex << " ";
    }
}

template <Scalar T>
void Octagon<T>::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 8; ++i) {
        T x, y;
        is >> x >> y;
        vertices.emplace_back(std::make_unique<Point<T>>(x, y));
    }
}

// Реализация методов для класса FigureArray
template <typename T>
void FigureArray<T>::addFigure(std::shared_ptr<T> figure) {
    figures.push_back(std::move(figure));
}

template <typename T>
void FigureArray<T>::removeFigure(size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

template <typename T>
double FigureArray<T>::getTotalArea() const { // Изменен тип возвращаемого значения на double
    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += figure->getArea();
    }
    return totalArea;
}

template <typename T>
void FigureArray<T>::printAll() const {
    for (const auto& figure : figures) {
        std::cout << *figure << std::endl;
    }
}

template <typename T>
void FigureArray<T>::printAllWithAreas() const {
    for (const auto& figure : figures) {
        std::cout << *figure << " Area: " << figure->getArea() << std::endl;
    }
}

// Явное инстанцирование шаблонов
template class Point<double>;
template class Figure<double>;
template class Pentagon<double>;
template class Hexagon<double>;
template class Octagon<double>;
template class FigureArray<Figure<double>>;
