#pragma once
#include <type_traits>

#include "cyber/common/log.h"
#include "cyber/common/log_advanced.h"
#include "cyber/common/macros.h"

#include "std_msgs/msg/string.hpp"
namespace apollo
{
    namespace cyber
    {

        class ReaderConfig
        {
        public:
            std::string channel_name = "topic";
            int pending_queue_size = 1;
        };
        template <class M0>
        class Reader
        {
        public:
            Reader(rclcpp::Node *node, std::string name, int queue = 1, const typename std::function<void(const typename M0::SharedPtr)> reader_func = nullptr)
            {
                topic = name;
                callback_function = reader_func;
                subscription_ = node->create_subscription<M0>(name, queue, std::bind(&Reader::read, this, std::placeholders::_1));
            }
            void Observe() {}
            typename M0::SharedPtr GetLatestObserved()
            {
                mtx.lock();

                typename M0::SharedPtr ret = last_observed;

                mtx.unlock();
                return ret;
            }

        protected:
            void read(const typename M0::SharedPtr msg)
            {
                mtx.lock();
                AINFO_EVERY(60000) << "Received message on topic " << topic;
                last_observed = msg;
                if (callback_function != nullptr)
                {

                    callback_function(msg);
                }
                mtx.unlock();
            }
            std::mutex mtx;
            std::string topic;
            typename M0::SharedPtr last_observed = nullptr;
            typename rclcpp::Subscription<M0>::SharedPtr subscription_ = nullptr;
            typename std::function<void(const typename M0::SharedPtr)> callback_function;
        };
        template <class M0>
        class ReaderJson
        {
        public:
            ReaderJson(rclcpp::Node *node, std::string name, int queue = 1, const typename std::function<void(const typename std::shared_ptr<M0>)> reader_func = nullptr)
            {
                topic = name;
                callback_function = reader_func;
                subscription_ = node->create_subscription<std_msgs::msg::String>(name, queue, std::bind(&ReaderJson::read, this, std::placeholders::_1));
            }
            void Observe() {}

        protected:
            void read(const typename std_msgs::msg::String::SharedPtr msg)
            {
                mtx.lock();
                AINFO_EVERY(60000) << "Received message on JSON topic " << topic;
                std::flush(std::cout);
                auto last_observed = std::make_shared<M0>(apollo_msgs::msg::from_json<M0>(nlohmann::json::parse(msg->data)));

                if (callback_function != nullptr)
                {
                    callback_function(last_observed);
                }
                mtx.unlock();
            }
            std::mutex mtx;
            std::string topic;
            typename rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_ = nullptr;
            typename std::function<void(const typename std::shared_ptr<M0>)> callback_function;
        };
    }
}