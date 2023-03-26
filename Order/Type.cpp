#include "Type.h"

std::string Type::GetStringFromType(OrderType type) {
  switch (type) {
    case BUY:
      return "BUY";
    case SELL:
      return "SELL";
    case TRANSACTION:
      return "TRANSACTION";
    default:
      return "NULL";
  }
}

OrderType Type::GetTypeFromString(std::string type) {
  std::transform(type.begin(), type.end(), type.begin(), ::toupper);
  if (type.size() > 0) {
    if (type == "BUY") {
      return OrderType::BUY;
    } else if (type == "SELL") {
      return OrderType::SELL;
    } else if (type == "TRANSACTION") {
      return OrderType::TRANSACTION;
    } else {
      return OrderType::NULL0;
    }
  }
}

Type::Type() {}

Type::Type(std::string type) {
  this->type_ = GetTypeFromString(type);
}

Type::Type(OrderType type) {
  this->type_ = type;
}

OrderType Type::GetOrderType() {
  return this->type_;
}

std::string Type::GetOrderString() {
  return GetStringFromType(this->type_);
}

std::string Type::ToString() {
  return "Type{type=" + GetOrderString() + "}";
}