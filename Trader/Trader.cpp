#include "Trader.hpp"

std::string Trader::ToString() {
  std::string return_ans = "Trader{id = " + std::to_string(id_) +
                           ", name = " + name_ +
                           ", currency = " + std::to_string(currency_) +
                           ", holdings = " + ToStringHoldings();
  return return_ans;
}

void Trader::PutHolding(Stock s, int q) {
  holdings_[s.HashCode()] = {s, q};
}

std::string Trader::ToStringHoldings() {
  if (holdings_.size() == 0) {
    return "{}";
  }
  std::string return_str = "{";
  for (auto it = holdings_.begin(); it != holdings_.end();) {
    Stock s = (it->second).first;
    return_str += "{stock = " + s.GetTicker() + ", quantity = " + std::to_string(holdings_[s.HashCode()].second) + "}";
    it++;
    if (it != holdings_.end()) {
      return_str += ", ";
    }
  }
  return_str += "}";
  return return_str;
}

std::unordered_map<int, std::pair<Stock, int>> Trader::GetHoldings() {
  return holdings_;
}

int Trader::GetHolding(Stock s) {
  return holdings_[s.HashCode()].second;
}

void Trader::SetHoldings(std::unordered_map<int, std::pair<Stock, int>> holdings) {
  this->holdings_ = holdings;
}

void Trader::SetCurrency(double currency) {
  this->currency_ = currency;
}

Trader::Trader() {}

Trader::Trader(std::string name, double currency, std::unordered_map<int, std::pair<Stock, int>> holdings) :
        name_(name), currency_(currency), holdings_(holdings), id_(++count) {}

Trader::Trader(std::string name, double currency) : name_(name), currency_(currency), id_(++count), holdings_({}) {}

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

double Trader::PutCurrency(double currency) {
  if (GetCurrency() + currency < 0.0) {
    return 0.0;
  } else {
    SetCurrency(GetCurrency() + currency);
    return currency;
  }
}
