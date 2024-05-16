#pragma once
#include "apollo_msgs/msg/data_extraction_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/io_config.hpp"
#include "adapter/serialization/apollo_msgs/channels.hpp"
#include "adapter/serialization/apollo_msgs/records.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const DataExtractionConfig &msg) ;
    DataExtractionConfig from_json_DataExtractionConfig (nlohmann::json obj) ;
    template <>
    DataExtractionConfig from_json<DataExtractionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, DataExtractionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const DataExtractionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const DataExtractionConfig & dt);
}
