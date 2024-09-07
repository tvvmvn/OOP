#include <iostream>
#include <string>
using namespace std;


/*
A class should open for extensions,
but closed for modification.
*/

class PaymentProcessor {
  public:
    void withCreditCard() {}
};

class PaymentProcessorExtended : PaymentProcessor {
  public:
    void withPaypal() {}
};
