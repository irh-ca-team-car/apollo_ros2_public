#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_proto.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBlobProto &msg) {
        nlohmann::json obj;
        obj["shape"] = to_json(msg.shape);
        nlohmann::json arr_data;
        for (auto it = msg.data.begin(); it != msg.data.end(); ++it) {
            arr_data.push_back((*it));
        }
        obj["data"] = arr_data;
        nlohmann::json arr_diff;
        for (auto it = msg.diff.begin(); it != msg.diff.end(); ++it) {
            arr_diff.push_back((*it));
        }
        obj["diff"] = arr_diff;
        nlohmann::json arr_doubledata;
        for (auto it = msg.doubledata.begin(); it != msg.doubledata.end(); ++it) {
            arr_doubledata.push_back((*it));
        }
        obj["doubledata"] = arr_doubledata;
        nlohmann::json arr_doublediff;
        for (auto it = msg.doublediff.begin(); it != msg.doublediff.end(); ++it) {
            arr_doublediff.push_back((*it));
        }
        obj["doublediff"] = arr_doublediff;
        obj["num"] = (msg.num);
        obj["channels"] = (msg.channels);
        obj["height"] = (msg.height);
        obj["width"] = (msg.width);
        return obj;
    }
    ApolloperceptioninferenceBlobProto from_json_ApolloperceptioninferenceBlobProto (nlohmann::json obj) {
        ApolloperceptioninferenceBlobProto msg;
        if(obj.contains("shape"))
        {
            msg.shape = from_json_ApolloperceptioninferenceBlobShape(obj["shape"]);
        }
        if(obj.contains("data"))
        {
            if(obj["data"].is_array())
            {
                for (auto& element : obj["data"])
                {
                    msg.data.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.data.push_back((obj["data"].is_string()?(float)atof(obj["data"].get<std::string>().c_str()):obj["data"].get<float>()));
            }
        }
        if(obj.contains("diff"))
        {
            if(obj["diff"].is_array())
            {
                for (auto& element : obj["diff"])
                {
                    msg.diff.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.diff.push_back((obj["diff"].is_string()?(float)atof(obj["diff"].get<std::string>().c_str()):obj["diff"].get<float>()));
            }
        }
        if(obj.contains("doubledata"))
        {
            if(obj["doubledata"].is_array())
            {
                for (auto& element : obj["doubledata"])
                {
                    msg.doubledata.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.doubledata.push_back((obj["doubledata"].is_string()?atof(obj["doubledata"].get<std::string>().c_str()):obj["doubledata"].get<double>()));
            }
        }
        if(obj.contains("doublediff"))
        {
            if(obj["doublediff"].is_array())
            {
                for (auto& element : obj["doublediff"])
                {
                    msg.doublediff.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.doublediff.push_back((obj["doublediff"].is_string()?atof(obj["doublediff"].get<std::string>().c_str()):obj["doublediff"].get<double>()));
            }
        }
        if(obj.contains("num"))
        {
            msg.num = (obj["num"].is_string()?atoi(obj["num"].get<std::string>().c_str()):obj["num"].get<int>());
        }
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
        return msg;
    }
    template <>
    ApolloperceptioninferenceBlobProto from_json<ApolloperceptioninferenceBlobProto>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceBlobProto(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBlobProto &dt)
    {
        dt=from_json_ApolloperceptioninferenceBlobProto(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBlobProto & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBlobProto & dt)
    {
        os << to_json(dt);
        return os;
    }
}
