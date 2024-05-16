#include "adapter/serialization/apollo_msgs/apolloprediction_list_data_for_learning.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListDataForLearning &msg) {
        nlohmann::json obj;
        nlohmann::json arr_dataforlearning;
        for (auto it = msg.dataforlearning.begin(); it != msg.dataforlearning.end(); ++it) {
            arr_dataforlearning.push_back(to_json(*it));
        }
        obj["dataforlearning"] = arr_dataforlearning;
        return obj;
    }
    ApollopredictionListDataForLearning from_json_ApollopredictionListDataForLearning (nlohmann::json obj) {
        ApollopredictionListDataForLearning msg;
        if(obj.contains("dataforlearning"))
        {
            if(obj["dataforlearning"].is_array())
            {
                for (auto& element : obj["dataforlearning"])
                {
                    msg.dataforlearning.push_back(from_json_ApollopredictionDataForLearning(element));
                }
            }
            else
            {
                msg.dataforlearning.push_back(from_json_ApollopredictionDataForLearning(obj["dataforlearning"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionListDataForLearning from_json<ApollopredictionListDataForLearning>(nlohmann::json obj){
        return from_json_ApollopredictionListDataForLearning(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListDataForLearning &dt)
    {
        dt=from_json_ApollopredictionListDataForLearning(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListDataForLearning & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListDataForLearning & dt)
    {
        os << to_json(dt);
        return os;
    }
}
