#include "Trader.h"

std::string Trader::ToString() {
  std::string return_ans = "Trader{id = " + std::to_string(id_) +
                           ", name = " + name_ +
                           ", currency = " + std::to_string(currency_) +
                           ", holdings = " + toStringHoldings()  +
                           '}';
}

void Trader::PutHolding(Stock s, int q) {
  holdings_.insert_or_assign(s, (holdings_[s] + q));
}

std::string Trader::toStringHoldings() {
  if (holdings_.size() == 0) {
    return "{}";
  }
  std::string return_str = "{";
  for (auto it = holdings_.begin(); it != holdings_.end(); ++it) {
    Stock s = it -> first;
    return_str += "{stock = " + s.GetTicker() + ", quantity = " + std::to_string(holdings_[s]) + "}, ";
  }
  return_str = return_str.substr(0, return_str.size() - 1);
  return_str += "}";
  return return_str;
}

std::unordered_map<Stock, int> Trader::GetHoldings() {
  return holdings_;
}

int Trader::GetHolding(Stock s) {
  return holdings_[s];
}

void Trader::SetHoldings(std::unordered_map<Stock, int> holdings) {
  this->holdings_ = holdings;
}

void Trader::SetCurrency(double currency) {
  this->currency_ = currency;
}

Trader::Trader() {}

Trader::Trader(std::string name, double currency, std::unordered_map<Stock, int> holdings) :
               name_(name), currency_(currency), holdings_(holdings), id_(count++) {}

Trader::Trader(std::string name, double currency) : name_(name), currency_(currency), id_(count++) {}

long Trader::GetId() {
  return id_;
}

void Trader::SetId(long id) {
  this->id_ = id;
}

std::string Trader::GetName() {
  return name_;
}

void Trader::SetName(std::string name) {
  this->name_ = name;
}

double Trader::GetCurrency() {
  return currency_;
}