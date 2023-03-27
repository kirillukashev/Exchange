#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Trader/Trader.h"
#include "Company/Company.h"
#include "Order/Order.h"

class StockExchange {
 public:
  StockExchange() = default;
  StockExchange(std::string name);

  std::vector<Company> GetCompanies();
  int GetCompanyInd(std::string ticker);
  std::vector<Company> GetCompaniesByCategory(std::string s);
  bool AddCompany(Company c);
  std::string DeleteCompany(std::string ticker);
  std::string GetCompanyInf(int ind);
  int GetTraderInd(long id);
  std::string CheckTrader(long id);
  bool AddTrader(Trader t);
  std::string DeleteTrader(int t);
  std::string DeleteTrader(long id);
  std::string ToString();
  std::string GetName();
  template<typename T>
  std::string ToString(std::vector<T> vector);
 private:
  std::string name_;
  std::vector<Company> companies_;
  std::vector<Trader> traders_;
  std::vector<Order> orders_;
};
