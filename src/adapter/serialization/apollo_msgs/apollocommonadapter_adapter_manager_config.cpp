#include "adapter/serialization/apollo_msgs/apollocommonadapter_adapter_manager_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonadapterAdapterManagerConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_config;
        for (auto it = msg.config.begin(); it != msg.config.end(); ++it) {
            arr_config.push_back(to_json(*it));
        }
        obj["config"] = arr_config;
        obj["isros"] = (msg.isros);
        return obj;
    }
    ApollocommonadapterAdapterManagerConfig from_json_ApollocommonadapterAdapterManagerConfig (nlohmann::json obj) {
        ApollocommonadapterAdapterManagerConfig msg;
        if(obj.contains("config"))
        {
            if(obj["config"].is_array())
            {
                for (auto& element : obj["config"])
                {
                    msg.config.push_back(from_json_ApollocommonadapterAdapterConfig(element));
                }
            }
            else
            {
                msg.config.push_back(from_json_ApollocommonadapterAdapterConfig(obj["config"]));
            }
        }
        if(obj.contains("isros"))
        {
            msg.isros = (obj["isros"].is_string()?(bool)atoi(obj["isros"].get<std::string>().c_str()):obj["isros"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocommonadapterAdapterManagerConfig from_json<ApollocommonadapterAdapterManagerConfig>(nlohmann::json obj){
        return from_json_ApollocommonadapterAdapterManagerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonadapterAdapterManagerConfig &dt)
    {
        dt=from_json_ApollocommonadapterAdapterManagerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonadapterAdapterManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonadapterAdapterManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
