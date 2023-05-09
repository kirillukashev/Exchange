#pragma once

#include <string>
#include <vector>
#include "../Backend/Actions/ActionHandler.hpp"
#include "../Backend/Actions/ActionType.hpp"
#include "../Backend/Actions/Action.hpp"
#include "../Backend/Company/Company.hpp"

class CompanyActionHandler : public ActionHandler {
 public:
  CompanyActionHandler() = default;
  CompanyActionHandler(StockExchange* exchange);
  ~CompanyActionHandler() = default;
  std::vector<std::string> HandleAction(Action action);
};
