#ifndef PROJECT_STRATEGY_H
#define PROJECT_STRATEGY_H

#include "xtp_trader_api.h"
#include "xtp_quote_api.h"
#include "trade_spi.h"
#include "quote_spi.h"
#include "xoms_api_struct.h"
#include "xtp_api_data_type.h"
#include <math.h>
#include <ctime>
#include <sys/time.h>

class Strategy{
    public:
        XTP::API::QuoteApi * quoteApi;
        MyQuoteSpi * quoteSpi;
        XTP::API::TraderApi * traderApi;
        MyTraderSpi * traderSpi;

        uint8_t client_id;
        uint64_t session;

        // system time, CHANGE TO CHINA TIMEZONE AT DEPLOY!
        // ptr->tm_hour, ptr->tm_min, ptr->tm_sec, start.tv_usec
		struct tm *ptr;
		time_t lt;

       	bool is_pre_open;
       	bool is_auction_cutoff;

        Strategy(XTP::API::QuoteApi * quoteApi,
                 MyQuoteSpi * quoteSpi,
                 XTP::API::TraderApi * traderApi,
                 MyTraderSpi * traderSpi,
                 uint8_t client_id,
                 char* ticker,
                 uint64_t session
        );
        void strategyHeartBeat();

        bool has_open_order;
        XTPOrderInsertInfo * tmp_order;       // stores the current order to submit

        void submitOrder(XTP_MARKET_TYPE market_name, int64_t quantity,
                         XTP_SIDE_TYPE side, float price);
        float edge;
        float priceEMA;  float coefEMA;

};

#endif //PROJECT_STRATEGY_H
