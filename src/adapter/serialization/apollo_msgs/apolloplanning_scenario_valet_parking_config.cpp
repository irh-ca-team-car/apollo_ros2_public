#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_valet_parking_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioValetParkingConfig &msg) {
        nlohmann::json obj;
        obj["parkingspotrangetostart"] = (msg.parkingspotrangetostart);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        return obj;
    }
    ApolloplanningScenarioValetParkingConfig from_json_ApolloplanningScenarioValetParkingConfig (nlohmann::json obj) {
        ApolloplanningScenarioValetParkingConfig msg;
        if(obj.contains("parkingspotrangetostart"))
        {
            msg.parkingspotrangetostart = (obj["parkingspotrangetostart"].is_string()?atof(obj["parkingspotrangetostart"].get<std::string>().c_str()):obj["parkingspotrangetostart"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioValetParkingConfig from_json<ApolloplanningScenarioValetParkingConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioValetParkingConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioValetParkingConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioValetParkingConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioValetParkingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioValetParkingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
