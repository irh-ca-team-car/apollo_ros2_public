#include "adapter/serialization/apollo_msgs/apollocanbus_epb.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEpb &msg) {
        nlohmann::json obj;
        obj["isepberror"] = (msg.isepberror);
        obj["isepbreleased"] = (msg.isepbreleased);
        obj["epbstatus"] = (msg.epbstatus);
        obj["parkingbrakestatus"] = (msg.parkingbrakestatus);
        return obj;
    }
    ApollocanbusEpb from_json_ApollocanbusEpb (nlohmann::json obj) {
        ApollocanbusEpb msg;
        if(obj.contains("isepberror"))
        {
            msg.isepberror = (obj["isepberror"].is_string()?(bool)atoi(obj["isepberror"].get<std::string>().c_str()):obj["isepberror"].get<bool>());
        }
        if(obj.contains("isepbreleased"))
        {
            msg.isepbreleased = (obj["isepbreleased"].is_string()?(bool)atoi(obj["isepbreleased"].get<std::string>().c_str()):obj["isepbreleased"].get<bool>());
        }
        if(obj.contains("epbstatus"))
        {
            msg.epbstatus = (obj["epbstatus"].is_string()?atoi(obj["epbstatus"].get<std::string>().c_str()):obj["epbstatus"].get<int>());
        }
        if(obj.contains("parkingbrakestatus"))
        {
            msg.parkingbrakestatus = (obj["parkingbrakestatus"].is_string()?atoi(obj["parkingbrakestatus"].get<std::string>().c_str()):obj["parkingbrakestatus"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusEpb from_json<ApollocanbusEpb>(nlohmann::json obj){
        return from_json_ApollocanbusEpb(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEpb &dt)
    {
        dt=from_json_ApollocanbusEpb(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEpb & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEpb & dt)
    {
        os << to_json(dt);
        return os;
    }
}
