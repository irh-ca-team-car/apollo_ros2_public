#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cloud_reference_line_routing_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCloudReferenceLineRoutingRequest &msg) {
        nlohmann::json obj;
        obj["routing"] = to_json(msg.routing);
        return obj;
    }
    ApolloplanningInternalCloudReferenceLineRoutingRequest from_json_ApolloplanningInternalCloudReferenceLineRoutingRequest (nlohmann::json obj) {
        ApolloplanningInternalCloudReferenceLineRoutingRequest msg;
        if(obj.contains("routing"))
        {
            msg.routing = from_json_ApolloroutingRoutingResponse(obj["routing"]);
        }
        return msg;
    }
    template <>
    ApolloplanningInternalCloudReferenceLineRoutingRequest from_json<ApolloplanningInternalCloudReferenceLineRoutingRequest>(nlohmann::json obj){
        return from_json_ApolloplanningInternalCloudReferenceLineRoutingRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCloudReferenceLineRoutingRequest &dt)
    {
        dt=from_json_ApolloplanningInternalCloudReferenceLineRoutingRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCloudReferenceLineRoutingRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCloudReferenceLineRoutingRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
