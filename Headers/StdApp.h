#pragma once

using namespace std;
namespace StdAppLib
{
	class StdApp
	{
	public:
		StdApp();
		static unique_ptr<StdApp> instance();		
		virtual void setup();
		virtual void onIdle()=0;
		void setClientType(string type);
		string getclientType();
		void exec();
		void publish(string msg);
		string fetch();
		string module();
		bool isReady();
		void shutdown(bool status);
		
		virtual ~StdApp();
		
	protected:
		string name;
	private:		
		bool ready;
		bool shuttingdown;
		string clientType;
	};
	
};// namespace StdApp
