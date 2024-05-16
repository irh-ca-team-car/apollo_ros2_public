#include "adapter/serialization/apollo_msgs/apollocommonutiltest_simple_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonutiltestSimpleMessage &msg) {
        nlohmann::json obj;
        obj["integer"] = (msg.integer);
        obj["text"] = (msg.text);
        obj["apolloheader"] = (msg.apolloheader);
        return obj;
    }
    ApollocommonutiltestSimpleMessage from_json_ApollocommonutiltestSimpleMessage (nlohmann::json obj) {
        ApollocommonutiltestSimpleMessage msg;
        if(obj.contains("integer"))
        {
            msg.integer = (obj["integer"].is_string()?atoi(obj["integer"].get<std::string>().c_str()):obj["integer"].get<int>());
        }
        if(obj.contains("text"))
        {
            msg.text = (obj["text"].is_string()?(obj["text"].get<std::string>().c_str()):obj["text"].get<std::string>());
        }
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = (obj["apolloheader"].is_string()?atoi(obj["apolloheader"].get<std::string>().c_str()):obj["apolloheader"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocommonutiltestSimpleMessage from_json<ApollocommonutiltestSimpleMessage>(nlohmann::json obj){
        return from_json_ApollocommonutiltestSimpleMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonutiltestSimpleMessage &dt)
    {
        dt=from_json_ApollocommonutiltestSimpleMessage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonutiltestSimpleMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonutiltestSimpleMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
