#include "Order.h"

Order::Order() {}

Order::Order(Trader trader, Stock stock, Type type, int quantity, double rate) {
  this->trader_ = trader;
  this->stock_ = stock;
  this->type_ = type;
  this->quantity_ = quantity;
  this->rate_ = rate;
}

Order::Order(Trader trader, Stock stock, std::string type, int quantity, double rate) {
  this->trader_ = trader;
  this->stock_ = stock;
  this->type_ = Type(type);
  this->quantity_ = quantity;
  this->rate_ = rate;
}

Trader Order::GetTrader() {
  return this->trader_;
}

void Order::SetTrader(Trader trader) {
  this->trader_ = trader;
}

Stock Order::GetStock() {
  return this->stock_;
}

void Order::SetStock(Stock stock) {
  this->stock_ = stock;
}

Type Order::GetType() {
  return this->type_;
}

int Order::GetQuantity() {
  return this->quantity_;
}

void Order::SetQuantity(int quantity) {
  this->quantity_ = quantity;
}

double Order::GetRate() {
  return this->rate_;
}

void Order::SetRate(double rate) {
  this->rate_ = rate;
}
std::string Order::ToString() {
  std::string str_trader_id = std::to_string(GetTrader().GetId());
  std::string str_quantity = std::to_string(GetQuantity());
  std::string str_rate = std::to_string(GetRate());
  return "Order{trader_id=" + str_trader_id + ", trader_name='" + GetTrader().GetName() + "', stock='" + GetStock().GetTicker()
  + "', type='" + GetType().GetOrderString() + "', quantity=" + str_quantity + ", rate=" + str_rate + "}";
}