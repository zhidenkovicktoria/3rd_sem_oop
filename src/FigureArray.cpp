#include "FigureArray.h"
#include <iostream>

void FigureArray::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void FigureArray::removeFigure(size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

double FigureArray::getTotalArea() const {
    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += figure->getArea();
    }
    return totalArea;
}

void FigureArray::printAll() const {
    for (const auto& figure : figures) {
        std::cout << *figure << std::endl;
    }
}

void FigureArray::printAllWithAreas() const {
    for (const auto& figure : figures) {
        std::cout << *figure << " Area: " << figure->getArea() << std::endl;
    }
}
