#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class Stock {
 public:
  Stock();
  Stock(std::string ticker, double open_price, double close_price, double low_price, double high_price);
  ~Stock() = default;

  std::string GetTicker();
  void SetTicker(std::string ticker);

  double GetOpenPrice();
  void SetOpenPrice(double open_price);
  double GetClosePrice();
  void SetClosePrice(double close_price);
  double GetLowPrice();
  void SetLowPrice(double high_price);
  double GetHighPrice();
  void SetHighPrice(double high_price);
  std::string ToString();
  int HashCode();
 private:
  std::string ticker_;
  double open_price_;
  double close_price_;
  double low_price_;
  double high_price_;
};
