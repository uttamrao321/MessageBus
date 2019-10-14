#include "pch.h"
#include <iostream>
#include<string>
#include <ctime>
#include "StdApp.h"
#include "PubClient.h"

using namespace StdAppLib;
using namespace std;


unique_ptr<StdApp> StdApp::instance()
{
	return unique_ptr<StdApp>(new PubClient);
}//unique_ptr<StdApp> StdApp::instance()


void PubClient::setup()
{
	
	setClientType("pub");
	//LOGDEBUG("Sample Publisher - Setup");
}//void PubClient::setup()

void PubClient::onIdle()
{
	//Quick & Dirty Publisher
	static unsigned long n = 0;
	char str[80];
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(str, 80, "[%Y-%m-%d %H:%M:%S]", &timeinfo);
	publish((std::to_string(++n) + ") message:" + string(str)));

}//void PubClient::onIdle()

