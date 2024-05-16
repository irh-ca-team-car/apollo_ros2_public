#include "adapter/serialization/apollo_msgs/apolloplanning_st_drivable_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSTDrivableBoundary &msg) {
        nlohmann::json obj;
        nlohmann::json arr_stboundary;
        for (auto it = msg.stboundary.begin(); it != msg.stboundary.end(); ++it) {
            arr_stboundary.push_back(to_json(*it));
        }
        obj["stboundary"] = arr_stboundary;
        return obj;
    }
    ApolloplanningSTDrivableBoundary from_json_ApolloplanningSTDrivableBoundary (nlohmann::json obj) {
        ApolloplanningSTDrivableBoundary msg;
        if(obj.contains("stboundary"))
        {
            if(obj["stboundary"].is_array())
            {
                for (auto& element : obj["stboundary"])
                {
                    msg.stboundary.push_back(from_json_ApolloplanningSTDrivableBoundaryInstance(element));
                }
            }
            else
            {
                msg.stboundary.push_back(from_json_ApolloplanningSTDrivableBoundaryInstance(obj["stboundary"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningSTDrivableBoundary from_json<ApolloplanningSTDrivableBoundary>(nlohmann::json obj){
        return from_json_ApolloplanningSTDrivableBoundary(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSTDrivableBoundary &dt)
    {
        dt=from_json_ApolloplanningSTDrivableBoundary(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSTDrivableBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSTDrivableBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
}
