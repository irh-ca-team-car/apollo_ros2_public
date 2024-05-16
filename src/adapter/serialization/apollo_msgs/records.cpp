#include "adapter/serialization/apollo_msgs/records.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Records &msg) {
        nlohmann::json obj;
        nlohmann::json arr_recordpath;
        for (auto it = msg.recordpath.begin(); it != msg.recordpath.end(); ++it) {
            arr_recordpath.push_back((*it));
        }
        obj["recordpath"] = arr_recordpath;
        return obj;
    }
    Records from_json_Records (nlohmann::json obj) {
        Records msg;
        if(obj.contains("recordpath"))
        {
            if(obj["recordpath"].is_array())
            {
                for (auto& element : obj["recordpath"])
                {
                    msg.recordpath.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.recordpath.push_back((obj["recordpath"].is_string()?(obj["recordpath"].get<std::string>().c_str()):obj["recordpath"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    Records from_json<Records>(nlohmann::json obj){
        return from_json_Records(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Records &dt)
    {
        dt=from_json_Records(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Records & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Records & dt)
    {
        os << to_json(dt);
        return os;
    }
}
