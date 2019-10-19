#include "pch.h"
#include <Windows.h>
#include <iostream>
#include<string>
#include <ctime>
#include<vector>
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
    //set object type as publisher	
	setClientType("pub");

	log(LOGINFO, "Sample Publisher - Setup");
}//void PubClient::setup()

void PubClient::onIdle()
{
    string msg = dummyInfo();
    publish(msg);

    Sleep(1000);//simulate delay
    //shutdown(true);
    //or leave it running like a service
}//void PubClient::onIdle()

string PubClient::dummyInfo()
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
}//string PubClient::dummyInfo()