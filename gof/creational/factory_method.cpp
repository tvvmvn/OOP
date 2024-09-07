#include <iostream>
#include <string>
using namespace std;

/*
Factory Method Pattern provides an interface for creating objects 
but leaves the actual object instantiation to derived classes. 

This allows for flexibility in object creation and promotes loose coupling 
between the creator (client code) and the concrete products.
*/


class Car {
  public:
    virtual void drive() = 0;
};

class Avante : public Car {
  public:
    void drive() {
      cout << "Avante is driving";
    }
};

class XM3 : public Car {};

class CarFactory {
  public:
    virtual Car *create() = 0;
};

class AvanteFactory : public CarFactory {
  public:
    Car *create() {
      return new Avante();
    }
};

class XM3Factory {};

int main() {
  CarFactory *avanteFactory = new AvanteFactory();
  Car *avante = avanteFactory->create();

  avante->drive(); // Avante is driving
}