#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_speed_pointwise_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningSpeedPointwiseFeature &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["t"] = (msg.t);
        obj["v"] = (msg.v);
        obj["speedlimit"] = (msg.speedlimit);
        obj["acc"] = (msg.acc);
        obj["jerk"] = (msg.jerk);
        nlohmann::json arr_followobsfeature;
        for (auto it = msg.followobsfeature.begin(); it != msg.followobsfeature.end(); ++it) {
            arr_followobsfeature.push_back(to_json(*it));
        }
        obj["followobsfeature"] = arr_followobsfeature;
        nlohmann::json arr_overtakeobsfeature;
        for (auto it = msg.overtakeobsfeature.begin(); it != msg.overtakeobsfeature.end(); ++it) {
            arr_overtakeobsfeature.push_back(to_json(*it));
        }
        obj["overtakeobsfeature"] = arr_overtakeobsfeature;
        nlohmann::json arr_nudgeobsfeature;
        for (auto it = msg.nudgeobsfeature.begin(); it != msg.nudgeobsfeature.end(); ++it) {
            arr_nudgeobsfeature.push_back(to_json(*it));
        }
        obj["nudgeobsfeature"] = arr_nudgeobsfeature;
        nlohmann::json arr_stopobsfeature;
        for (auto it = msg.stopobsfeature.begin(); it != msg.stopobsfeature.end(); ++it) {
            arr_stopobsfeature.push_back(to_json(*it));
        }
        obj["stopobsfeature"] = arr_stopobsfeature;
        obj["collisiontimes"] = (msg.collisiontimes);
        nlohmann::json arr_virtualobsfeature;
        for (auto it = msg.virtualobsfeature.begin(); it != msg.virtualobsfeature.end(); ++it) {
            arr_virtualobsfeature.push_back(to_json(*it));
        }
        obj["virtualobsfeature"] = arr_virtualobsfeature;
        obj["lateralacc"] = (msg.lateralacc);
        obj["pathcurvatureabs"] = (msg.pathcurvatureabs);
        nlohmann::json arr_sidepassfrontobsfeature;
        for (auto it = msg.sidepassfrontobsfeature.begin(); it != msg.sidepassfrontobsfeature.end(); ++it) {
            arr_sidepassfrontobsfeature.push_back(to_json(*it));
        }
        obj["sidepassfrontobsfeature"] = arr_sidepassfrontobsfeature;
        nlohmann::json arr_sidepassrearobsfeature;
        for (auto it = msg.sidepassrearobsfeature.begin(); it != msg.sidepassrearobsfeature.end(); ++it) {
            arr_sidepassrearobsfeature.push_back(to_json(*it));
        }
        obj["sidepassrearobsfeature"] = arr_sidepassrearobsfeature;
        return obj;
    }
    ApolloplanningautotuningSpeedPointwiseFeature from_json_ApolloplanningautotuningSpeedPointwiseFeature (nlohmann::json obj) {
        ApolloplanningautotuningSpeedPointwiseFeature msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("t"))
        {
            msg.t = (obj["t"].is_string()?atof(obj["t"].get<std::string>().c_str()):obj["t"].get<double>());
        }
        if(obj.contains("v"))
        {
            msg.v = (obj["v"].is_string()?atof(obj["v"].get<std::string>().c_str()):obj["v"].get<double>());
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        if(obj.contains("acc"))
        {
            msg.acc = (obj["acc"].is_string()?atof(obj["acc"].get<std::string>().c_str()):obj["acc"].get<double>());
        }
        if(obj.contains("jerk"))
        {
            msg.jerk = (obj["jerk"].is_string()?atof(obj["jerk"].get<std::string>().c_str()):obj["jerk"].get<double>());
        }
        if(obj.contains("followobsfeature"))
        {
            if(obj["followobsfeature"].is_array())
            {
                for (auto& element : obj["followobsfeature"])
                {
                    msg.followobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.followobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["followobsfeature"]));
            }
        }
        if(obj.contains("overtakeobsfeature"))
        {
            if(obj["overtakeobsfeature"].is_array())
            {
                for (auto& element : obj["overtakeobsfeature"])
                {
                    msg.overtakeobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.overtakeobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["overtakeobsfeature"]));
            }
        }
        if(obj.contains("nudgeobsfeature"))
        {
            if(obj["nudgeobsfeature"].is_array())
            {
                for (auto& element : obj["nudgeobsfeature"])
                {
                    msg.nudgeobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.nudgeobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["nudgeobsfeature"]));
            }
        }
        if(obj.contains("stopobsfeature"))
        {
            if(obj["stopobsfeature"].is_array())
            {
                for (auto& element : obj["stopobsfeature"])
                {
                    msg.stopobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.stopobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["stopobsfeature"]));
            }
        }
        if(obj.contains("collisiontimes"))
        {
            msg.collisiontimes = (obj["collisiontimes"].is_string()?atoi(obj["collisiontimes"].get<std::string>().c_str()):obj["collisiontimes"].get<int>());
        }
        if(obj.contains("virtualobsfeature"))
        {
            if(obj["virtualobsfeature"].is_array())
            {
                for (auto& element : obj["virtualobsfeature"])
                {
                    msg.virtualobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.virtualobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["virtualobsfeature"]));
            }
        }
        if(obj.contains("lateralacc"))
        {
            msg.lateralacc = (obj["lateralacc"].is_string()?atof(obj["lateralacc"].get<std::string>().c_str()):obj["lateralacc"].get<double>());
        }
        if(obj.contains("pathcurvatureabs"))
        {
            msg.pathcurvatureabs = (obj["pathcurvatureabs"].is_string()?atof(obj["pathcurvatureabs"].get<std::string>().c_str()):obj["pathcurvatureabs"].get<double>());
        }
        if(obj.contains("sidepassfrontobsfeature"))
        {
            if(obj["sidepassfrontobsfeature"].is_array())
            {
                for (auto& element : obj["sidepassfrontobsfeature"])
                {
                    msg.sidepassfrontobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.sidepassfrontobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["sidepassfrontobsfeature"]));
            }
        }
        if(obj.contains("sidepassrearobsfeature"))
        {
            if(obj["sidepassrearobsfeature"].is_array())
            {
                for (auto& element : obj["sidepassrearobsfeature"])
                {
                    msg.sidepassrearobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.sidepassrearobsfeature.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["sidepassrearobsfeature"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningSpeedPointwiseFeature from_json<ApolloplanningautotuningSpeedPointwiseFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningSpeedPointwiseFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningSpeedPointwiseFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningSpeedPointwiseFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningSpeedPointwiseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningSpeedPointwiseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
