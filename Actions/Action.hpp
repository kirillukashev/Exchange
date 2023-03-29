#pragma once

#include "ActionHandler.hpp"
#include "ActionType.hpp"
#include <iostream>
#include <vector>

class Action {
 public:
  ActionType action_type;
  std::vector<std::string> arguments;

  Action(ActionType action_type, std::vector<std::string> arguments);
  Action(std::string actionTypeString, std::vector<std::string> arguments);
};
