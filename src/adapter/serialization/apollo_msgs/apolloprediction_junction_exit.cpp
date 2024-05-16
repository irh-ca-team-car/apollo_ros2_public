#include "adapter/serialization/apollo_msgs/apolloprediction_junction_exit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionJunctionExit &msg) {
        nlohmann::json obj;
        obj["exitlaneid"] = (msg.exitlaneid);
        obj["exitposition"] = to_json(msg.exitposition);
        obj["exitheading"] = (msg.exitheading);
        obj["exitwidth"] = (msg.exitwidth);
        return obj;
    }
    ApollopredictionJunctionExit from_json_ApollopredictionJunctionExit (nlohmann::json obj) {
        ApollopredictionJunctionExit msg;
        if(obj.contains("exitlaneid"))
        {
            msg.exitlaneid = (obj["exitlaneid"].is_string()?(obj["exitlaneid"].get<std::string>().c_str()):obj["exitlaneid"].get<std::string>());
        }
        if(obj.contains("exitposition"))
        {
            msg.exitposition = from_json_ApollocommonPoint3D(obj["exitposition"]);
        }
        if(obj.contains("exitheading"))
        {
            msg.exitheading = (obj["exitheading"].is_string()?atof(obj["exitheading"].get<std::string>().c_str()):obj["exitheading"].get<double>());
        }
        if(obj.contains("exitwidth"))
        {
            msg.exitwidth = (obj["exitwidth"].is_string()?atof(obj["exitwidth"].get<std::string>().c_str()):obj["exitwidth"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionJunctionExit from_json<ApollopredictionJunctionExit>(nlohmann::json obj){
        return from_json_ApollopredictionJunctionExit(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionJunctionExit &dt)
    {
        dt=from_json_ApollopredictionJunctionExit(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionJunctionExit & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionJunctionExit & dt)
    {
        os << to_json(dt);
        return os;
    }
}
