#pragma once

#include "ActionType.hpp"
#include <iostream>
#include <algorithm>
#include "../StockExchange.hpp"

class ActionHandler {
 public:
  StockExchange* context;
  std::string action_leader;

  ActionHandler() = default;
  ActionHandler(StockExchange* cont, std::string lead);
  static std::string GetActionString(ActionType action);
  static ActionType GetActionType(std::string actionString);
};
