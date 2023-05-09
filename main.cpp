#include <iostream>
#include "Backend/StockExchange.hpp"
#include "Frontend/Starter.hpp"

bool CheckNumb(std::string string) {
  for (auto symbol : string) {
    if (symbol < '0' || symbol > '9') {
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
  StockExchange *exchange = new StockExchange(stock_exchange_name);

  int control;
  do {
    std::cout << exchange->GetName() + " (STOCK EXCHANGE SERVICES)\n";
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
    Starter starter = Starter(exchange);
    switch (control) {
      case 1:
        std::cout << "\n" << exchange->GetName() << " INTERPRETER\n";
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
  delete exchange;
  return 0;
}
