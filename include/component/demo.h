#include "cyber/cyber.h"
#include "cyber/adapter.h"
#include "cyber/common/file.h"
#include "apollo_msgs/msg/apollocanbus_wey.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads338e.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wey.hpp"
#include <filesystem>
#include <iostream>
#include "cyber/common/log_advanced.h"

class D
{
public:
    D(int d)
    {
        v = d * d;
    }
    int v;

    nlohmann::json to_json() const
    {
        return v;
    }
};

class DemoComponent : public apollo::cyber::Component
{
public:
    DemoComponent() : Component("DemoComponent") {}
    bool Init();
};