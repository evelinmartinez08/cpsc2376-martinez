#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159
#endif

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
private:
    double width;
    double height;
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return M_PI * radius * radius;
    }
private:
    double radius;
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4) << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream infile("shapes.txt");
    if (!infile) {
        std::cerr << "Error: Could not open shapes.txt\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "rectangle") {
            double w, h;
            if (iss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            }
        } else if (type == "circle") {
            double r;
            if (iss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            }
        } else {
            std::cerr << "Warning: Unknown shape type '" << type << "'\n";
        }
    }

    printAllAreas(shapes);
    return 0;
}