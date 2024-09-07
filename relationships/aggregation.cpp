#include <iostream>
#include <string>
using namespace std;

// Aggregation

class Keyboard {
  public:
    string model;
};

class Computer {
  public:
    Keyboard keyboard;
};

int main() {
  Keyboard keyboard;
  keyboard.model = "Logitec K1";

  Computer computer;
  computer.keyboard = keyboard;

  cout << computer.keyboard.model;
}