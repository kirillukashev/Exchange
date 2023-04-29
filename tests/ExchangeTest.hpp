//
// Created by lisa on 29.04.23.
//

#pragma once

#include <gtest/gtest.h>
#include "../Trader/TraderActionHandler.hpp"
#include "../Company/CompanyActionHandler.hpp"
#include "../Order/OrderActionHandler.hpp"
#include "../Actions/ActionType.hpp"
#include "../Trader/Trader.hpp"
#include "../StockExchange.hpp"
#include "../Company/Company.hpp"
#include "../Company/Stock.hpp"
#include "../Actions/ActionHandler.hpp"

class TestTrader : public ::testing::Test {
};
