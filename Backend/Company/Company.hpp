#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Stock.hpp"

const std::vector<std::string> category_list = {"ENERGY", "MATERIALS", "INDUSTRY", "FINANCE", "IT"};

class Company {
 public:
  Company();
  Company(std::string name, std::string ticker, std::string category, double open_price,
          double close_price, double low_price, double high_price, int quantity_stock);
  ~Company() = default;

  static int GetCategoryIndex(std::string name);
  std::string GetName();
  void SetName(std::string name);
  int GetCategoryIndex();
  void SetCategoryIndex(int category_index);
  Stock GetStock();
  void SetStock(Stock stock);
  std::string GetCategory();
  void SetCategory(std::string category);
  int GetQuantity();
  void SetQuantity(int quantity_stock);
  std::string ToString();
 private:
  std::string name_;
  int category_index_;
  Stock stock_;
  int quantity_stock_;
};
