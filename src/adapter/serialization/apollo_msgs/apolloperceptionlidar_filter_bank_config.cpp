#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_filter_bank_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarFilterBankConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_filtername;
        for (auto it = msg.filtername.begin(); it != msg.filtername.end(); ++it) {
            arr_filtername.push_back((*it));
        }
        obj["filtername"] = arr_filtername;
        return obj;
    }
    ApolloperceptionlidarFilterBankConfig from_json_ApolloperceptionlidarFilterBankConfig (nlohmann::json obj) {
        ApolloperceptionlidarFilterBankConfig msg;
        if(obj.contains("filtername"))
        {
            if(obj["filtername"].is_array())
            {
                for (auto& element : obj["filtername"])
                {
                    msg.filtername.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.filtername.push_back((obj["filtername"].is_string()?(obj["filtername"].get<std::string>().c_str()):obj["filtername"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarFilterBankConfig from_json<ApolloperceptionlidarFilterBankConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarFilterBankConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarFilterBankConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarFilterBankConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarFilterBankConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarFilterBankConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
