#include <iostream>
#include <string>

using namespace std;

/*
Car
*/

class Car {
  public:
    virtual string about() = 0;
};

class Avante : public Car {
  public:
    string about() {
      return "Hyundai Avante";
    }
};

/*
Decorator
*/

class CarDecorator : public Car {
  public:
    Car* car;
    CarDecorator(Car *c): car(c) {};

    string about() {
      return car->about();
    }
};


class WingDecorator : public CarDecorator {
  public:
    WingDecorator(Car *c): CarDecorator(c) {}; 
    
    string about() {
      return car->about() + " with wing";
    }
};

class CarbonDecorator : public CarDecorator {
  public:
    CarbonDecorator(Car *c): CarDecorator(c) {}; 
    
    string about() {
      return car->about() + " covered with carbon";
    }
};

/*
main
*/

int main() {
  Car *avante = new Avante();
  Car *avante_wing = new WingDecorator(avante);
  Car *avante_carbon = new CarbonDecorator(avante);

  cout << avante->about() << endl; // Hyundai Avante
  cout << avante_wing->about() << endl; // Hyundai Avante with wing
  cout << avante_carbon->about() << endl; // Hyundai Avante covered with carbon

  delete avante;
  delete avante_wing;
  delete avante_carbon;
}