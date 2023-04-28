#pragma once

#include <string>
#include <vector>
#include "../Actions/ActionHandler.hpp"
#include "../Actions/ActionType.hpp"
#include "../Actions/Action.hpp"
#include "Company.hpp"

class CompanyActionHandler : public ActionHandler {
 public:
  CompanyActionHandler() = default;
  CompanyActionHandler(StockExchange* exchange);
  ~CompanyActionHandler() = default;
  std::vector<std::string> HandleAction(Action action);
};
