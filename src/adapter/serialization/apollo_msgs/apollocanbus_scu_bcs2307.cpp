#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs2307.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuBcs2307 &msg) {
        nlohmann::json obj;
        obj["bcsvehspdvd"] = (msg.bcsvehspdvd);
        obj["bcsyawrate"] = (msg.bcsyawrate);
        obj["bcsvehspd"] = (msg.bcsvehspd);
        obj["bcsvehlongaccel"] = (msg.bcsvehlongaccel);
        obj["bcsvehlataccel"] = (msg.bcsvehlataccel);
        return obj;
    }
    ApollocanbusScuBcs2307 from_json_ApollocanbusScuBcs2307 (nlohmann::json obj) {
        ApollocanbusScuBcs2307 msg;
        if(obj.contains("bcsvehspdvd"))
        {
            msg.bcsvehspdvd = (obj["bcsvehspdvd"].is_string()?atoi(obj["bcsvehspdvd"].get<std::string>().c_str()):obj["bcsvehspdvd"].get<int>());
        }
        if(obj.contains("bcsyawrate"))
        {
            msg.bcsyawrate = (obj["bcsyawrate"].is_string()?atof(obj["bcsyawrate"].get<std::string>().c_str()):obj["bcsyawrate"].get<double>());
        }
        if(obj.contains("bcsvehspd"))
        {
            msg.bcsvehspd = (obj["bcsvehspd"].is_string()?atof(obj["bcsvehspd"].get<std::string>().c_str()):obj["bcsvehspd"].get<double>());
        }
        if(obj.contains("bcsvehlongaccel"))
        {
            msg.bcsvehlongaccel = (obj["bcsvehlongaccel"].is_string()?atof(obj["bcsvehlongaccel"].get<std::string>().c_str()):obj["bcsvehlongaccel"].get<double>());
        }
        if(obj.contains("bcsvehlataccel"))
        {
            msg.bcsvehlataccel = (obj["bcsvehlataccel"].is_string()?atof(obj["bcsvehlataccel"].get<std::string>().c_str()):obj["bcsvehlataccel"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuBcs2307 from_json<ApollocanbusScuBcs2307>(nlohmann::json obj){
        return from_json_ApollocanbusScuBcs2307(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuBcs2307 &dt)
    {
        dt=from_json_ApollocanbusScuBcs2307(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuBcs2307 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuBcs2307 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
