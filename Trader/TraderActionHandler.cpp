#include "TraderActionHandler.h"

TraderActionHandler::TraderActionHandler(StockExchange se) :
        ActionHandler(se, "TRADER") {}

std::vector<std::string> TraderActionHandler::HandleAction(const Action& action) {
  std::vector<std::string> return_ans;
  std::vector<std::string> arguments = action.arguments;

  switch (action.action_type) {
    case SHOW:
      if (arguments.size() == 1) {
        long id = std::stol(arguments[0]);
        return_ans.push_back(context.CheckTrader(id));
      } else {
        return_ans.push_back("Usage: TRADER SHOW id?");
      }
      break;

    case ADD:
      if (arguments.size() == 2) {
        std::string name = arguments[0];
        double currency = std::stod(arguments[1]);
        Trader t = Trader(name, currency);

        if (context.AddTrader(t)) {
            return_ans.push_back("Added " + t.ToString());
          break;
        } else {
          return_ans.push_back("Failed to add trader '" + name + "'");
        }
      }
      if (arguments.size() >= 3) {
        std::string name = arguments[0];
        double currency = std::stod(arguments[1]);
        Trader t = Trader(name, currency);
        std::string holdings_string;
        if (arguments.size() >= 4 && arguments.size() % 2 == 0) {
          for (int i = 2; i < arguments.size(); i += 2) {
            //TODO
//            std::transform(arguments[i].begin(), arguments[i].end(), arguments[i].begin(), ::toupper);
//            Company* c = context.GetCompany(arguments[i]);
//            t.PutHolding(context.GetCompany(arguments[i])->GetStock(), std::stoi(arguments[i + 1]));
//              return_ans.push_back("Failed to add holding {" + arguments[i] + ": " + arguments[i + 1] + "}");
          }

          if (context.AddTrader(t)) {
            return_ans.push_back("Added " + t.ToString());
            break;
          } else {
            return_ans.push_back("Failed to add trader '" + name + "'");
          }
        }
      }
      return_ans.push_back(
              "Usage: TRADER ADD name? currency? holdings(format:\'{ticker: quantity, ticker2: quantity2, ...}\")?");
      break;

    case DELETE:
      if (arguments.size() == 1) {
        std::string id_str = arguments[0];
//        Trader *t = context.GetTrader(std::stol(id_str));
//        if (t != nullptr) {
//          if (context.DeleteTrader(t)) {
//              return_ans.push_back("Deleted " + t->ToString());
//          } else {
//            return_ans.push_back("Failed to delete trader " + id_str);
//          }
//        } else {
//          return_ans.push_back("Trader with id " + id_str + " isn't registered with " + context.GetName());
//        }
        return_ans.push_back(context.DeleteTrader(std::stol(id_str)));
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
  return return_ans;
}