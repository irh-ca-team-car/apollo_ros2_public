#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Bytes &msg) {
        std::string s(msg.data.begin(), msg.data.end());
        nlohmann::json obj(s);
        return obj;
    }
    Bytes from_json_Bytes (nlohmann::json obj) {
        Bytes msg;
        if(obj.is_string())
        {
            std::string str = obj.get<std::string>().c_str();
            for (auto& element : str)
                msg.data.push_back(element);
        }
        if(obj.contains("data"))
        {
            if(obj["data"].is_array())
            {
                for (auto& element : obj["data"])
                {
                    msg.data.push_back((element.is_string()?(uint8_t)atoi(element.get<std::string>().c_str()):element.get<uint8_t>()));
                }
            }
            else
            {
                msg.data.push_back((obj["data"].is_string()?(uint8_t)atoi(obj["data"].get<std::string>().c_str()):obj["data"].get<uint8_t>()));
            }
        }
        return msg;
    }
    template <>
    Bytes from_json<Bytes>(nlohmann::json obj){
        return from_json_Bytes(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Bytes &dt)
    {
        dt=from_json_Bytes(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Bytes & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Bytes & dt)
    {
        os << to_json(dt);
        return os;
    }
}
