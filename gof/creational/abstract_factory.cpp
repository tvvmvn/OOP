#include <iostream>
#include <string>
using namespace std;

/*
It provides an interface for creating families of related or 
dependent objects without specifying their concrete classes.
*/

// Car
class Car {
  public:
    virtual void drive() = 0;
};

class AvanteGasoline : public Car {
  public:
    void drive() {
      cout << "driving an Avante Gasoline" << endl;
    }
};

class AvanteHybrid : public Car {
  public:
    void drive() {
      cout << "driving an Avante Hybrid" << endl;
    }
};

class XM3Gasoline : public Car {};

class XM3Hybrid : public Car {
  public:
    void drive() {
      cout << "driving an XM3 Hybrid" << endl;
    }
};


// CarFactory
class CarFactory {
  public:
    virtual Car *createGasolineCar() = 0;
    virtual Car *createHybridCar() = 0;
};

class AvanteFactory : public CarFactory {
  public:
    Car *createGasolineCar() {
      return new AvanteGasoline();
    }
    
    Car *createHybridCar() {
      return new AvanteHybrid();
    }
};

class XM3Factory : public CarFactory {};


// Run
int main() {
  // CarFactory
  CarFactory *avanteFactory = new AvanteFactory();

  // Car
  Car *avanteGasoline = avanteFactory->createGasolineCar();
  Car *avanteHybrid = avanteFactory->createHybridCar();

  // usage
  avanteGasoline->drive();
  avanteHybrid->drive();

  // clean up
  // delete avanteFactory;
  // delete avanteGasoline;
  // delete avanteHybrid;
}