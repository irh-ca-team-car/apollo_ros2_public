#include "adapter/serialization/apollo_msgs/apolloprediction_performance.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPerformance &msg) {
        nlohmann::json obj;
        nlohmann::json arr_accuracy;
        for (auto it = msg.accuracy.begin(); it != msg.accuracy.end(); ++it) {
            arr_accuracy.push_back((*it));
        }
        obj["accuracy"] = arr_accuracy;
        nlohmann::json arr_recall;
        for (auto it = msg.recall.begin(); it != msg.recall.end(); ++it) {
            arr_recall.push_back((*it));
        }
        obj["recall"] = arr_recall;
        nlohmann::json arr_precision;
        for (auto it = msg.precision.begin(); it != msg.precision.end(); ++it) {
            arr_precision.push_back((*it));
        }
        obj["precision"] = arr_precision;
        return obj;
    }
    ApollopredictionPerformance from_json_ApollopredictionPerformance (nlohmann::json obj) {
        ApollopredictionPerformance msg;
        if(obj.contains("accuracy"))
        {
            if(obj["accuracy"].is_array())
            {
                for (auto& element : obj["accuracy"])
                {
                    msg.accuracy.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.accuracy.push_back((obj["accuracy"].is_string()?(float)atof(obj["accuracy"].get<std::string>().c_str()):obj["accuracy"].get<float>()));
            }
        }
        if(obj.contains("recall"))
        {
            if(obj["recall"].is_array())
            {
                for (auto& element : obj["recall"])
                {
                    msg.recall.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.recall.push_back((obj["recall"].is_string()?(float)atof(obj["recall"].get<std::string>().c_str()):obj["recall"].get<float>()));
            }
        }
        if(obj.contains("precision"))
        {
            if(obj["precision"].is_array())
            {
                for (auto& element : obj["precision"])
                {
                    msg.precision.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.precision.push_back((obj["precision"].is_string()?(float)atof(obj["precision"].get<std::string>().c_str()):obj["precision"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionPerformance from_json<ApollopredictionPerformance>(nlohmann::json obj){
        return from_json_ApollopredictionPerformance(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPerformance &dt)
    {
        dt=from_json_ApollopredictionPerformance(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPerformance & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPerformance & dt)
    {
        os << to_json(dt);
        return os;
    }
}
