#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "Figure.h"
#include <vector>
#include <memory>

class FigureArray {
public:
    void addFigure(std::unique_ptr<Figure> figure);
    void removeFigure(size_t index);
    double getTotalArea() const;
    void printAll() const;
    void printAllWithAreas() const;

private:
    std::vector<std::unique_ptr<Figure>> figures;
};

#endif // FIGUREARRAY_H
