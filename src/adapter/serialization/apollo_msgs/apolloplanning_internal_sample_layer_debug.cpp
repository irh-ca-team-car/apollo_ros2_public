#include "adapter/serialization/apollo_msgs/apolloplanning_internal_sample_layer_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSampleLayerDebug &msg) {
        nlohmann::json obj;
        nlohmann::json arr_slpoint;
        for (auto it = msg.slpoint.begin(); it != msg.slpoint.end(); ++it) {
            arr_slpoint.push_back(to_json(*it));
        }
        obj["slpoint"] = arr_slpoint;
        return obj;
    }
    ApolloplanningInternalSampleLayerDebug from_json_ApolloplanningInternalSampleLayerDebug (nlohmann::json obj) {
        ApolloplanningInternalSampleLayerDebug msg;
        if(obj.contains("slpoint"))
        {
            if(obj["slpoint"].is_array())
            {
                for (auto& element : obj["slpoint"])
                {
                    msg.slpoint.push_back(from_json_ApollocommonSLPoint(element));
                }
            }
            else
            {
                msg.slpoint.push_back(from_json_ApollocommonSLPoint(obj["slpoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSampleLayerDebug from_json<ApolloplanningInternalSampleLayerDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSampleLayerDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSampleLayerDebug &dt)
    {
        dt=from_json_ApolloplanningInternalSampleLayerDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSampleLayerDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSampleLayerDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
