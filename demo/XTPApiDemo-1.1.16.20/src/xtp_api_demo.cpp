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

XTP::API::TraderApi* pUserApi;//yes
bool is_connected_ = false;//yes
std::string trade_server_ip;//yes
int trade_server_port;
uint64_t session_id_ = 0;
std::map<uint64_t,uint64_t> map_session;
uint64_t* session_arrary = NULL;
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
    char **ticker = new char*[0];
    ticker[0] = new char [64];
    std::strcpy(ticker[0], std::string("600120").c_str());

    XTP_EXCHANGE_TYPE quote_exchange = XTP_EXCHANGE_SH;
    qApi->SubscribeOrderBook(ticker, 1, quote_exchange);


    /*

	//初始化交易类Api
	pUserApi = XTP::API::TraderApi::CreateTraderApi(client_id,filepath.c_str());			// 创建UserApi
	pUserApi->SubscribePublicTopic((XTP_TE_RESUME_TYPE)resume_type);
	pUserApi->SetSoftwareVersion("1.1.0"); //设定此软件的开发版本号，用户自定义
	pUserApi->SetSoftwareKey(account_key.c_str());//设定用户的开发代码，在XTP申请开户时，由xtp人员提供
	pUserApi->SetHeartBeatInterval(heat_beat_interval);//设定交易服务器超时时间，单位为秒，此为1.1.16新增接口
	MyTraderSpi* pUserSpi = new MyTraderSpi();
	pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
	pUserSpi->setUserAPI(pUserApi);
	pUserSpi->set_save_to_file(auto_save);
	if (out_count > 0)
	{
		pUserSpi->OutCount(out_count);
	}
	else
	{
		out_count = 1;
	}

	if (account_count > 0)
	{
		//多用户时，用session数组来管理用户session_id
		session_arrary = new uint64_t[account_count];

		for (int i = 0; i < account_count; i++)
		{
			//从配置文件中读取第i个用户登录信息
			std::string account_name = fileUtils->stdStringForKey("account[%d].user", i);
			std::string account_pw = fileUtils->stdStringForKey("account[%d].password", i);
			
			uint64_t temp_session_ = 0;
			std::cout << account_name << " login begin." << std::endl;
			temp_session_ = pUserApi->Login(trade_server_ip.c_str(), trade_server_port, account_name.c_str(), account_pw.c_str(), XTP_PROTOCOL_TCP); //登录交易服务器

			if (session_id_ == 0)
			{
				session_id_ = temp_session_;
			}

			if (temp_session_ > 0)
			{
				//登录成功后，建立session_id与用户之间的映射关系
				map_session.insert(std::make_pair(temp_session_, i));
			}
			else
			{
				//登录失败，获取登录失败原因
				XTPRI* error_info = pUserApi->GetApiLastError();
				std::cout << account_name << " login to server error, " << error_info->error_id << " : " << error_info->error_msg << std::endl;
			}

			session_arrary[i] = temp_session_;
		}
	}

	if (session_id_ > 0)
	{
		//有用户成功登录交易服务器
		std::cout << "Login to server success." << std::endl;

		is_connected_ = true;

		//每个用户均根据配置文件报单
		for (int i = 0; i < account_count; i++)
		{
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

			if (session_arrary[i] == 0)
			{
				//用户登录不成功时，跳过
				continue;
			}

			//报单
			int64_t xtp_id = pUserApi->InsertOrder(&(orderList[i]), session_arrary[i]);
			if (xtp_id == 0)
			{
				//报单不成功时，等待一会儿，跳过
#ifdef _WIN32
				Sleep(1000);
#else
				sleep(1);
#endif // WIN32
				continue;
			}

			std::string account_name = fileUtils->stdStringForKey("account[%d].user", i);
			std::cout << account_name <<" insert order success." << std::endl;
		}

		//主线程循环，防止进程退出
		while (true)
		{
#ifdef _WIN32
			Sleep(1000);
#else
			sleep(1);
#endif // WIN32

		}
	}

	
	delete fileUtils;
	fileUtils = NULL;

	if (orderList)
	{
		delete[] orderList;
		orderList = NULL;
	}

	if (session_arrary)
	{
		delete[] session_arrary;
		session_arrary = NULL;
	}

	return 0;
     */

}
