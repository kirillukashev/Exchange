//
// Created by lis on 18.03.2023.
//

#ifndef EXCHANGE_ACTIONHANDLER_H
#define EXCHANGE_ACTIONHANDLER_H


class ActionHandler {
  enum ActionType {
    SHOW,
    SHOW_ALL,
    SHOW_CATEGORY,
    ADD,
    DELETE,
    STAGE,
    EXECUTE_ALL,
    NULL
  };

  StockExchange context;


};


#endif //EXCHANGE_ACTIONHANDLER_H
