#include <iostream>
#include "strategy.h"


Strategy::Strategy(XTP::API::QuoteApi * quoteApi,
                   MyQuoteSpi * quoteSpi,
                   XTP::API::TraderApi * traderApi,
                   MyTraderSpi * traderSpi,
                   uint8_t client_id,
                   char * ticker,
                   uint64_t session)
{
    tmp_order = new XTPOrderInsertInfo();
    this->quoteApi = quoteApi;
    this->quoteSpi = quoteSpi;
    this->traderApi = traderApi;
    this->traderSpi = traderSpi;
    has_open_order = false;
    tmp_order->order_client_id = client_id;
    strcpy(tmp_order->ticker, ticker);
    this->session = session;
}


void Strategy::strategyHeartBeat() {
    if(!has_open_order && quoteSpi->depthMarketDataNum > 0){
        has_open_order = true;
        submitOrder(XTP_MKT_SH_A, 100, XTP_SIDE_BUY,
                    floorf(quoteSpi->midpt*100)/100);
    }
}


void Strategy::submitOrder(XTP_MARKET_TYPE market_name, int64_t quantity,
                 XTP_SIDE_TYPE side, float price)
{
    std::cout << "ticker is: " << tmp_order->ticker << std::endl;
    tmp_order->order_client_id = client_id;
    tmp_order->market = XTP_MKT_SH_A;
    tmp_order->price = price;
    tmp_order->quantity = quantity;
    tmp_order->side = XTP_SIDE_BUY;  // XTP_SIDE_TYPE
    tmp_order->price_type = XTP_PRICE_LIMIT;
    tmp_order->business_type = XTP_BUSINESS_TYPE_CASH;
    traderApi->InsertOrder(tmp_order, session);
}
