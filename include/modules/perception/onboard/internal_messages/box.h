#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/box.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::BBox2D;
    template <typename T>
    nlohmann::json to_json(const BBox2D<T> &msg);
    template <>
    nlohmann::json to_json(const BBox2D<float> &msg);
    template <typename T>
    BBox2D<T> from_json_BBox2D(nlohmann::json obj);
    template <>
    BBox2D<double> from_json<BBox2D<double>>(nlohmann::json obj);
    template <>
    BBox2D<float> from_json<BBox2D<float>>(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, BBox2D<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const BBox2D<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const BBox2D<T> &dt);
    
}
