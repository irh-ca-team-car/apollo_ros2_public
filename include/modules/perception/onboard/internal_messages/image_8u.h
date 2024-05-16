#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/image_8u.h"
#include "modules/perception/onboard/internal_messages/blob.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Image8U;
    nlohmann::json to_json(const Image8U &msg);
    Image8U from_json_Image8U(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Image8U &dt);
    std::ostream &operator<<(std::ostream &os, const Image8U &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Image8U &dt);
}
