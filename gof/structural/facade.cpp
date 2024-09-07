#include <iostream>
#include <string>
using namespace std;

// Subsystem 1
class Engine {
  public:
    void Start() {
      cout << "Engine started" << endl;
    }

    void Stop() {
      cout << "Engine stopped" << endl;
    }
};

// Subsystem 2
class Lights {
  public:
    void TurnOn() { 
      cout << "Lights on" << endl; 
    }

    void TurnOff() {
      cout << "Lights off" << endl;
    }
};

// Facade
class Car {
  private:
    Engine engine;
    Lights lights;

  public:
    void StartCar() {
      engine.Start();
      lights.TurnOn();

      cout << "Car is ready to drive" << endl;
    }

    void StopCar() {
      lights.TurnOff();
      engine.Stop();

      cout << "Car has stopped" << endl;
    }
};

int main() {
  // Using the Facade to start and stop the car
  Car car;
  
  car.StartCar();
  // driving..
  car.StopCar();

  return 0;
}