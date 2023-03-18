//
// Created by lis on 18.03.2023.
//
#include "ActionHandler.h"
#include "ActionType.h"
#include <iostream>
#include <vector>

#ifndef EXCHANGE_ACTION_H
#define EXCHANGE_ACTION_H

class Action {
 public:
  ActionType action_type;
  std::vector<std::string> arguments;

  Action(ActionType action_type, std::vector<std::string> arguments) {
    this->action_type = action_type;
    this->arguments = arguments;
  }

//  Action(std::string actionTypeString, std::vector<std::string> arguments) {
//    this(ActionHandler.getActionType(actionTypeString), arguments);
//  }

};

#endif //EXCHANGE_ACTION_H
