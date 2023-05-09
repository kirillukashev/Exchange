#include "Action.hpp"

#include <utility>

Action::Action(ActionType action_type, std::vector<std::string> arguments) :
       action_type(action_type), arguments(std::move(arguments)) {}

Action::Action(std::string actionTypeString, std::vector<std::string> arguments) :
       action_type(ActionHandler::GetActionType(std::move(actionTypeString))), arguments(std::move(arguments)) {}
