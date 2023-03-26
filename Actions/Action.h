#pragma once

#include "ActionHandler.h"
#include "ActionType.h"
#include <iostream>
#include <vector>

class Action {
 public:
  ActionType action_type;
  std::vector<std::string> arguments;

  Action(ActionType action_type, std::vector<std::string> arguments);
  Action(std::string actionTypeString, std::vector<std::string> arguments);
};
