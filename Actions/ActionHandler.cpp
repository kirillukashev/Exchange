#include "ActionHandler.h"

std::string ActionHandler::GetActionString(ActionType action) {
  switch (action) {
    case SHOW:
      return "SHOW";
    case ADD:
      return "ADD";
    case DELETE:
      return "DELETE";
    case STAGE:
      return "STAGE";
    case EXECUTE_ALL:
      return "EXECUTE_ALL";
    default:
      return "NULL";
  }
}

ActionType ActionHandler::GetActionType(std::string actionString) {
  std::string s;
  std::transform(actionString.begin(), actionString.end(), s.begin(), ::toupper);
  if (s.length() > 0) {
    if (s == "SHOW") {
      return ActionType::SHOW;
    }
    if (s == "ADD") {
      return ActionType::ADD;
    }
    if (s == "DELETE") {
      return ActionType::DELETE;
    }
    if (s == "STAGE") {
      return ActionType::STAGE;
    }
    if (s == "EXECUTE_ALL") {
      return ActionType::EXECUTE_ALL;
    }
  }
  return ActionType::NULL0;
}

ActionHandler::ActionHandler(StockExchange cont, std::string lead):
  action_leader(lead) {}