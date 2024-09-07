#include <iostream>
#include <string>
using namespace std;


/*
Abstraction 

A class is abstract if it has at least one pure virtual function.

An interface does not have an implementation of any of its methods.
It can be considered as a collection of method declarations. 
In C++, an interface can be simulated by making all methods pure virtual. 

* reference
In Java, there is a separate keyword for this.

1) abstract 
2) interface (complete abstract class)
*/


class Base {
  // private member variable
  int x;
 
  public:
    // pure virtual function (or abstract function)
    virtual void fun() = 0;

    // getter function to access x
    int getX() { return x; }
};
 
class Derived : public Base {
  // private member variable
  int y;
 
  public:
    // implementation of the pure virtual function
    void fun() { cout << "fun() called"; }
};
 
int main(void) {
  Derived d;

  d.fun();

  return 0;
}


/*
object of abstract class is not allowed.
*/


class Test {
  // private member variable
  int x;

  public:
    // pure virtual function
    virtual void show() = 0;

    // getter function to access x
    int getX() { return x; }
};

int main(void) {
  // object of abstract class "Test" is not allowed.
  Test t;
}


/*
C++ program to demonstrate that if we do not override
the pure virtual function in the derived class, then
the derived class also becomes an abstract class
*/


class Base {
  public:
    // pure virtual function
    virtual void show() = 0;
};
 
// pure virtual function "Base::show" has no overrider
class Derived : public Base {};
 
int main(void) {
  // object of abstract class type "Derived" is not allowed.
  Derived d;
}


/*
C++ program to demonstrate that
an abstract class can have constructors.
*/
 

// An abstract class with constructor
class Base {
  protected:
    // protected member variable
    int x;
 
  public:
    // pure virtual function
    virtual void fun() = 0;
 
    // constructor of Base class
    Base(int i) {
      x = i;
      cout << "Constructor of base called\n";
    }
};
 
class Derived : public Base {
  // private member variable
  int y;
 
  public:
    // calling the constructor of Base class
    Derived(int i, int j): Base(i) {
      y = j;
    }
 
    // implementation of pure virtual function
    void fun() {
        cout << "x = " << x << ", y = " << y << '\n';
    }
};
 
int main(void) {
  // creating an object of Derived class
  Derived d(4, 5);

  // calling the fun() function of Derived class
  d.fun();

  // creating an object of Derived class using
  // a pointer of the Base class
  Base* ptr = new Derived(6, 7);

  // calling the fun() function using the pointer
  ptr->fun();
}


/*
An abstract class in C++ can also be defined 
using struct keyword.
*/


struct shapeClass {
    virtual void Draw()=0;
};