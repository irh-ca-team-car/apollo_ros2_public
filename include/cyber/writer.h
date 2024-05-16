#pragma once
#include <type_traits>

#include "cyber/common/log.h"
#include "cyber/common/macros.h"
#include "cyber/common/log_advanced.h"
#include "std_msgs/msg/string.hpp"
namespace apollo
{
    namespace cyber
    {
        template <class M0>
        class Writer
        {
        public:
            Writer(typename rclcpp::Publisher<M0>::SharedPtr publisher,std::string topic)
            {
                this->writer_ = publisher;
                this->topic = topic;
            }
            void Write(const std::shared_ptr<M0> &msg)
            {
                AINFO_EVERY(60000) << "Publishing on topic "<< this->topic;
                this->writer_->publish(*msg);
            }
            void Write(const M0 &msg)
            {
                AINFO_EVERY(60000) << "Publishing on topic "<< this->topic;
                this->writer_->publish(msg);
            }

        protected:
            std::string topic;
            typename rclcpp::Publisher<M0>::SharedPtr writer_ = nullptr;
        };
        template <class M0>
        class WriterJson
        {
        public:
            WriterJson(typename rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher,std::string topic)
            {
                this->writer_ = publisher;
                this->topic = topic;
            }
            void Write(const nlohmann::json &msg)
            {
                std_msgs::msg::String msg_str;
                msg_str.data = msg.dump();
                AINFO_EVERY(60000) << "Publishing on topic "<< this->topic;
                this->writer_->publish(msg_str);
            }

        protected:
            typename rclcpp::Publisher<std_msgs::msg::String>::SharedPtr writer_ = nullptr;
            std::string topic;
        };
    }
}