#include <iostream>
#include <string>
using namespace std;

// Receiver
class Receiver {
  public: 
    void performAction() {
      cout << "Receiver is performing" << endl;
    }
};

// Command interface
class Command {
  public:
    virtual void execute() = 0;
};

// Concrete Command
class ConcreteCommand : public Command {
  private:
    Receiver &receiver;

  public:
    ConcreteCommand(Receiver &rec): receiver(rec) {}

    void execute() { 
      receiver.performAction(); 
    }
};

// Invoker
class Invoker {
  private:
    Command *command;

  public:
    void setCommand(Command *cmd) { 
      command = cmd; 
    }

    void executeCommand() { 
      command->execute(); 
    }
};

int main() {
  Receiver receiver;
  ConcreteCommand command(receiver);
  Invoker invoker;

  invoker.setCommand(&command);
  invoker.executeCommand(); // Receiver is performing an action.

  return 0;
}