#include "adapter/serialization/apollo_msgs/apollov2x_mini_area_map.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xMiniAreaMap &msg) {
        nlohmann::json obj;
        obj["rscuid"] = to_json(msg.rscuid);
        obj["featureposition"] = to_json(msg.featureposition);
        obj["startposition"] = to_json(msg.startposition);
        obj["endposition"] = to_json(msg.endposition);
        return obj;
    }
    Apollov2xMiniAreaMap from_json_Apollov2xMiniAreaMap (nlohmann::json obj) {
        Apollov2xMiniAreaMap msg;
        if(obj.contains("rscuid"))
        {
            msg.rscuid = from_json_Bytes(obj["rscuid"]);
        }
        if(obj.contains("featureposition"))
        {
            msg.featureposition = from_json_Apollov2xPoint(obj["featureposition"]);
        }
        if(obj.contains("startposition"))
        {
            msg.startposition = from_json_Apollov2xPoint(obj["startposition"]);
        }
        if(obj.contains("endposition"))
        {
            msg.endposition = from_json_Apollov2xPoint(obj["endposition"]);
        }
        return msg;
    }
    template <>
    Apollov2xMiniAreaMap from_json<Apollov2xMiniAreaMap>(nlohmann::json obj){
        return from_json_Apollov2xMiniAreaMap(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xMiniAreaMap &dt)
    {
        dt=from_json_Apollov2xMiniAreaMap(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xMiniAreaMap & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xMiniAreaMap & dt)
    {
        os << to_json(dt);
        return os;
    }
}
