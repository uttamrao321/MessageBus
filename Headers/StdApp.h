#pragma once
/**
 *********************************************************************************
 * A lightweight and extensible message bus for rapid application development    *
 * in distributed and multi-user environment.                                    *
 * Implementation types:                                                         *
 * - hub    : A central message bus to synchronize messages on all clients       *
 * - pub    : The lightweight clients which will only publish messages           *
 * - sub    : The lightweight clients which will only subscribe to messages      *
 * - pubsub : The clients which will subscribe as well as publish messages       *
 * - cache  : A central cache server between clients and message bus             *
 *                                                                               *
 *  Run as:                                                                      *
 *  <app>.exe [-cfg <cfgname>]                                                   *
 *                                                                               *
 * This work is licensed under the terms of the MIT license.                     * 
 *     < https://github.com/uttamrao321/MessageBus/blob/master/LICENSE>.         * 
 *                                                                               *
 *********************************************************************************
 */

using namespace std;
namespace StdAppLib
{
    /** Implement your class using StdApp
     */
    class StdApp
    {
        
    public:

        /** Log messsage type
         */
        typedef enum { NONE = -1, LOGTRACE = 0, LOGDEBUG, LOGINFO, LOGERROR, LOGFATAL } LOGLEVEL;

        /** Default constructor
         */
        StdApp();

        /** Static instance of your implementation 
         */                
        static unique_ptr<StdApp> instance();

        /** Initialization of your object
         */
        virtual void setup();

        /** Implementation of your object
         */
        virtual void onIdle()=0;
        
        /** Returns module name
         */
        string module();
        
        /** Set client type 
         *  "hub", "pub", "sub", "pubsub", "cache"
         */
        void setClientType(string type);
        
        /** Get client type            
         */
        string getclientType();

        /** Send shutdown signal to terminate the service
         */
        void shutdown(bool status);

        /** Send ready signal to start processing
         */
        void ready(bool status);

        /** Destructor
         */
        virtual ~StdApp();

    protected:

        /** Use it inside pub, pubsub tp publish message to the bus.
         */
        void publish(string msg);

        /** Use it inside sub, pubsub to fetch message from the bus.
         */
        string fetch();
        
        /** Use it inside cache to update local cache and publish to bus.
         */
        void updateCache(string data);

        /** get data from cache server.
         */
        vector<string> getCache();
        
        /** Log message
         */
        void log(LOGLEVEL loglevel, string data);

        /** Set passphrase for communication betweeen your client and server
         */
        void setPassphrase(string key);
    
        /** Set max watermarks limit
         *  Default = 100000
         */
        void setWatermarks(unsigned int size);

        /** Set Message length
         *  Default 1024
         */
        void setMsgLen(unsigned int size);

    protected:
        string name;    

    private:
        void exec();
        
    private:
        bool isReady;
        bool isShuttingdown;
        string clientType;
    };
    
};// namespace StdApp
