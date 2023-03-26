#pragma once

#include "ActionType.h"
#include <iostream>
#include <algorithm>
#include "StockExchange.h"

class ActionHandler {
 public:
  static StockExchange context; // Trouble with static?

  static std::string GetActionString(ActionType action);
  static ActionType GetActionType(std::string actionString);
};