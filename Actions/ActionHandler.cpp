#include "ActionHandler.hpp"

std::string ActionHandler::GetActionString(ActionType action) {
  switch (action) {
    case SHOW:
      return "SHOW";
    case SHOW_CATEGORY:
      return "SHOW_CATEGORY";
    case SHOW_CATEGORIES:
      return "SHOW_CATEGORIES";
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
  std::transform(actionString.begin(), actionString.end(), actionString.begin(), ::toupper);
  if (!actionString.empty()) {
    if (actionString == "SHOW") {
      return ActionType::SHOW;
    }
    if (actionString == "SHOW_CATEGORY") {
      return ActionType::SHOW_CATEGORY;
    }
    if (actionString == "SHOW_CATEGORIES") {
      return ActionType::SHOW_CATEGORIES;
    }
    if (actionString == "ADD") {
      return ActionType::ADD;
    }
    if (actionString == "DELETE") {
      return ActionType::DELETE;
    }
    if (actionString == "STAGE") {
      return ActionType::STAGE;
    }
    if (actionString == "EXECUTE_ALL") {
      return ActionType::EXECUTE_ALL;
    }
  }
  return ActionType::NULL0;
}

ActionHandler::ActionHandler(StockExchange* context, std::string lead):
  action_leader(lead), context(context) {}