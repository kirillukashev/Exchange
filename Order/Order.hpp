#pragma once

#include<iostream>
#include <string>
#include "../Trader/Trader.hpp"
#include "../Company/Stock.hpp"
#include "Type.hpp"

class Order {
 public:
  Order();
  Order(Trader trader, Stock stock, Type type, int quantity, double rate);
  Order(Trader trader, Stock stock, std::string type, int quantity, double rate);
  ~Order() = default;

  Trader GetTrader();
  void SetTrader(Trader trader);
  Stock GetStock();
  void SetStock(Stock stock);
  Type GetType();
  int GetQuantity();
  void SetQuantity(int quantity);
  double GetRate();
  void SetRate(double rate);
  std::string ToString();

 protected:
  Trader trader_;
  Stock stock_;
  Type type_;
  int quantity_ = 0;
  double rate_ = 0.0;
};
