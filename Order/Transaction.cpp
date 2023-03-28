/*#include "Transaction.h"

Transaction::Transaction() {}

Transaction::Transaction(Order order, Trader seller, Trader buyer) {
  this->stock_ = order.GetStock();
  this->type_ = Type("TRANSACTION");
  this->quantity_ = order.GetQuantity();
  this->rate_ = order.GetRate();
  this->seller_ = seller;
  this->buyer_ = buyer;
}

Trader Transaction::GetSeller() {
  return this->seller_;
}

void Transaction::SetSeller(Trader seller) {
 this->seller_ = seller;
}

Trader Transaction::GetBuyer() {
  return this->buyer_;
}

void Transaction::SetBuyer(Trader buyer) {
  this->buyer_ = buyer;
}

std::string Transaction::ToString() {
  std::string str_seller_id = std::to_string(GetSeller().GetId());
  std::string str_buyer_id = std::to_string(GetBuyer().GetId());
  std::string str_quantity = std::to_string(GetQuantity());
  std::string str_rate = std::to_string(GetRate());
  return "Transaction{seller_id=" + str_seller_id + ", seller_name='" + GetSeller().GetName() + "', buyer_id="
  + str_buyer_id + ", buyer_name='" + GetBuyer().GetName() + "', stock='" + GetStock().GetTicker()
  + "', quantity=" + str_quantity+ ", rate=" + str_rate + "}";
}

bool execute() {
  //TODO
}*/