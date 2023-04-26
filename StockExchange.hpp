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
  ~StockExchange() = default;

  std::vector<Company> GetCompanies();
  Company GetCompanyByIndex(int index);
  int GetCompanyIndex(std::string ticker);
  std::vector<Company> GetCompaniesByCategory(std::string ticker);
  bool AddCompany(Company company);
  std::string DeleteCompany(std::string ticker);
  int GetTraderIndex(long id);
  Trader GetTraderByIndex(int index);
  std::string CheckTrader(long id);
  bool AddTrader(Trader trader);
  std::string DeleteTrader(int index);
  std::string DeleteTrader(long id);
  std::string ToString();
  std::string GetName();
  void AddOrder(Order order);
  std::vector<Order> GetOrders();
  std::string ExecuteOrder(Order order, int index_order);
  template<typename T>
  std::string ToString(std::vector<T> vector);
 private:
  std::string name_;
  std::vector<Company> companies_;
  std::vector<Trader> traders_;
  std::vector<Order> orders_;
};
