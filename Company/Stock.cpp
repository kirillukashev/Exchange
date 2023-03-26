#include "Stock.h"

Stock::Stock() {}

Stock::Stock(std::string ticker, double open_price, double close_price, double low_price, double high_price) :
  open_price_(open_price),
  close_price_(close_price),
  low_price_(low_price),
  high_price_(high_price) {
  std::transform(ticker.begin(), ticker.end(), ticker.begin(), ::toupper);
  this->ticker_ = ticker;
};

std::string Stock::GetTicker() {
  return this->ticker_;
}

void Stock::SetTicker(std::string ticker) {
  this->ticker_ = ticker;
}

double Stock::GetOpenPrice() {
  return this->open_price_;
}

void Stock::SetOpenPrice(double open_price) {
  this->open_price_ = open_price;
}

double Stock::GetClosePrice() {
  return this->close_price_;
}

void Stock::SetClosePrice(double close_price) {
  this->close_price_ = close_price;
}

double Stock::GetLowPrice() {
  return this->low_price_;
}

void Stock::SetLowPrice(double low_price) {
  this->low_price_ = low_price;
}

double Stock::GetHighPrice() {
  return this->high_price_;
}

void Stock::SetHighPrice(double high_price) {
  this->high_price_ = high_price;
}

int Stock::HashCode() {
  long long p = 31;
  long long mod = 1e9 + 7;
  long long hash = 0;
  std::string s = this->GetTicker();
  for(int i = 0; i < s.size(); ++i){
    hash = (hash * p % mod + (s[i] - 'A' + 1)) % mod;
  }
  return hash;
}
std::string Stock::ToString() {
  std::string str_open_price = std::to_string(GetOpenPrice());
  std::string str_close_price = std::to_string(GetClosePrice());
  std::string str_low_price = std::to_string(GetLowPrice());
  std::string str_high_price = std::to_string(GetHighPrice());
  return "Stock{ticker = '" + GetTicker() + "', open_price = " + str_open_price + ", close_price = "
  + str_close_price + ", low_price = " + str_low_price + ", high_price = " + str_high_price + "}";
}