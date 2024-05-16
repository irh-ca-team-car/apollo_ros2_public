#include "adapter/serialization/apollo_msgs/apolloprediction_list_data_for_tuning.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListDataForTuning &msg) {
        nlohmann::json obj;
        nlohmann::json arr_datafortuning;
        for (auto it = msg.datafortuning.begin(); it != msg.datafortuning.end(); ++it) {
            arr_datafortuning.push_back(to_json(*it));
        }
        obj["datafortuning"] = arr_datafortuning;
        return obj;
    }
    ApollopredictionListDataForTuning from_json_ApollopredictionListDataForTuning (nlohmann::json obj) {
        ApollopredictionListDataForTuning msg;
        if(obj.contains("datafortuning"))
        {
            if(obj["datafortuning"].is_array())
            {
                for (auto& element : obj["datafortuning"])
                {
                    msg.datafortuning.push_back(from_json_ApollopredictionDataForTuning(element));
                }
            }
            else
            {
                msg.datafortuning.push_back(from_json_ApollopredictionDataForTuning(obj["datafortuning"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionListDataForTuning from_json<ApollopredictionListDataForTuning>(nlohmann::json obj){
        return from_json_ApollopredictionListDataForTuning(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListDataForTuning &dt)
    {
        dt=from_json_ApollopredictionListDataForTuning(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListDataForTuning & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListDataForTuning & dt)
    {
        os << to_json(dt);
        return os;
    }
}
