#include "pch.h"
#include <iostream>
#include <vector>
#include "MsgBus.h"

using namespace std;

unique_ptr<StdApp> StdApp::instance()
{
	return unique_ptr<StdApp>(new MsgBus);
}//unique_ptr<StdApp> StdApp::instance()


void MsgBus::setup()
{
    //set object type as msg bus
    setClientType("hub");

	log(LOGINFO, "Msg Bus - setup");
    
}//void MsgBus::setup()


void MsgBus::onIdle()
{
   //nothing required
}//void MsgBus::onIdle()
