#include "StockExchange.h"

StockExchange::StockExchange(std::string name) {
std::transform(name.begin(), name.end(), this->name_.begin(), ::toupper);
}

bool StockExchange::addTrader(Trader t) {
  if (GetTrader(t.GetId()) == nullptr) {
    traders_.push_back(t);
    return true;
  }
  return false;
}

bool StockExchange::DeleteTrader(long id) {
  Trader* t = GetTrader(id);
  if (t != nullptr) {
    return DeleteTrader(t);
  }
  return false;
}

bool StockExchange::DeleteTrader(Trader* t) {
  for (std::vector<Trader>::iterator it = traders_.begin(); it != traders_.end(); ++it) {
    if (it->GetId() == t->GetId()) {
      traders_.erase(it);
      return true;
    }
  }
  return false;
}

std::string StockExchange::GetName() {
  return name_;
}

Trader* StockExchange::GetTrader(long id)  {
  for (Trader t : traders_) {
    if (t.GetId() == id) {
      return &t;
    }
  }
  return nullptr;
}

std::vector<Company> StockExchange::GetCompanies() {
  return companies_;
}

Company* StockExchange::GetCompany(std::string ticker) {
  std::transform(ticker.begin(), ticker.end(), ticker.begin(), ::toupper);
  for (Company c : companies_) {
    if (c.GetStock().GetTicker() == ticker) {
      return &c;
    }
  }
  return nullptr;
}

std::vector<Company> StockExchange::GetCompaniesByCategory(std::string ticker) {
  std::vector<Company> return_ans;
  for (Company c : companies_) {
    if (c.GetCategory() == ticker) {
      return_ans.push_back(c);
    }
  }
  return return_ans;
}

bool StockExchange::AddCompany(Company c) {
  if (GetCompany(c.GetStock().GetTicker()) == nullptr) {
    this->companies_.push_back(c);
    return true;
  }
  return false;
}

bool StockExchange::DeleteCompany(Company* c) {
  for (int x = 0; x < companies_.size(); ++x) {
    if (companies_[x].GetName() == c->GetName()) {
      companies_.erase(companies_.begin() + x);
      return true;
    }
  }
  return false;
}

bool StockExchange::DeleteCompany(std::string ticker) {
  Company* c = GetCompany(ticker);
  if (c != nullptr) {
    return DeleteCompany(c);
  }
  return false;
}

template<typename T>
std::string StockExchange::ToString(std::vector<T> vector) {
  std::string ans = "{";
  for (auto x : vector) {
    ans += x.ToString();
  }
  ans += "}";
  return ans;
}

std::string StockExchange::ToString() {
  std::string return_ans =  "StockExchange {name='" + name_ + '\'' +
                            ", publiclyListedCompanies=" + ToString(companies_) +
                            ", orders=" + ToString(orders_) + '}';
  return return_ans;
}