#pragma once

#include <iostream>
#include <unordered_map>
#include "../Company/Stock.hpp"

static int count = 0;

class Trader {
 public:
  Trader();
  ~Trader() = default;
  Trader(std::string name, double currency, std::unordered_map<int, std::pair<Stock, int>>);
  Trader(std::string name, double currency);

  long GetId();
  void SetId(long id);
  std::string GetName();
  void SetName(std::string name);
  double GetCurrency();
  void SetCurrency(double currency);
  std::unordered_map<int, std::pair<Stock, int>> GetHoldings();
  int GetHolding(Stock stock);
  void SetHoldings(std::unordered_map<int, std::pair<Stock, int>> holdings);
  void PutHolding(Stock stock, int quantity);
  double PutCurrency(double currency);
  std::string ToStringHoldings();
  std::string ToString();
 private:
  long id_;
  std::string name_;
  double currency_;
  std::unordered_map<int, std::pair<Stock, int>> holdings_; // stock, count
};
