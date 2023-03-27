#include "OrderActionHandler.h"

OrderActionHandler::OrderActionHandler(StockExchange se) {
  context = se;
  action_leader = "ORDER";
}

std::vector<std::string> OrderActionHandler::HandleAction(Action action) {
  std::vector<std::string> return_ans;
  std::vector<std::string> arguments = action.arguments;
  //TODO
  return return_ans;
}