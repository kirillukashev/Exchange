#include "CompanyActionHandler.h"

CompanyActionHandler::CompanyActionHandler(StockExchange se) :
      ActionHandler(se, "COMPANY") {}

std::vector<std::string> CompanyActionHandler::HandleAction(Action action) {
  std::vector<std::string> return_ans;
  std::vector<std::string> arguments = action.arguments;
  switch (action.action_type) {
    case SHOW:
      if (arguments.size() == 1) {
        std::string ticker = arguments[0];
        Company *c = context.GetCompany(ticker);
        if (c != nullptr) {
          return_ans.push_back(c->ToString());
        } else {
          return_ans.push_back("Company with ticker " + ticker + " isn't registered");
        }
      } else {
        return_ans.push_back("Usage: COMPANY SHOW ticker?");
      }
      break;
    case SHOW_CATEGORY:
      if (arguments.size() == 1) {
        std::string ticker = arguments[0];
        return_ans.push_back("SHOWING '" + ticker + "' COMPANIES");
        std::vector<Company> companies = context.GetCompaniesByCategory(ticker);
        if (companies.size() > 0) {
          for (int x = 0; x < companies.size(); ++x) {
            return_ans.push_back(companies[x].ToString());
          }
        } else {
          return_ans.push_back("No companies with category '" + ticker + "' registered");
        }
      } else {
        return_ans.push_back("Usage: COMPANY SHOW ticker?");
      }
      break;
    case ADD:
      if (arguments.size() == 7) {
        std::string name = arguments[0];
        std::string ticker = arguments[1];
        std::string category = arguments[2];
        double open_price = std::stod(arguments[3]);
        double close_price = std::stod(arguments[4]);
        double low_price = std::stod(arguments[5]);
        double high_price = std::stod(arguments[6]);
        Company c(name, ticker, category, open_price, close_price, low_price, high_price);
        if (context.AddCompany(c)) {
          return_ans.push_back("Added " + c.ToString());
          break;
        }
        return_ans.push_back("Failed to add company '" + ticker + "'");
      }
      return_ans.push_back("Usage: COMPANY ADD name? ticker? open_price? close_price? low_price? high_price?");
      break;
    case DELETE:
      if (arguments.size() == 1) {
        std::string ticker = arguments[0];
        Company *c = context.GetCompany(ticker);
        if (c != nullptr) {
          if (context.DeleteCompany(c)) {
            return_ans.push_back("Deleted " + c->ToString());
          } else {
            return_ans.push_back("Failed to delete company '" + ticker + "'");
          }
        } else {
          return_ans.push_back("Company with id " + ticker + " isn't registered with " + context.GetName());
        }
      } else {
        return_ans.push_back("Usage: COMPANY DELETE id?");
      }
      break;
    default:
      return_ans.push_back("Usage:");
      return_ans.push_back("  COMPANY SHOW ticker?");
      return_ans.push_back("  COMPANY SHOW_CATEGORY category?");
      return_ans.push_back("  COMPANY ADD name? ticker? category? open_price? close_price? low_price? high_price?");
      return_ans.push_back("  COMPANY DELETE ticker?");
  }
  return return_ans;
}