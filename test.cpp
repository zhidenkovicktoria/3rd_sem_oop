#include <gtest/gtest.h>
#include "solution.h"

// Тесты для вычисления площади
TEST(FigureTest, PentagonArea) {
    std::vector<std::unique_ptr<Point<double>>> vertices;
    vertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 2));
    vertices.emplace_back(std::make_unique<Point<double>>(0, 1));
    Pentagon<double> pentagon(std::move(vertices));
    EXPECT_NEAR(pentagon.getArea(), 2.5, 0.01);
}

TEST(FigureTest, HexagonArea) {
    std::vector<std::unique_ptr<Point<double>>> vertices;
    vertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 2));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices.emplace_back(std::make_unique<Point<double>>(0, 2));
    Hexagon<double> hexagon(std::move(vertices));
    EXPECT_NEAR(hexagon.getArea(), 4.5, 0.01);
}

TEST(FigureTest, OctagonArea) {
    std::vector<std::unique_ptr<Point<double>>> vertices;
    vertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(3, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(3, 2));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 3));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices.emplace_back(std::make_unique<Point<double>>(0, 2));
    Octagon<double> octagon(std::move(vertices));
    EXPECT_NEAR(octagon.getArea(), 6.5, 0.01);
}

// Тесты для вычисления геометрического центра
TEST(FigureTest, PentagonCenter) {
    std::vector<std::unique_ptr<Point<double>>> vertices;
    vertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 2));
    vertices.emplace_back(std::make_unique<Point<double>>(0, 1));
    Pentagon<double> pentagon(std::move(vertices));
    auto center = pentagon.getGeometricCenter();
    EXPECT_NEAR(center.first, 0.8, 0.01);
    EXPECT_NEAR(center.second, 0.8, 0.01);
}

TEST(FigureTest, HexagonCenter) {
    std::vector<std::unique_ptr<Point<double>>> vertices;
    vertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 2));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices.emplace_back(std::make_unique<Point<double>>(0, 2));
    Hexagon<double> hexagon(std::move(vertices));
    auto center = hexagon.getGeometricCenter();
    EXPECT_NEAR(center.first, 1.0, 0.01);
    EXPECT_NEAR(center.second, 1.333, 0.01);
}

TEST(FigureTest, OctagonCenter) {
    std::vector<std::unique_ptr<Point<double>>> vertices;
    vertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(3, 1));
    vertices.emplace_back(std::make_unique<Point<double>>(3, 2));
    vertices.emplace_back(std::make_unique<Point<double>>(2, 3));
    vertices.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices.emplace_back(std::make_unique<Point<double>>(0, 2));
    Octagon<double> octagon(std::move(vertices));
    auto center = octagon.getGeometricCenter();
    EXPECT_NEAR(center.first, 1.5, 0.01);
    EXPECT_NEAR(center.second, 1.5, 0.01);
}

// Тесты для работы с массивом фигур
TEST(FigureArrayTest, AddAndRemove) {
    FigureArray<Figure<double>> array;
    std::vector<std::unique_ptr<Point<double>>> pentagonVertices;
    pentagonVertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    pentagonVertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    pentagonVertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    pentagonVertices.emplace_back(std::make_unique<Point<double>>(1, 2));
    pentagonVertices.emplace_back(std::make_unique<Point<double>>(0, 1));

    std::vector<std::unique_ptr<Point<double>>> hexagonVertices;
    hexagonVertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    hexagonVertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    hexagonVertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    hexagonVertices.emplace_back(std::make_unique<Point<double>>(2, 2));
    hexagonVertices.emplace_back(std::make_unique<Point<double>>(1, 3));
    hexagonVertices.emplace_back(std::make_unique<Point<double>>(0, 2));

    std::vector<std::unique_ptr<Point<double>>> octagonVertices;
    octagonVertices.emplace_back(std::make_unique<Point<double>>(0, 0));
    octagonVertices.emplace_back(std::make_unique<Point<double>>(1, 0));
    octagonVertices.emplace_back(std::make_unique<Point<double>>(2, 1));
    octagonVertices.emplace_back(std::make_unique<Point<double>>(3, 1));
    octagonVertices.emplace_back(std::make_unique<Point<double>>(3, 2));
    octagonVertices.emplace_back(std::make_unique<Point<double>>(2, 3));
    octagonVertices.emplace_back(std::make_unique<Point<double>>(1, 3));
    octagonVertices.emplace_back(std::make_unique<Point<double>>(0, 2));

    std::shared_ptr<Figure<double>> pentagon = std::make_shared<Pentagon<double>>(std::move(pentagonVertices));
    std::shared_ptr<Figure<double>> hexagon = std::make_shared<Hexagon<double>>(std::move(hexagonVertices));
    std::shared_ptr<Figure<double>> octagon = std::make_shared<Octagon<double>>(std::move(octagonVertices));

    array.addFigure(pentagon);
    array.addFigure(hexagon);
    array.addFigure(octagon);

    EXPECT_NEAR(array.getTotalArea(), 13.5, 0.01);

    array.removeFigure(1);
    EXPECT_NEAR(array.getTotalArea(), 9.0, 0.01);
}

