#include "adapter/serialization/apollo_msgs/apolloplanning_learning_data_frame.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningDataFrame &msg) {
        nlohmann::json obj;
        obj["messagetimestampsec"] = (msg.messagetimestampsec);
        obj["framenum"] = (msg.framenum);
        obj["mapname"] = (msg.mapname);
        obj["planningtag"] = to_json(msg.planningtag);
        obj["chassis"] = to_json(msg.chassis);
        obj["localization"] = to_json(msg.localization);
        nlohmann::json arr_obstacle;
        for (auto it = msg.obstacle.begin(); it != msg.obstacle.end(); ++it) {
            arr_obstacle.push_back(to_json(*it));
        }
        obj["obstacle"] = arr_obstacle;
        obj["routing"] = to_json(msg.routing);
        obj["trafficlightdetection"] = to_json(msg.trafficlightdetection);
        nlohmann::json arr_adctrajectorypoint;
        for (auto it = msg.adctrajectorypoint.begin(); it != msg.adctrajectorypoint.end(); ++it) {
            arr_adctrajectorypoint.push_back(to_json(*it));
        }
        obj["adctrajectorypoint"] = arr_adctrajectorypoint;
        obj["output"] = to_json(msg.output);
        return obj;
    }
    ApolloplanningLearningDataFrame from_json_ApolloplanningLearningDataFrame (nlohmann::json obj) {
        ApolloplanningLearningDataFrame msg;
        if(obj.contains("messagetimestampsec"))
        {
            msg.messagetimestampsec = (obj["messagetimestampsec"].is_string()?atof(obj["messagetimestampsec"].get<std::string>().c_str()):obj["messagetimestampsec"].get<double>());
        }
        if(obj.contains("framenum"))
        {
            msg.framenum = (obj["framenum"].is_string()?atoi(obj["framenum"].get<std::string>().c_str()):obj["framenum"].get<uint32_t>());
        }
        if(obj.contains("mapname"))
        {
            msg.mapname = (obj["mapname"].is_string()?(obj["mapname"].get<std::string>().c_str()):obj["mapname"].get<std::string>());
        }
        if(obj.contains("planningtag"))
        {
            msg.planningtag = from_json_ApolloplanningPlanningTag(obj["planningtag"]);
        }
        if(obj.contains("chassis"))
        {
            msg.chassis = from_json_ApolloplanningChassisFeature(obj["chassis"]);
        }
        if(obj.contains("localization"))
        {
            msg.localization = from_json_ApolloplanningLocalizationFeature(obj["localization"]);
        }
        if(obj.contains("obstacle"))
        {
            if(obj["obstacle"].is_array())
            {
                for (auto& element : obj["obstacle"])
                {
                    msg.obstacle.push_back(from_json_ApolloplanningObstacleFeature(element));
                }
            }
            else
            {
                msg.obstacle.push_back(from_json_ApolloplanningObstacleFeature(obj["obstacle"]));
            }
        }
        if(obj.contains("routing"))
        {
            msg.routing = from_json_ApolloplanningRoutingFeature(obj["routing"]);
        }
        if(obj.contains("trafficlightdetection"))
        {
            msg.trafficlightdetection = from_json_ApolloplanningTrafficLightDetectionFeature(obj["trafficlightdetection"]);
        }
        if(obj.contains("adctrajectorypoint"))
        {
            if(obj["adctrajectorypoint"].is_array())
            {
                for (auto& element : obj["adctrajectorypoint"])
                {
                    msg.adctrajectorypoint.push_back(from_json_ApolloplanningADCTrajectoryPoint(element));
                }
            }
            else
            {
                msg.adctrajectorypoint.push_back(from_json_ApolloplanningADCTrajectoryPoint(obj["adctrajectorypoint"]));
            }
        }
        if(obj.contains("output"))
        {
            msg.output = from_json_ApolloplanningLearningOutput(obj["output"]);
        }
        return msg;
    }
    template <>
    ApolloplanningLearningDataFrame from_json<ApolloplanningLearningDataFrame>(nlohmann::json obj){
        return from_json_ApolloplanningLearningDataFrame(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningDataFrame &dt)
    {
        dt=from_json_ApolloplanningLearningDataFrame(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningDataFrame & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningDataFrame & dt)
    {
        os << to_json(dt);
        return os;
    }
}
