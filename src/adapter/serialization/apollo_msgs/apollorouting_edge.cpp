#include "adapter/serialization/apollo_msgs/apollorouting_edge.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingEdge &msg) {
        nlohmann::json obj;
        obj["fromlaneid"] = (msg.fromlaneid);
        obj["tolaneid"] = (msg.tolaneid);
        obj["cost"] = (msg.cost);
        obj["directiontype"] = (msg.directiontype);
        return obj;
    }
    ApolloroutingEdge from_json_ApolloroutingEdge (nlohmann::json obj) {
        ApolloroutingEdge msg;
        if(obj.contains("fromlaneid"))
        {
            msg.fromlaneid = (obj["fromlaneid"].is_string()?(obj["fromlaneid"].get<std::string>().c_str()):obj["fromlaneid"].get<std::string>());
        }
        if(obj.contains("tolaneid"))
        {
            msg.tolaneid = (obj["tolaneid"].is_string()?(obj["tolaneid"].get<std::string>().c_str()):obj["tolaneid"].get<std::string>());
        }
        if(obj.contains("cost"))
        {
            msg.cost = (obj["cost"].is_string()?atof(obj["cost"].get<std::string>().c_str()):obj["cost"].get<double>());
        }
        if(obj.contains("directiontype"))
        {
            msg.directiontype = (obj["directiontype"].is_string()?atoi(obj["directiontype"].get<std::string>().c_str()):obj["directiontype"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloroutingEdge from_json<ApolloroutingEdge>(nlohmann::json obj){
        return from_json_ApolloroutingEdge(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingEdge &dt)
    {
        dt=from_json_ApolloroutingEdge(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingEdge & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingEdge & dt)
    {
        os << to_json(dt);
        return os;
    }
}
