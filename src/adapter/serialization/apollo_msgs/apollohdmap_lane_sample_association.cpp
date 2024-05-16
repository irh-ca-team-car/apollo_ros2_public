#include "adapter/serialization/apollo_msgs/apollohdmap_lane_sample_association.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneSampleAssociation &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["width"] = (msg.width);
        return obj;
    }
    ApollohdmapLaneSampleAssociation from_json_ApollohdmapLaneSampleAssociation (nlohmann::json obj) {
        ApollohdmapLaneSampleAssociation msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atof(obj["width"].get<std::string>().c_str()):obj["width"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapLaneSampleAssociation from_json<ApollohdmapLaneSampleAssociation>(nlohmann::json obj){
        return from_json_ApollohdmapLaneSampleAssociation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneSampleAssociation &dt)
    {
        dt=from_json_ApollohdmapLaneSampleAssociation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneSampleAssociation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneSampleAssociation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
