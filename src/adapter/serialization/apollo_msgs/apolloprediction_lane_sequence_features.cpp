#include "adapter/serialization/apollo_msgs/apolloprediction_lane_sequence_features.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneSequenceFeatures &msg) {
        nlohmann::json obj;
        nlohmann::json arr_mlpfeatures;
        for (auto it = msg.mlpfeatures.begin(); it != msg.mlpfeatures.end(); ++it) {
            arr_mlpfeatures.push_back((*it));
        }
        obj["mlpfeatures"] = arr_mlpfeatures;
        return obj;
    }
    ApollopredictionLaneSequenceFeatures from_json_ApollopredictionLaneSequenceFeatures (nlohmann::json obj) {
        ApollopredictionLaneSequenceFeatures msg;
        if(obj.contains("mlpfeatures"))
        {
            if(obj["mlpfeatures"].is_array())
            {
                for (auto& element : obj["mlpfeatures"])
                {
                    msg.mlpfeatures.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.mlpfeatures.push_back((obj["mlpfeatures"].is_string()?atof(obj["mlpfeatures"].get<std::string>().c_str()):obj["mlpfeatures"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionLaneSequenceFeatures from_json<ApollopredictionLaneSequenceFeatures>(nlohmann::json obj){
        return from_json_ApollopredictionLaneSequenceFeatures(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneSequenceFeatures &dt)
    {
        dt=from_json_ApollopredictionLaneSequenceFeatures(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneSequenceFeatures & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneSequenceFeatures & dt)
    {
        os << to_json(dt);
        return os;
    }
}
