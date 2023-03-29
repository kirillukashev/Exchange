#include "Company.hpp"

Company::Company() {}

Company::Company(std::string name, std::string ticker, std::string category, double open_price, double close_price,
                 double low_price, double high_price, int quantity_stock) {
  std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  this->name_ = name;
  std::transform(category.begin(), category.end(), category.begin(), ::toupper);
  this->category_index_ = GetCategoryIndex(category);
  this->stock_ = Stock(ticker, open_price, close_price, low_price, high_price);
  this->quantity_stock_ = quantity_stock;
}

int Company::GetCategoryIndex(std::string s) {
  for (int i = 0; i < category_list.size(); ++i) {
    if (s == category_list[i]) {
      return i;
    }
  }
  return -1;
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

void Company::SetCategory(std::string category) {
  for (int i = 0; i < category_list.size(); ++i) {
    if (category == category_list[i]) {
      this->category_index_ = i;
      break;
    }
  }
  throw std::invalid_argument("This category does not exist");
}

int Company::GetQuantity() {
  return this->quantity_stock_;
}

void Company::SetQuantity(int quantity_stock) {
  this->quantity_stock_ = quantity_stock;
}

std::string Company::ToString() {
  return "Company{name = '" + GetName() + "', category = '" + GetCategory() + ", quantity_stock = " + std::to_string(GetQuantity())
  + "', stock = " + this->stock_.ToString();
}
