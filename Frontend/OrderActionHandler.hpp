#pragma once

#include<iostream>
#include <string>
#include <vector>
#include "../Backend/Actions/ActionHandler.hpp"
#include "../Backend/Actions/ActionType.hpp"
#include "../Backend/Actions/Action.hpp"
#include "../Backend/Company/Company.hpp"
#include "../Backend/Order/Order.hpp"

class OrderActionHandler : public ActionHandler {
 public:
  OrderActionHandler() = default;
  ~OrderActionHandler() = default;
  OrderActionHandler(StockExchange* exchange);
  std::vector<std::string> HandleAction(Action action);
};
