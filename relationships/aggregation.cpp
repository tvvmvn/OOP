#include <iostream>
#include <string>
using namespace std;

class Keyboard {
  public:
    string model;
};

class WhiteKeyboard : public Keyboard {};
class BlackKeyboard : public Keyboard {};

class Computer {
  public:
    Keyboard keyboard;
};

int main() {
  WhiteKeyboard myKeyboard;
  myKeyboard.model = "kbd01";

  Computer computer;
  // you can switch from one to another style of keyboard.
  computer.keyboard = myKeyboard;

  cout << computer.keyboard.model;
}