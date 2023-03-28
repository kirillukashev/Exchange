#include "StockExchange.h"

StockExchange::StockExchange(std::string name) {
  std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  this->name_ = name;
}

bool StockExchange::AddTrader(Trader t) {
  if (GetTraderInd(t.GetId()) == -1) {
    traders_.push_back(t);
    return true;
  }
  return false;
}

std::string StockExchange::DeleteTrader(long id) {
  int ind = GetTraderInd(id);
  if (ind != -1) {
    return DeleteTrader(ind);
  }
  return ("Trader with id " + std::to_string(id) + " isn't registered with " + GetName());
}

std::string StockExchange::DeleteTrader(int i) {
  for (std::vector<Trader>::iterator it = traders_.begin(); it != traders_.end(); ++it) {
    if (it->GetId() == traders_[i].GetId()) {
      std::string ans = ("Deleted " + traders_[i].ToString());
      traders_.erase(it);
      return ans;
    }
  }
  return ("Failed to delete trader " + std::to_string(traders_[i].GetId()));
}

std::string StockExchange::GetName() {
  return name_;
}

std::string StockExchange::CheckTrader(long id) {
  for (Trader t : traders_) {
    if (t.GetId() == id) {
      return t.ToString();
    }
  }
  return ("Trader with id " + std::to_string(id) + " isn't registered");
}

int StockExchange::GetTraderInd(long id)  {
  for (int i = 0; i < traders_.size(); ++i) {
    if (traders_[i].GetId() == id) {
      return i;
    }
  }
  return -1;
}

std::vector<Company> StockExchange::GetCompanies() {
  return companies_;
}

int StockExchange::GetCompanyIndex(std::string ticker) {
  std::transform(ticker.begin(), ticker.end(), ticker.begin(), ::toupper);
  for (int i = 0; i < companies_.size(); ++i) {
    if (companies_[i].GetStock().GetTicker() == ticker) {
      return i;
    }
  }
  return -1;
}

Company StockExchange::GetCompanyByIndex(int index) {
  return companies_[index];
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
  if (GetCompanyIndex(c.GetStock().GetTicker()) == -1) {
    this->companies_.push_back(c);
    return true;
  }
  return false;
}

std::string StockExchange::DeleteCompany(std::string ticker) {
  int ind = GetCompanyIndex(ticker);
  if (ind != -1) {
    std::string ans = companies_[ind].ToString();
    companies_.erase(companies_.begin() + ind);
    return ans;
  }
  return "NULL";
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