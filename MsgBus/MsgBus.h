#pragma once
#include "StdApp.h"

using namespace StdAppLib;

class MsgBus :public StdApp
{
public:
	MsgBus() { name = __func__; }
	void setup()  override;
	void onIdle()  override;
};