#pragma once
#include "StdApp.h"

using namespace StdAppLib;

/** A simple publisher
 */
class PubClient :public StdApp
{
public:
	PubClient() { name = __func__; }
	void setup()  override;
	void onIdle() override;

    string dummyInfo();
};