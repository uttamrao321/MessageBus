#pragma once
#include "StdApp.h"

using namespace StdAppLib;

/** A simple cache svr
 */
class MktSvrCache :public StdApp
{
public:
	MktSvrCache() { name = __func__;}
	void setup()  override;
	void onIdle()  override;	

    string dummyInfo();
};