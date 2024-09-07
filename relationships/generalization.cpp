#include <iostream>
#include <string>
using namespace std;


// Generalization

class Car {
  public:
    string model;
};

class KoreanCar : public Car {};

int main() {
  KoreanCar car;
  car.model = "Avante Hybrid";

  cout << car.model;
}