#include "adapter/serialization/apollo_msgs/apollohdmap_lane_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneBoundary &msg) {
        nlohmann::json obj;
        obj["curve"] = to_json(msg.curve);
        obj["length"] = (msg.length);
        obj["virtuall"] = (msg.virtuall);
        nlohmann::json arr_boundarytype;
        for (auto it = msg.boundarytype.begin(); it != msg.boundarytype.end(); ++it) {
            arr_boundarytype.push_back(to_json(*it));
        }
        obj["boundarytype"] = arr_boundarytype;
        return obj;
    }
    ApollohdmapLaneBoundary from_json_ApollohdmapLaneBoundary (nlohmann::json obj) {
        ApollohdmapLaneBoundary msg;
        if(obj.contains("curve"))
        {
            msg.curve = from_json_ApollohdmapCurve(obj["curve"]);
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("virtuall"))
        {
            msg.virtuall = (obj["virtuall"].is_string()?(bool)atoi(obj["virtuall"].get<std::string>().c_str()):obj["virtuall"].get<bool>());
        }
        if(obj.contains("boundarytype"))
        {
            if(obj["boundarytype"].is_array())
            {
                for (auto& element : obj["boundarytype"])
                {
                    msg.boundarytype.push_back(from_json_ApollohdmapLaneBoundaryType(element));
                }
            }
            else
            {
                msg.boundarytype.push_back(from_json_ApollohdmapLaneBoundaryType(obj["boundarytype"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapLaneBoundary from_json<ApollohdmapLaneBoundary>(nlohmann::json obj){
        return from_json_ApollohdmapLaneBoundary(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneBoundary &dt)
    {
        dt=from_json_ApollohdmapLaneBoundary(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
}
