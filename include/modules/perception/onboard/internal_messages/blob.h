#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/blob.h"
#include "modules/perception/onboard/internal_messages/syncedmem.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Blob;
    template <typename T>
    nlohmann::json to_json(const Blob<T> &msg);
    template <>
    nlohmann::json to_json(const Blob<uint8_t> &msg);
    template <typename T>
    Blob<T> from_json_Blob(nlohmann::json obj);
    template <>
    Blob<uint8_t> from_json<Blob<uint8_t>>(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Blob<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Blob<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Blob<T> &dt);
}
