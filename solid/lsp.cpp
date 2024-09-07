#include <iostream>
#include <string>
using namespace std;

/*
Derived classes must be substitutable for their base class.
*/

class Rectangle {
  public:
    int width;
    int height;

    int getSize() {
      return width * height;
    }
};

// violate
class Square : public Rectangle {
  public:
    int getSize() {
      return width * width;
    }
};

