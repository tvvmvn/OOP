#include <iostream>
#include <string>
using namespace std;


// Association

class Person {
  public:
    string name;
};

class Book {
  public:
    string title;
    string author;
};

int main() {
  // Person
  Person person;
  person.name = "John";

  // Book
  Book book;
  book.author = person.name;

  cout << book.author;
}
