#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigConfig &msg) {
        nlohmann::json obj;
        obj["data"] = to_json(msg.data);
        obj["command"] = to_json(msg.command);
        obj["rtkfrom"] = to_json(msg.rtkfrom);
        obj["rtkto"] = to_json(msg.rtkto);
        nlohmann::json arr_logincommands;
        for (auto it = msg.logincommands.begin(); it != msg.logincommands.end(); ++it) {
            arr_logincommands.push_back(to_json(*it));
        }
        obj["logincommands"] = arr_logincommands;
        nlohmann::json arr_logoutcommands;
        for (auto it = msg.logoutcommands.begin(); it != msg.logoutcommands.end(); ++it) {
            arr_logoutcommands.push_back(to_json(*it));
        }
        obj["logoutcommands"] = arr_logoutcommands;
        obj["deviceconfig"] = to_json(msg.deviceconfig);
        obj["rtksolutiontype"] = (msg.rtksolutiontype);
        obj["imutype"] = (msg.imutype);
        obj["proj4text"] = (msg.proj4text);
        obj["tf"] = to_json(msg.tf);
        obj["wheelparameters"] = (msg.wheelparameters);
        obj["gpsbinfolder"] = (msg.gpsbinfolder);
        return obj;
    }
    ApollodriversgnssconfigConfig from_json_ApollodriversgnssconfigConfig (nlohmann::json obj) {
        ApollodriversgnssconfigConfig msg;
        if(obj.contains("data"))
        {
            msg.data = from_json_ApollodriversgnssconfigStream(obj["data"]);
        }
        if(obj.contains("command"))
        {
            msg.command = from_json_ApollodriversgnssconfigStream(obj["command"]);
        }
        if(obj.contains("rtkfrom"))
        {
            msg.rtkfrom = from_json_ApollodriversgnssconfigStream(obj["rtkfrom"]);
        }
        if(obj.contains("rtkto"))
        {
            msg.rtkto = from_json_ApollodriversgnssconfigStream(obj["rtkto"]);
        }
        if(obj.contains("logincommands"))
        {
            if(obj["logincommands"].is_array())
            {
                for (auto& element : obj["logincommands"])
                {
                    msg.logincommands.push_back(from_json_Bytes(element));
                }
            }
            else
            {
                msg.logincommands.push_back(from_json_Bytes(obj["logincommands"]));
            }
        }
        if(obj.contains("logoutcommands"))
        {
            if(obj["logoutcommands"].is_array())
            {
                for (auto& element : obj["logoutcommands"])
                {
                    msg.logoutcommands.push_back(from_json_Bytes(element));
                }
            }
            else
            {
                msg.logoutcommands.push_back(from_json_Bytes(obj["logoutcommands"]));
            }
        }
        if(obj.contains("deviceconfig"))
        {
            msg.deviceconfig = from_json_ApollodriversgnssconfigConfigdeviceConfig(obj["deviceconfig"]);
        }
        if(obj.contains("rtksolutiontype"))
        {
            msg.rtksolutiontype = (obj["rtksolutiontype"].is_string()?atoi(obj["rtksolutiontype"].get<std::string>().c_str()):obj["rtksolutiontype"].get<int>());
        }
        if(obj.contains("imutype"))
        {
            msg.imutype = (obj["imutype"].is_string()?atoi(obj["imutype"].get<std::string>().c_str()):obj["imutype"].get<int>());
        }
        if(obj.contains("proj4text"))
        {
            msg.proj4text = (obj["proj4text"].is_string()?(obj["proj4text"].get<std::string>().c_str()):obj["proj4text"].get<std::string>());
        }
        if(obj.contains("tf"))
        {
            msg.tf = from_json_ApollodriversgnssconfigTF(obj["tf"]);
        }
        if(obj.contains("wheelparameters"))
        {
            msg.wheelparameters = (obj["wheelparameters"].is_string()?(obj["wheelparameters"].get<std::string>().c_str()):obj["wheelparameters"].get<std::string>());
        }
        if(obj.contains("gpsbinfolder"))
        {
            msg.gpsbinfolder = (obj["gpsbinfolder"].is_string()?(obj["gpsbinfolder"].get<std::string>().c_str()):obj["gpsbinfolder"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigConfig from_json<ApollodriversgnssconfigConfig>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigConfig &dt)
    {
        dt=from_json_ApollodriversgnssconfigConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
