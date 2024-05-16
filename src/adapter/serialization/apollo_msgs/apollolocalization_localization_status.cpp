#include "adapter/serialization/apollo_msgs/apollolocalization_localization_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationLocalizationStatus &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["fusionstatus"] = (msg.fusionstatus);
        obj["gnssstatus"] = (msg.gnssstatus);
        obj["lidarstatus"] = (msg.lidarstatus);
        obj["measurementtime"] = (msg.measurementtime);
        obj["statemessage"] = (msg.statemessage);
        return obj;
    }
    ApollolocalizationLocalizationStatus from_json_ApollolocalizationLocalizationStatus (nlohmann::json obj) {
        ApollolocalizationLocalizationStatus msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("fusionstatus"))
        {
            msg.fusionstatus = (obj["fusionstatus"].is_string()?atoi(obj["fusionstatus"].get<std::string>().c_str()):obj["fusionstatus"].get<int>());
        }
        if(obj.contains("gnssstatus"))
        {
            msg.gnssstatus = (obj["gnssstatus"].is_string()?atoi(obj["gnssstatus"].get<std::string>().c_str()):obj["gnssstatus"].get<int>());
        }
        if(obj.contains("lidarstatus"))
        {
            msg.lidarstatus = (obj["lidarstatus"].is_string()?atoi(obj["lidarstatus"].get<std::string>().c_str()):obj["lidarstatus"].get<int>());
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("statemessage"))
        {
            msg.statemessage = (obj["statemessage"].is_string()?(obj["statemessage"].get<std::string>().c_str()):obj["statemessage"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollolocalizationLocalizationStatus from_json<ApollolocalizationLocalizationStatus>(nlohmann::json obj){
        return from_json_ApollolocalizationLocalizationStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationLocalizationStatus &dt)
    {
        dt=from_json_ApollolocalizationLocalizationStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationLocalizationStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationLocalizationStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
