/*
 * To demonstrate QuoteApi.
 */

#include "xtp_trader_api.h"
#include <string>
#include <map>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // _WIN32

#include "trade_spi.h"
#include "FileUtils.h"
#include "xtp_quote_api.h"
#include "quote_spi.h"

void demoQuote(){
    /// Quote API setup
    uint8_t client_id = 0;
    std::string log_path("/Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/"
                    "demo/XTPApiDemo-1.1.16.20/log/");
    std::string account_key("b8aa7173bba3470e390d787219b2112e");
    std::string user_name("15005381");
    std::string password("XOjMGSZ4");
    std::string quote_ip("120.27.164.138");
    int quote_port = 6002;
    int quote_buffer_size = 128;
    int heart_beat_interval = 15;
    XTP_PROTOCOL_TYPE quote_protocol = XTP_PROTOCOL_TCP;

    XTP::API::QuoteApi *qApi = XTP::API::QuoteApi::CreateQuoteApi(
            client_id, log_path.c_str());

    MyQuoteSpi *qSpi = new MyQuoteSpi();
    qApi->RegisterSpi(qspi);

    qApi->SetUDPBufferSize((uint32_t) quote_buffer_size);
    qApi->SetHeartBeatInterval((uint32_t) heart_beat_interval);
    std::cout << "API version: " << qApi->GetApiVersion() << std::endl;

    int login_result = qApi->Login(quote_ip.c_str(), quote_port, user_name.c_str(),
                                   password.c_str(), quote_protocol);
    int max_try = 3;
    for (int i = 0; i < max_try && login_result != 0; i++) {
        switch (login_result) {
            case -3:
                std::cout << "Login error: input error" << std::endl;
                break;
            case -2:
                std::cout << "Login error: repeated login" << std::endl;
                break;
            case -1:
                std::cout << "Login error: retrieve last error" << std::endl;
                qApi->GetApiLastError();  break;
        }
    }
    std::cout << "Login successful" << std::endl;
    std::cout << "Trading day: " << qApi->GetTradingDay() << std::endl;

    /// Ticker setup
    char *ticker[] = {"600120",};
    XTP_EXCHANGE_TYPE quote_exchange = XTP_EXCHANGE_SH;
    qApi->SubscribeOrderBook(ticker, 1, quote_exchange);
    qApi->UnSubscribeOrderBook(ticker, 1, quote_exchange);

    while(true){
        sleep(1);
        continue;
    }

    // Subscribe Market Data (unSub)
    // Subscribe Order Book (unSub)
    // Subscribe Tick By Tick (unSub)
    // ...

    // QueryAllTickers

    // Logout
    // quoteApi::Release
}

