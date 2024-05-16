#pragma once
#include "apollo_msgs/msg/apollov2xobu_obu_rsi.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuObuRsi &msg) ;
    Apollov2xobuObuRsi from_json_Apollov2xobuObuRsi (nlohmann::json obj) ;
    template <>
    Apollov2xobuObuRsi from_json<Apollov2xobuObuRsi>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuObuRsi &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuObuRsi & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuObuRsi & dt);
}
