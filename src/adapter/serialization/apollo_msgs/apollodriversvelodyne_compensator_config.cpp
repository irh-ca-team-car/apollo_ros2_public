#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_compensator_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneCompensatorConfig &msg) {
        nlohmann::json obj;
        obj["outputchannel"] = (msg.outputchannel);
        obj["transformquerytimeout"] = (msg.transformquerytimeout);
        obj["worldframeid"] = (msg.worldframeid);
        obj["targetframeid"] = (msg.targetframeid);
        obj["pointcloudsize"] = (msg.pointcloudsize);
        return obj;
    }
    ApollodriversvelodyneCompensatorConfig from_json_ApollodriversvelodyneCompensatorConfig (nlohmann::json obj) {
        ApollodriversvelodyneCompensatorConfig msg;
        if(obj.contains("outputchannel"))
        {
            msg.outputchannel = (obj["outputchannel"].is_string()?(obj["outputchannel"].get<std::string>().c_str()):obj["outputchannel"].get<std::string>());
        }
        if(obj.contains("transformquerytimeout"))
        {
            msg.transformquerytimeout = (obj["transformquerytimeout"].is_string()?(float)atof(obj["transformquerytimeout"].get<std::string>().c_str()):obj["transformquerytimeout"].get<float>());
        }
        if(obj.contains("worldframeid"))
        {
            msg.worldframeid = (obj["worldframeid"].is_string()?(obj["worldframeid"].get<std::string>().c_str()):obj["worldframeid"].get<std::string>());
        }
        if(obj.contains("targetframeid"))
        {
            msg.targetframeid = (obj["targetframeid"].is_string()?(obj["targetframeid"].get<std::string>().c_str()):obj["targetframeid"].get<std::string>());
        }
        if(obj.contains("pointcloudsize"))
        {
            msg.pointcloudsize = (obj["pointcloudsize"].is_string()?atoi(obj["pointcloudsize"].get<std::string>().c_str()):obj["pointcloudsize"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversvelodyneCompensatorConfig from_json<ApollodriversvelodyneCompensatorConfig>(nlohmann::json obj){
        return from_json_ApollodriversvelodyneCompensatorConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneCompensatorConfig &dt)
    {
        dt=from_json_ApollodriversvelodyneCompensatorConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneCompensatorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneCompensatorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
