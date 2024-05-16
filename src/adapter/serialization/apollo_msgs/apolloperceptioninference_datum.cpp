#include "adapter/serialization/apollo_msgs/apolloperceptioninference_datum.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDatum &msg) {
        nlohmann::json obj;
        obj["channels"] = (msg.channels);
        obj["height"] = (msg.height);
        obj["width"] = (msg.width);
        obj["data"] = to_json(msg.data);
        obj["label"] = (msg.label);
        nlohmann::json arr_floatdata;
        for (auto it = msg.floatdata.begin(); it != msg.floatdata.end(); ++it) {
            arr_floatdata.push_back((*it));
        }
        obj["floatdata"] = arr_floatdata;
        obj["encoded"] = (msg.encoded);
        return obj;
    }
    ApolloperceptioninferenceDatum from_json_ApolloperceptioninferenceDatum (nlohmann::json obj) {
        ApolloperceptioninferenceDatum msg;
        if(obj.contains("channels"))
        {
            msg.channels = (obj["channels"].is_string()?atoi(obj["channels"].get<std::string>().c_str()):obj["channels"].get<int>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<int>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<int>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_Bytes(obj["data"]);
        }
        if(obj.contains("label"))
        {
            msg.label = (obj["label"].is_string()?atoi(obj["label"].get<std::string>().c_str()):obj["label"].get<int>());
        }
        if(obj.contains("floatdata"))
        {
            if(obj["floatdata"].is_array())
            {
                for (auto& element : obj["floatdata"])
                {
                    msg.floatdata.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.floatdata.push_back((obj["floatdata"].is_string()?(float)atof(obj["floatdata"].get<std::string>().c_str()):obj["floatdata"].get<float>()));
            }
        }
        if(obj.contains("encoded"))
        {
            msg.encoded = (obj["encoded"].is_string()?(bool)atoi(obj["encoded"].get<std::string>().c_str()):obj["encoded"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDatum from_json<ApolloperceptioninferenceDatum>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDatum(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDatum &dt)
    {
        dt=from_json_ApolloperceptioninferenceDatum(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDatum & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDatum & dt)
    {
        os << to_json(dt);
        return os;
    }
}
