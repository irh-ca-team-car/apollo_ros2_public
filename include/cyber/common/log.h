#pragma once
#ifndef __NVCC__
#include "rclcpp/rclcpp.hpp"
#endif
#include <type_traits>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#ifndef __NVCC__
#include "nlohmann/json.hpp"
#endif
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)
#define STACK __FILENAME__ << ":" << __LINE__ << ";" << __FUNCTION__
#ifndef UNUSED
#define UNUSED(param) (void)param
#endif

extern std::string __module_name__;
#ifndef __NVCC__
namespace apollo_msgs::msg
{
    template <typename T>
    T from_json(nlohmann::json obj);
}
#endif
class close_after_if_not_null
{
    bool _exit;
    int *count = nullptr;

public:
    bool _print;
    close_after_if_not_null(bool exit, bool print)
    {
        this->_exit = exit;
        this->_print = print;
        count = new int[1];
        *count = 1;
    }
    close_after_if_not_null(bool exit) : close_after_if_not_null(exit, exit)
    {
    }
    // Copy constructor
    close_after_if_not_null(close_after_if_not_null &sp)
    {
        this->_exit = sp._exit;
        this->_print = sp._print;

        (*count)++;
    }
    ~close_after_if_not_null()
    {
        (*count)--;
        if (*count == 0)
        {
            delete count;
            if (this->_print)
                std::cerr << std::endl;
            if (this->_exit)
            {
                std::flush(std::cout);
#ifndef __NVCC__
                rclcpp::shutdown();
#endif
                exit(-1);
            }
        }
    }
    template <typename T>
    close_after_if_not_null &operator<<(const T &v)
    {
        if (this->_print)
            std::cerr << v;
        return *this;
    }
};

#define AERROR (close_after_if_not_null(false, true) << "[ERROR] [" << STACK << "] ")
#define AINFO (close_after_if_not_null(false, true) << "[INFO] [" << STACK << "] ")
#define ADEBUG (close_after_if_not_null(false, false) << "[DEBUG] [" << STACK << "] ")
#define AWARN (close_after_if_not_null(false, true) << "[WARN] [" << STACK << "] ")
#define AFATAL (close_after_if_not_null(true, true) << "[FATAL] [" << STACK << "] ")

#define AERROR_IF(cond) (close_after_if_not_null(false, cond) << "[ERROR] [" << STACK << "] ")
#define AINFO_IF(cond) (close_after_if_not_null(false, cond) << "[INFO] [" << STACK << "] ")
#define ADEBUG_IF(cond) (close_after_if_not_null(false, cond) << "[DEBUG] [" << STACK << "] ")
#define AWARN_IF(cond) (close_after_if_not_null(false, cond) << "[WARN] [" << STACK << "] ")
#define AFATAL_IF(cond) (close_after_if_not_null(true, cond) << "[FATAL] [" << STACK << "] ")

#ifndef MODULE_NAME
#define MODULE_NAME (__module_name__)
#endif

#define CRLF ("\r\n")

#define CYBER_REGISTER_COMPONENT(A) std::string __module_name__ = #A;

#ifdef ACHECK
#undef ACHECK
#endif
#define ACHECK(cond) close_after_if_not_null(!(cond)) << "[FATAL] [" << STACK << "] ( FAILED ASSERT " << #cond << " ) "

#ifdef CHECK_GT
#undef CHECK_GT
#endif
#define CHECK_GT(A, B) ACHECK((A) > (B))

#ifdef CHECK_LT
#undef CHECK_LT
#endif
#define CHECK_LT(A, B) ACHECK((A) < (B))
#ifdef CHECK_GE
#undef CHECK_GE
#endif
#define CHECK_GE(A, B) ACHECK((A) >= (B))
#ifdef CHECK_LE
#undef CHECK_LE
#endif
#define CHECK_LE(A, B) ACHECK((A) <= (B))
#ifdef CHECK_EQ
#undef CHECK_EQ
#endif
#define CHECK_EQ(A, B) ACHECK((A) == (B))
#ifdef CHECK_NE
#undef CHECK_NE
#endif
#define CHECK_NE(A, B) ACHECK((A) != (B))
#ifdef CHECK_NOTNULL
#undef CHECK_NOTNULL
#endif
#define CHECK_NOTNULL(A) ACHECK((A) != (nullptr))

#if !defined(RETURN_IF_NULL)
#define RETURN_IF_NULL(ptr)              \
    if (ptr == nullptr)                  \
    {                                    \
        AWARN << #ptr << " is nullptr."; \
        return;                          \
    }
#endif

#if !defined(RETURN_VAL_IF_NULL)
#define RETURN_VAL_IF_NULL(ptr, val)     \
    if (ptr == nullptr)                  \
    {                                    \
        AWARN << #ptr << " is nullptr."; \
        return val;                      \
    }
#endif

#if !defined(RETURN_IF)
#define RETURN_IF(condition)               \
    if (condition)                         \
    {                                      \
        AWARN << #condition << " is met."; \
        return;                            \
    }
#endif
#if !defined(RETURN_VAL_IF)
#define RETURN_VAL_IF(condition, val)      \
    if (condition)                         \
    {                                      \
        AWARN << #condition << " is met."; \
        return val;                        \
    }
#endif

#if !defined(_RETURN_VAL_IF_NULL2__)
#define _RETURN_VAL_IF_NULL2__
#define RETURN_VAL_IF_NULL2(ptr, val) \
    if (ptr == nullptr)               \
    {                                 \
        return (val);                 \
    }
#endif

#if !defined(_RETURN_VAL_IF2__)
#define _RETURN_VAL_IF2__
#define RETURN_VAL_IF2(condition, val) \
    if (condition)                     \
    {                                  \
        return (val);                  \
    }
#endif

#if !defined(_RETURN_IF2__)
#define _RETURN_IF2__
#define RETURN_IF2(condition) \
    if (condition)            \
    {                         \
        return;               \
    }
#endif
