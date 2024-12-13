#include <gtest/gtest.h>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "FigureArray.h"

// Тесты для вычисления площади
TEST(FigureTest, PentagonArea) {
    std::vector<std::pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 1}
    };
    Pentagon pentagon(vertices);
    EXPECT_NEAR(pentagon.getArea(), 2.5, 0.01);
}

TEST(FigureTest, HexagonArea) {
    std::vector<std::pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {2, 1}, {2, 2}, {1, 3}, {0, 2}
    };
    Hexagon hexagon(vertices);
    EXPECT_NEAR(hexagon.getArea(), 4.5, 0.01);
}

TEST(FigureTest, OctagonArea) {
    std::vector<std::pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {2, 1}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}
    };
    Octagon octagon(vertices);
    EXPECT_NEAR(octagon.getArea(), 6.5, 0.01);
}

// Тесты для вычисления геометрического центра
TEST(FigureTest, PentagonCenter) {
    std::vector<std::pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 1}
    };
    Pentagon pentagon(vertices);
    auto center = pentagon.getGeometricCenter();
    EXPECT_NEAR(center.first, 0.8, 0.01);
    EXPECT_NEAR(center.second, 0.8, 0.01);
}

TEST(FigureTest, HexagonCenter) {
    std::vector<std::pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {2, 1}, {2, 2}, {1, 3}, {0, 2}
    };
    Hexagon hexagon(vertices);
    auto center = hexagon.getGeometricCenter();
    EXPECT_NEAR(center.first, 1.0, 0.01);
    EXPECT_NEAR(center.second, 1.333, 0.01);
}

TEST(FigureTest, OctagonCenter) {
    std::vector<std::pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {2, 1}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}
    };
    Octagon octagon(vertices);
    auto center = octagon.getGeometricCenter();
    EXPECT_NEAR(center.first, 1.5, 0.01);
    EXPECT_NEAR(center.second, 1.5, 0.01);
}

// Тесты для работы с массивом фигур
TEST(FigureArrayTest, AddAndRemove) {
    FigureArray array;
    std::vector<std::pair<double, double>> pentagonVertices = {
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 1}
    };
    std::vector<std::pair<double, double>> hexagonVertices = {
        {0, 0}, {1, 0}, {2, 1}, {2, 2}, {1, 3}, {0, 2}
    };
    std::vector<std::pair<double, double>> octagonVertices = {
        {0, 0}, {1, 0}, {2, 1}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}
    };

    std::unique_ptr<Figure> pentagon = std::make_unique<Pentagon>(pentagonVertices);
    std::unique_ptr<Figure> hexagon = std::make_unique<Hexagon>(hexagonVertices);
    std::unique_ptr<Figure> octagon = std::make_unique<Octagon>(octagonVertices);

    array.addFigure(std::move(pentagon));
    array.addFigure(std::move(hexagon));
    array.addFigure(std::move(octagon));

    EXPECT_NEAR(array.getTotalArea(), 13.5, 0.01);

    array.removeFigure(1);
    EXPECT_NEAR(array.getTotalArea(), 9.0, 0.01);
}

TEST(FigureArrayTest, AddMultipleFigures) {
    FigureArray array;
    std::vector<std::pair<double, double>> vertices1 = {
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 1}
    };
    std::vector<std::pair<double, double>> vertices2 = {
        {0, 0}, {1, 0}, {2, 1}, {2, 2}, {1, 3}, {0, 2}
    };
    std::vector<std::pair<double, double>> vertices3 = {
        {0, 0}, {1, 0}, {2, 1}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}
    };

    array.addFigure(std::make_unique<Pentagon>(vertices1));
    array.addFigure(std::make_unique<Hexagon>(vertices2));
    array.addFigure(std::make_unique<Octagon>(vertices3));

    EXPECT_EQ(array.getTotalArea(), 13.5);
}

TEST(FigureArrayTest, RemoveAllFigures) {
    FigureArray array;
    std::vector<std::pair<double, double>> vertices1 = {
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 1}
    };
    std::vector<std::pair<double, double>> vertices2 = {
        {0, 0}, {1, 0}, {2, 1}, {2, 2}, {1, 3}, {0, 2}
    };
    std::vector<std::pair<double, double>> vertices3 = {
        {0, 0}, {1, 0}, {2, 1}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}
    };

    array.addFigure(std::make_unique<Pentagon>(vertices1));
    array.addFigure(std::make_unique<Hexagon>(vertices2));
    array.addFigure(std::make_unique<Octagon>(vertices3));

    array.removeFigure(0);
    array.removeFigure(0);
    array.removeFigure(0);

    EXPECT_EQ(array.getTotalArea(), 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
