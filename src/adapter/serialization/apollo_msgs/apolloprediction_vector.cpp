#include "adapter/serialization/apollo_msgs/apolloprediction_vector.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionVector &msg) {
        nlohmann::json obj;
        nlohmann::json arr_columns;
        for (auto it = msg.columns.begin(); it != msg.columns.end(); ++it) {
            arr_columns.push_back((*it));
        }
        obj["columns"] = arr_columns;
        return obj;
    }
    ApollopredictionVector from_json_ApollopredictionVector (nlohmann::json obj) {
        ApollopredictionVector msg;
        if(obj.contains("columns"))
        {
            if(obj["columns"].is_array())
            {
                for (auto& element : obj["columns"])
                {
                    msg.columns.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.columns.push_back((obj["columns"].is_string()?atof(obj["columns"].get<std::string>().c_str()):obj["columns"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionVector from_json<ApollopredictionVector>(nlohmann::json obj){
        return from_json_ApollopredictionVector(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionVector &dt)
    {
        dt=from_json_ApollopredictionVector(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionVector & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionVector & dt)
    {
        os << to_json(dt);
        return os;
    }
}
