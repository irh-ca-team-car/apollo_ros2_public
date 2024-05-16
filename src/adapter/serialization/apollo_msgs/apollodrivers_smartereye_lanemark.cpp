#include "adapter/serialization/apollo_msgs/apollodrivers_smartereye_lanemark.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversSmartereyeLanemark &msg) {
        nlohmann::json obj;
        obj["laneroaddata"] = to_json(msg.laneroaddata);
        return obj;
    }
    ApollodriversSmartereyeLanemark from_json_ApollodriversSmartereyeLanemark (nlohmann::json obj) {
        ApollodriversSmartereyeLanemark msg;
        if(obj.contains("laneroaddata"))
        {
            msg.laneroaddata = from_json_ApollodriversLdwDataPacks(obj["laneroaddata"]);
        }
        return msg;
    }
    template <>
    ApollodriversSmartereyeLanemark from_json<ApollodriversSmartereyeLanemark>(nlohmann::json obj){
        return from_json_ApollodriversSmartereyeLanemark(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversSmartereyeLanemark &dt)
    {
        dt=from_json_ApollodriversSmartereyeLanemark(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversSmartereyeLanemark & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversSmartereyeLanemark & dt)
    {
        os << to_json(dt);
        return os;
    }
}
