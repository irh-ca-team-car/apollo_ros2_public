#include "adapter/serialization/apollo_msgs/apollocanbus_ads_req_vin390.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsReqVin390 &msg) {
        nlohmann::json obj;
        obj["reqvinsignal"] = (msg.reqvinsignal);
        return obj;
    }
    ApollocanbusAdsReqVin390 from_json_ApollocanbusAdsReqVin390 (nlohmann::json obj) {
        ApollocanbusAdsReqVin390 msg;
        if(obj.contains("reqvinsignal"))
        {
            msg.reqvinsignal = (obj["reqvinsignal"].is_string()?atoi(obj["reqvinsignal"].get<std::string>().c_str()):obj["reqvinsignal"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdsReqVin390 from_json<ApollocanbusAdsReqVin390>(nlohmann::json obj){
        return from_json_ApollocanbusAdsReqVin390(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsReqVin390 &dt)
    {
        dt=from_json_ApollocanbusAdsReqVin390(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsReqVin390 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsReqVin390 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
