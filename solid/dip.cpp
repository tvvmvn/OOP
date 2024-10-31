#include <iostream>
#include <string>
using namespace std;

class Toy {
  public:
    virtual void use() = 0;
};

class Lego : public Toy {
  public:
    void use() {};
};

class PS5 : public Toy {};
class Gun : public Toy {};

class Kids {
  public:
    // depends on toy interface, not on concreate toy
    void play(Toy* toy) {
      toy->use();
    }
};