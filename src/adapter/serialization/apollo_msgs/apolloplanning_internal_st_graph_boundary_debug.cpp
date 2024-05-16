#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_boundary_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalStGraphBoundaryDebug &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_point;
        for (auto it = msg.point.begin(); it != msg.point.end(); ++it) {
            arr_point.push_back(to_json(*it));
        }
        obj["point"] = arr_point;
        obj["type"] = (msg.type);
        return obj;
    }
    ApolloplanningInternalStGraphBoundaryDebug from_json_ApolloplanningInternalStGraphBoundaryDebug (nlohmann::json obj) {
        ApolloplanningInternalStGraphBoundaryDebug msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("point"))
        {
            if(obj["point"].is_array())
            {
                for (auto& element : obj["point"])
                {
                    msg.point.push_back(from_json_ApollocommonSpeedPoint(element));
                }
            }
            else
            {
                msg.point.push_back(from_json_ApollocommonSpeedPoint(obj["point"]));
            }
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalStGraphBoundaryDebug from_json<ApolloplanningInternalStGraphBoundaryDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalStGraphBoundaryDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalStGraphBoundaryDebug &dt)
    {
        dt=from_json_ApolloplanningInternalStGraphBoundaryDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalStGraphBoundaryDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalStGraphBoundaryDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
