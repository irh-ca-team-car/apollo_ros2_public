#include "adapter/serialization/apollo_msgs/apollodata_software_infoconfigs.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSoftwareInfoconfigs &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = (msg.data);
        return obj;
    }
    ApollodataSoftwareInfoconfigs from_json_ApollodataSoftwareInfoconfigs (nlohmann::json obj) {
        ApollodataSoftwareInfoconfigs msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?(obj["key"].get<std::string>().c_str()):obj["key"].get<std::string>());
        }
        if(obj.contains("data"))
        {
            msg.data = (obj["data"].is_string()?(obj["data"].get<std::string>().c_str()):obj["data"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodataSoftwareInfoconfigs from_json<ApollodataSoftwareInfoconfigs>(nlohmann::json obj){
        return from_json_ApollodataSoftwareInfoconfigs(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSoftwareInfoconfigs &dt)
    {
        dt=from_json_ApollodataSoftwareInfoconfigs(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataSoftwareInfoconfigs & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSoftwareInfoconfigs & dt)
    {
        os << to_json(dt);
        return os;
    }
}
