//
// Created by lis on 18.03.2023.
//

#include <iostream>
//#include "../Company/Stock"
#include <unordered_map>

#ifndef EXCHANGE_TRADER_H
#define EXCHANGE_TRADER_H

static int count = 0;

class Trader {
 private:
  long id;
  std::string name;
  double currency;
//  std::unordered_map<Stock, int> holdings; // stock, count
//
 public:
//  Trader(std::string name, double currency, std::unordered_map<Stock, int> holdings) :
//         name(name), currency(currency), holdings(holdings) {
//    id = count++;
//  }

  Trader(std::string name, double currency) : name(name), currency(currency) {
    id = count++;
  }

  long GetId() {
    return id;
  }

  void SetId(long id) {
    this->id = id;
  }

  std::string GetName() {
    return name;
  }

  void SetName(std::string name) {
    this->name = name;
  }

  double GetCurrency() {
    return currency;
  }

  void SetCurrency(double currency) {
    this->currency = currency;
  }

//  std::unordered_map<Stock, int> GetHoldings() {
//    return holdings;
//  }
//
//  int GetHolding(Stock s) {
//    return holdings[s];
//  }
//
//  void SetHoldings(HashMap<Stock, Integer> holdings) {
//    this->holdings = holdings;
//  }

//  void PutHolding(Stock s, int q) {
//    holdings[s] += q;
//  }
//
//  std::string toStringHoldings() {
//    if (holdings.size() == 0) {
//      return "{}";
//    }
//    std::string return_str = "{";
//    for (Stock s : holdings.keySet()) {
//      return_str += "{stock = " + s.getTicker() + ", quantity = " + holdings.get(s) + "}, ";
//    }
//    return_str = return_str.substr(0, return_str.size() - 1);
//    return_str += "}";
//    return return_str;
//  }

//  std::string ToString() {
//    std::string return_ans = "Trader{id = " + std::to_string(id) +
//    ", name = " + name +
//    ", currency = " + std::to_string(currency) +
//    ", holdings = " + toStringHoldings() +
//    '}';
//  }

  // ToString?
};

#endif //EXCHANGE_TRADER_H
