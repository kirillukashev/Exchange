#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Actions/Action.h"
#include "Trader/TraderActionHandler.h"
#include "CompanyActionHandler.h"
#include "OrderActionHandler.h"

class Starter {
 public:
  Starter(StockExchange se);
  std::vector<std::string> Interpret(StockExchange se, std::vector<std::string> parsed);
  void StartSession(StockExchange se);

 private:
  std::vector<std::string> Split(const std::string& s, std::vector<std::string>& elems);
  StockExchange context_;
  CompanyActionHandler company_action_handler_;
  TraderActionHandler trader_action_handler_;
  OrderActionHandler order_action_handler_;
};