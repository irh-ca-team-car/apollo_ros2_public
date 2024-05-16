#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dummy_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDummyDataParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_datafiller;
        for (auto it = msg.datafiller.begin(); it != msg.datafiller.end(); ++it) {
            arr_datafiller.push_back(to_json(*it));
        }
        obj["datafiller"] = arr_datafiller;
        nlohmann::json arr_shape;
        for (auto it = msg.shape.begin(); it != msg.shape.end(); ++it) {
            arr_shape.push_back(to_json(*it));
        }
        obj["shape"] = arr_shape;
        nlohmann::json arr_num;
        for (auto it = msg.num.begin(); it != msg.num.end(); ++it) {
            arr_num.push_back((*it));
        }
        obj["num"] = arr_num;
        nlohmann::json arr_channels;
        for (auto it = msg.channels.begin(); it != msg.channels.end(); ++it) {
            arr_channels.push_back((*it));
        }
        obj["channels"] = arr_channels;
        nlohmann::json arr_height;
        for (auto it = msg.height.begin(); it != msg.height.end(); ++it) {
            arr_height.push_back((*it));
        }
        obj["height"] = arr_height;
        nlohmann::json arr_width;
        for (auto it = msg.width.begin(); it != msg.width.end(); ++it) {
            arr_width.push_back((*it));
        }
        obj["width"] = arr_width;
        return obj;
    }
    ApolloperceptioninferenceDummyDataParameter from_json_ApolloperceptioninferenceDummyDataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDummyDataParameter msg;
        if(obj.contains("datafiller"))
        {
            if(obj["datafiller"].is_array())
            {
                for (auto& element : obj["datafiller"])
                {
                    msg.datafiller.push_back(from_json_ApolloperceptioninferenceFillerParameter(element));
                }
            }
            else
            {
                msg.datafiller.push_back(from_json_ApolloperceptioninferenceFillerParameter(obj["datafiller"]));
            }
        }
        if(obj.contains("shape"))
        {
            if(obj["shape"].is_array())
            {
                for (auto& element : obj["shape"])
                {
                    msg.shape.push_back(from_json_ApolloperceptioninferenceBlobShape(element));
                }
            }
            else
            {
                msg.shape.push_back(from_json_ApolloperceptioninferenceBlobShape(obj["shape"]));
            }
        }
        if(obj.contains("num"))
        {
            if(obj["num"].is_array())
            {
                for (auto& element : obj["num"])
                {
                    msg.num.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.num.push_back((obj["num"].is_string()?atoi(obj["num"].get<std::string>().c_str()):obj["num"].get<uint32_t>()));
            }
        }
        if(obj.contains("channels"))
        {
            if(obj["channels"].is_array())
            {
                for (auto& element : obj["channels"])
                {
                    msg.channels.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.channels.push_back((obj["channels"].is_string()?atoi(obj["channels"].get<std::string>().c_str()):obj["channels"].get<uint32_t>()));
            }
        }
        if(obj.contains("height"))
        {
            if(obj["height"].is_array())
            {
                for (auto& element : obj["height"])
                {
                    msg.height.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.height.push_back((obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<uint32_t>()));
            }
        }
        if(obj.contains("width"))
        {
            if(obj["width"].is_array())
            {
                for (auto& element : obj["width"])
                {
                    msg.width.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.width.push_back((obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<uint32_t>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDummyDataParameter from_json<ApolloperceptioninferenceDummyDataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDummyDataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDummyDataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDummyDataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDummyDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDummyDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
