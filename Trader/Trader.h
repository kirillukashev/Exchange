//
// Created by lis on 18.03.2023.
//

#include <iostream>
#include "../Company/Stock>
#include <unordered_map>

#ifndef EXCHANGE_TRADER_H
#define EXCHANGE_TRADER_H

class Trader {
  long id;
  std::string name;
  double currency;
  std::unordered_map<Stock, int> holdings; // stock, count

  Trader(std::string name, double currency, std::unordered_map<Stock, int> holdings) :
         name(name), currency(currency), holdings(holdings) {}

  Trader(std::string name, double currency) : name(name), currency(currency) {}

  long GetId() {
    return id;
  }

  void SetId(long id) {
    this->id = id;
  }

  std::string GetName() {
    return name;
  }

  void SetName(String name) {
    this.name = name;
  }

  double GetCurrency() {
    return currency;
  }

  void SetCurrency(double currency) {
    this->currency = currency;
  }

  std::unordered_map<Stock, int> GetHoldings() {
    return holdings;
  }

  int GetHolding(Stock s) {
    return holdings[s];
  }

  void SetHoldings(HashMap<Stock, Integer> holdings) {
    this->holdings = holdings;
  }

  void PutHolding(Stock s, int q) {
    holdings[s] += q;
  }

  // ToString?
};

#endif //EXCHANGE_TRADER_H
