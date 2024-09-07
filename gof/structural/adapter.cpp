#include <iostream>
#include <string>
using namespace std;


// Socket
class Socket110 {
  public:
    void charge(int volt) {
        cout << "Charging in " << volt << "V" << endl;
    }
};

// Charge
class Charger220 {};

// Adapter
class Adapter {
  private:
    Socket110 socket110;

  public:
    void convert(int volt) {

      // 220 to 110

      socket110.charge(110);
    };
};

// main
int main() {
  Adapter adapter;

  adapter.convert(220);
}
