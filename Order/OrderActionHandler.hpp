#pragma once

#include<iostream>
#include <string>
#include <vector>
#include "../Actions/ActionHandler.hpp"
#include "../Actions/ActionType.hpp"
#include "../Actions/Action.hpp"
#include "../Company/Company.hpp"
#include "Order.hpp"

class OrderActionHandler : public ActionHandler {
 public:
  OrderActionHandler() = default;
  OrderActionHandler(StockExchange* se);
  std::vector<std::string> HandleAction(Action action);
};
