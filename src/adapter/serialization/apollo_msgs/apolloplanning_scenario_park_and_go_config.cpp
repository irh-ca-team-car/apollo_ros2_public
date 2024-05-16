#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_park_and_go_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioParkAndGoConfig &msg) {
        nlohmann::json obj;
        obj["frontobstaclebuffer"] = (msg.frontobstaclebuffer);
        obj["headingbuffer"] = (msg.headingbuffer);
        obj["mindisttodest"] = (msg.mindisttodest);
        obj["maxsteeringpercentagewhencruise"] = (msg.maxsteeringpercentagewhencruise);
        return obj;
    }
    ApolloplanningScenarioParkAndGoConfig from_json_ApolloplanningScenarioParkAndGoConfig (nlohmann::json obj) {
        ApolloplanningScenarioParkAndGoConfig msg;
        if(obj.contains("frontobstaclebuffer"))
        {
            msg.frontobstaclebuffer = (obj["frontobstaclebuffer"].is_string()?atof(obj["frontobstaclebuffer"].get<std::string>().c_str()):obj["frontobstaclebuffer"].get<double>());
        }
        if(obj.contains("headingbuffer"))
        {
            msg.headingbuffer = (obj["headingbuffer"].is_string()?atof(obj["headingbuffer"].get<std::string>().c_str()):obj["headingbuffer"].get<double>());
        }
        if(obj.contains("mindisttodest"))
        {
            msg.mindisttodest = (obj["mindisttodest"].is_string()?atof(obj["mindisttodest"].get<std::string>().c_str()):obj["mindisttodest"].get<double>());
        }
        if(obj.contains("maxsteeringpercentagewhencruise"))
        {
            msg.maxsteeringpercentagewhencruise = (obj["maxsteeringpercentagewhencruise"].is_string()?atof(obj["maxsteeringpercentagewhencruise"].get<std::string>().c_str()):obj["maxsteeringpercentagewhencruise"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioParkAndGoConfig from_json<ApolloplanningScenarioParkAndGoConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioParkAndGoConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioParkAndGoConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioParkAndGoConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioParkAndGoConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioParkAndGoConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
