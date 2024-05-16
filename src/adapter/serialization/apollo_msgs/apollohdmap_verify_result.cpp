#include "adapter/serialization/apollo_msgs/apollohdmap_verify_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapVerifyResult &msg) {
        nlohmann::json obj;
        obj["topics"] = to_json(msg.topics);
        nlohmann::json arr_rates;
        for (auto it = msg.rates.begin(); it != msg.rates.end(); ++it) {
            arr_rates.push_back(to_json(*it));
        }
        obj["rates"] = arr_rates;
        return obj;
    }
    ApollohdmapVerifyResult from_json_ApollohdmapVerifyResult (nlohmann::json obj) {
        ApollohdmapVerifyResult msg;
        if(obj.contains("topics"))
        {
            msg.topics = from_json_ApollohdmapTopicResult(obj["topics"]);
        }
        if(obj.contains("rates"))
        {
            if(obj["rates"].is_array())
            {
                for (auto& element : obj["rates"])
                {
                    msg.rates.push_back(from_json_ApollohdmapFrameRate(element));
                }
            }
            else
            {
                msg.rates.push_back(from_json_ApollohdmapFrameRate(obj["rates"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapVerifyResult from_json<ApollohdmapVerifyResult>(nlohmann::json obj){
        return from_json_ApollohdmapVerifyResult(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapVerifyResult &dt)
    {
        dt=from_json_ApollohdmapVerifyResult(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapVerifyResult & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapVerifyResult & dt)
    {
        os << to_json(dt);
        return os;
    }
}
