#include "pch.h"
#include <iostream>
#include "MsgBus.h"

using namespace std;

unique_ptr<StdApp> StdApp::instance()
{
	return unique_ptr<StdApp>(new MsgBus);
}//unique_ptr<StdApp> StdApp::instance()


void MsgBus::setup()
{
	//LOGDEBUG("Msg Bus - setup");
}//void MsgBus::setup()


void MsgBus::onIdle()
{
	//LOGDEBUG("Msg Bus - onIdle");
}//void MsgBus::onIdle()
