#include <iostream>
#include <string>
using namespace std;


// Base class
class Animal {
  public:
    virtual void animalSound() = 0;
};

// Derived class
class Pig : public Animal {
  public:
    void animalSound() {
      cout << "The pig says: wee wee \n";
    }
};

// Derived class
class Dog : public Animal {
  public:
    void animalSound() {
      cout << "The dog says: bow wow \n";
    }
};