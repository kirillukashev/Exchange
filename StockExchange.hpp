#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Trader/Trader.hpp"
#include "Company/Company.hpp"
#include "Order/Order.hpp"

class StockExchange {
 public:
  StockExchange() = default;
  StockExchange(std::string name);

  std::vector<Company> GetCompanies();
  Company GetCompanyByIndex(int index);
  int GetCompanyIndex(std::string ticker);
  std::vector<Company> GetCompaniesByCategory(std::string s);
  bool AddCompany(Company c);
  std::string DeleteCompany(std::string ticker);
  int GetTraderInd(long id);
  Trader GetTraderByIndex(int index);
  std::string CheckTrader(long id);
  bool AddTrader(Trader t);
  std::string DeleteTrader(int t);
  std::string DeleteTrader(long id);
  std::string ToString();
  std::string GetName();
  void AddOrder(Order o);
  std::vector<Order> GetOrders();
  std::string ExecuteOrder(Order o, int index_order);
  template<typename T>
  std::string ToString(std::vector<T> vector);
 private:
  std::string name_;
  std::vector<Company> companies_;
  std::vector<Trader> traders_;
  std::vector<Order> orders_;
};
