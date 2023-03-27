#include "Starter.h"
#include "CompanyActionHandler.h"

std::vector<std::string> Starter::Split(const std::string& s, std::vector<std::string>& elems) {
  std::stringstream ss(s);
  std::string item;
  while(std::getline(ss, item, ' ')) {
    elems.push_back(item);
  }
  return elems;
}

std::vector<std::string> Starter::Interpret(StockExchange se, std::vector<std::string> parsed) {
  if (!parsed.empty()) {
    for (auto & i : parsed) {
      std::transform(i.begin(), i.end(), i.begin(), ::toupper);
    }
    std::string leader = parsed[0];
    std::string actionTypeString;

    std::vector<std::string> arguments;
    if (parsed.size() > 1) {
      actionTypeString = parsed[1];
      if (parsed.size() > 2) {
        arguments.resize(parsed.size() - 2);
        std::copy(parsed.begin() + 2, parsed.end(), arguments.begin());
      }
    }

      Action action = Action(actionTypeString, arguments);

    if (leader == "COMPANY") {
        return CompanyActionHandler::HandleAction(se, action);
    } else if (leader == "TRADER") {
        return TraderActionHandler::HandleAction(se, action);
    } else if (leader == "ORDER") {
//        return OrderActionHandler.HandleAction(action);
    } else {
      return  std::vector<std::string>{
              "Usage:",
              "  COMPANY:",
              "    COMPANY SHOW ticker?",
              "    COMPANY ADD name? ticker? open_price? close_price? low_price? high_price?",
              "    COMPANY DELETE ticker?",
              "  TRADER:",
              "    TRADER SHOW id?",
              "    TRADER ADD name? currency? holdings(format:\"{ticker:quantity, ticker2:quantity2}\")?",
              "    TRADER DELETE id?",
              "  ORDER:",
              "    ORDER EXECUTE_ALL",
              "    ORDER STAGE trader_id? stock_ticker? type(BUY/SELL)? quantity? rate?",
              "  EXIT (only in interpreter mode)"
      };
    }
  }
  return {};
}

void Starter::StartSession(StockExchange se) {
  std::string s;
  while (true) {
    std::getline(std::cin, s);
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    std::vector<std::string> parsed;
    Split(s, parsed);
    if (!parsed.empty() && (parsed[0] == "EXIT"
                               || parsed[0] == "QUIT"
                               || parsed[0] == "Q")) {
      return;
    }
    std::vector<std::string> interpreted = Interpret(se, parsed);
    for (const std::string& i : interpreted) {
      std::cout << i << "\n";
    }
  }
}

