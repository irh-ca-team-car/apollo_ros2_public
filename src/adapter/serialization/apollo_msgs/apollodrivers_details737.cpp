#include "adapter/serialization/apollo_msgs/apollodrivers_details737.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails737 &msg) {
        nlohmann::json obj;
        obj["lanecurvature"] = (msg.lanecurvature);
        obj["laneheading"] = (msg.laneheading);
        obj["caconstructionarea"] = (msg.caconstructionarea);
        obj["rightldwavailability"] = (msg.rightldwavailability);
        obj["leftldwavailability"] = (msg.leftldwavailability);
        obj["reserved1"] = (msg.reserved1);
        obj["yawangle"] = (msg.yawangle);
        obj["pitchangle"] = (msg.pitchangle);
        return obj;
    }
    ApollodriversDetails737 from_json_ApollodriversDetails737 (nlohmann::json obj) {
        ApollodriversDetails737 msg;
        if(obj.contains("lanecurvature"))
        {
            msg.lanecurvature = (obj["lanecurvature"].is_string()?atof(obj["lanecurvature"].get<std::string>().c_str()):obj["lanecurvature"].get<double>());
        }
        if(obj.contains("laneheading"))
        {
            msg.laneheading = (obj["laneheading"].is_string()?atof(obj["laneheading"].get<std::string>().c_str()):obj["laneheading"].get<double>());
        }
        if(obj.contains("caconstructionarea"))
        {
            msg.caconstructionarea = (obj["caconstructionarea"].is_string()?(bool)atoi(obj["caconstructionarea"].get<std::string>().c_str()):obj["caconstructionarea"].get<bool>());
        }
        if(obj.contains("rightldwavailability"))
        {
            msg.rightldwavailability = (obj["rightldwavailability"].is_string()?(bool)atoi(obj["rightldwavailability"].get<std::string>().c_str()):obj["rightldwavailability"].get<bool>());
        }
        if(obj.contains("leftldwavailability"))
        {
            msg.leftldwavailability = (obj["leftldwavailability"].is_string()?(bool)atoi(obj["leftldwavailability"].get<std::string>().c_str()):obj["leftldwavailability"].get<bool>());
        }
        if(obj.contains("reserved1"))
        {
            msg.reserved1 = (obj["reserved1"].is_string()?(bool)atoi(obj["reserved1"].get<std::string>().c_str()):obj["reserved1"].get<bool>());
        }
        if(obj.contains("yawangle"))
        {
            msg.yawangle = (obj["yawangle"].is_string()?atof(obj["yawangle"].get<std::string>().c_str()):obj["yawangle"].get<double>());
        }
        if(obj.contains("pitchangle"))
        {
            msg.pitchangle = (obj["pitchangle"].is_string()?atof(obj["pitchangle"].get<std::string>().c_str()):obj["pitchangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversDetails737 from_json<ApollodriversDetails737>(nlohmann::json obj){
        return from_json_ApollodriversDetails737(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails737 &dt)
    {
        dt=from_json_ApollodriversDetails737(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails737 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails737 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
