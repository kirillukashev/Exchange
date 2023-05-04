#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "../Actions/Action.hpp"
#include "TraderActionHandler.hpp"
#include "CompanyActionHandler.hpp"
#include "OrderActionHandler.hpp"

class Starter {
 public:
  Starter(StockExchange* exchange);
  ~Starter() = default;
  std::vector<std::string> Interpret(std::vector<std::string> parsed);
  void StartSession();
 private:
  static void Split(const std::string& string, std::vector<std::string>& elems);
  StockExchange* context_;
  CompanyActionHandler company_action_handler_;
  TraderActionHandler trader_action_handler_;
  OrderActionHandler order_action_handler_;
};
