#pragma once
#include "log.h"
#include <sstream>
#include <string>
#include <future>
#include <chrono>
#include <mutex>
class log_every
{
public:
    static close_after_if_not_null get(std::string prefix, bool exit, long d)
    {
        static std::set<std::string> prefixes;
        static std::mutex mtx_print;
        mtx_print.lock();
        bool print = prefixes.find(prefix) == prefixes.end();
        close_after_if_not_null ret_(exit, print);
        prefixes.emplace(prefix);

        if (print)
        {
            std::thread t([d, prefix]()
                          {
                            std::this_thread::sleep_for(std::chrono::milliseconds(d));
                            mtx_print.lock();
                            prefixes.erase(prefix); 
                            mtx_print.unlock(); });
            t.detach();
        }
        mtx_print.unlock();
        return ret_;
    }
};
#define AERROR_EVERY(DELAY) (log_every::get(std::string("[ERROR] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define AINFO_EVERY(DELAY) (log_every::get(std::string("[INFO] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define ADEBUG_EVERY(DELAY) (log_every::get(std::string("[DEBUG] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define AWARN_EVERY(DELAY) (log_every::get(std::string("[WARN] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define AFATAL_EVERY(DELAY) (log_every::get(std::string("[FATAL] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))

#define AERROR_ONCE AERROR_EVERY(60 * 60 * 1000)
#define AINFO_ONCE AINFO_EVERY(60 * 60 * 1000)
#define ADEBUG_ONCE ADEBUG_EVERY(60 * 60 * 1000)
#define AWARN_ONCE AWARN_EVERY(60 * 60 * 1000)
#define AFATAL_ONCE AFATAL_EVERY(60 * 60 * 1000)