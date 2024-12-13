#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
#include <memory>
#include <concepts>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    Point(T x, T y);

    T getX() const;
    T getY() const;

    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Point<U>& point);

    template <Scalar U>
    friend std::istream& operator>>(std::istream& is, Point<U>& point);

private:
    T x, y;
};

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<T, T> getGeometricCenter() const = 0;
    virtual T getArea() const = 0;

    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Figure<U>& figure);

    template <Scalar U>
    friend std::istream& operator>>(std::istream& is, Figure<U>& figure);

    virtual Figure<T>* clone() const = 0;

    Figure<T>& operator=(const Figure<T>& other);
    Figure<T>& operator=(Figure<T>&& other) noexcept;

    bool operator==(const Figure<T>& other) const;

protected:
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    Figure(const Figure<T>& other) = default;
    Figure(Figure<T>&& other) noexcept = default;
    Figure() = default;
};

template <typename T>
class FigureArray {
public:
    void addFigure(std::shared_ptr<T> figure);
    void removeFigure(size_t index);
    double getTotalArea() const; // Изменен тип возвращаемого значения на double
    void printAll() const;
    void printAllWithAreas() const;

private:
    std::vector<std::shared_ptr<T>> figures;
};

template <Scalar T>
class Pentagon : public Figure<T> {
public:
    Pentagon(std::vector<std::unique_ptr<Point<T>>> vertices);

    std::pair<T, T> getGeometricCenter() const override;
    T getArea() const override;

    Figure<T>* clone() const override;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
};

template <Scalar T>
class Hexagon : public Figure<T> {
public:
    Hexagon(std::vector<std::unique_ptr<Point<T>>> vertices);

    std::pair<T, T> getGeometricCenter() const override;
    T getArea() const override;

    Figure<T>* clone() const override;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
};

template <Scalar T>
class Octagon : public Figure<T> {
public:
    Octagon(std::vector<std::unique_ptr<Point<T>>> vertices);

    std::pair<T, T> getGeometricCenter() const override;
    T getArea() const override;

    Figure<T>* clone() const override;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
};

#endif // SOLUTION_H
