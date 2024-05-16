#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_tf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigTF &msg) {
        nlohmann::json obj;
        obj["frameid"] = (msg.frameid);
        obj["childframeid"] = (msg.childframeid);
        obj["enable"] = (msg.enable);
        return obj;
    }
    ApollodriversgnssconfigTF from_json_ApollodriversgnssconfigTF (nlohmann::json obj) {
        ApollodriversgnssconfigTF msg;
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("childframeid"))
        {
            msg.childframeid = (obj["childframeid"].is_string()?(obj["childframeid"].get<std::string>().c_str()):obj["childframeid"].get<std::string>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigTF from_json<ApollodriversgnssconfigTF>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigTF(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigTF &dt)
    {
        dt=from_json_ApollodriversgnssconfigTF(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigTF & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigTF & dt)
    {
        os << to_json(dt);
        return os;
    }
}
