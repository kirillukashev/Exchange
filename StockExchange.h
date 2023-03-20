//
// Created by днс on 18.03.2023.
//
#include <iostream>
#include <vector>
#include "Trader/Trader.h"


#ifndef EXCHANGE_STOCKEXCHANGE_H
#define EXCHANGE_STOCKEXCHANGE_H

class StockExchange {
  std::string name;
//  std::vector<Company> companies;
  std::vector<Trader> traders;
//  std::vector<Order> orders;

 public:

  StockExchange() = default;

  StockExchange(std::string name) {
    std::transform(name.begin(), name.end(), this->name.begin(), ::toupper);
  }

//  std::vector<Company> getCompanies() {
//    return companies;
//  }

//  Company* getCompany(std::string ticker) {
//    for (Company c : companies) {
//      //
//    }
//    return nullptr;
//  }

//  std::vector<Company> getCompaniesByCategory(std::string s) {
//    std::vector<Company> return_ans;
//    for (Company c : companies) {
//      if (c.getCategory().compareTo(s) == 0) {
//        return_ans.push_back(c);
//      }
//    }
//    return return_ans;
//  }

  Trader* getTrader(long id) {
    for (Trader t : traders) {
      if (t.GetId() == id) {
        return &t;
      }
    }
    return nullptr;
  }

  bool addTrader(Trader t) {
    if (getTrader(t.GetId()) == nullptr) {
      traders.push_back(t);
      return true;
    }
    return false;
  }

  bool deleteTrader(Trader *t) {
    for (auto it = traders.begin(); it != traders.end(); ++it) {
      if (it->GetId() == t->GetId()) {
        traders.erase(it);
        return true;
      }
    }
    return false;
  }

  bool deleteTrader(long id) {
    Trader* t = getTrader(id);
    if (t != nullptr) {
      return deleteTrader(t);
    }
    return false;
  }

//  std::string ToString() {
//    std::string return_ans =  "StockExchange {name='" + name + '\'' +
//           ", publiclyListedCompanies=" + companies.toString() +
//           ", orders=" + orders.toString() + '}';
//    return return_ans;
//  }

  std::string getName() {
    return name;
  }
};

#endif //EXCHANGE_STOCKEXCHANGE_H
