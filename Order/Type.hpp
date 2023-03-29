#pragma once

#include <iostream>
#include <algorithm>
#include "OrderType.hpp"

class Type {
 public:
  static std::string GetStringFromType(OrderType type);
  static OrderType GetTypeFromString(std::string type);

  Type();
  Type(std::string type);
  Type(OrderType type);

  OrderType GetOrderType();
  std::string GetOrderString();
  std::string ToString();
 private:
  OrderType type_;
};
