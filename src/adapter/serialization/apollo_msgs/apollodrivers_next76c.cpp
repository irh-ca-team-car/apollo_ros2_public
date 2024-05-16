#include "adapter/serialization/apollo_msgs/apollodrivers_next76c.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversNext76c &msg) {
        nlohmann::json obj;
        obj["lanetype"] = (msg.lanetype);
        obj["quality"] = (msg.quality);
        obj["modeldegree"] = (msg.modeldegree);
        obj["position"] = (msg.position);
        obj["curvature"] = (msg.curvature);
        obj["curvaturederivative"] = (msg.curvaturederivative);
        obj["lanemarkwidth"] = (msg.lanemarkwidth);
        return obj;
    }
    ApollodriversNext76c from_json_ApollodriversNext76c (nlohmann::json obj) {
        ApollodriversNext76c msg;
        if(obj.contains("lanetype"))
        {
            msg.lanetype = (obj["lanetype"].is_string()?atoi(obj["lanetype"].get<std::string>().c_str()):obj["lanetype"].get<int>());
        }
        if(obj.contains("quality"))
        {
            msg.quality = (obj["quality"].is_string()?atoi(obj["quality"].get<std::string>().c_str()):obj["quality"].get<int>());
        }
        if(obj.contains("modeldegree"))
        {
            msg.modeldegree = (obj["modeldegree"].is_string()?atoi(obj["modeldegree"].get<std::string>().c_str()):obj["modeldegree"].get<int>());
        }
        if(obj.contains("position"))
        {
            msg.position = (obj["position"].is_string()?atof(obj["position"].get<std::string>().c_str()):obj["position"].get<double>());
        }
        if(obj.contains("curvature"))
        {
            msg.curvature = (obj["curvature"].is_string()?atof(obj["curvature"].get<std::string>().c_str()):obj["curvature"].get<double>());
        }
        if(obj.contains("curvaturederivative"))
        {
            msg.curvaturederivative = (obj["curvaturederivative"].is_string()?atof(obj["curvaturederivative"].get<std::string>().c_str()):obj["curvaturederivative"].get<double>());
        }
        if(obj.contains("lanemarkwidth"))
        {
            msg.lanemarkwidth = (obj["lanemarkwidth"].is_string()?atof(obj["lanemarkwidth"].get<std::string>().c_str()):obj["lanemarkwidth"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversNext76c from_json<ApollodriversNext76c>(nlohmann::json obj){
        return from_json_ApollodriversNext76c(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversNext76c &dt)
    {
        dt=from_json_ApollodriversNext76c(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversNext76c & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversNext76c & dt)
    {
        os << to_json(dt);
        return os;
    }
}
