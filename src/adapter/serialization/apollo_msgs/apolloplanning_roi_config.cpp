#include "adapter/serialization/apollo_msgs/apolloplanning_roi_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningROIConfig &msg) {
        nlohmann::json obj;
        obj["roilongitudinalrangestart"] = (msg.roilongitudinalrangestart);
        obj["roilongitudinalrangeend"] = (msg.roilongitudinalrangeend);
        obj["parkingstartrange"] = (msg.parkingstartrange);
        obj["parkinginwards"] = (msg.parkinginwards);
        return obj;
    }
    ApolloplanningROIConfig from_json_ApolloplanningROIConfig (nlohmann::json obj) {
        ApolloplanningROIConfig msg;
        if(obj.contains("roilongitudinalrangestart"))
        {
            msg.roilongitudinalrangestart = (obj["roilongitudinalrangestart"].is_string()?atof(obj["roilongitudinalrangestart"].get<std::string>().c_str()):obj["roilongitudinalrangestart"].get<double>());
        }
        if(obj.contains("roilongitudinalrangeend"))
        {
            msg.roilongitudinalrangeend = (obj["roilongitudinalrangeend"].is_string()?atof(obj["roilongitudinalrangeend"].get<std::string>().c_str()):obj["roilongitudinalrangeend"].get<double>());
        }
        if(obj.contains("parkingstartrange"))
        {
            msg.parkingstartrange = (obj["parkingstartrange"].is_string()?atof(obj["parkingstartrange"].get<std::string>().c_str()):obj["parkingstartrange"].get<double>());
        }
        if(obj.contains("parkinginwards"))
        {
            msg.parkinginwards = (obj["parkinginwards"].is_string()?(bool)atoi(obj["parkinginwards"].get<std::string>().c_str()):obj["parkinginwards"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningROIConfig from_json<ApolloplanningROIConfig>(nlohmann::json obj){
        return from_json_ApolloplanningROIConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningROIConfig &dt)
    {
        dt=from_json_ApolloplanningROIConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningROIConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningROIConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
