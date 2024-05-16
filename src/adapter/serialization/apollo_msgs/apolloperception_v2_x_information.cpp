#include "adapter/serialization/apollo_msgs/apolloperception_v2_x_information.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionV2XInformation &msg) {
        nlohmann::json obj;
        nlohmann::json arr_v2xtype;
        for (auto it = msg.v2xtype.begin(); it != msg.v2xtype.end(); ++it) {
            arr_v2xtype.push_back((*it));
        }
        obj["v2xtype"] = arr_v2xtype;
        return obj;
    }
    ApolloperceptionV2XInformation from_json_ApolloperceptionV2XInformation (nlohmann::json obj) {
        ApolloperceptionV2XInformation msg;
        if(obj.contains("v2xtype"))
        {
            if(obj["v2xtype"].is_array())
            {
                for (auto& element : obj["v2xtype"])
                {
                    msg.v2xtype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.v2xtype.push_back((obj["v2xtype"].is_string()?atoi(obj["v2xtype"].get<std::string>().c_str()):obj["v2xtype"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionV2XInformation from_json<ApolloperceptionV2XInformation>(nlohmann::json obj){
        return from_json_ApolloperceptionV2XInformation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionV2XInformation &dt)
    {
        dt=from_json_ApolloperceptionV2XInformation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionV2XInformation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionV2XInformation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
