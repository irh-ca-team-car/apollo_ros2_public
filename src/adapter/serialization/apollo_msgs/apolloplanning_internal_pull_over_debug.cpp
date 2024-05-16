#include "adapter/serialization/apollo_msgs/apolloplanning_internal_pull_over_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalPullOverDebug &msg) {
        nlohmann::json obj;
        obj["position"] = to_json(msg.position);
        obj["theta"] = (msg.theta);
        obj["lengthfront"] = (msg.lengthfront);
        obj["lengthback"] = (msg.lengthback);
        obj["widthleft"] = (msg.widthleft);
        obj["widthright"] = (msg.widthright);
        return obj;
    }
    ApolloplanningInternalPullOverDebug from_json_ApolloplanningInternalPullOverDebug (nlohmann::json obj) {
        ApolloplanningInternalPullOverDebug msg;
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPointENU(obj["position"]);
        }
        if(obj.contains("theta"))
        {
            msg.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<double>());
        }
        if(obj.contains("lengthfront"))
        {
            msg.lengthfront = (obj["lengthfront"].is_string()?atof(obj["lengthfront"].get<std::string>().c_str()):obj["lengthfront"].get<double>());
        }
        if(obj.contains("lengthback"))
        {
            msg.lengthback = (obj["lengthback"].is_string()?atof(obj["lengthback"].get<std::string>().c_str()):obj["lengthback"].get<double>());
        }
        if(obj.contains("widthleft"))
        {
            msg.widthleft = (obj["widthleft"].is_string()?atof(obj["widthleft"].get<std::string>().c_str()):obj["widthleft"].get<double>());
        }
        if(obj.contains("widthright"))
        {
            msg.widthright = (obj["widthright"].is_string()?atof(obj["widthright"].get<std::string>().c_str()):obj["widthright"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalPullOverDebug from_json<ApolloplanningInternalPullOverDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalPullOverDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalPullOverDebug &dt)
    {
        dt=from_json_ApolloplanningInternalPullOverDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalPullOverDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalPullOverDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
