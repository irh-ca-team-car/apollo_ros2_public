#include "adapter/serialization/apollo_msgs/apollocommonutiltest_simple_repeated_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonutiltestSimpleRepeatedMessage &msg) {
        nlohmann::json obj;
        nlohmann::json arr_message;
        for (auto it = msg.message.begin(); it != msg.message.end(); ++it) {
            arr_message.push_back(to_json(*it));
        }
        obj["message"] = arr_message;
        return obj;
    }
    ApollocommonutiltestSimpleRepeatedMessage from_json_ApollocommonutiltestSimpleRepeatedMessage (nlohmann::json obj) {
        ApollocommonutiltestSimpleRepeatedMessage msg;
        if(obj.contains("message"))
        {
            if(obj["message"].is_array())
            {
                for (auto& element : obj["message"])
                {
                    msg.message.push_back(from_json_ApollocommonutiltestSimpleMessage(element));
                }
            }
            else
            {
                msg.message.push_back(from_json_ApollocommonutiltestSimpleMessage(obj["message"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonutiltestSimpleRepeatedMessage from_json<ApollocommonutiltestSimpleRepeatedMessage>(nlohmann::json obj){
        return from_json_ApollocommonutiltestSimpleRepeatedMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonutiltestSimpleRepeatedMessage &dt)
    {
        dt=from_json_ApollocommonutiltestSimpleRepeatedMessage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonutiltestSimpleRepeatedMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonutiltestSimpleRepeatedMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
