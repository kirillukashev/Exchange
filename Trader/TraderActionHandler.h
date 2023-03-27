#pragma once

#include <iostream>
#include <vector>
#include "../Actions/ActionType.h"
#include "../Actions/Action.h"
#include "Trader.h"
#include "../Actions/ActionHandler.h"
#include "../Company/Company.h"

class TraderActionHandler : public ActionHandler {
 public:
  TraderActionHandler() = default;
  TraderActionHandler(StockExchange se);
  std::vector<std::string> HandleAction(const Action& action);
};