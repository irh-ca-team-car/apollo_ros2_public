#pragma once

#include "rclcpp/rclcpp.hpp"
#include <string>

#include "cyber/componentbase.h"

namespace apollo
{
    namespace cyber
    {

        class NIComponent : public ComponentBase
        {
        public:
            NIComponent(std::string name) : ComponentBase(name) {}

        protected:
            bool Init() override { return true; }
        };
        class Component : public ComponentBase
        {
        public:
            Component(std::string name) : ComponentBase(name) {}

        protected:
        };

        class TimerComponent : public ComponentBase
        {
        public:
            TimerComponent(std::string name) : ComponentBase(name)
            {
            }

        protected:
            virtual bool Proc() = 0;
            virtual long IntervalMilliseconds() = 0;
            void Initialize() override
            {
                ComponentBase::Initialize();
                timer_ = this->create_wall_timer(std::chrono::milliseconds(IntervalMilliseconds()), std::bind(&TimerComponent::ProcessStep, this));
            }

        private:
            rclcpp::TimerBase::SharedPtr timer_;
            void ProcessStep()
            {
                if (!Proc())
                {
                    AFATAL << "PROC FAILURE";
                }
            }
        };

    }
}