#include "StockExchange.h"

StockExchange::StockExchange(std::string name) {
std::transform(name.begin(), name.end(), this->name_.begin(), ::toupper);
}

bool StockExchange::addTrader(Trader t) {
  if (getTrader(t.GetId()) == nullptr) {
    traders_.push_back(t);
    return true;
  }
  return false;
}

bool StockExchange::deleteTrader(long id) {
  Trader* t = getTrader(id);
  if (t != nullptr) {
    return deleteTrader(t);
  }
  return false;
}

bool StockExchange::deleteTrader(Trader* t) {
  for (auto it = traders_.begin(); it != traders_.end(); ++it) {
    if (it->GetId() == t->GetId()) {
      traders_.erase(it);
      return true;
    }
  }
  return false;
}

std::string StockExchange::getName() {
  return name_;
}

Trader* StockExchange::getTrader(long id)  {
  for (Trader t : traders_) {
    if (t.GetId() == id) {
      return &t;
    }
  }
  return nullptr;
}

std::vector<Company> StockExchange::getCompanies() {
  return companies_;
}

Company* StockExchange::getCompany(std::string ticker) {
  for (Company c : companies_) {
    //
  }
  return nullptr;
}

std::vector<Company> StockExchange::getCompaniesByCategory(std::string s) {
  std::vector<Company> return_ans;
  for (Company c : companies_) {
    if (c.GetCategory() == s) {
      return_ans.push_back(c);
    }
  }
  return return_ans;
}

std::string StockExchange::ToString() {
  std::string return_ans =  "StockExchange {name='" + name_ + '\'' +
                            ", publiclyListedCompanies=" + companies_.ToString() +
                            ", orders=" + orders_.ToString() + '}';
  return return_ans;
}