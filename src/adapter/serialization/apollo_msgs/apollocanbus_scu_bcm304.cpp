#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcm304.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuBcm304 &msg) {
        nlohmann::json obj;
        obj["bcmvehreversest"] = (msg.bcmvehreversest);
        obj["bcmrightturnlampst"] = (msg.bcmrightturnlampst);
        obj["bcmrearfoglampst"] = (msg.bcmrearfoglampst);
        obj["bcmparkinglampst"] = (msg.bcmparkinglampst);
        obj["bcmlowbeamst"] = (msg.bcmlowbeamst);
        obj["bcmleftturnlampst"] = (msg.bcmleftturnlampst);
        obj["bcmkeyst"] = (msg.bcmkeyst);
        obj["bcmhornst"] = (msg.bcmhornst);
        obj["bcmhighbeamst"] = (msg.bcmhighbeamst);
        obj["bcmhazardlampst"] = (msg.bcmhazardlampst);
        obj["bcmfrontfoglampst"] = (msg.bcmfrontfoglampst);
        obj["bcmbrakelightswitchst"] = (msg.bcmbrakelightswitchst);
        return obj;
    }
    ApollocanbusScuBcm304 from_json_ApollocanbusScuBcm304 (nlohmann::json obj) {
        ApollocanbusScuBcm304 msg;
        if(obj.contains("bcmvehreversest"))
        {
            msg.bcmvehreversest = (obj["bcmvehreversest"].is_string()?atoi(obj["bcmvehreversest"].get<std::string>().c_str()):obj["bcmvehreversest"].get<int>());
        }
        if(obj.contains("bcmrightturnlampst"))
        {
            msg.bcmrightturnlampst = (obj["bcmrightturnlampst"].is_string()?atoi(obj["bcmrightturnlampst"].get<std::string>().c_str()):obj["bcmrightturnlampst"].get<int>());
        }
        if(obj.contains("bcmrearfoglampst"))
        {
            msg.bcmrearfoglampst = (obj["bcmrearfoglampst"].is_string()?atoi(obj["bcmrearfoglampst"].get<std::string>().c_str()):obj["bcmrearfoglampst"].get<int>());
        }
        if(obj.contains("bcmparkinglampst"))
        {
            msg.bcmparkinglampst = (obj["bcmparkinglampst"].is_string()?atoi(obj["bcmparkinglampst"].get<std::string>().c_str()):obj["bcmparkinglampst"].get<int>());
        }
        if(obj.contains("bcmlowbeamst"))
        {
            msg.bcmlowbeamst = (obj["bcmlowbeamst"].is_string()?atoi(obj["bcmlowbeamst"].get<std::string>().c_str()):obj["bcmlowbeamst"].get<int>());
        }
        if(obj.contains("bcmleftturnlampst"))
        {
            msg.bcmleftturnlampst = (obj["bcmleftturnlampst"].is_string()?atoi(obj["bcmleftturnlampst"].get<std::string>().c_str()):obj["bcmleftturnlampst"].get<int>());
        }
        if(obj.contains("bcmkeyst"))
        {
            msg.bcmkeyst = (obj["bcmkeyst"].is_string()?atoi(obj["bcmkeyst"].get<std::string>().c_str()):obj["bcmkeyst"].get<int>());
        }
        if(obj.contains("bcmhornst"))
        {
            msg.bcmhornst = (obj["bcmhornst"].is_string()?atoi(obj["bcmhornst"].get<std::string>().c_str()):obj["bcmhornst"].get<int>());
        }
        if(obj.contains("bcmhighbeamst"))
        {
            msg.bcmhighbeamst = (obj["bcmhighbeamst"].is_string()?atoi(obj["bcmhighbeamst"].get<std::string>().c_str()):obj["bcmhighbeamst"].get<int>());
        }
        if(obj.contains("bcmhazardlampst"))
        {
            msg.bcmhazardlampst = (obj["bcmhazardlampst"].is_string()?atoi(obj["bcmhazardlampst"].get<std::string>().c_str()):obj["bcmhazardlampst"].get<int>());
        }
        if(obj.contains("bcmfrontfoglampst"))
        {
            msg.bcmfrontfoglampst = (obj["bcmfrontfoglampst"].is_string()?atoi(obj["bcmfrontfoglampst"].get<std::string>().c_str()):obj["bcmfrontfoglampst"].get<int>());
        }
        if(obj.contains("bcmbrakelightswitchst"))
        {
            msg.bcmbrakelightswitchst = (obj["bcmbrakelightswitchst"].is_string()?atoi(obj["bcmbrakelightswitchst"].get<std::string>().c_str()):obj["bcmbrakelightswitchst"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuBcm304 from_json<ApollocanbusScuBcm304>(nlohmann::json obj){
        return from_json_ApollocanbusScuBcm304(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuBcm304 &dt)
    {
        dt=from_json_ApollocanbusScuBcm304(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuBcm304 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuBcm304 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
