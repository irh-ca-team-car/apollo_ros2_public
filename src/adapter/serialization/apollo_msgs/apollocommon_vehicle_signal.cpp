#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_signal.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleSignal &msg) {
        nlohmann::json obj;
        obj["turnsignal"] = (msg.turnsignal);
        obj["highbeam"] = (msg.highbeam);
        obj["lowbeam"] = (msg.lowbeam);
        obj["horn"] = (msg.horn);
        obj["emergencylight"] = (msg.emergencylight);
        return obj;
    }
    ApollocommonVehicleSignal from_json_ApollocommonVehicleSignal (nlohmann::json obj) {
        ApollocommonVehicleSignal msg;
        if(obj.contains("turnsignal"))
        {
            msg.turnsignal = (obj["turnsignal"].is_string()?atoi(obj["turnsignal"].get<std::string>().c_str()):obj["turnsignal"].get<int>());
        }
        if(obj.contains("highbeam"))
        {
            msg.highbeam = (obj["highbeam"].is_string()?(bool)atoi(obj["highbeam"].get<std::string>().c_str()):obj["highbeam"].get<bool>());
        }
        if(obj.contains("lowbeam"))
        {
            msg.lowbeam = (obj["lowbeam"].is_string()?(bool)atoi(obj["lowbeam"].get<std::string>().c_str()):obj["lowbeam"].get<bool>());
        }
        if(obj.contains("horn"))
        {
            msg.horn = (obj["horn"].is_string()?(bool)atoi(obj["horn"].get<std::string>().c_str()):obj["horn"].get<bool>());
        }
        if(obj.contains("emergencylight"))
        {
            msg.emergencylight = (obj["emergencylight"].is_string()?(bool)atoi(obj["emergencylight"].get<std::string>().c_str()):obj["emergencylight"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocommonVehicleSignal from_json<ApollocommonVehicleSignal>(nlohmann::json obj){
        return from_json_ApollocommonVehicleSignal(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleSignal &dt)
    {
        dt=from_json_ApollocommonVehicleSignal(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
}
