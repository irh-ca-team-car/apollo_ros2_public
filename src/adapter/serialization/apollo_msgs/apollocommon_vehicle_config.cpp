#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleConfig &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["vehicleparam"] = to_json(msg.vehicleparam);
        obj["extrinsics"] = to_json(msg.extrinsics);
        return obj;
    }
    ApollocommonVehicleConfig from_json_ApollocommonVehicleConfig (nlohmann::json obj) {
        ApollocommonVehicleConfig msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("vehicleparam"))
        {
            msg.vehicleparam = from_json_ApollocommonVehicleParam(obj["vehicleparam"]);
        }
        if(obj.contains("extrinsics"))
        {
            msg.extrinsics = from_json_ApollocommonExtrinsics(obj["extrinsics"]);
        }
        return msg;
    }
    template <>
    ApollocommonVehicleConfig from_json<ApollocommonVehicleConfig>(nlohmann::json obj){
        return from_json_ApollocommonVehicleConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleConfig &dt)
    {
        dt=from_json_ApollocommonVehicleConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
