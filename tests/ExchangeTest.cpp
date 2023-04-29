//
// Created by lisa on 29.04.23.
//

#include "ExchangeTest.hpp"

TEST(ExchangeTest, ActionInit) {
    Action action = Action(ActionType::ADD, {"lis", "1200"});
    Action action2 = Action("ADD", {"lis", "1200"});
}

TEST(ExchangeTest, TraderInit) {
    Trader trader1 = Trader("lis", 1200);

}

TEST(ExchangeTest, ExchangeInitWithTrader) {
    StockExchange exchange_example = StockExchange();
    std::string name = "BiRgA";
    std::string name_expected = "BIRGA";
    StockExchange exchange = StockExchange(name);
    ASSERT_EQ(name_expected, exchange.GetName());
    Trader trader = Trader("lis", 1200);
    exchange.AddTrader(trader);
    exchange.AddTrader(trader); //double add
    exchange.ToString();
    exchange.DeleteTrader(1L);
    exchange.DeleteTrader(1L); //double delete
    exchange.AddTrader(trader);
    EXPECT_FALSE(exchange.CheckTrader(2) == "Trader with id 2 isn't registered");
    EXPECT_TRUE(exchange.CheckTrader(4) == "Trader with id 4 isn't registered");
    int index = exchange.GetTraderIndex(2);
    EXPECT_TRUE(exchange.GetTraderByIndex(index).GetName() == trader.GetName());
    exchange.DeleteTrader(index);
    exchange.DeleteTrader(index);
    ASSERT_EQ(exchange.GetTraderIndex(124), -1);
}

TEST(ExchangeTest, ExchangeInitWithCompany) {
    StockExchange exchange = StockExchange();
    Company company = Company("Yandex", "ya", "IT", 120, 120, 120, 120, 20000);
    std::vector<Company> companies = exchange.GetCompanies();
    exchange.AddCompany(company);
    exchange.ToString();
    ASSERT_EQ(company.GetName(), exchange.GetCompanyByIndex(exchange.GetCompanyIndex("ya")).GetName());
    std::vector<Company> categories = exchange.GetCompaniesByCategory("FINANCE");
    EXPECT_TRUE(categories.empty());
    exchange.DeleteCompany("ya");
    exchange.DeleteCompany("lo");
}