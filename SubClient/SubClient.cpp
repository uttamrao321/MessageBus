#include "pch.h"
#include <iostream>
#include <ctime>
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
	setClientType("sub");
	//LOGDEBUG("Sample Publisher - Setup");
}//void SubClient::setup()

void SubClient::onIdle()
{
	//Quick & Dirty Subscriber
	string msg = fetch();
	if (msg.length() > 0)
	{
		cout << "Your Message - " << msg.c_str() << std::endl;
	}
}//void SubClient::onIdle()

