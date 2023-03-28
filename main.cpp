#include <iostream>
#include "StockExchange.h"
#include "Starter.h"

bool CheckNumb(std::string s) {
  for (auto c : s) {
    if (c < '0' || c > '9') {
      return false;
    }
  }
  return true;
}

int main() {
  std::cout << "Please, enter name of Stock Exchange: \n>> ";
  std::string stock_exchange_name;
  std::cin >> stock_exchange_name;
  std::cout << "\n";
  StockExchange* se = new StockExchange(stock_exchange_name);

  int control;
  do {
    std::cout << se->GetName() + " (STOCK EXCHANGE SERVICES)\n";
    std::cout << "Please choose: \n";
    std::cout << "1. Start Interpreter\n";
    std::cout << "2. Load Input File\n";
    std::cout << "3. Load Sample Data and Start Interpreter\n";
    std::cout << "4. Exit\n";
    std::cout << ">> ";
    std::string input;
    std::cin >> input;
    if (!CheckNumb(input)) {
      std::cout << "\nPlease choose a valid option\n";
      continue;
    }
    control = std::stoi(input);
    Starter starter = Starter(se);
    switch (control) {
      case 1:
        std::cout << "\n" << se->GetName() << " INTERPRETER\n";
        std::cout << "Type 'help' to check usages\n\n";
        starter.StartSession();
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      default:
        std::cout << "\nPlease choose a valid option\n";
        break;
    }
  } while (control != 4);
  return 0;
}