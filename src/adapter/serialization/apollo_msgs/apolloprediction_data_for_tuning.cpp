#include "adapter/serialization/apollo_msgs/apolloprediction_data_for_tuning.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionDataForTuning &msg) {
        nlohmann::json obj;
        obj["category"] = (msg.category);
        obj["id"] = (msg.id);
        obj["timestamp"] = (msg.timestamp);
        nlohmann::json arr_valuesfortuning;
        for (auto it = msg.valuesfortuning.begin(); it != msg.valuesfortuning.end(); ++it) {
            arr_valuesfortuning.push_back((*it));
        }
        obj["valuesfortuning"] = arr_valuesfortuning;
        nlohmann::json arr_realcostvalue;
        for (auto it = msg.realcostvalue.begin(); it != msg.realcostvalue.end(); ++it) {
            arr_realcostvalue.push_back((*it));
        }
        obj["realcostvalue"] = arr_realcostvalue;
        obj["lanesequenceid"] = (msg.lanesequenceid);
        nlohmann::json arr_adctrajectorypoint;
        for (auto it = msg.adctrajectorypoint.begin(); it != msg.adctrajectorypoint.end(); ++it) {
            arr_adctrajectorypoint.push_back(to_json(*it));
        }
        obj["adctrajectorypoint"] = arr_adctrajectorypoint;
        return obj;
    }
    ApollopredictionDataForTuning from_json_ApollopredictionDataForTuning (nlohmann::json obj) {
        ApollopredictionDataForTuning msg;
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
        if(obj.contains("valuesfortuning"))
        {
            if(obj["valuesfortuning"].is_array())
            {
                for (auto& element : obj["valuesfortuning"])
                {
                    msg.valuesfortuning.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.valuesfortuning.push_back((obj["valuesfortuning"].is_string()?atof(obj["valuesfortuning"].get<std::string>().c_str()):obj["valuesfortuning"].get<double>()));
            }
        }
        if(obj.contains("realcostvalue"))
        {
            if(obj["realcostvalue"].is_array())
            {
                for (auto& element : obj["realcostvalue"])
                {
                    msg.realcostvalue.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.realcostvalue.push_back((obj["realcostvalue"].is_string()?atof(obj["realcostvalue"].get<std::string>().c_str()):obj["realcostvalue"].get<double>()));
            }
        }
        if(obj.contains("lanesequenceid"))
        {
            msg.lanesequenceid = (obj["lanesequenceid"].is_string()?atoi(obj["lanesequenceid"].get<std::string>().c_str()):obj["lanesequenceid"].get<int>());
        }
        if(obj.contains("adctrajectorypoint"))
        {
            if(obj["adctrajectorypoint"].is_array())
            {
                for (auto& element : obj["adctrajectorypoint"])
                {
                    msg.adctrajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(element));
                }
            }
            else
            {
                msg.adctrajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(obj["adctrajectorypoint"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionDataForTuning from_json<ApollopredictionDataForTuning>(nlohmann::json obj){
        return from_json_ApollopredictionDataForTuning(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionDataForTuning &dt)
    {
        dt=from_json_ApollopredictionDataForTuning(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionDataForTuning & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionDataForTuning & dt)
    {
        os << to_json(dt);
        return os;
    }
}
