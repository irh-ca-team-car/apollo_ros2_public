#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle55f4.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle55f4 &msg) {
        nlohmann::json obj;
        obj["canrxyawratebiasshift"] = (msg.canrxyawratebiasshift);
        obj["canrxsteeringgearratio"] = (msg.canrxsteeringgearratio);
        obj["canrxwheelbase"] = (msg.canrxwheelbase);
        obj["canrxdistancerearaxle"] = (msg.canrxdistancerearaxle);
        obj["canrxcwblockagethreshold"] = (msg.canrxcwblockagethreshold);
        obj["canrxfunneloffsetright"] = (msg.canrxfunneloffsetright);
        obj["canrxfunneloffsetleft"] = (msg.canrxfunneloffsetleft);
        obj["canrxbeamwidthvert"] = (msg.canrxbeamwidthvert);
        obj["canrxoversteerundersteer"] = (msg.canrxoversteerundersteer);
        return obj;
    }
    ApollodriversVehicle55f4 from_json_ApollodriversVehicle55f4 (nlohmann::json obj) {
        ApollodriversVehicle55f4 msg;
        if(obj.contains("canrxyawratebiasshift"))
        {
            msg.canrxyawratebiasshift = (obj["canrxyawratebiasshift"].is_string()?atoi(obj["canrxyawratebiasshift"].get<std::string>().c_str()):obj["canrxyawratebiasshift"].get<int>());
        }
        if(obj.contains("canrxsteeringgearratio"))
        {
            msg.canrxsteeringgearratio = (obj["canrxsteeringgearratio"].is_string()?atof(obj["canrxsteeringgearratio"].get<std::string>().c_str()):obj["canrxsteeringgearratio"].get<double>());
        }
        if(obj.contains("canrxwheelbase"))
        {
            msg.canrxwheelbase = (obj["canrxwheelbase"].is_string()?atof(obj["canrxwheelbase"].get<std::string>().c_str()):obj["canrxwheelbase"].get<double>());
        }
        if(obj.contains("canrxdistancerearaxle"))
        {
            msg.canrxdistancerearaxle = (obj["canrxdistancerearaxle"].is_string()?atof(obj["canrxdistancerearaxle"].get<std::string>().c_str()):obj["canrxdistancerearaxle"].get<double>());
        }
        if(obj.contains("canrxcwblockagethreshold"))
        {
            msg.canrxcwblockagethreshold = (obj["canrxcwblockagethreshold"].is_string()?atof(obj["canrxcwblockagethreshold"].get<std::string>().c_str()):obj["canrxcwblockagethreshold"].get<double>());
        }
        if(obj.contains("canrxfunneloffsetright"))
        {
            msg.canrxfunneloffsetright = (obj["canrxfunneloffsetright"].is_string()?atof(obj["canrxfunneloffsetright"].get<std::string>().c_str()):obj["canrxfunneloffsetright"].get<double>());
        }
        if(obj.contains("canrxfunneloffsetleft"))
        {
            msg.canrxfunneloffsetleft = (obj["canrxfunneloffsetleft"].is_string()?atof(obj["canrxfunneloffsetleft"].get<std::string>().c_str()):obj["canrxfunneloffsetleft"].get<double>());
        }
        if(obj.contains("canrxbeamwidthvert"))
        {
            msg.canrxbeamwidthvert = (obj["canrxbeamwidthvert"].is_string()?atof(obj["canrxbeamwidthvert"].get<std::string>().c_str()):obj["canrxbeamwidthvert"].get<double>());
        }
        if(obj.contains("canrxoversteerundersteer"))
        {
            msg.canrxoversteerundersteer = (obj["canrxoversteerundersteer"].is_string()?atoi(obj["canrxoversteerundersteer"].get<std::string>().c_str()):obj["canrxoversteerundersteer"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversVehicle55f4 from_json<ApollodriversVehicle55f4>(nlohmann::json obj){
        return from_json_ApollodriversVehicle55f4(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle55f4 &dt)
    {
        dt=from_json_ApollodriversVehicle55f4(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle55f4 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle55f4 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
