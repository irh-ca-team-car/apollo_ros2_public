#ifndef CYBER_COMMON_MACROS_H_
#define CYBER_COMMON_MACROS_H_

#include <iostream>
#include <memory>
#include <mutex>
#include <type_traits>
#include <utility>

#include "cyber/base/macros.h"

DEFINE_TYPE_TRAIT(HasShutdown, Shutdown)

template <typename T>
typename std::enable_if<HasShutdown<T>::value>::type CallShutdown(T *instance)
{
    instance->Shutdown();
}

template <typename T>
typename std::enable_if<!HasShutdown<T>::value>::type CallShutdown(
    T *instance)
{
    (void)instance;
}

// There must be many copy-paste versions of these macros which are same
// things, undefine them to avoid conflict.
#undef UNUSED
#undef DISALLOW_COPY_AND_ASSIGN
#ifndef UNUSED
#define UNUSED(param) (void)param
#endif
#define DISALLOW_COPY_AND_ASSIGN(classname) \
    classname(const classname &) = delete;  \
    classname &operator=(const classname &) = delete;

#define DECLARE_SINGLETON(classname)                                            \
public:                                                                         \
    static classname *Instance(bool create_if_needed = true)                    \
    {                                                                           \
        static classname *instance = nullptr;                                   \
        if (!instance && create_if_needed)                                      \
        {                                                                       \
            static std::once_flag flag;                                         \
            std::call_once(flag,                                                \
                           [&] { instance = new (std::nothrow) classname(); }); \
            instance->Init();                                                   \
        }                                                                       \
        return instance;                                                        \
    }                                                                           \
                                                                                \
    static void CleanUp()                                                       \
    {                                                                           \
        auto instance = Instance(false);                                        \
        if (instance != nullptr)                                                \
        {                                                                       \
            CallShutdown(instance);                                             \
        }                                                                       \
    }                                                                           \
                                                                                \
private:                                                                        \
    classname();                                                               \
    DISALLOW_COPY_AND_ASSIGN(classname)
#endif