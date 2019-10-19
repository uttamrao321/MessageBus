#include "pch.h"
#include<Windows.h>
#include <iostream>
#include <ctime>
#include <vector>
#include "StdApp.h"
#include "SubClient.h"

using namespace StdAppLib;
using namespace std;


unique_ptr<StdApp> StdApp::instance()
{
	return unique_ptr<StdApp>(new SubClient);
}//unique_ptr<StdApp> StdApp::instance()


void SubClient::setup()
{
    //set object type as subscriber
	setClientType("sub"); 

    //Initial load from cache
    log(LOGDEBUG, "Initial load from cache");
    vector<string> cache = getCache();
    for (vector<string>::iterator it = cache.begin(); it != cache.end(); it++)
    {
        string msg = *it;
        log(LOGDEBUG, msg);
    }

}//void SubClient::setup()

void SubClient::onIdle()
{
    // continues subscription to messages
	string msg = fetch();
	if (msg.length() > 0)
	{
        log(LOGDEBUG, msg);
	}
  
    //shutdown(true);
    //or leave it running like a service
}//void SubClient::onIdle()

