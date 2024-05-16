#include "adapter/serialization/apollo_msgs/apollov2x_policy_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPolicyData &msg) {
        nlohmann::json obj;
        obj["map"] = to_json(msg.map);
        obj["spat"] = to_json(msg.spat);
        return obj;
    }
    Apollov2xPolicyData from_json_Apollov2xPolicyData (nlohmann::json obj) {
        Apollov2xPolicyData msg;
        if(obj.contains("map"))
        {
            msg.map = from_json_Apollov2xMap(obj["map"]);
        }
        if(obj.contains("spat"))
        {
            msg.spat = from_json_Apollov2xSpat(obj["spat"]);
        }
        return msg;
    }
    template <>
    Apollov2xPolicyData from_json<Apollov2xPolicyData>(nlohmann::json obj){
        return from_json_Apollov2xPolicyData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPolicyData &dt)
    {
        dt=from_json_Apollov2xPolicyData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xPolicyData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPolicyData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
