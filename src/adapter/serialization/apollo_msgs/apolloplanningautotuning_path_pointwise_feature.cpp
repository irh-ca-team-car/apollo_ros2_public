#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_pointwise_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningPathPointwiseFeature &msg) {
        nlohmann::json obj;
        obj["l"] = (msg.l);
        obj["dl"] = (msg.dl);
        obj["ddl"] = (msg.ddl);
        obj["kappa"] = (msg.kappa);
        nlohmann::json arr_obstacleinfo;
        for (auto it = msg.obstacleinfo.begin(); it != msg.obstacleinfo.end(); ++it) {
            arr_obstacleinfo.push_back(to_json(*it));
        }
        obj["obstacleinfo"] = arr_obstacleinfo;
        obj["leftboundfeature"] = to_json(msg.leftboundfeature);
        obj["rightboundfeature"] = to_json(msg.rightboundfeature);
        return obj;
    }
    ApolloplanningautotuningPathPointwiseFeature from_json_ApolloplanningautotuningPathPointwiseFeature (nlohmann::json obj) {
        ApolloplanningautotuningPathPointwiseFeature msg;
        if(obj.contains("l"))
        {
            msg.l = (obj["l"].is_string()?atof(obj["l"].get<std::string>().c_str()):obj["l"].get<double>());
        }
        if(obj.contains("dl"))
        {
            msg.dl = (obj["dl"].is_string()?atof(obj["dl"].get<std::string>().c_str()):obj["dl"].get<double>());
        }
        if(obj.contains("ddl"))
        {
            msg.ddl = (obj["ddl"].is_string()?atof(obj["ddl"].get<std::string>().c_str()):obj["ddl"].get<double>());
        }
        if(obj.contains("kappa"))
        {
            msg.kappa = (obj["kappa"].is_string()?atof(obj["kappa"].get<std::string>().c_str()):obj["kappa"].get<double>());
        }
        if(obj.contains("obstacleinfo"))
        {
            if(obj["obstacleinfo"].is_array())
            {
                for (auto& element : obj["obstacleinfo"])
                {
                    msg.obstacleinfo.push_back(from_json_ApolloplanningautotuningObstacleFeature(element));
                }
            }
            else
            {
                msg.obstacleinfo.push_back(from_json_ApolloplanningautotuningObstacleFeature(obj["obstacleinfo"]));
            }
        }
        if(obj.contains("leftboundfeature"))
        {
            msg.leftboundfeature = from_json_ApolloplanningautotuningBoundRelatedFeature(obj["leftboundfeature"]);
        }
        if(obj.contains("rightboundfeature"))
        {
            msg.rightboundfeature = from_json_ApolloplanningautotuningBoundRelatedFeature(obj["rightboundfeature"]);
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningPathPointwiseFeature from_json<ApolloplanningautotuningPathPointwiseFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningPathPointwiseFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningPathPointwiseFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningPathPointwiseFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningPathPointwiseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningPathPointwiseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
