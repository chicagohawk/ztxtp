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
    edge = 0.05;
    priceEMA = 0.;
    coefEMA = .002;
}


void Strategy::setRegime() {
    lt = time(NULL);
    ptr = localtime(&lt);

    if(!is_pre_open && ptr->tm_hour > 21 && ptr->tm_min >= 15){
        is_pre_open = true;
    }

    // CHANGE tm_hour TO 21 (USA) or 9 (CHINA) !
    if(is_pre_open && !is_auction_cutoff &&
            ptr->tm_hour > 21 && ptr->tm_min >= 24) {
        is_auction_cutoff = true;
    }
}


void Strategy::strategyHeartBeat() {

    std::cout << "priceEMA: " << priceEMA << std::endl;
    setRegime();

    if(priceEMA == 0. && is_pre_open && quoteSpi->auction_qty>0){
        // first-time set priceEMA
        priceEMA = quoteSpi->midpt;
    }

    if(is_pre_open){
        priceEMA = priceEMA * (1-coefEMA) + quoteSpi->midpt * coefEMA;
    }

    if (is_pre_open && is_auction_cutoff && !has_open_order) {
        int64_t quantity = ceil((float)quoteSpi->auction_qty / 100. * .1) * 100;    // 10% participation
        float bid_price = floorf( (quoteSpi->midpt - edge) *100 ) / 100;
        float ask_price = floorf( (quoteSpi->midpt + edge) *100 ) / 100;

        has_open_order = true;
        submitOrder(XTP_MKT_SH_A, quantity, XTP_SIDE_BUY, bid_price);
        submitOrder(XTP_MKT_SH_A, quantity, XTP_SIDE_SELL, ask_price);
    }
}


void Strategy::submitOrder(XTP_MARKET_TYPE market_name, int64_t quantity,
                 XTP_SIDE_TYPE side, float price)
{
    std::cout << "Order sent on strategy heartbeat:" << std::endl;
    std::cout << "ticker is: " << tmp_order->ticker << std::endl;
    std::cout << price << " | " << quantity << std::endl;
    std::cout << side << std::endl;

    tmp_order->order_client_id = client_id;
    tmp_order->market = XTP_MKT_SH_A;
    tmp_order->price = price;
    tmp_order->quantity = quantity;
    tmp_order->side = XTP_SIDE_BUY;  // XTP_SIDE_TYPE
    tmp_order->price_type = XTP_PRICE_LIMIT;
    tmp_order->business_type = XTP_BUSINESS_TYPE_CASH;
    traderApi->InsertOrder(tmp_order, session);
}
