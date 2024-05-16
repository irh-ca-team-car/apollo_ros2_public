#include "adapter/serialization/apollo_msgs/apollodata_software_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSoftwareInfo &msg) {
        nlohmann::json obj;
        obj["dockerimage"] = (msg.dockerimage);
        obj["commitid"] = (msg.commitid);
        obj["mode"] = (msg.mode);
        nlohmann::json arr_configs;
        for (auto it = msg.configs.begin(); it != msg.configs.end(); ++it) {
            arr_configs.push_back(to_json(*it));
        }
        obj["configs"] = arr_configs;
        obj["latestroutingrequest"] = to_json(msg.latestroutingrequest);
        return obj;
    }
    ApollodataSoftwareInfo from_json_ApollodataSoftwareInfo (nlohmann::json obj) {
        ApollodataSoftwareInfo msg;
        if(obj.contains("dockerimage"))
        {
            msg.dockerimage = (obj["dockerimage"].is_string()?(obj["dockerimage"].get<std::string>().c_str()):obj["dockerimage"].get<std::string>());
        }
        if(obj.contains("commitid"))
        {
            msg.commitid = (obj["commitid"].is_string()?(obj["commitid"].get<std::string>().c_str()):obj["commitid"].get<std::string>());
        }
        if(obj.contains("mode"))
        {
            msg.mode = (obj["mode"].is_string()?(obj["mode"].get<std::string>().c_str()):obj["mode"].get<std::string>());
        }
        if(obj.contains("configs"))
        {
            if(obj["configs"].is_array())
            {
                for (auto& element : obj["configs"])
                {
                    msg.configs.push_back(from_json_ApollodataSoftwareInfoconfigs(element));
                }
            }
            else
            {
                msg.configs.push_back(from_json_ApollodataSoftwareInfoconfigs(obj["configs"]));
            }
        }
        if(obj.contains("latestroutingrequest"))
        {
            msg.latestroutingrequest = from_json_ApolloroutingRoutingRequest(obj["latestroutingrequest"]);
        }
        return msg;
    }
    template <>
    ApollodataSoftwareInfo from_json<ApollodataSoftwareInfo>(nlohmann::json obj){
        return from_json_ApollodataSoftwareInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSoftwareInfo &dt)
    {
        dt=from_json_ApollodataSoftwareInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataSoftwareInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSoftwareInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
