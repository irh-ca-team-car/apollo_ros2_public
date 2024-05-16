#include "adapter/serialization/apollo_msgs/apollohdmap_topic_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapTopicResult &msg) {
        nlohmann::json obj;
        nlohmann::json arr_topiclack;
        for (auto it = msg.topiclack.begin(); it != msg.topiclack.end(); ++it) {
            arr_topiclack.push_back((*it));
        }
        obj["topiclack"] = arr_topiclack;
        return obj;
    }
    ApollohdmapTopicResult from_json_ApollohdmapTopicResult (nlohmann::json obj) {
        ApollohdmapTopicResult msg;
        if(obj.contains("topiclack"))
        {
            if(obj["topiclack"].is_array())
            {
                for (auto& element : obj["topiclack"])
                {
                    msg.topiclack.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.topiclack.push_back((obj["topiclack"].is_string()?(obj["topiclack"].get<std::string>().c_str()):obj["topiclack"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapTopicResult from_json<ApollohdmapTopicResult>(nlohmann::json obj){
        return from_json_ApollohdmapTopicResult(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapTopicResult &dt)
    {
        dt=from_json_ApollohdmapTopicResult(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapTopicResult & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapTopicResult & dt)
    {
        os << to_json(dt);
        return os;
    }
}
