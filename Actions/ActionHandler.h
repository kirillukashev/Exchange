#pragma once

#include "ActionType.h"
#include <iostream>
#include <algorithm>
#include "StockExchange.h"

class ActionHandler {
 public:
  StockExchange context;

  static std::string getActionString(ActionType action);
  static ActionType getActionType(std::string actionString);
};
