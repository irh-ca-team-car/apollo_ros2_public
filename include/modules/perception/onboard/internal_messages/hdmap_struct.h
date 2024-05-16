#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/hdmap_struct.h"
#include "modules/perception/onboard/internal_messages/point_cloud.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::RoadBoundary;
    using apollo::perception::base::PointD;
    nlohmann::json to_json(const RoadBoundary &msg);
    RoadBoundary from_json_RoadBoundary(nlohmann::json obj);
    template <>
    RoadBoundary from_json<RoadBoundary>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, RoadBoundary &dt);
    std::ostream &operator<<(std::ostream &os, const RoadBoundary &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const RoadBoundary &dt);
}
namespace apollo_msgs::msg
{
    template <typename T>
    nlohmann::json to_json(const EigenVector<T> &msg);
    template <typename T>
    EigenVector<T> from_json_EigenVector(nlohmann::json obj);
    template <typename T>
    EigenVector<PointCloud<T>> from_json_EigenVectorPC(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, EigenVector<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const EigenVector<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const EigenVector<T> &dt);
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::HdmapStruct;
    using apollo::perception::base::PointD;
    using apollo::perception::base::RoadBoundary;
    using apollo::perception::base::PointCloud;
    nlohmann::json to_json(const HdmapStruct &msg);
    HdmapStruct from_json_HdmapStruct(nlohmann::json obj);
    template <>
    HdmapStruct from_json<HdmapStruct>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, HdmapStruct &dt);
    std::ostream &operator<<(std::ostream &os, const HdmapStruct &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const HdmapStruct &dt);
    
    
}
