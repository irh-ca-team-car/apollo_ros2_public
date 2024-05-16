#include "adapter/serialization/apollo_msgs/apollocanbus_global_cmd69.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGlobalCmd69 &msg) {
        nlohmann::json obj;
        obj["pacmodenable"] = (msg.pacmodenable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["ignoreoverride"] = (msg.ignoreoverride);
        return obj;
    }
    ApollocanbusGlobalCmd69 from_json_ApollocanbusGlobalCmd69 (nlohmann::json obj) {
        ApollocanbusGlobalCmd69 msg;
        if(obj.contains("pacmodenable"))
        {
            msg.pacmodenable = (obj["pacmodenable"].is_string()?atoi(obj["pacmodenable"].get<std::string>().c_str()):obj["pacmodenable"].get<int>());
        }
        if(obj.contains("clearoverride"))
        {
            msg.clearoverride = (obj["clearoverride"].is_string()?atoi(obj["clearoverride"].get<std::string>().c_str()):obj["clearoverride"].get<int>());
        }
        if(obj.contains("ignoreoverride"))
        {
            msg.ignoreoverride = (obj["ignoreoverride"].is_string()?atoi(obj["ignoreoverride"].get<std::string>().c_str()):obj["ignoreoverride"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGlobalCmd69 from_json<ApollocanbusGlobalCmd69>(nlohmann::json obj){
        return from_json_ApollocanbusGlobalCmd69(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGlobalCmd69 &dt)
    {
        dt=from_json_ApollocanbusGlobalCmd69(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGlobalCmd69 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGlobalCmd69 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
