#include <cmath>
#include <iostream>
//point
class Point {
public:
    double x;
    double y;

    Point(double x, double y);
};

Point::Point(double x, double y) : x(x), y(y) {}

//shape
class Shape {
    //Point* points;
    //int num_points;

public:
    Point* points;
    int numpoints;
    Shape(Point* points, int numpoints);
    ~Shape();

    virtual double square() const = 0;
    virtual double perimetr() const = 0;
    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
};

Shape::Shape(Point* points, int numpoints) : points(points), numpoints(numpoints) {}

Shape::~Shape() {
    delete points;
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    shape.print(os);
    return os;
}

//line

class Segmemt_Line : public Shape {
public:
    Segmemt_Line(Point start, Point end);

    double square() const override;
    double perimetr() const override;
    void print(std::ostream& os) const override;

};
Segmemt_Line::Segmemt_Line(Point start, Point end) : Shape(new Point[2]{ start, end }, 2) {}

double Segmemt_Line::square() const {
    return 0;
}

double Segmemt_Line::perimetr() const {
    return std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
}

void Segmemt_Line::print(std::ostream& os) const {
    os << "Line: (" << points[0].x << ", " << points[0].y << ") - (" << points[1].x << ", " << points[1].y << ")";
}

//ellips

class Ellips : public Shape {
public:
    Ellips(Point center, double a, double b);

    double square() const override;
    double perimetr() const override;
    void print(std::ostream& os) const override;
};

Ellips::Ellips(Point center, double a, double b) : Shape(new Point[1]{ center }, 1) {}

double Ellips::square() const {
    return 0;
}

double Ellips::perimetr() const {
    return 0;
}

void Ellips::print(std::ostream& os) const {
    os << "Ellips: (" << points[0].x << ", " << points[0].y << ")";
}

// circle

class Circle : public Ellips {
public:
    Circle(Point center, double radius);

    double square() const override;
    double perimetr() const override;
    void print(std::ostream& os) const override;
};

Circle::Circle(Point center, double radius) : Ellips(center, radius, radius) {}

double Circle::square() const {
    return 3.1416 * std::pow(points[1].x, 2);
}

double Circle::perimetr() const {
    return 2 * 3.1416 * points[1].x;
}

void Circle::print(std::ostream& os) const {
    os << "Circle: (" << points[0].x << ", " << points[0].y << "), radius = " << points[1].x;
}

//triangle

class Triangle : public Shape {
public:
    Triangle(Point a, Point b, Point c);

    double square() const override;
    double perimetr() const override;
    void print(std::ostream& os) const override;
};



Triangle::Triangle(Point a, Point b, Point c) : Shape(new Point[3]{ a, b, c }, 3) {}

double Triangle::square() const {
    double a = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double b = std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2));
    double c = std::sqrt(std::pow(points[0].x - points[2].x, 2) + std::pow(points[0].y - points[2].y, 2));
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimetr() const {
    return std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2))
        + std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2))
        + std::sqrt(std::pow(points[0].x - points[2].x, 2) + std::pow(points[0].y - points[2].y, 2));
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: (" << points[0].x << ", " << points[0].y << ") - (" << points[1].x << ", " << points[1].y << ") - (" << points[2].x << ", " << points[2].y << ")";
}

//main

int main() {
    Shape* shapes[] = {
        new Segmemt_Line({0, 0}, {1, 1}),
        new Circle({0, 0}, 4),
        new Triangle({0, 0}, {1, 0}, {0, 1}),
    };

    for (auto shape : shapes) {
        std::cout << *shape << std::endl;
        std::cout << "Area: " << square() << std::endl;
        std::cout << "Perimeter: " << perimetr() << std::endl;
    }

    return 0;
}