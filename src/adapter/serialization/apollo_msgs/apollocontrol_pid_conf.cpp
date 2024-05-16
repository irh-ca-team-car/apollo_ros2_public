#include "adapter/serialization/apollo_msgs/apollocontrol_pid_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolPidConf &msg) {
        nlohmann::json obj;
        obj["integratorenable"] = (msg.integratorenable);
        obj["integratorsaturationlevel"] = (msg.integratorsaturationlevel);
        obj["kp"] = (msg.kp);
        obj["ki"] = (msg.ki);
        obj["kd"] = (msg.kd);
        obj["kaw"] = (msg.kaw);
        obj["outputsaturationlevel"] = (msg.outputsaturationlevel);
        return obj;
    }
    ApollocontrolPidConf from_json_ApollocontrolPidConf (nlohmann::json obj) {
        ApollocontrolPidConf msg;
        if(obj.contains("integratorenable"))
        {
            msg.integratorenable = (obj["integratorenable"].is_string()?(bool)atoi(obj["integratorenable"].get<std::string>().c_str()):obj["integratorenable"].get<bool>());
        }
        if(obj.contains("integratorsaturationlevel"))
        {
            msg.integratorsaturationlevel = (obj["integratorsaturationlevel"].is_string()?atof(obj["integratorsaturationlevel"].get<std::string>().c_str()):obj["integratorsaturationlevel"].get<double>());
        }
        if(obj.contains("kp"))
        {
            msg.kp = (obj["kp"].is_string()?atof(obj["kp"].get<std::string>().c_str()):obj["kp"].get<double>());
        }
        if(obj.contains("ki"))
        {
            msg.ki = (obj["ki"].is_string()?atof(obj["ki"].get<std::string>().c_str()):obj["ki"].get<double>());
        }
        if(obj.contains("kd"))
        {
            msg.kd = (obj["kd"].is_string()?atof(obj["kd"].get<std::string>().c_str()):obj["kd"].get<double>());
        }
        if(obj.contains("kaw"))
        {
            msg.kaw = (obj["kaw"].is_string()?atof(obj["kaw"].get<std::string>().c_str()):obj["kaw"].get<double>());
        }
        if(obj.contains("outputsaturationlevel"))
        {
            msg.outputsaturationlevel = (obj["outputsaturationlevel"].is_string()?atof(obj["outputsaturationlevel"].get<std::string>().c_str()):obj["outputsaturationlevel"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolPidConf from_json<ApollocontrolPidConf>(nlohmann::json obj){
        return from_json_ApollocontrolPidConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolPidConf &dt)
    {
        dt=from_json_ApollocontrolPidConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolPidConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolPidConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
