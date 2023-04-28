#pragma once

#include <iostream>
#include <vector>
#include "../Actions/ActionType.hpp"
#include "../Actions/Action.hpp"
#include "Trader.hpp"
#include "../Actions/ActionHandler.hpp"
#include "../Company/Company.hpp"

class TraderActionHandler : public ActionHandler {
 public:
  TraderActionHandler() = default;
  ~TraderActionHandler() = default;
  TraderActionHandler(StockExchange* exchange);
  std::vector<std::string> HandleAction(const Action& action);
};
