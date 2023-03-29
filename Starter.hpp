#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Actions/Action.hpp"
#include "Trader/TraderActionHandler.hpp"
#include "Company/CompanyActionHandler.hpp"
#include "Order/OrderActionHandler.hpp"

class Starter {
 public:
  Starter(StockExchange* se);
  std::vector<std::string> Interpret(std::vector<std::string> parsed);
  void StartSession();
 private:
  void Split(const std::string& s, std::vector<std::string>& elems);
  StockExchange* context_;
  CompanyActionHandler company_action_handler_;
  TraderActionHandler trader_action_handler_;
  OrderActionHandler order_action_handler_;
};
