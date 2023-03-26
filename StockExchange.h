#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Trader/Trader.h"
#include "Company/Company.h"

class StockExchange {
 public:
  StockExchange() = default;
  StockExchange(std::string name);

  std::vector<Company> GetCompanies();
  Company* GetCompany(std::string ticker);
  std::vector<Company> GetCompaniesByCategory(std::string s);
  bool AddCompany(Company c);
  bool DeleteCompany(Company* c);
  bool DeleteCompany(std::string ticker);
  Trader* GetTrader(long id);
  bool addTrader(Trader t);
  bool DeleteTrader(Trader *t);
  bool DeleteTrader(long id);
  std::string ToString();
  std::string GetName();
 private:
  std::string name_;
  std::vector<Company> companies_;
  std::vector<Trader> traders_;
//  std::vector<Order> orders_;
};
