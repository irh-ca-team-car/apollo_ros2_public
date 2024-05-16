#include "adapter/serialization/apollo_msgs/apollocanbus_deceleration.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDeceleration &msg) {
        nlohmann::json obj;
        obj["isdecelerationavailable"] = (msg.isdecelerationavailable);
        obj["isdecelerationactive"] = (msg.isdecelerationactive);
        obj["deceleration"] = (msg.deceleration);
        obj["isevbfail"] = (msg.isevbfail);
        obj["evbpressure"] = (msg.evbpressure);
        obj["brakepressure"] = (msg.brakepressure);
        obj["brakepressurespd"] = (msg.brakepressurespd);
        return obj;
    }
    ApollocanbusDeceleration from_json_ApollocanbusDeceleration (nlohmann::json obj) {
        ApollocanbusDeceleration msg;
        if(obj.contains("isdecelerationavailable"))
        {
            msg.isdecelerationavailable = (obj["isdecelerationavailable"].is_string()?(bool)atoi(obj["isdecelerationavailable"].get<std::string>().c_str()):obj["isdecelerationavailable"].get<bool>());
        }
        if(obj.contains("isdecelerationactive"))
        {
            msg.isdecelerationactive = (obj["isdecelerationactive"].is_string()?(bool)atoi(obj["isdecelerationactive"].get<std::string>().c_str()):obj["isdecelerationactive"].get<bool>());
        }
        if(obj.contains("deceleration"))
        {
            msg.deceleration = (obj["deceleration"].is_string()?atof(obj["deceleration"].get<std::string>().c_str()):obj["deceleration"].get<double>());
        }
        if(obj.contains("isevbfail"))
        {
            msg.isevbfail = (obj["isevbfail"].is_string()?atof(obj["isevbfail"].get<std::string>().c_str()):obj["isevbfail"].get<double>());
        }
        if(obj.contains("evbpressure"))
        {
            msg.evbpressure = (obj["evbpressure"].is_string()?atof(obj["evbpressure"].get<std::string>().c_str()):obj["evbpressure"].get<double>());
        }
        if(obj.contains("brakepressure"))
        {
            msg.brakepressure = (obj["brakepressure"].is_string()?atof(obj["brakepressure"].get<std::string>().c_str()):obj["brakepressure"].get<double>());
        }
        if(obj.contains("brakepressurespd"))
        {
            msg.brakepressurespd = (obj["brakepressurespd"].is_string()?atof(obj["brakepressurespd"].get<std::string>().c_str()):obj["brakepressurespd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusDeceleration from_json<ApollocanbusDeceleration>(nlohmann::json obj){
        return from_json_ApollocanbusDeceleration(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDeceleration &dt)
    {
        dt=from_json_ApollocanbusDeceleration(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDeceleration & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDeceleration & dt)
    {
        os << to_json(dt);
        return os;
    }
}
