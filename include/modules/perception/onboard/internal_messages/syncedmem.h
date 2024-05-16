#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/syncedmem.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::SyncedMemory;
    nlohmann::json to_json(SyncedMemory &msg);
    SyncedMemory from_json_SyncedMemory(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, SyncedMemory &dt);
    std::ostream &operator<<(std::ostream &os, const SyncedMemory &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SyncedMemory &dt);
}
