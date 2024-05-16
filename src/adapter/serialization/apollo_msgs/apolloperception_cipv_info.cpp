#include "adapter/serialization/apollo_msgs/apolloperception_cipv_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionCIPVInfo &msg) {
        nlohmann::json obj;
        obj["cipvid"] = (msg.cipvid);
        nlohmann::json arr_potentialcipvid;
        for (auto it = msg.potentialcipvid.begin(); it != msg.potentialcipvid.end(); ++it) {
            arr_potentialcipvid.push_back((*it));
        }
        obj["potentialcipvid"] = arr_potentialcipvid;
        return obj;
    }
    ApolloperceptionCIPVInfo from_json_ApolloperceptionCIPVInfo (nlohmann::json obj) {
        ApolloperceptionCIPVInfo msg;
        if(obj.contains("cipvid"))
        {
            msg.cipvid = (obj["cipvid"].is_string()?atoi(obj["cipvid"].get<std::string>().c_str()):obj["cipvid"].get<int>());
        }
        if(obj.contains("potentialcipvid"))
        {
            if(obj["potentialcipvid"].is_array())
            {
                for (auto& element : obj["potentialcipvid"])
                {
                    msg.potentialcipvid.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.potentialcipvid.push_back((obj["potentialcipvid"].is_string()?atoi(obj["potentialcipvid"].get<std::string>().c_str()):obj["potentialcipvid"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionCIPVInfo from_json<ApolloperceptionCIPVInfo>(nlohmann::json obj){
        return from_json_ApolloperceptionCIPVInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionCIPVInfo &dt)
    {
        dt=from_json_ApolloperceptionCIPVInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionCIPVInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionCIPVInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
