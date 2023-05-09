#pragma once

#include <iostream>
#include <vector>
#include "../Backend/Actions/ActionType.hpp"
#include "../Backend/Actions/Action.hpp"
#include "../Backend/Trader/Trader.hpp"
#include "../Backend/Actions/ActionHandler.hpp"
#include "../Backend/Company/Company.hpp"

class TraderActionHandler : public ActionHandler {
 public:
  TraderActionHandler() = default;
  ~TraderActionHandler() = default;
  TraderActionHandler(StockExchange* exchange);
  std::vector<std::string> HandleAction(const Action& action);
};
