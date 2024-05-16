#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_diagresp718.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebDiagresp718 &msg) {
        nlohmann::json obj;
        obj["aebdiagresp"] = (msg.aebdiagresp);
        return obj;
    }
    ApollocanbusAebDiagresp718 from_json_ApollocanbusAebDiagresp718 (nlohmann::json obj) {
        ApollocanbusAebDiagresp718 msg;
        if(obj.contains("aebdiagresp"))
        {
            msg.aebdiagresp = (obj["aebdiagresp"].is_string()?(bool)atoi(obj["aebdiagresp"].get<std::string>().c_str()):obj["aebdiagresp"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusAebDiagresp718 from_json<ApollocanbusAebDiagresp718>(nlohmann::json obj){
        return from_json_ApollocanbusAebDiagresp718(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebDiagresp718 &dt)
    {
        dt=from_json_ApollocanbusAebDiagresp718(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebDiagresp718 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebDiagresp718 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
