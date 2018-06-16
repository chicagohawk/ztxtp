// testTradeApi.cpp : 定义控制台应用程序的入口点。
//

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

// global var

XTP::API::TraderApi* pUserApi;
bool is_connected_ = false;
std::string trade_server_ip;
int trade_server_port;
uint64_t session_id_ = 0;
std::map<uint64_t,uint64_t> map_session;
uint64_t* session_array = NULL;
FileUtils* fileUtils = NULL;
XTPOrderInsertInfo* orderList = NULL;
std::string quote_server_ip;
int quote_server_port;
std::string quote_username;
std::string quote_password;
XTP_PROTOCOL_TYPE quote_protocol = XTP_PROTOCOL_UDP;


int main()
{

    /// Quote API setup
    uint8_t client_id = 1;
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
    qApi->RegisterSpi(qSpi);

    qApi->SetUDPBufferSize((uint32_t) quote_buffer_size);
    qApi->SetHeartBeatInterval((uint32_t) heart_beat_interval);
    std::cout << "API version: " << qApi->GetApiVersion() << std::endl;

    int login_result = 999;
    int max_try = 3;
    for (int i = 0; i < max_try && login_result != 0; i++) {
        login_result = qApi->Login(
                quote_ip.c_str(), quote_port, user_name.c_str(),
                password.c_str(), quote_protocol
        );
        std::cout << login_result << std::endl;
        switch (login_result) {
            case 0:
                std::cout << "Login successful" << std::endl;
                break;
            case -3:
                std::cout << "Login error: input error" << std::endl;
                sleep(1);
                break;
            case -2:
                std::cout << "Login error: repeated login" << std::endl;
                sleep(1);
                break;
            case -1:
                std::cout << "Login error: sth. wrong connecting quote server" << std::endl;
                qApi->GetApiLastError();
                sleep(1);
                break;
        }
    }
    if(login_result != 0){
        std::cout << "max try reached, abort login quote server" << std::cout;
        return 1;
    }

    std::cout << "Trading day: " << qApi->GetTradingDay() << std::endl;

    /// Ticker setup
    char **tickers = new char*[0];
    tickers[0] = new char [64];
    std::strcpy(tickers[0], std::string("600120").c_str());

    XTP_EXCHANGE_TYPE quote_exchange = XTP_EXCHANGE_SH;
    qApi->SubscribeMarketData(tickers, 1, quote_exchange);
    std::cout << "last_price | B2, B1; A1, A2 | QB2, QB1; QA1, QA2" << std::endl;



    /* Send an order at a given time, then sleeps for x seconds.
     * If filled, do nothing.
     * If partially or not filled, cancel the remainder.
    */

    char *log_file_path = new char[64];
    std::strcpy(log_file_path, std::string("../log/").c_str());
    std::string trade_server_ip = "120.27.164.69";
    int trade_port = 6001;


    pUserApi = XTP::API::TraderApi::CreateTraderApi(client_id, log_file_path);
    pUserApi->SubscribePublicTopic(XTP_TERT_QUICK);
	pUserApi->SetSoftwareVersion("1.1.0"); //设定此软件的开发版本号，用户自定义
	pUserApi->SetSoftwareKey(account_key.c_str());//设定用户的开发代码，在XTP申请开户时，由xtp人员提供
	pUserApi->SetHeartBeatInterval(10);//设定交易服务器超时时间，单位为秒，此为1.1.16新增接口

	MyTraderSpi* pUserSpi = new MyTraderSpi();
	pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
	pUserSpi->setUserAPI(pUserApi);
	pUserSpi->set_save_to_file(true);
    uint64_t session = pUserApi->Login(
            trade_server_ip.c_str(), trade_port, user_name.c_str(), password.c_str(),
            XTP_PROTOCOL_TCP);
    if (session>0)
        map_session.insert(std::make_pair(session, 0));
    else {
        std::cout << "login to trader server error" << std::endl;
        return 0;
    }

    /// Query position and asset
    pUserApi->QueryPosition(tickers[0], session, 0);
    pUserApi->QueryAsset(session, 1);

/*
    /// make order
    myOrder.order_client_id = client_id;
    strcpy(myOrder.ticker, ticker[0]);
    myOrder.market = XTP_MKT_SH_A;
    // myOrder.price unset, use onQuote to send orders;
    myOrder.quantity = 100;
    myOrder.side = XTP_SIDE_BUY;
    myOrder.price_type = XTP_PRICE_LIMIT;
    myOrder.business_type = XTP_BUSINESS_TYPE_CASH;

//    InsertOrder at midpt;



   			//从配置文件中读取报单信息
			int j = 0;
			orderList[i].order_client_id = i;
			std::string instrument = fileUtils->stdStringForKey("order[%d].instrument_id", j);
			strcpy(orderList[i].ticker, instrument.c_str());
			orderList[i].market = (XTP_MARKET_TYPE)fileUtils->intForKey("order[%d].exchange", j);
			orderList[i].price = fileUtils->floatForKey("order[%d].price", j);
			orderList[i].quantity = fileUtils->intForKey("order[%d].quantity", j);
			orderList[i].side = (XTP_SIDE_TYPE)fileUtils->intForKey("order[%d].side", j);
			orderList[i].price_type = (XTP_PRICE_TYPE)fileUtils->intForKey("order[%d].price_type", j);
			orderList[i].business_type = (XTP_BUSINESS_TYPE)fileUtils->intForKey("order[%d].business_type", j);

			if (session_array[i] == 0)
			{
				//用户登录不成功时，跳过
				continue;
			}

			//报单
			int64_t xtp_id = pUserApi->InsertOrder(&(orderList[i]), session_array[i]);
			if (xtp_id == 0)
			{
*/
    while(true){
        sleep(1);
    }

}
