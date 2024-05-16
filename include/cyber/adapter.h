#pragma once
#include "rclcpp/rclcpp.hpp"
#include <functional>

#define HLINE                                    \
    {                                            \
        struct winsize size;                     \
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size); \
        for (auto i = 0; i < size.ws_col; i++)   \
            printf("-");                         \
        fflush(stdout);                          \
    }

namespace apollo
{
    namespace cyber
    {
        namespace adapter
        {
            typedef void *NullType;
            template <typename M0 = NullType, typename M1 = NullType,
                      typename M2 = NullType, typename M3 = NullType>
            class Sync
            {
            public:
                void callback0(typename M0::SharedPtr p)
                {
                    flag0 = true;
                    state0 = p;
                    check();
                }
                void callback1(typename M1::SharedPtr p)
                {
                    flag1 = true;
                    state1 = p;
                    check();
                }
                void callback2(typename M2::SharedPtr p)
                {
                    flag2 = true;
                    state2 = p;
                    check();
                }
                void callback3(typename M3::SharedPtr p)
                {
                    flag3 = true;
                    state3 = p;
                    check();
                }
                std::function<void(const typename M0::SharedPtr, const typename M1::SharedPtr, const typename M2::SharedPtr, const typename M3::SharedPtr)> proc;

            private:
                void check()
                {
                    if (flag0 && flag1 && flag2 && flag3)
                    {
                        proc(state0, state1, state2, state3);
                        flag0 = flag1 = flag2 = flag2 = false;
                    }
                }
                typename M0::SharedPtr state0;
                typename M1::SharedPtr state1;
                typename M2::SharedPtr state2;
                typename M3::SharedPtr state3;
                bool flag0 = false, flag1 = false, flag2 = false, flag3 = false;
            };
            template <typename M0, typename M1, typename M2>
            class Sync<M0, M1, M2, NullType>
            {
            public:
                void callback0(typename std::shared_ptr<M0> p)
                {
                    flag0 = true;
                    state0 = p;
                    check();
                }
                void callback1(typename std::shared_ptr < M1> p)
                {
                    flag1 = true;
                    state1 = p;
                    check();
                }
                void callback2(typename std::shared_ptr < M2> p)
                {
                    flag2 = true;
                    state2 = p;
                    check();
                }
                std::function<void(const typename std::shared_ptr<M0>, const typename std::shared_ptr<M1>, const typename std::shared_ptr < M2>)> proc;

            private:
                void check()
                {
                    if (flag0 && flag1 && flag2)
                    {
                        proc(state0, state1, state2);
                        flag0 = flag1 = flag2 = false;
                    }
                }
                bool flag0 = false, flag1 = false, flag2 = false;
                typename std::shared_ptr < M0> state0;
                typename std::shared_ptr < M1> state1;
                typename std::shared_ptr < M2> state2;
            };
            template <typename M0, typename M1>
            class Sync<M0, M1, NullType, NullType>
            {
            public:
                void callback0(typename M0::SharedPtr p)
                {
                    flag0 = true;
                    state0 = p;
                    check();
                }
                void callback1(typename M1::SharedPtr p)
                {
                    flag1 = true;
                    state1 = p;
                    check();
                }
                std::function<void(const typename M0::SharedPtr, const typename M1::SharedPtr)> proc;

            private:
                void check()
                {
                    if (flag0 && flag1)
                    {
                        proc(state0, state1);
                        flag0 = flag1 = false;
                    }
                }
                bool flag0 = false, flag1 = false;
                typename M0::SharedPtr state0;
                typename M1::SharedPtr state1;
            };
        } // namespace adapter
    }     // namespace cyber
} // namespace apollo

#include "rclcpp/serialization.hpp"

template <typename T>
rclcpp::SerializedMessage serialize_msg(T &msg)
{
    static rclcpp::Serialization<T> serializer;

    rclcpp::SerializedMessage serialized_msg_;

    serializer.serialize_message(&msg, &serialized_msg_);

    return serialized_msg_;
}

template <typename T>
T deserialize_msg(rclcpp::SerializedMessage &msg)
{
    static rclcpp::Serialization<T> serializer;
    T val;
    serializer.deserialize_message(&msg, &val);
    return val;
}
