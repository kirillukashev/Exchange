#include "OrderActionHandler.h"

OrderActionHandler::OrderActionHandler(StockExchange* se) :
      ActionHandler(se, "COMPANY") {}

std::vector<std::string> OrderActionHandler::HandleAction(Action action) {
  std::vector<std::string> return_ans;
  std::vector<std::string> arguments = action.arguments;
  std::vector<Order> orders_ex = context->GetOrders();
  switch (action.action_type) {
    case EXECUTE_ALL:
      return_ans.push_back("* EXECUTING ORDERS *");
      for (int x = 0; x < orders_ex.size(); ++x) {
        return_ans.push_back( context->ExecuteOrder(orders_ex[x], x));
      }
      return_ans.push_back("* ORDERS PROCESSED *");
      break;
    case STAGE:
      std::cout << "\n";
      if (arguments.size() == 5) {
        long id = std::stol(arguments[0]);
        std::string ticker = arguments[1];
        std::string type = arguments[2];
        int quantity = std::stoi(arguments[3]);
        double rate = std::stod(arguments[4]);
        int trader_index = context->GetTraderInd(id);
        int company_index = context->GetCompanyIndex(ticker);
        if (trader_index != -1) {
          if (company_index != -1) {
            Trader t = context->GetTraderByIndex(trader_index);
            Company c = context->GetCompanyByIndex(company_index);
            Order o(t, c.GetStock(), type, quantity, rate);
            context->AddOrder(o);
            return_ans.push_back(o.ToString());
          } else {
            return_ans.push_back("Company with ticker '" + ticker + "' not found");
          }
        } else {
          return_ans.push_back("Trader with id '" + std::to_string(id) + "' not found");
        }
      } else {
        return_ans.push_back("Usage: ORDER STAGE trader_id? stock_ticker? type(BUY/SELL)? quantity? rate?");
      }
      break;
    default:
      return_ans.push_back("Usage:");
      return_ans.push_back("  ORDER EXECUTE_ALL");
      return_ans.push_back("  ORDER STAGE trader_id? stock_ticker? type(BUY/SELL)? quantity? rate?");
  }

  return return_ans;
}