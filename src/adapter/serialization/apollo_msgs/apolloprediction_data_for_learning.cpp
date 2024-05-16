#include "adapter/serialization/apollo_msgs/apolloprediction_data_for_learning.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionDataForLearning &msg) {
        nlohmann::json obj;
        obj["category"] = (msg.category);
        obj["id"] = (msg.id);
        obj["timestamp"] = (msg.timestamp);
        nlohmann::json arr_featuresforlearning;
        for (auto it = msg.featuresforlearning.begin(); it != msg.featuresforlearning.end(); ++it) {
            arr_featuresforlearning.push_back((*it));
        }
        obj["featuresforlearning"] = arr_featuresforlearning;
        nlohmann::json arr_stringfeaturesforlearning;
        for (auto it = msg.stringfeaturesforlearning.begin(); it != msg.stringfeaturesforlearning.end(); ++it) {
            arr_stringfeaturesforlearning.push_back((*it));
        }
        obj["stringfeaturesforlearning"] = arr_stringfeaturesforlearning;
        nlohmann::json arr_labels;
        for (auto it = msg.labels.begin(); it != msg.labels.end(); ++it) {
            arr_labels.push_back((*it));
        }
        obj["labels"] = arr_labels;
        obj["lanesequenceid"] = (msg.lanesequenceid);
        return obj;
    }
    ApollopredictionDataForLearning from_json_ApollopredictionDataForLearning (nlohmann::json obj) {
        ApollopredictionDataForLearning msg;
        if(obj.contains("category"))
        {
            msg.category = (obj["category"].is_string()?(obj["category"].get<std::string>().c_str()):obj["category"].get<std::string>());
        }
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("featuresforlearning"))
        {
            if(obj["featuresforlearning"].is_array())
            {
                for (auto& element : obj["featuresforlearning"])
                {
                    msg.featuresforlearning.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.featuresforlearning.push_back((obj["featuresforlearning"].is_string()?atof(obj["featuresforlearning"].get<std::string>().c_str()):obj["featuresforlearning"].get<double>()));
            }
        }
        if(obj.contains("stringfeaturesforlearning"))
        {
            if(obj["stringfeaturesforlearning"].is_array())
            {
                for (auto& element : obj["stringfeaturesforlearning"])
                {
                    msg.stringfeaturesforlearning.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.stringfeaturesforlearning.push_back((obj["stringfeaturesforlearning"].is_string()?(obj["stringfeaturesforlearning"].get<std::string>().c_str()):obj["stringfeaturesforlearning"].get<std::string>()));
            }
        }
        if(obj.contains("labels"))
        {
            if(obj["labels"].is_array())
            {
                for (auto& element : obj["labels"])
                {
                    msg.labels.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.labels.push_back((obj["labels"].is_string()?atof(obj["labels"].get<std::string>().c_str()):obj["labels"].get<double>()));
            }
        }
        if(obj.contains("lanesequenceid"))
        {
            msg.lanesequenceid = (obj["lanesequenceid"].is_string()?atoi(obj["lanesequenceid"].get<std::string>().c_str()):obj["lanesequenceid"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionDataForLearning from_json<ApollopredictionDataForLearning>(nlohmann::json obj){
        return from_json_ApollopredictionDataForLearning(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionDataForLearning &dt)
    {
        dt=from_json_ApollopredictionDataForLearning(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionDataForLearning & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionDataForLearning & dt)
    {
        os << to_json(dt);
        return os;
    }
}