TEST(FigureArrayTest, AddMultipleFigures) {
    FigureArray<Figure<double>> array;
    std::vector<std::unique_ptr<Point<double>>> vertices1;
    vertices1.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices1.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices1.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices1.emplace_back(std::make_unique<Point<double>>(1, 2));
    vertices1.emplace_back(std::make_unique<Point<double>>(0, 1));

    std::vector<std::unique_ptr<Point<double>>> vertices2;
    vertices2.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices2.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices2.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices2.emplace_back(std::make_unique<Point<double>>(2, 2));
    vertices2.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices2.emplace_back(std::make_unique<Point<double>>(0, 2));

    std::vector<std::unique_ptr<Point<double>>> vertices3;
    vertices3.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices3.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices3.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices3.emplace_back(std::make_unique<Point<double>>(3, 1));
    vertices3.emplace_back(std::make_unique<Point<double>>(3, 2));
    vertices3.emplace_back(std::make_unique<Point<double>>(2, 3));
    vertices3.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices3.emplace_back(std::make_unique<Point<double>>(0, 2));

    array.addFigure(std::make_shared<Pentagon<double>>(std::move(vertices1)));
    array.addFigure(std::make_shared<Hexagon<double>>(std::move(vertices2)));
    array.addFigure(std::make_shared<Octagon<double>>(std::move(vertices3)));

    EXPECT_EQ(array.getTotalArea(), 13.5);
}

TEST(FigureArrayTest, RemoveAllFigures) {
    FigureArray<Figure<double>> array;
    std::vector<std::unique_ptr<Point<double>>> vertices1;
    vertices1.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices1.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices1.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices1.emplace_back(std::make_unique<Point<double>>(1, 2));
    vertices1.emplace_back(std::make_unique<Point<double>>(0, 1));

    std::vector<std::unique_ptr<Point<double>>> vertices2;
    vertices2.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices2.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices2.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices2.emplace_back(std::make_unique<Point<double>>(2, 2));
    vertices2.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices2.emplace_back(std::make_unique<Point<double>>(0, 2));

    std::vector<std::unique_ptr<Point<double>>> vertices3;
    vertices3.emplace_back(std::make_unique<Point<double>>(0, 0));
    vertices3.emplace_back(std::make_unique<Point<double>>(1, 0));
    vertices3.emplace_back(std::make_unique<Point<double>>(2, 1));
    vertices3.emplace_back(std::make_unique<Point<double>>(3, 1));
    vertices3.emplace_back(std::make_unique<Point<double>>(3, 2));
    vertices3.emplace_back(std::make_unique<Point<double>>(2, 3));
    vertices3.emplace_back(std::make_unique<Point<double>>(1, 3));
    vertices3.emplace_back(std::make_unique<Point<double>>(0, 2));

    array.addFigure(std::make_shared<Pentagon<double>>(std::move(vertices1)));
    array.addFigure(std::make_shared<Hexagon<double>>(std::move(vertices2)));
    array.addFigure(std::make_shared<Octagon<double>>(std::move(vertices3)));

    array.removeFigure(0);
    array.removeFigure(0);
    array.removeFigure(0);

    EXPECT_EQ(array.getTotalArea(), 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
