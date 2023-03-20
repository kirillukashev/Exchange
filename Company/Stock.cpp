#include "Stock.h"

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