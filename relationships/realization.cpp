#include <iostream>
#include <string>
using namespace std;


// realization
class Animal {
  public:
    virtual string sound() = 0;
};

class Cat : public Animal {
  public:
    string sound() {
      return "Meow";
    }
};

int main() {
  Cat cat;

  cout << cat.sound();
}