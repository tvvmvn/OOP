#include <iostream>
#include <string>
using namespace std;

/*
high-level modules should not depend on low-level modules. 
Both should depend on abstractions. 

Kids: high-level module
Lego: low-level module
Toy: abstraction
*/

// DIP violate
class Toy {
  public:
    virtual void use() = 0;
};

class Lego : public Toy {
  public:
    void use() {};
};

class PS5 : public Toy {};

class Kids {
  public:
    void play() {
      // you have to modify this if kids want to play with PS5.
      Lego lego;

      lego.use();
    }
};

// DIP apply
class Toy {
  public:
    virtual void use() = 0;
};

class Lego : public Toy {
  public:
    void use() {};
};

class PS5 : public Toy {};

class Kids {
  public:
    // depend on abstraction
    void play(Toy* toy) {
      toy->use();
    }
};