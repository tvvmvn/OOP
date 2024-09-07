#include <iostream>
#include <string>
using namespace std;

// interface
class Instrument { 
  virtual string sound() = 0;
};

// Musical Band 
class Vocal : Instrument {
  public:
    string sound() {
      return "bi bap";
    }
};

class Keyboard {
  public:
    string sound() {
      return "D F A C";
    }
};

class Drum {
  public:
    string sound() {
      return "doom chit";
    }
};