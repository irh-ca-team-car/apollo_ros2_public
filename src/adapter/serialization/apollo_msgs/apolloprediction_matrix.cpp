#include "adapter/serialization/apollo_msgs/apolloprediction_matrix.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionMatrix &msg) {
        nlohmann::json obj;
        nlohmann::json arr_rows;
        for (auto it = msg.rows.begin(); it != msg.rows.end(); ++it) {
            arr_rows.push_back(to_json(*it));
        }
        obj["rows"] = arr_rows;
        return obj;
    }
    ApollopredictionMatrix from_json_ApollopredictionMatrix (nlohmann::json obj) {
        ApollopredictionMatrix msg;
        if(obj.contains("rows"))
        {
            if(obj["rows"].is_array())
            {
                for (auto& element : obj["rows"])
                {
                    msg.rows.push_back(from_json_ApollopredictionVector(element));
                }
            }
            else
            {
                msg.rows.push_back(from_json_ApollopredictionVector(obj["rows"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionMatrix from_json<ApollopredictionMatrix>(nlohmann::json obj){
        return from_json_ApollopredictionMatrix(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionMatrix &dt)
    {
        dt=from_json_ApollopredictionMatrix(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionMatrix & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionMatrix & dt)
    {
        os << to_json(dt);
        return os;
    }
}
