#include "quote_spi.h"
#include <iostream>
#include <stdio.h>
using namespace std;



void MyQuoteSpi::OnError(XTPRI *error_info, bool is_last)
{
	cout << "--->>> "<< "OnRspError" << endl;
	IsErrorRspInfo(error_info);
}

MyQuoteSpi::MyQuoteSpi()
{
}

MyQuoteSpi::~MyQuoteSpi()
{
}

void MyQuoteSpi::OnDisconnected(int reason)
{
	cout << "--->>> " << "OnDisconnected quote" << endl;
	cout << "--->>> Reason = " << reason << endl;
	//断线后，可以重新连接
	//重新连接成功后，需要重新向服务器发起订阅请求
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
    mitpt = (market_data->bid[0] + market_data->ask[0]) * .5;
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

