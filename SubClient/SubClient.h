#pragma once
#include "StdApp.h"

using namespace StdAppLib;

class SubClient :public StdApp
{
public:
	SubClient() { name = __func__; }
	void setup()  override;
	void onIdle() override;

};