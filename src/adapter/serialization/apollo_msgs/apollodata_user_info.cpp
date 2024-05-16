#include "adapter/serialization/apollo_msgs/apollodata_user_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataUserInfo &msg) {
        nlohmann::json obj;
        obj["entity"] = (msg.entity);
        obj["driver"] = (msg.driver);
        obj["codriver"] = (msg.codriver);
        return obj;
    }
    ApollodataUserInfo from_json_ApollodataUserInfo (nlohmann::json obj) {
        ApollodataUserInfo msg;
        if(obj.contains("entity"))
        {
            msg.entity = (obj["entity"].is_string()?(obj["entity"].get<std::string>().c_str()):obj["entity"].get<std::string>());
        }
        if(obj.contains("driver"))
        {
            msg.driver = (obj["driver"].is_string()?(obj["driver"].get<std::string>().c_str()):obj["driver"].get<std::string>());
        }
        if(obj.contains("codriver"))
        {
            msg.codriver = (obj["codriver"].is_string()?(obj["codriver"].get<std::string>().c_str()):obj["codriver"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodataUserInfo from_json<ApollodataUserInfo>(nlohmann::json obj){
        return from_json_ApollodataUserInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataUserInfo &dt)
    {
        dt=from_json_ApollodataUserInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataUserInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataUserInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
