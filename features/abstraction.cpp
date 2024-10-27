#include <iostream>
#include <string>
using namespace std;


class Base {
  public:
    // pure virtual function (or abstract function)
    // In C++, an interface can be simulated by making all methods pure virtual. 
    virtual void fun() = 0;
};
 
class Derived : public Base {
  public:
    // implementation of the pure virtual function
    void fun() { cout << "fun() called"; }
};
 
int main(void) {
  Derived d;

  d.fun();

  return 0;
}

