#include "adapter/serialization/apollo_msgs/apollocontrolcalibrationtable_control_calibration_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolcalibrationtableControlCalibrationInfo &msg) {
        nlohmann::json obj;
        obj["speed"] = (msg.speed);
        obj["acceleration"] = (msg.acceleration);
        obj["command"] = (msg.command);
        return obj;
    }
    ApollocontrolcalibrationtableControlCalibrationInfo from_json_ApollocontrolcalibrationtableControlCalibrationInfo (nlohmann::json obj) {
        ApollocontrolcalibrationtableControlCalibrationInfo msg;
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        if(obj.contains("acceleration"))
        {
            msg.acceleration = (obj["acceleration"].is_string()?atof(obj["acceleration"].get<std::string>().c_str()):obj["acceleration"].get<double>());
        }
        if(obj.contains("command"))
        {
            msg.command = (obj["command"].is_string()?atof(obj["command"].get<std::string>().c_str()):obj["command"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolcalibrationtableControlCalibrationInfo from_json<ApollocontrolcalibrationtableControlCalibrationInfo>(nlohmann::json obj){
        return from_json_ApollocontrolcalibrationtableControlCalibrationInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolcalibrationtableControlCalibrationInfo &dt)
    {
        dt=from_json_ApollocontrolcalibrationtableControlCalibrationInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolcalibrationtableControlCalibrationInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolcalibrationtableControlCalibrationInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
