#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Stock.h"

const std::vector<std::string> category_list = {"ENERGY", "MATERIALS", "INDUSTRY", "FINANCE", "IT"};

class Company {
 public:
  Company();
  Company(std::string name, std::string ticker, std::string category, double open_price,
          double close_price, double low_price, double high_price);
  int GetCategoryIndex(std::string s);

  std::string GetName();
  void SetName(std::string name);
  int GetCategoryIndex();
  void SetCategoryIndex(int category_index);
  Stock GetStock();
  void SetStock(Stock stock);
  std::string GetCategory();
  void SetCategory(std::string category);
  std::string ToString();
 private:
  std::string name_;
  int category_index_;
  Stock stock_;
};

