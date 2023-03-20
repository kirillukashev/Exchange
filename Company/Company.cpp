#include "Company.h"

Company::Company() {}

Company::Company(std::string name, std::string ticker, std::string category, double open_price, double close_price, double low_price, double high_price) {
  std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  this->name_ = name;
  std::transform(category.begin(), category.end(), category.begin(), ::toupper);
  this->category_index_ = GetCategoryIndex(category);
  this->stock_ = Stock(ticker, open_price, close_price, low_price, high_price);
}

int Company::GetCategoryIndex(std::string s) {
  for (int i = 0; i < category_list.size(); ++i) {
    if (s == category_list[i]) {
      return i;
    }
  }
}

std::string Company::GetName() {
  return this->name_;
}

void Company::SetName(std::string name) {
  this->name_ = name;
}

int Company::GetCategoryIndex() {
  return this->category_index_;
}

void Company::SetCategoryIndex(int category_index) {
  this->category_index_ = category_index;
}

Stock Company::GetStock() {
  return this->stock_;
}

void Company::SetStock(Stock stock) {
  this->stock_ = stock;
}

std::string Company::GetCategory() {
  return category_list[this->category_index_];
}

std::string Company::ToString() {
  return "6";
  //return "Сompany{name = '" + GetName() + "', category = '" + GetCategory() +
  //"', stock = " + this->stock_.ToString();
}