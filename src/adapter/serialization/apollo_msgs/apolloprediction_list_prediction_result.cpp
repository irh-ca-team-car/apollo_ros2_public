#include "adapter/serialization/apollo_msgs/apolloprediction_list_prediction_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListPredictionResult &msg) {
        nlohmann::json obj;
        nlohmann::json arr_predictionresult;
        for (auto it = msg.predictionresult.begin(); it != msg.predictionresult.end(); ++it) {
            arr_predictionresult.push_back(to_json(*it));
        }
        obj["predictionresult"] = arr_predictionresult;
        return obj;
    }
    ApollopredictionListPredictionResult from_json_ApollopredictionListPredictionResult (nlohmann::json obj) {
        ApollopredictionListPredictionResult msg;
        if(obj.contains("predictionresult"))
        {
            if(obj["predictionresult"].is_array())
            {
                for (auto& element : obj["predictionresult"])
                {
                    msg.predictionresult.push_back(from_json_ApollopredictionPredictionResult(element));
                }
            }
            else
            {
                msg.predictionresult.push_back(from_json_ApollopredictionPredictionResult(obj["predictionresult"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionListPredictionResult from_json<ApollopredictionListPredictionResult>(nlohmann::json obj){
        return from_json_ApollopredictionListPredictionResult(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListPredictionResult &dt)
    {
        dt=from_json_ApollopredictionListPredictionResult(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListPredictionResult & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListPredictionResult & dt)
    {
        os << to_json(dt);
        return os;
    }
}
