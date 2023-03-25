#pragma once
#include <iostream>
#include "../Company/Stock.h"
#include <unordered_map>

static int count = 0;

class Trader {
 private:
  long id_;
  std::string name_;
  double currency_;
  std::unordered_map<Stock, int> holdings_; // stock, count

 public:
  Trader(std::string name, double currency, std::unordered_map<Stock, int> holdings);

  Trader(std::string name, double currency);

  long GetId();

  void SetId(long id);

  std::string GetName();

  void SetName(std::string name);

  double GetCurrency();

  void SetCurrency(double currency);

  std::unordered_map<Stock, int> GetHoldings();

  int GetHolding(Stock s);

  void SetHoldings(std::unordered_map<Stock, int> holdings);

  void PutHolding(Stock s, int q);

  std::string toStringHoldings();

  std::string ToString();
};
