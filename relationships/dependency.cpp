#include <iostream>
#include <string>
using namespace std;


// isp
class Gasoline {
  public:
    int fill() {
      return 40;
    }
};

class Car {
  public:
    void drive(Gasoline gasoline) {
      int fuel = gasoline.fill();
      
      cout << "It can drive now!";
    }
};

int main() {
  Gasoline gasoline;
  Car car;

  car.drive(gasoline);
}