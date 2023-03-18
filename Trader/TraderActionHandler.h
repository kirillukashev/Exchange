//
// Created by lis on 18.03.2023.
//

#include <iostream>
#include <vector>
#include "../Actions/ActionType.h"
#include "../Actions/Action.h"
#include "Trader.h"
#include "../Actions/ActionHandler.h"

#ifndef EXCHANGE_TRADERACTIONHANDLER_H
#define EXCHANGE_TRADERACTIONHANDLER_H

class TraderActionHandler : public ActionHandler {

  std::vector<std::string> HandleAction(Action action) {
    std::vector<std::string> return_ans;
    std::vector<std::string> arguments = action.arguments;

    switch (action.action_type) {
      case SHOW:
        if (arguments.size() == 1) {
          long id = std::stol(arguments[0]);
          Trader* t = context.getTrader(id); // From StockExchange
          if (t != nullptr) {
//            return_ans.push_back(t.ToString());
          } else {
            return_ans.push_back("Trader with id " + std::to_string(id) + " isn't registered");
          }
        } else {
          return_ans.push_back("Usage: TRADER SHOW id?");
        }
        break;

      case ADD:
        if (arguments.size() == 2) {
          std::string name = arguments[0];
          double currency = std::stod(arguments[1]);
          Trader t = Trader(name, currency);

          if (context.addTrader(t)) {
//            return_ans.push_back("Added " + t.ToString());
            break;
          } else {
            return_ans.push_back("Failed to add trader '" + name + "'");
          }
        }
//        if (arguments.size() >= 3) {
//          std::string name = arguments[0];
//          double currency = std::stod(arguments[1]);
//          Trader t = Trader(name, currency);
//          std::string holdings_string;
//          if (arguments.size() >= 4 && arguments.size() % 2 == 0) {
//            for (int i = 2; i < arguments.size(); i += 2) {
//              std::transform(arguments[i].begin(), arguments[i].end(), arguments[i].begin(), ::toupper);
//              Company c = context.getCompany(arguments[i]);
//              if (c != NULL) {
////                bool temp = t.putHolding(context.getCompany(arguments[i]).getStock(), static_cast<int>(argument[i + 1]));
//                if (temp) {
//                  continue;
//                }
//              }
//              return_ans.push_back("Failed to add holding {" + arguments[i] + ": " + arguments[i + 1] + "}");
//            }
//
//            if (context.addTrader(t)) {
//              return_ans.push_back("Added " + t.ToString());
//              break;
//            } else {
//              return_ans.push_back("Failed to add trader '" + name + "'");
//            }
//          }
//        }
        return_ans.push_back(
                "Usage: TRADER ADD name? currency? holdings(format:\'{ticker: quantity, ticker2: quantity2, ...}\")?");
        break;

      case DELETE:
        if (arguments.size() == 1) {
          std::string id_str = arguments[0];
          Trader* t = context.getTrader(std::stol(id_str));
          if (t != nullptr) {
            if (context.deleteTrader(t)) {
//              return_ans.push_back("Deleted " + t.ToString());
            } else {
              return_ans.push_back("Failed to delete trader " + id_str);
            }
          } else {
            return_ans.push_back("Trader with id " + id_str + " isn't registered with " + context.getName());
          }
        } else {
          return_ans.push_back("Usage: TRADER DELETE id?");
        }
        break;

      default:
        return_ans.push_back("Usage:");
        return_ans.push_back("  TRADER SHOW id?");
        return_ans.push_back(
                "  TRADER ADD name? currency? holdings(format:\"{ticker:quantity, ticker2:quantity2, ...}\")?");
        return_ans.push_back("  TRADER DELETE id?");
    }
  }
};

#endif //EXCHANGE_TRADERACTIONHANDLER_H
