#pragma once
#include "StdApp.h"

using namespace StdAppLib;

/** A simple subscriber to cache svr and message bus
 */
class SubClient :public StdApp
{
public:
	SubClient() { name = __func__; }
	void setup()  override;
	void onIdle() override;
};