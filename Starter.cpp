#include "Starter.hpp"

void Starter::Split(const std::string& s, std::vector<std::string>& elems) {
  int start = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ' || s[i] == ':' || s[i] == '{' || s[i] == '}' || s[i] == ',' || s[i] == '"') {
      if (i > start) {
        elems.push_back(s.substr(start, i - start));
      }
      start = i + 1;
    }
  }
  int i = s.size() - 1;
  if (s[i] == ' ' || s[i] == ':' || s[i] == '{' || s[i] == '}' || s[i] == ',' || i < start) {
    return;
  }
  elems.push_back(s.substr(start, i + 1 - start));
}

Starter::Starter(StockExchange* se): context_(se) {
  // registering action handlers
  this->company_action_handler_ = CompanyActionHandler(se);
  this->trader_action_handler_ = TraderActionHandler(se);
  this->order_action_handler_ = OrderActionHandler(se);
}

std::vector<std::string> Starter::Interpret(std::vector<std::string> parsed) {
  if (!parsed.empty()) {
    for (auto &i : parsed) {
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
        return company_action_handler_.HandleAction(action);
    } else if (leader == "TRADER") {
        return trader_action_handler_.HandleAction(action);
    } else if (leader == "ORDER") {
        return order_action_handler_.HandleAction(action);
    }
  }
  return  std::vector<std::string>{
          "Usage:",
          "  COMPANY:",
          "    COMPANY SHOW ticker?",
          "    COMPANY SHOW_CATEGORIES",
          "    COMPANY SHOW_CATEGORY category?",
          "    COMPANY ADD name? ticker? category? open_price? close_price? low_price? high_price? quantity_stock?",
          "    COMPANY DELETE ticker?",
          "  TRADER:",
          "    TRADER SHOW id?",
          "    TRADER ADD name? currency? holdings(format:\"{ticker:quantity, ticker2:quantity2}\")?",
          "    TRADER DELETE id?",
          "  ORDER:",
          "    ORDER EXECUTE_ALL",
          "    ORDER STAGE trader_id? stock_ticker? type(BUY/SELL)? quantity? rate?",
          "  EXIT (only in interpreter mode)"};
}

void Starter::StartSession() {
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
    std::vector<std::string> interpreted = Interpret(parsed);
    for (const std::string& i : interpreted) {
      std::cout << i << "\n";
    }
  }
}
