//
// Created by lis on 18.03.2023.
//
#include <iostream>
#include "Trader.h"
#include "../ActionHandler.h"

#ifndef EXCHANGE_TRADERACTIONHANDLER_H
#define EXCHANGE_TRADERACTIONHANDLER_H

class TraderActionHandler : public ActionHandler{
  std::vector<std::vector> handleAction(Action action) {
    std::vector<std::string> arguments = action.arguments;
    switch (action.ActionType) {
      case SHOW:
        if (arguments.size() == 1) {
          long id = std::stol(arguments[0]);
          //Trader t = context.getTrader(id);
        }

  }
};


#endif //EXCHANGE_TRADERACTIONHANDLER_H
