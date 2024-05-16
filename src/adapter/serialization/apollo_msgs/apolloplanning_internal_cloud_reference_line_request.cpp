#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cloud_reference_line_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCloudReferenceLineRequest &msg) {
        nlohmann::json obj;
        nlohmann::json arr_lanesegment;
        for (auto it = msg.lanesegment.begin(); it != msg.lanesegment.end(); ++it) {
            arr_lanesegment.push_back(to_json(*it));
        }
        obj["lanesegment"] = arr_lanesegment;
        return obj;
    }
    ApolloplanningInternalCloudReferenceLineRequest from_json_ApolloplanningInternalCloudReferenceLineRequest (nlohmann::json obj) {
        ApolloplanningInternalCloudReferenceLineRequest msg;
        if(obj.contains("lanesegment"))
        {
            if(obj["lanesegment"].is_array())
            {
                for (auto& element : obj["lanesegment"])
                {
                    msg.lanesegment.push_back(from_json_ApolloroutingLaneSegment(element));
                }
            }
            else
            {
                msg.lanesegment.push_back(from_json_ApolloroutingLaneSegment(obj["lanesegment"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalCloudReferenceLineRequest from_json<ApolloplanningInternalCloudReferenceLineRequest>(nlohmann::json obj){
        return from_json_ApolloplanningInternalCloudReferenceLineRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCloudReferenceLineRequest &dt)
    {
        dt=from_json_ApolloplanningInternalCloudReferenceLineRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCloudReferenceLineRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCloudReferenceLineRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
