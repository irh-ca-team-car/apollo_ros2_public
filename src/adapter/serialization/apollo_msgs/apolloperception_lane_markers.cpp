#include "adapter/serialization/apollo_msgs/apolloperception_lane_markers.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionLaneMarkers &msg) {
        nlohmann::json obj;
        obj["leftlanemarker"] = to_json(msg.leftlanemarker);
        obj["rightlanemarker"] = to_json(msg.rightlanemarker);
        nlohmann::json arr_nextleftlanemarker;
        for (auto it = msg.nextleftlanemarker.begin(); it != msg.nextleftlanemarker.end(); ++it) {
            arr_nextleftlanemarker.push_back(to_json(*it));
        }
        obj["nextleftlanemarker"] = arr_nextleftlanemarker;
        nlohmann::json arr_nextrightlanemarker;
        for (auto it = msg.nextrightlanemarker.begin(); it != msg.nextrightlanemarker.end(); ++it) {
            arr_nextrightlanemarker.push_back(to_json(*it));
        }
        obj["nextrightlanemarker"] = arr_nextrightlanemarker;
        return obj;
    }
    ApolloperceptionLaneMarkers from_json_ApolloperceptionLaneMarkers (nlohmann::json obj) {
        ApolloperceptionLaneMarkers msg;
        if(obj.contains("leftlanemarker"))
        {
            msg.leftlanemarker = from_json_ApolloperceptionLaneMarker(obj["leftlanemarker"]);
        }
        if(obj.contains("rightlanemarker"))
        {
            msg.rightlanemarker = from_json_ApolloperceptionLaneMarker(obj["rightlanemarker"]);
        }
        if(obj.contains("nextleftlanemarker"))
        {
            if(obj["nextleftlanemarker"].is_array())
            {
                for (auto& element : obj["nextleftlanemarker"])
                {
                    msg.nextleftlanemarker.push_back(from_json_ApolloperceptionLaneMarker(element));
                }
            }
            else
            {
                msg.nextleftlanemarker.push_back(from_json_ApolloperceptionLaneMarker(obj["nextleftlanemarker"]));
            }
        }
        if(obj.contains("nextrightlanemarker"))
        {
            if(obj["nextrightlanemarker"].is_array())
            {
                for (auto& element : obj["nextrightlanemarker"])
                {
                    msg.nextrightlanemarker.push_back(from_json_ApolloperceptionLaneMarker(element));
                }
            }
            else
            {
                msg.nextrightlanemarker.push_back(from_json_ApolloperceptionLaneMarker(obj["nextrightlanemarker"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionLaneMarkers from_json<ApolloperceptionLaneMarkers>(nlohmann::json obj){
        return from_json_ApolloperceptionLaneMarkers(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionLaneMarkers &dt)
    {
        dt=from_json_ApolloperceptionLaneMarkers(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionLaneMarkers & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionLaneMarkers & dt)
    {
        os << to_json(dt);
        return os;
    }
}
