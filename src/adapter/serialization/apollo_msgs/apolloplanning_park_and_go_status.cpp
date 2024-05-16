#include "adapter/serialization/apollo_msgs/apolloplanning_park_and_go_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningParkAndGoStatus &msg) {
        nlohmann::json obj;
        obj["adcinitposition"] = to_json(msg.adcinitposition);
        obj["adcinitheading"] = (msg.adcinitheading);
        obj["incheckstage"] = (msg.incheckstage);
        obj["adcadjustendpose"] = to_json(msg.adcadjustendpose);
        return obj;
    }
    ApolloplanningParkAndGoStatus from_json_ApolloplanningParkAndGoStatus (nlohmann::json obj) {
        ApolloplanningParkAndGoStatus msg;
        if(obj.contains("adcinitposition"))
        {
            msg.adcinitposition = from_json_ApollocommonPointENU(obj["adcinitposition"]);
        }
        if(obj.contains("adcinitheading"))
        {
            msg.adcinitheading = (obj["adcinitheading"].is_string()?atof(obj["adcinitheading"].get<std::string>().c_str()):obj["adcinitheading"].get<double>());
        }
        if(obj.contains("incheckstage"))
        {
            msg.incheckstage = (obj["incheckstage"].is_string()?(bool)atoi(obj["incheckstage"].get<std::string>().c_str()):obj["incheckstage"].get<bool>());
        }
        if(obj.contains("adcadjustendpose"))
        {
            msg.adcadjustendpose = from_json_ApollocommonPointENU(obj["adcadjustendpose"]);
        }
        return msg;
    }
    template <>
    ApolloplanningParkAndGoStatus from_json<ApolloplanningParkAndGoStatus>(nlohmann::json obj){
        return from_json_ApolloplanningParkAndGoStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningParkAndGoStatus &dt)
    {
        dt=from_json_ApolloplanningParkAndGoStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningParkAndGoStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningParkAndGoStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
