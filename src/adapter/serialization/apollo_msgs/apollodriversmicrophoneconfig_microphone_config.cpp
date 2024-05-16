#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_microphone_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversmicrophoneconfigMicrophoneConfig &msg) {
        nlohmann::json obj;
        obj["microphonemodel"] = (msg.microphonemodel);
        obj["chunk"] = (msg.chunk);
        obj["samplerate"] = (msg.samplerate);
        obj["recordseconds"] = (msg.recordseconds);
        obj["samplewidth"] = (msg.samplewidth);
        obj["channelname"] = (msg.channelname);
        obj["frameid"] = (msg.frameid);
        obj["micdistance"] = (msg.micdistance);
        nlohmann::json arr_channeltype;
        for (auto it = msg.channeltype.begin(); it != msg.channeltype.end(); ++it) {
            arr_channeltype.push_back((*it));
        }
        obj["channeltype"] = arr_channeltype;
        return obj;
    }
    ApollodriversmicrophoneconfigMicrophoneConfig from_json_ApollodriversmicrophoneconfigMicrophoneConfig (nlohmann::json obj) {
        ApollodriversmicrophoneconfigMicrophoneConfig msg;
        if(obj.contains("microphonemodel"))
        {
            msg.microphonemodel = (obj["microphonemodel"].is_string()?atoi(obj["microphonemodel"].get<std::string>().c_str()):obj["microphonemodel"].get<int>());
        }
        if(obj.contains("chunk"))
        {
            msg.chunk = (obj["chunk"].is_string()?atoi(obj["chunk"].get<std::string>().c_str()):obj["chunk"].get<int>());
        }
        if(obj.contains("samplerate"))
        {
            msg.samplerate = (obj["samplerate"].is_string()?(float)atof(obj["samplerate"].get<std::string>().c_str()):obj["samplerate"].get<float>());
        }
        if(obj.contains("recordseconds"))
        {
            msg.recordseconds = (obj["recordseconds"].is_string()?(float)atof(obj["recordseconds"].get<std::string>().c_str()):obj["recordseconds"].get<float>());
        }
        if(obj.contains("samplewidth"))
        {
            msg.samplewidth = (obj["samplewidth"].is_string()?atoi(obj["samplewidth"].get<std::string>().c_str()):obj["samplewidth"].get<int>());
        }
        if(obj.contains("channelname"))
        {
            msg.channelname = (obj["channelname"].is_string()?(obj["channelname"].get<std::string>().c_str()):obj["channelname"].get<std::string>());
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("micdistance"))
        {
            msg.micdistance = (obj["micdistance"].is_string()?(float)atof(obj["micdistance"].get<std::string>().c_str()):obj["micdistance"].get<float>());
        }
        if(obj.contains("channeltype"))
        {
            if(obj["channeltype"].is_array())
            {
                for (auto& element : obj["channeltype"])
                {
                    msg.channeltype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.channeltype.push_back((obj["channeltype"].is_string()?atoi(obj["channeltype"].get<std::string>().c_str()):obj["channeltype"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApollodriversmicrophoneconfigMicrophoneConfig from_json<ApollodriversmicrophoneconfigMicrophoneConfig>(nlohmann::json obj){
        return from_json_ApollodriversmicrophoneconfigMicrophoneConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversmicrophoneconfigMicrophoneConfig &dt)
    {
        dt=from_json_ApollodriversmicrophoneconfigMicrophoneConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversmicrophoneconfigMicrophoneConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversmicrophoneconfigMicrophoneConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
