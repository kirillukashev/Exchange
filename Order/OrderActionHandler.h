#pragma once

#include<iostream>
#include <string>
#include <vector>
#include "ActionHandler.h"
#include "../Actions/ActionType.h"
#include "../Actions/Action.h"

class OrderActionHandler : public ActionHandler {
  static std::vector<std::string> HandleAction(StockExchange context, Action action);
};