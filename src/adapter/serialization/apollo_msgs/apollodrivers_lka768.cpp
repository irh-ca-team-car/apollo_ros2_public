#include "adapter/serialization/apollo_msgs/apollodrivers_lka768.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLka768 &msg) {
        nlohmann::json obj;
        obj["lanetype"] = (msg.lanetype);
        obj["quality"] = (msg.quality);
        obj["modeldegree"] = (msg.modeldegree);
        obj["position"] = (msg.position);
        obj["curvature"] = (msg.curvature);
        obj["curvaturederivative"] = (msg.curvaturederivative);
        obj["widthrightmarking"] = (msg.widthrightmarking);
        return obj;
    }
    ApollodriversLka768 from_json_ApollodriversLka768 (nlohmann::json obj) {
        ApollodriversLka768 msg;
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
        if(obj.contains("widthrightmarking"))
        {
            msg.widthrightmarking = (obj["widthrightmarking"].is_string()?atof(obj["widthrightmarking"].get<std::string>().c_str()):obj["widthrightmarking"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversLka768 from_json<ApollodriversLka768>(nlohmann::json obj){
        return from_json_ApollodriversLka768(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLka768 &dt)
    {
        dt=from_json_ApollodriversLka768(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversLka768 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLka768 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
