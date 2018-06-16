//
// Created by Han Chen on 2018/6/15.
//

#ifndef PROJECT_STRATEGY_H
#define PROJECT_STRATEGY_H

#include "xtp_api_struct_common.h"
#include "xquote_api_struct.h"

class Strategy{

  public:

    /// observing quote spi
    XTPMD * market_data;
    int64_t * bid1_qty, * ask1_qty;
    int32_t bid1_count, ask1_count;
    int32_t max_bid1_count, max_ask1_count;

    int num_DepthMarketData = 0;

    /// observing trade spi

    /// market states
    double last_price;

    void Quote_OnDepthMarketData(
            XTPMD * market_data,
            int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count,
            int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count
    );

    void OnStrategyHeartBeat();
};


#endif //PROJECT_STRATEGY_H
