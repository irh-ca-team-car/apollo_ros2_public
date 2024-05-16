#include "adapter/serialization/apollo_msgs/apolloplanning_internal_dp_poly_graph_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalDpPolyGraphDebug &msg) {
        nlohmann::json obj;
        nlohmann::json arr_samplelayer;
        for (auto it = msg.samplelayer.begin(); it != msg.samplelayer.end(); ++it) {
            arr_samplelayer.push_back(to_json(*it));
        }
        obj["samplelayer"] = arr_samplelayer;
        nlohmann::json arr_mincostpoint;
        for (auto it = msg.mincostpoint.begin(); it != msg.mincostpoint.end(); ++it) {
            arr_mincostpoint.push_back(to_json(*it));
        }
        obj["mincostpoint"] = arr_mincostpoint;
        return obj;
    }
    ApolloplanningInternalDpPolyGraphDebug from_json_ApolloplanningInternalDpPolyGraphDebug (nlohmann::json obj) {
        ApolloplanningInternalDpPolyGraphDebug msg;
        if(obj.contains("samplelayer"))
        {
            if(obj["samplelayer"].is_array())
            {
                for (auto& element : obj["samplelayer"])
                {
                    msg.samplelayer.push_back(from_json_ApolloplanningInternalSampleLayerDebug(element));
                }
            }
            else
            {
                msg.samplelayer.push_back(from_json_ApolloplanningInternalSampleLayerDebug(obj["samplelayer"]));
            }
        }
        if(obj.contains("mincostpoint"))
        {
            if(obj["mincostpoint"].is_array())
            {
                for (auto& element : obj["mincostpoint"])
                {
                    msg.mincostpoint.push_back(from_json_ApollocommonSLPoint(element));
                }
            }
            else
            {
                msg.mincostpoint.push_back(from_json_ApollocommonSLPoint(obj["mincostpoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalDpPolyGraphDebug from_json<ApolloplanningInternalDpPolyGraphDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalDpPolyGraphDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalDpPolyGraphDebug &dt)
    {
        dt=from_json_ApolloplanningInternalDpPolyGraphDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalDpPolyGraphDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalDpPolyGraphDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
