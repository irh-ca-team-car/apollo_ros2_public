#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle65f5.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle65f5 &msg) {
        nlohmann::json obj;
        obj["canrxinnerfunneloffsetright"] = (msg.canrxinnerfunneloffsetright);
        obj["canrxinnerfunneloffsetleft"] = (msg.canrxinnerfunneloffsetleft);
        obj["canvolvofarangemaxshort"] = (msg.canvolvofarangemaxshort);
        obj["canvolvofaminvspeedshort"] = (msg.canvolvofaminvspeedshort);
        obj["canvolvofaaalignestimate"] = (msg.canvolvofaaalignestimate);
        return obj;
    }
    ApollodriversVehicle65f5 from_json_ApollodriversVehicle65f5 (nlohmann::json obj) {
        ApollodriversVehicle65f5 msg;
        if(obj.contains("canrxinnerfunneloffsetright"))
        {
            msg.canrxinnerfunneloffsetright = (obj["canrxinnerfunneloffsetright"].is_string()?atof(obj["canrxinnerfunneloffsetright"].get<std::string>().c_str()):obj["canrxinnerfunneloffsetright"].get<double>());
        }
        if(obj.contains("canrxinnerfunneloffsetleft"))
        {
            msg.canrxinnerfunneloffsetleft = (obj["canrxinnerfunneloffsetleft"].is_string()?atof(obj["canrxinnerfunneloffsetleft"].get<std::string>().c_str()):obj["canrxinnerfunneloffsetleft"].get<double>());
        }
        if(obj.contains("canvolvofarangemaxshort"))
        {
            msg.canvolvofarangemaxshort = (obj["canvolvofarangemaxshort"].is_string()?atoi(obj["canvolvofarangemaxshort"].get<std::string>().c_str()):obj["canvolvofarangemaxshort"].get<int>());
        }
        if(obj.contains("canvolvofaminvspeedshort"))
        {
            msg.canvolvofaminvspeedshort = (obj["canvolvofaminvspeedshort"].is_string()?atof(obj["canvolvofaminvspeedshort"].get<std::string>().c_str()):obj["canvolvofaminvspeedshort"].get<double>());
        }
        if(obj.contains("canvolvofaaalignestimate"))
        {
            msg.canvolvofaaalignestimate = (obj["canvolvofaaalignestimate"].is_string()?atof(obj["canvolvofaaalignestimate"].get<std::string>().c_str()):obj["canvolvofaaalignestimate"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversVehicle65f5 from_json<ApollodriversVehicle65f5>(nlohmann::json obj){
        return from_json_ApollodriversVehicle65f5(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle65f5 &dt)
    {
        dt=from_json_ApollodriversVehicle65f5(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle65f5 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle65f5 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
