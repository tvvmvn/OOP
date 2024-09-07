#include <iostream>
#include <string>
using namespace std;

// Car
class Car {
  private:
    string _engine;
    // ..

  public:
    void setEngine(const string &engine) {
      _engine = engine;
    }

    void about() {
      cout << "Car Powered by " + _engine << endl;
    }
};

// CarBuilder
class CarBuilder {
  public:
    virtual void buildEngine(const string &engine) = 0;
    virtual Car getResult() = 0;
};

class MyCarBuilder : public CarBuilder {
  private:
    Car _car;

  public:
    MyCarBuilder() {
      _car = Car();
    }

    void buildEngine(const string &engine) {
    // Car setEngine()
      _car.setEngine(engine);
    }

    Car getResult() {
      return _car;
    }
};

// CarAssembler
class CarAssembler {
  public:
    Car assembleCar(CarBuilder &builder) {
      // Builder buileEngine()
      builder.buildEngine("Hybrid");

      return builder.getResult();
    }
};

int main() {
  MyCarBuilder myCarBuilder;
  CarAssembler assembler;
  
  Car car = assembler.assembleCar(myCarBuilder);

  car.about();
}

