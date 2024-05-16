#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_fusion_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneFusionConfig &msg) {
        nlohmann::json obj;
        obj["maxintervalms"] = (msg.maxintervalms);
        obj["dropexpireddata"] = (msg.dropexpireddata);
        obj["fusionchannel"] = (msg.fusionchannel);
        nlohmann::json arr_inputchannel;
        for (auto it = msg.inputchannel.begin(); it != msg.inputchannel.end(); ++it) {
            arr_inputchannel.push_back((*it));
        }
        obj["inputchannel"] = arr_inputchannel;
        obj["waittimes"] = (msg.waittimes);
        return obj;
    }
    ApollodriversvelodyneFusionConfig from_json_ApollodriversvelodyneFusionConfig (nlohmann::json obj) {
        ApollodriversvelodyneFusionConfig msg;
        if(obj.contains("maxintervalms"))
        {
            msg.maxintervalms = (obj["maxintervalms"].is_string()?atoi(obj["maxintervalms"].get<std::string>().c_str()):obj["maxintervalms"].get<uint32_t>());
        }
        if(obj.contains("dropexpireddata"))
        {
            msg.dropexpireddata = (obj["dropexpireddata"].is_string()?(bool)atoi(obj["dropexpireddata"].get<std::string>().c_str()):obj["dropexpireddata"].get<bool>());
        }
        if(obj.contains("fusionchannel"))
        {
            msg.fusionchannel = (obj["fusionchannel"].is_string()?(obj["fusionchannel"].get<std::string>().c_str()):obj["fusionchannel"].get<std::string>());
        }
        if(obj.contains("inputchannel"))
        {
            if(obj["inputchannel"].is_array())
            {
                for (auto& element : obj["inputchannel"])
                {
                    msg.inputchannel.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.inputchannel.push_back((obj["inputchannel"].is_string()?(obj["inputchannel"].get<std::string>().c_str()):obj["inputchannel"].get<std::string>()));
            }
        }
        if(obj.contains("waittimes"))
        {
            msg.waittimes = (obj["waittimes"].is_string()?(float)atof(obj["waittimes"].get<std::string>().c_str()):obj["waittimes"].get<float>());
        }
        return msg;
    }
    template <>
    ApollodriversvelodyneFusionConfig from_json<ApollodriversvelodyneFusionConfig>(nlohmann::json obj){
        return from_json_ApollodriversvelodyneFusionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneFusionConfig &dt)
    {
        dt=from_json_ApollodriversvelodyneFusionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
