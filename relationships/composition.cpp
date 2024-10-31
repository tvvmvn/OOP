#include <iostream>
#include <string>
using namespace std;

class AvanteEngine {};

class Avante {
  public:
    AvanteEngine engine;
};

int main() {
  AvanteEngine eg;

  Avante avante;
  avante.engine = eg;
}