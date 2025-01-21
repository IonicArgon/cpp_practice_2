#include <iostream>
#include <numbers>
#include <cmath>
#include <memory>

template <class T>
class Shape {
public:
  virtual T perimeter(void) = 0;
  virtual T area(void) = 0;
};

template <class T>
class Rectangle : public Shape<T> {
public:
  Rectangle(T length, T width) : length(length), width(width) {};
  ~Rectangle() = default;

  virtual T perimeter(void) override {
    return (2 * this->length) + (2 * this->width);
  }

  virtual T area(void) override {
    return (this->length * this->width);
  }

private:
  T length, width;
};

template <class T>
class Circle : public Shape<T> {
public:
  Circle(T radius) : radius(radius) {};
  ~Circle() = default;

  virtual T perimeter(void) override {
    return 2 * std::numbers::pi * this->radius;
  }

  virtual T area(void) override {
    return std::numbers::pi * std::pow(this->radius, 2);
  }

private:
  T radius;
};

template <class T>
std::unique_ptr<Shape<T>> printShapeCharacteristics(std::unique_ptr<Shape<T>> shape) {
  std::cout << "area: " << shape->area() << std::endl;
  std::cout << "perimeter: " << shape->perimeter() << std::endl;
  return std::move(shape);
}

int main() {
  std::unique_ptr<Shape<int>> rectangle = std::make_unique<Rectangle<int>>(1, 2);
  std::unique_ptr<Shape<double>> circle = std::make_unique<Circle<double>>(1.0);

  rectangle = printShapeCharacteristics<int>(std::move(rectangle));
  circle = printShapeCharacteristics<double>(std::move(circle));

  // and we shouldn't have undefined behaviour here
  rectangle->area();

  return 0;
}
