#include "adapter/serialization/apollo_msgs/apollodrivers_reference76a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversReference76a &msg) {
        nlohmann::json obj;
        obj["refpoint1position"] = (msg.refpoint1position);
        obj["refpoint1distance"] = (msg.refpoint1distance);
        obj["refpoint1validity"] = (msg.refpoint1validity);
        obj["refpoint2position"] = (msg.refpoint2position);
        obj["refpoint2distance"] = (msg.refpoint2distance);
        obj["refpoint2validity"] = (msg.refpoint2validity);
        return obj;
    }
    ApollodriversReference76a from_json_ApollodriversReference76a (nlohmann::json obj) {
        ApollodriversReference76a msg;
        if(obj.contains("refpoint1position"))
        {
            msg.refpoint1position = (obj["refpoint1position"].is_string()?atof(obj["refpoint1position"].get<std::string>().c_str()):obj["refpoint1position"].get<double>());
        }
        if(obj.contains("refpoint1distance"))
        {
            msg.refpoint1distance = (obj["refpoint1distance"].is_string()?atof(obj["refpoint1distance"].get<std::string>().c_str()):obj["refpoint1distance"].get<double>());
        }
        if(obj.contains("refpoint1validity"))
        {
            msg.refpoint1validity = (obj["refpoint1validity"].is_string()?(bool)atoi(obj["refpoint1validity"].get<std::string>().c_str()):obj["refpoint1validity"].get<bool>());
        }
        if(obj.contains("refpoint2position"))
        {
            msg.refpoint2position = (obj["refpoint2position"].is_string()?atof(obj["refpoint2position"].get<std::string>().c_str()):obj["refpoint2position"].get<double>());
        }
        if(obj.contains("refpoint2distance"))
        {
            msg.refpoint2distance = (obj["refpoint2distance"].is_string()?atof(obj["refpoint2distance"].get<std::string>().c_str()):obj["refpoint2distance"].get<double>());
        }
        if(obj.contains("refpoint2validity"))
        {
            msg.refpoint2validity = (obj["refpoint2validity"].is_string()?(bool)atoi(obj["refpoint2validity"].get<std::string>().c_str()):obj["refpoint2validity"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversReference76a from_json<ApollodriversReference76a>(nlohmann::json obj){
        return from_json_ApollodriversReference76a(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversReference76a &dt)
    {
        dt=from_json_ApollodriversReference76a(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversReference76a & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversReference76a & dt)
    {
        os << to_json(dt);
        return os;
    }
}
