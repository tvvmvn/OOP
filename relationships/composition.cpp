#include <iostream>
#include <string>
using namespace std;


// Composition

class Legs {
  public:
    string material;
};

class Desk {
  public:
    Legs legs;
};

int main() {
  Legs legs;
  legs.material = "Steel";

  Desk desk;
  desk.legs = legs;

  cout << desk.legs.material;
}