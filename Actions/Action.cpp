#include "Action.h"

Action::Action(ActionType action_type, std::vector<std::string> arguments) :
       action_type_(action_type), arguments_(arguments) {}

Action::Action(std::string actionTypeString, std::vector<std::string> arguments) :
       action_type_(ActionHandler::getActionType(actionTypeString)), arguments_(arguments) {}