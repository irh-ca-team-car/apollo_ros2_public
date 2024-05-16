#include "adapter/serialization/apollo_msgs/apollodrivers_point_xyzit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversPointXYZIT &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["intensity"] = (msg.intensity);
        obj["timestamp"] = (msg.timestamp);
        return obj;
    }
    ApollodriversPointXYZIT from_json_ApollodriversPointXYZIT (nlohmann::json obj) {
        ApollodriversPointXYZIT msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?(float)atof(obj["x"].get<std::string>().c_str()):obj["x"].get<float>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?(float)atof(obj["y"].get<std::string>().c_str()):obj["y"].get<float>());
        }
        if(obj.contains("z"))
        {
            msg.z = (obj["z"].is_string()?(float)atof(obj["z"].get<std::string>().c_str()):obj["z"].get<float>());
        }
        if(obj.contains("intensity"))
        {
            msg.intensity = (obj["intensity"].is_string()?atoi(obj["intensity"].get<std::string>().c_str()):obj["intensity"].get<uint32_t>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atol(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<uint64_t>());
        }
        return msg;
    }
    template <>
    ApollodriversPointXYZIT from_json<ApollodriversPointXYZIT>(nlohmann::json obj){
        return from_json_ApollodriversPointXYZIT(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversPointXYZIT &dt)
    {
        dt=from_json_ApollodriversPointXYZIT(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversPointXYZIT & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversPointXYZIT & dt)
    {
        os << to_json(dt);
        return os;
    }
}
