#include <iostream>
#include <string>
using namespace std;


// isp
class Fuel {
  public:
    string type;
    
    int fill() {
      return 100;
    }
};

class Car {
  public:
    void drive(Fuel fuel) {
      cout << fuel.fill();
    }
};

int main() {
  Fuel fuel;
  Car car;

  car.drive(fuel);
}