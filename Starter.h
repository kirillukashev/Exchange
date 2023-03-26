#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Actions/Action.h"
#include "Trader/TraderActionHandler.h"

class Starter {
 private:
  static std::vector<std::string> split(const std::string& s, std::vector<std::string>& elems);

 public:
  static std::vector<std::string> interpret(std::vector<std::string> parsed);
  static void StartSession();
};