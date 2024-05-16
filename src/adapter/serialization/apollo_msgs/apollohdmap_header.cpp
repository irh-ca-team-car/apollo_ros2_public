#include "adapter/serialization/apollo_msgs/apollohdmap_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapHeader &msg) {
        nlohmann::json obj;
        obj["version"] = to_json(msg.version);
        obj["date"] = to_json(msg.date);
        obj["projection"] = to_json(msg.projection);
        obj["district"] = to_json(msg.district);
        obj["generation"] = to_json(msg.generation);
        obj["revmajor"] = to_json(msg.revmajor);
        obj["revminor"] = to_json(msg.revminor);
        obj["left"] = (msg.left);
        obj["top"] = (msg.top);
        obj["right"] = (msg.right);
        obj["bottom"] = (msg.bottom);
        obj["vendor"] = to_json(msg.vendor);
        return obj;
    }
    ApollohdmapHeader from_json_ApollohdmapHeader (nlohmann::json obj) {
        ApollohdmapHeader msg;
        if(obj.contains("version"))
        {
            msg.version = from_json_Bytes(obj["version"]);
        }
        if(obj.contains("date"))
        {
            msg.date = from_json_Bytes(obj["date"]);
        }
        if(obj.contains("projection"))
        {
            msg.projection = from_json_ApollohdmapProjection(obj["projection"]);
        }
        if(obj.contains("district"))
        {
            msg.district = from_json_Bytes(obj["district"]);
        }
        if(obj.contains("generation"))
        {
            msg.generation = from_json_Bytes(obj["generation"]);
        }
        if(obj.contains("revmajor"))
        {
            msg.revmajor = from_json_Bytes(obj["revmajor"]);
        }
        if(obj.contains("revminor"))
        {
            msg.revminor = from_json_Bytes(obj["revminor"]);
        }
        if(obj.contains("left"))
        {
            msg.left = (obj["left"].is_string()?atof(obj["left"].get<std::string>().c_str()):obj["left"].get<double>());
        }
        if(obj.contains("top"))
        {
            msg.top = (obj["top"].is_string()?atof(obj["top"].get<std::string>().c_str()):obj["top"].get<double>());
        }
        if(obj.contains("right"))
        {
            msg.right = (obj["right"].is_string()?atof(obj["right"].get<std::string>().c_str()):obj["right"].get<double>());
        }
        if(obj.contains("bottom"))
        {
            msg.bottom = (obj["bottom"].is_string()?atof(obj["bottom"].get<std::string>().c_str()):obj["bottom"].get<double>());
        }
        if(obj.contains("vendor"))
        {
            msg.vendor = from_json_Bytes(obj["vendor"]);
        }
        return msg;
    }
    template <>
    ApollohdmapHeader from_json<ApollohdmapHeader>(nlohmann::json obj){
        return from_json_ApollohdmapHeader(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapHeader &dt)
    {
        dt=from_json_ApollohdmapHeader(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapHeader & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapHeader & dt)
    {
        os << to_json(dt);
        return os;
    }
}
