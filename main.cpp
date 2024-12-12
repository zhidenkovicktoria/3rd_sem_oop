#include "FigureArray.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    FigureArray array;
    int choice;
    std::vector<std::pair<double, double>> vertices;

    while (true) {
        std::cout << "Choose a figure to add (1 for Pentagon, 2 for Hexagon, 3 for Octagon, 0 to exit): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        vertices.clear();
        std::cout << "Enter the coordinates of the vertices (x y):" << std::endl;
        for (int i = 0; i < (choice == 1 ? 5 : (choice == 2 ? 6 : 8)); ++i) {
            double x, y;
            std::cin >> x >> y;
            vertices.emplace_back(x, y);
        }

        switch (choice) {
            case 1:
                array.addFigure(std::make_unique<Pentagon>(vertices));
                break;
            case 2:
                array.addFigure(std::make_unique<Hexagon>(vertices));
                break;
            case 3:
                array.addFigure(std::make_unique<Octagon>(vertices));
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    array.printAllWithAreas();
    std::cout << "Total area: " << array.getTotalArea() << std::endl;

    int removeChoice;
    std::cout << "Do you want to remove a figure? (1 for Yes, 0 for No): ";
    std::cin >> removeChoice;

    if (removeChoice == 1) {
        size_t index;
        std::cout << "Enter the index of the figure to remove: ";
        std::cin >> index;
        array.removeFigure(index);

        array.printAllWithAreas();
        std::cout << "Total area after removal: " << array.getTotalArea() << std::endl;
    }

    return 0;
}