#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cloud_reference_line_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCloudReferenceLineResponse &msg) {
        nlohmann::json obj;
        nlohmann::json arr_segment;
        for (auto it = msg.segment.begin(); it != msg.segment.end(); ++it) {
            arr_segment.push_back(to_json(*it));
        }
        obj["segment"] = arr_segment;
        return obj;
    }
    ApolloplanningInternalCloudReferenceLineResponse from_json_ApolloplanningInternalCloudReferenceLineResponse (nlohmann::json obj) {
        ApolloplanningInternalCloudReferenceLineResponse msg;
        if(obj.contains("segment"))
        {
            if(obj["segment"].is_array())
            {
                for (auto& element : obj["segment"])
                {
                    msg.segment.push_back(from_json_ApollocommonPath(element));
                }
            }
            else
            {
                msg.segment.push_back(from_json_ApollocommonPath(obj["segment"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalCloudReferenceLineResponse from_json<ApolloplanningInternalCloudReferenceLineResponse>(nlohmann::json obj){
        return from_json_ApolloplanningInternalCloudReferenceLineResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCloudReferenceLineResponse &dt)
    {
        dt=from_json_ApolloplanningInternalCloudReferenceLineResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCloudReferenceLineResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCloudReferenceLineResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
