#include "Figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.read(is);
    return is;
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        *this = *other.clone();
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        *this = std::move(*other.clone());
    }
    return *this;
}

bool Figure::operator==(const Figure& other) const {
    return getArea() == other.getArea() && getGeometricCenter() == other.getGeometricCenter();
}
