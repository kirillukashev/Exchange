#include "TraderActionHandler.hpp"

TraderActionHandler::TraderActionHandler(StockExchange* exchange) :
        ActionHandler(exchange, "TRADER") {}

std::vector<std::string> TraderActionHandler::HandleAction(const Action& action) {
  std::vector<std::string> return_ans;
  std::vector<std::string> arguments = action.arguments;

  switch (action.action_type) {
    case SHOW:
      if (arguments.size() == 1) {
        long id = std::stol(arguments[0]);
        return_ans.push_back(context->CheckTrader(id));
      } else {
        return_ans.push_back("Usage: TRADER SHOW id?");
      }
      break;

    case ADD:
      if (arguments.size() == 2) {
        std::string name = arguments[0];
        double currency = std::stod(arguments[1]);
        Trader t = Trader(name, currency);

        if (context->AddTrader(t)) {
            return_ans.push_back("Added " + t.ToString());
          break;
        } else {
          return_ans.push_back("Failed to add trader '" + name + "'");
        }
      }
      if (arguments.size() >= 3) {
        std::string name = arguments[0];
        double currency = std::stod(arguments[1]);
        Trader trader = Trader(name, currency);
        std::string holdings_string;
        if (arguments.size() >= 4 && arguments.size() % 2 == 0) {
          for (int i = 2; i < arguments.size(); i += 2) {
            int index = context->GetCompanyIndex(arguments[i]);
            if (index != -1) {
              trader.PutHolding(context->GetCompanyByIndex(index).GetStock(), std::stoi(arguments[i + 1]));
            } else {
              return_ans.push_back("Failed to add holding {" + arguments[i] + ": " + arguments[i + 1] + "}");
            }
          }

          if (context->AddTrader(trader)) {
            return_ans.push_back("Added " + trader.ToString());
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
        return_ans.push_back(context->DeleteTrader(std::stol(id_str)));
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
