#include "adapter/serialization/apollo_msgs/apollodata_trigger.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataTrigger &msg) {
        nlohmann::json obj;
        obj["triggername"] = (msg.triggername);
        obj["enabled"] = (msg.enabled);
        obj["backwardtime"] = (msg.backwardtime);
        obj["forwardtime"] = (msg.forwardtime);
        obj["description"] = (msg.description);
        return obj;
    }
    ApollodataTrigger from_json_ApollodataTrigger (nlohmann::json obj) {
        ApollodataTrigger msg;
        if(obj.contains("triggername"))
        {
            msg.triggername = (obj["triggername"].is_string()?(obj["triggername"].get<std::string>().c_str()):obj["triggername"].get<std::string>());
        }
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
        if(obj.contains("backwardtime"))
        {
            msg.backwardtime = (obj["backwardtime"].is_string()?atof(obj["backwardtime"].get<std::string>().c_str()):obj["backwardtime"].get<double>());
        }
        if(obj.contains("forwardtime"))
        {
            msg.forwardtime = (obj["forwardtime"].is_string()?atof(obj["forwardtime"].get<std::string>().c_str()):obj["forwardtime"].get<double>());
        }
        if(obj.contains("description"))
        {
            msg.description = (obj["description"].is_string()?(obj["description"].get<std::string>().c_str()):obj["description"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodataTrigger from_json<ApollodataTrigger>(nlohmann::json obj){
        return from_json_ApollodataTrigger(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataTrigger &dt)
    {
        dt=from_json_ApollodataTrigger(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataTrigger & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataTrigger & dt)
    {
        os << to_json(dt);
        return os;
    }
}
