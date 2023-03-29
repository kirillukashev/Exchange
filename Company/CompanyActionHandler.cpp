#include "CompanyActionHandler.hpp"

CompanyActionHandler::CompanyActionHandler(StockExchange* se) :
      ActionHandler(se, "ORDER") {}

std::vector<std::string> CompanyActionHandler::HandleAction(Action action) {
  std::vector<std::string> return_ans;
  std::vector<std::string> arguments = action.arguments;
  switch (action.action_type) {
    case SHOW:
      if (arguments.size() == 1) {
        std::string ticker = arguments[0];
        int index = context->GetCompanyIndex(ticker);
        if (index != -1) {
          return_ans.push_back(context->GetCompanyByIndex(index).ToString());
        } else {
          return_ans.push_back("Company with ticker " + ticker + " isn't registered");
        }
      } else {
        return_ans.push_back("Usage: COMPANY SHOW ticker?");
      }
      break;
    case SHOW_CATEGORIES:
      return_ans = {"COMPANY CATEGORIES:", "ENERGY", "MATERIALS", "INDUSTRY", "FINANCE", "IT"};
      break;
    case SHOW_CATEGORY:
      if (arguments.size() == 1) {
        std::string category = arguments[0];
        return_ans.push_back("SHOWING '" + category + "' COMPANIES");
        std::vector<Company> companies = context->GetCompaniesByCategory(category);
        if (companies.size() > 0) {
          for (int x = 0; x < companies.size(); ++x) {
            return_ans.push_back(companies[x].ToString());
          }
        } else {
          return_ans.push_back("No companies with category '" + category + "' registered");
        }
      } else {
        return_ans.push_back("Usage: COMPANY SHOW ticker?");
      }
      break;
    case ADD:
      if (arguments.size() == 8) {
        std::string name = arguments[0];
        std::string ticker = arguments[1];
        std::string category = arguments[2];
        double open_price = std::stod(arguments[3]);
        double close_price = std::stod(arguments[4]);
        double low_price = std::stod(arguments[5]);
        double high_price = std::stod(arguments[6]);
        int quantity_stock = std::stoi(arguments[7]);
        if (Company::GetCategoryIndex(category) == -1) {
          return_ans.push_back("This category does not exist");
          return_ans.push_back("Usage: COMPANY ADD name? ticker? category? open_price?"
                               " close_price? low_price? high_price? quantity_stock?");
          break;
        }
        Company c(name, ticker, category, open_price, close_price, low_price,
                  high_price, quantity_stock);
        if (context->AddCompany(c)) {
          return_ans.push_back("Added " + c.ToString());
          break;
        }
        return_ans.push_back("Failed to add company '" + ticker + "'");
      }
      return_ans.push_back("Usage: COMPANY ADD name? ticker? category? open_price? "
                           "close_price? low_price? high_price? quantity_stock?");
      break;
    case DELETE:
      if (arguments.size() == 1) {
        std::string ticker = arguments[0];
        std::string name_company = context->DeleteCompany(ticker);
        if (name_company != "NULL") {
          return_ans.push_back("Deleted " + name_company);
        } else {
          return_ans.push_back("Company with ticker " + ticker + " isn't registered");
        }
      } else {
        return_ans.push_back("Usage: COMPANY DELETE id?");
      }
      break;
    default:
      return_ans.push_back("Usage:");
      return_ans.push_back("  COMPANY SHOW ticker?");
      return_ans.push_back("  COMPANY SHOW_CATEGORIES");
      return_ans.push_back("  COMPANY SHOW_CATEGORY category?");
      return_ans.push_back("  COMPANY ADD name? ticker? category? open_price?"
                           " close_price? low_price? high_price? quantity_stock_?");
      return_ans.push_back("  COMPANY DELETE ticker?");
  }
  return return_ans;
}
