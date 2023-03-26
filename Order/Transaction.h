#pragma once

#include <iostream>
#include <string>
#include "Order.h"
#include "Trader/Trader.h"

class Transaction : public Order {
 public:
  Transaction();
  Transaction(Order order, Trader seller, Trader buyer);

  Trader GetSeller();
  void SetSeller(Trader seller);
  Trader GetBuyer();
  void SetBuyer(Trader buyer);
  std::string ToString();
  bool execute();

 private:
  Trader buyer_;
  Trader seller_;
};

