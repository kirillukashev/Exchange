#pragma once

#include "ActionType.h"
#include <iostream>
#include <algorithm>
#include "StockExchange.h"

class ActionHandler {
 public:
  std::string action_leader;

  ActionHandler(StockExchange cont, std::string lead);
  static std::string GetActionString(ActionType action);
  static ActionType GetActionType(std::string actionString);
};