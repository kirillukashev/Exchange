#include "ActionType.h"
#include <iostream>

class ActionHandler {
 public:
  StockExchange context;

  static std::string getActionString(ActionType action);
  static ActionType getActionType(std::string actionString);
};
