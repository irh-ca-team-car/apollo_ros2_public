#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_b_box_statistics.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeBBoxStatistics &msg) {
        nlohmann::json obj;
        nlohmann::json arr_mean;
        for (auto it = msg.mean.begin(); it != msg.mean.end(); ++it) {
            arr_mean.push_back((*it));
        }
        obj["mean"] = arr_mean;
        nlohmann::json arr_std;
        for (auto it = msg.std.begin(); it != msg.std.end(); ++it) {
            arr_std.push_back((*it));
        }
        obj["std"] = arr_std;
        return obj;
    }
    ApolloperceptioncamerasmokeBBoxStatistics from_json_ApolloperceptioncamerasmokeBBoxStatistics (nlohmann::json obj) {
        ApolloperceptioncamerasmokeBBoxStatistics msg;
        if(obj.contains("mean"))
        {
            if(obj["mean"].is_array())
            {
                for (auto& element : obj["mean"])
                {
                    msg.mean.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.mean.push_back((obj["mean"].is_string()?(float)atof(obj["mean"].get<std::string>().c_str()):obj["mean"].get<float>()));
            }
        }
        if(obj.contains("std"))
        {
            if(obj["std"].is_array())
            {
                for (auto& element : obj["std"])
                {
                    msg.std.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.std.push_back((obj["std"].is_string()?(float)atof(obj["std"].get<std::string>().c_str()):obj["std"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioncamerasmokeBBoxStatistics from_json<ApolloperceptioncamerasmokeBBoxStatistics>(nlohmann::json obj){
        return from_json_ApolloperceptioncamerasmokeBBoxStatistics(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeBBoxStatistics &dt)
    {
        dt=from_json_ApolloperceptioncamerasmokeBBoxStatistics(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeBBoxStatistics & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeBBoxStatistics & dt)
    {
        os << to_json(dt);
        return os;
    }
}
