#include <iostream>
#include "strategy.h"

void Strategy::Quote_OnDepthMarketData(
        XTPMD *market_data,
        int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count,
        int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count){

  num_DepthMarketData ++;

  this->market_data = market_data;
  this->bid1_qty = bid1_qty;
  this->ask1_qty = ask1_qty;
  this->bid1_count = bid1_count;
  this->ask1_count = ask1_count;
  this->max_bid1_count = max_bid1_count;
  this->max_ask1_count = max_ask1_count;
}

void Strategy::OnStrategyHeartBeat(){
  if(num_DepthMarketData <= 0)
    return;
  last_price = market_data->last_price;
  std::cout << market_data->last_price << std::endl;
}
