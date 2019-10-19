#include "pch.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "MktSvrCache.h"

using namespace std;

unique_ptr<StdApp> StdApp::instance()
{
	return unique_ptr<StdApp>(new MktSvrCache);
}//unique_ptr<StdApp> StdApp::instance()


void MktSvrCache::setup()
{
	//set object type as cache svr
    setClientType("cache");
    
    //simulating initial database upload
    std::map<string, string> stockPrices
    {
        {"AAPL", "220.63"},
        {"FB", "187.87"},
        {"BAC", "30.45"},
        {"JPM", "120.12"}
    };

    for (std::map<string, string>::iterator it = stockPrices.begin();
        it != stockPrices.end(); it++)
    {
        string msg = it->first + ":" + it->second;
        log(LOGDEBUG, ("Updating from initial load: "+ msg));
        updateCache(msg);
    }
    
}//void MktSvrCache::setup()


void MktSvrCache::onIdle()
{   
    // Simulate your cache server as if it is listening to some 
    // realtime stock ticker svc
    string msg = dummyInfo();
    updateCache(msg); 
    log(LOGDEBUG, ("Updating from listener: " + msg));
    Sleep(10000); //simulate delay

    //shutdown(true);
    //or leave it running like a service
}//void MktSvrCache::onIdle()

string MktSvrCache::dummyInfo()
{
    //dummy test simulation
    string stockInfo;    
    for (int i = 0; i < 4; i++)
    {
        stockInfo += (static_cast<char>('A' + (rand() % 26)));
    }
    stockInfo += ":";
    stockInfo += std::to_string(((rand() % (160000 - 120000)) / 100.0));
    return stockInfo;
}//string MktSvrCache::dummyInfo()