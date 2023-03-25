#pragma once
#include <iostream>
#include <vector>
#include "Trader/Trader.h"
#include "Company/Company.h"

class StockExchange {
 private:
  std::string name_;
  std::vector<Company> companies_;
  std::vector<Trader> traders_;
//  std::vector<Order> orders_;

 public:
  StockExchange() = default;
  StockExchange(std::string name);

  std::vector<Company> getCompanies();

  Company* getCompany(std::string ticker);

  std::vector<Company> getCompaniesByCategory(std::string s);

  Trader* getTrader(long id);

  bool addTrader(Trader t);

  bool deleteTrader(Trader *t);

  bool deleteTrader(long id);

  std::string ToString();

  std::string getName();
};
