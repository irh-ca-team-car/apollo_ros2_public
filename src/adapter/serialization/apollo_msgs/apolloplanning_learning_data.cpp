#include "adapter/serialization/apollo_msgs/apolloplanning_learning_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningData &msg) {
        nlohmann::json obj;
        nlohmann::json arr_learningdataframe;
        for (auto it = msg.learningdataframe.begin(); it != msg.learningdataframe.end(); ++it) {
            arr_learningdataframe.push_back(to_json(*it));
        }
        obj["learningdataframe"] = arr_learningdataframe;
        return obj;
    }
    ApolloplanningLearningData from_json_ApolloplanningLearningData (nlohmann::json obj) {
        ApolloplanningLearningData msg;
        if(obj.contains("learningdataframe"))
        {
            if(obj["learningdataframe"].is_array())
            {
                for (auto& element : obj["learningdataframe"])
                {
                    msg.learningdataframe.push_back(from_json_ApolloplanningLearningDataFrame(element));
                }
            }
            else
            {
                msg.learningdataframe.push_back(from_json_ApolloplanningLearningDataFrame(obj["learningdataframe"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningLearningData from_json<ApolloplanningLearningData>(nlohmann::json obj){
        return from_json_ApolloplanningLearningData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningData &dt)
    {
        dt=from_json_ApolloplanningLearningData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
