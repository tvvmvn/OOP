#include <iostream>
#include <string>
using namespace std;


class Circle {
  private:
    double radius;

  public:
    Circle(double r) : radius(r) {};

    Circle clone() {
      return Circle(radius);
    }

    void draw() {
      cout << "Drawing a circle with radius " << radius;
    }
};

int main() {
  Circle circlePrototype(5.0);

  Circle circle = circlePrototype.clone();

  circle.draw(); // Drawing a circle with radius 5
}