#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/object_supplement.h"
#include "modules/perception/onboard/internal_messages/point_cloud.h"
#include "modules/perception/onboard/internal_messages/box.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::LidarObjectSupplement;
    using apollo::perception::base::PointD;
    using apollo::perception::base::PointF;
    nlohmann::json to_json(const LidarObjectSupplement &msg);
    LidarObjectSupplement from_json_LidarObjectSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, LidarObjectSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const LidarObjectSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarObjectSupplement &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::RadarObjectSupplement;
    nlohmann::json to_json(const RadarObjectSupplement &msg);
    RadarObjectSupplement from_json_RadarObjectSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, RadarObjectSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const RadarObjectSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const RadarObjectSupplement &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::CameraObjectSupplement;
    nlohmann::json to_json(const CameraObjectSupplement &msg);
    CameraObjectSupplement from_json_CameraObjectSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, CameraObjectSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const CameraObjectSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CameraObjectSupplement &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::SensorObjectMeasurement;
    nlohmann::json to_json(const SensorObjectMeasurement &msg);
    SensorObjectMeasurement from_json_SensorObjectMeasurement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, SensorObjectMeasurement &dt);
    std::ostream &operator<<(std::ostream &os, const SensorObjectMeasurement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SensorObjectMeasurement &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::FusionObjectSupplement;
    nlohmann::json to_json(const FusionObjectSupplement &msg);
    FusionObjectSupplement from_json_FusionObjectSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, FusionObjectSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const FusionObjectSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const FusionObjectSupplement &dt);
}
