#include "Action.h"

Action::Action(ActionType action_type, std::vector<std::string> arguments) :
       action_type(action_type), arguments(arguments) {}

Action::Action(std::string actionTypeString, std::vector<std::string> arguments) :
       action_type(ActionHandler::GetActionType(actionTypeString)), arguments(arguments) {}