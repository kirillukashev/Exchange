//
// Created by akhtyamovpavel on 5/1/20.
//

#include "../Trader/Trader.hpp"
#include <iostream>

int main() {
    std::string name = "lis";
    int currency = 1200;
    Trader trader = Trader(name, currency);
    if (name == trader.GetName()) {
        std::cout << "ACCEPT";
    }
}