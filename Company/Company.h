#pragma once
#include<string>
#include "Stock.h"
#include<vector>

std::vector<std::string> category_list = {"ENERGY", "MATERIALS", "INDUSTRY", "FINANCE", "IT"};

class Company {
 public:
  Company(std::string name, std::string ticker, std::string category, double open_price,
          double close_price, double low_price, double high_price);
  int GetCategoryIndex(std::string s) {
    for (int i = 0; i < category_list.size(); ++i) {
      if (s == category_list[i]) {
        return i;
      }
    }
  }
 private:
  std::string name_;
  int category_index_;
  Stock stock_;
};

