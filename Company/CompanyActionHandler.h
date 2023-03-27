#pragma once

#include <string>
#include <vector>
#include "../Actions/ActionHandler.h"
#include "../Actions/ActionType.h"
#include "../Actions/Action.h"
#include "Company.h"

class CompanyActionHandler : public ActionHandler {
 public:
  static std::vector<std::string> HandleAction(StockExchange context, Action action);
};
