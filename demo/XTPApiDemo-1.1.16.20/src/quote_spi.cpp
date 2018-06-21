#include "quote_spi.h"
#include <iostream>
#include <stdio.h>
using namespace std;



void MyQuoteSpi::OnError(XTPRI *error_info, bool is_last)
{
	cout << "--->>> "<< "OnRspError" << endl;
	IsErrorRspInfo(error_info);
}

MyQuoteSpi::MyQuoteSpi() : depthMarketDataNum(0)
{
}

MyQuoteSpi::~MyQuoteSpi()
{
}

void MyQuoteSpi::OnDisconnected(int reason)
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


	cout << "--->>> " << "OnDisconnected quote" << endl;
	cout << "--->>> Reason = " << reason << endl;
	//断线后，可以重新连接
	//重新连接成功后，需要重新向服务器发起订阅请求
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
    }

    std::cout << "Trading day: " << qApi->GetTradingDay() << std::endl;

    qApi->SubscribeMarketData(tickers, 2, XTP_EXCHANGE_SH);

}

void MyQuoteSpi::OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last)
{
 	cout << "OnRspSubMarketData -----" << endl;
}

void MyQuoteSpi::OnUnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last)
{
 	cout << "OnRspUnSubMarketData -----------" << endl;
}

void MyQuoteSpi::OnDepthMarketData(XTPMD * market_data, int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count)
{

    depthMarketDataNum ++ ;
    midpt = (market_data->bid[0] + market_data->ask[0]) * .5;
    //if(market_data->bid_qty[0] == market_data->ask_qty[0]) {
        auction_qty = market_data->bid_qty[0];
    //}
    if(market_data->bid_qty[0] == 0){
        imbl_quantity = -1 * market_data->ask_qty[0];
    }
    else if (market_data->ask_qty[0] == 0){
        imbl_quantity = market_data->bid_qty[0];
    }
    else{
        imbl_quantity = 0;
    }

    cout << market_data->ticker << " | ";
    cout << market_data->last_price << " | ";
    cout << market_data->bid[1] << "," << market_data->bid[0] << " ; ";
    cout << market_data->ask[0] << "," << market_data->ask[1] << " | ";
    cout << market_data->bid_qty[1] << "," << market_data->bid_qty[0] << " ; ";
    cout << market_data->ask_qty[0] << "," << market_data->ask_qty[1] << endl;
}

void MyQuoteSpi::OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last)
{
	cout << "OnSubOrderBook --------" << endl;
}

void MyQuoteSpi::OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last)
{
	cout << "OnUnSubOrderBook ---------" << endl;
}

void MyQuoteSpi::OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last)
{
	cout << "OnSubTickByTick ---------" << endl;
}

void MyQuoteSpi::OnUnSubTickByTick(XTPST * ticker, XTPRI * error_info, bool is_last)
{
	cout << "OnUnSubTickByTick --------" << endl;
}

void MyQuoteSpi::OnOrderBook(XTPOB *order_book)
{
	cout << "OnOrderBook ----------" << endl;
	cout << "lastPrice: " << order_book->last_price << endl;
}

void MyQuoteSpi::OnTickByTick(XTPTBT *tbt_data)
{
	cout << "OnTickByTick ---------" << endl;
}

void MyQuoteSpi::OnQueryAllTickers(XTPQSI * ticker_info, XTPRI * error_info, bool is_last)
{
	cout << "OnQueryAllTickers -----------" << endl;
}

void MyQuoteSpi::OnSubscribeAllMarketData(XTPRI * error_info)
{
	cout << "OnSubscribeAllMarketData --------" << endl;
}

void MyQuoteSpi::OnUnSubscribeAllMarketData(XTPRI *error_info)
{
	cout << "OnUnSubscribeAllMarketData --------" << endl;
}

void MyQuoteSpi::OnSubscribeAllOrderBook(XTPRI *error_info)
{
	cout << "OnSubscribeAllOrderBook --------" << endl;
}

void MyQuoteSpi::OnUnSubscribeAllOrderBook(XTPRI * error_info)
{
	cout << "OnUnSubscribeAllOrderBook --------" << endl;
}

void MyQuoteSpi::OnSubscribeAllTickByTick(XTPRI * error_info)
{
	cout << "OnSubscribeAllTickByTick --------" << endl;
}

void MyQuoteSpi::OnUnSubscribeAllTickByTick(XTPRI * error_info)
{
	cout << "OnUnSubscribeAllTickByTick --------" << endl;
}

void MyQuoteSpi::OnQueryTickersPriceInfo(XTPTPI * ticker_info, XTPRI * error_info, bool is_last)
{
	cout << "OnQueryTickersPriceInfo --------" << endl;
}

bool MyQuoteSpi::IsErrorRspInfo(XTPRI *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->error_id != 0));
	if (bResult)
		cout << "--->>> ErrorID=" << pRspInfo->error_id << ", ErrorMsg=" << pRspInfo->error_msg << endl;
	return bResult;
}

