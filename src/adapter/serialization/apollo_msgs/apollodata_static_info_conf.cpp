#include "adapter/serialization/apollo_msgs/apollodata_static_info_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataStaticInfoConf &msg) {
        nlohmann::json obj;
        nlohmann::json arr_hardwareconfigs;
        for (auto it = msg.hardwareconfigs.begin(); it != msg.hardwareconfigs.end(); ++it) {
            arr_hardwareconfigs.push_back((*it));
        }
        obj["hardwareconfigs"] = arr_hardwareconfigs;
        nlohmann::json arr_softwareconfigs;
        for (auto it = msg.softwareconfigs.begin(); it != msg.softwareconfigs.end(); ++it) {
            arr_softwareconfigs.push_back((*it));
        }
        obj["softwareconfigs"] = arr_softwareconfigs;
        return obj;
    }
    ApollodataStaticInfoConf from_json_ApollodataStaticInfoConf (nlohmann::json obj) {
        ApollodataStaticInfoConf msg;
        if(obj.contains("hardwareconfigs"))
        {
            if(obj["hardwareconfigs"].is_array())
            {
                for (auto& element : obj["hardwareconfigs"])
                {
                    msg.hardwareconfigs.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.hardwareconfigs.push_back((obj["hardwareconfigs"].is_string()?(obj["hardwareconfigs"].get<std::string>().c_str()):obj["hardwareconfigs"].get<std::string>()));
            }
        }
        if(obj.contains("softwareconfigs"))
        {
            if(obj["softwareconfigs"].is_array())
            {
                for (auto& element : obj["softwareconfigs"])
                {
                    msg.softwareconfigs.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.softwareconfigs.push_back((obj["softwareconfigs"].is_string()?(obj["softwareconfigs"].get<std::string>().c_str()):obj["softwareconfigs"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApollodataStaticInfoConf from_json<ApollodataStaticInfoConf>(nlohmann::json obj){
        return from_json_ApollodataStaticInfoConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataStaticInfoConf &dt)
    {
        dt=from_json_ApollodataStaticInfoConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataStaticInfoConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataStaticInfoConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
