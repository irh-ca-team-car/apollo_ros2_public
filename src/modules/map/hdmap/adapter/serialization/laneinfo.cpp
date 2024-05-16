#include "adapter/serialization/internal/hdmap/laneinfo.h"
#include "adapter/serialization/internal/common/polygon2d.h"

namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::hdmap::LaneInfo &msg)
    {
        nlohmann::json obj;
        obj["lane_"] = to_json(msg.lane_);
        //TODO are we sure only lane_ is important
        return obj;
    }
    apollo::hdmap::LaneInfo from_json_LaneInfo(nlohmann::json obj)
    {
        ApollohdmapLane l;
        l = from_json_ApollohdmapLane(obj["lane_"]);
        //TODO are we sure only lane_ is important
        auto msg=apollo::hdmap::LaneInfo(l);

        return msg;
    }
    template <>
    apollo::hdmap::LaneInfo from_json<apollo::hdmap::LaneInfo>(nlohmann::json obj)
    {
        return from_json_LaneInfo(obj);
    }

    std::ostream &
    operator<<(std::ostream &os, const apollo::hdmap::LaneInfo &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::hdmap::LaneInfo &dt)
    {
        return os << to_json(dt).dump();
    }
}
