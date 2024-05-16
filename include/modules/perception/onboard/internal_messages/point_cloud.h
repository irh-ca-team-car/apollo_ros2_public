#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/point_cloud.h"
#include "modules/perception/onboard/internal_messages/point.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::PointCloud;
    template<typename T>
    nlohmann::json to_json(const PointCloud<T> &msg);
    template<>
    nlohmann::json to_json(const PointCloud<Point<double>> &msg);
    template <typename T>
    PointCloud<T> from_json_PointCloud(nlohmann::json obj);
    template <>
    PointCloud<Point<double>> from_json<PointCloud<Point<double>>>(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, PointCloud<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const PointCloud<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const PointCloud<T> &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::AttributePointCloud;
    template<typename T>
    nlohmann::json to_json(const AttributePointCloud<T> &msg);
    template<>
    nlohmann::json to_json(const AttributePointCloud<Point<float>> &msg);
    template<>
    nlohmann::json to_json(const AttributePointCloud<Point<double>> &msg);
    template <typename T>
    AttributePointCloud<T> from_json_AttributePointCloud(nlohmann::json obj);
    template <>
    AttributePointCloud<Point<float>> from_json<AttributePointCloud<Point<float>>>(nlohmann::json obj);
    template <>
    AttributePointCloud<Point<double>> from_json<AttributePointCloud<Point<double>>>(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, AttributePointCloud<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const AttributePointCloud<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const AttributePointCloud<T> &dt);
}
