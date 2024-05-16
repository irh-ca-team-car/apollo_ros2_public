#include "adapter/serialization/apollo_msgs/apollolocalization_localization_estimate.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationLocalizationEstimate &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["pose"] = to_json(msg.pose);
        obj["uncertainty"] = to_json(msg.uncertainty);
        obj["measurementtime"] = (msg.measurementtime);
        nlohmann::json arr_trajectorypoint;
        for (auto it = msg.trajectorypoint.begin(); it != msg.trajectorypoint.end(); ++it) {
            arr_trajectorypoint.push_back(to_json(*it));
        }
        obj["trajectorypoint"] = arr_trajectorypoint;
        obj["msfstatus"] = to_json(msg.msfstatus);
        obj["sensorstatus"] = to_json(msg.sensorstatus);
        return obj;
    }
    ApollolocalizationLocalizationEstimate from_json_ApollolocalizationLocalizationEstimate (nlohmann::json obj) {
        ApollolocalizationLocalizationEstimate msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("pose"))
        {
            msg.pose = from_json_ApollolocalizationPose(obj["pose"]);
        }
        if(obj.contains("uncertainty"))
        {
            msg.uncertainty = from_json_ApollolocalizationUncertainty(obj["uncertainty"]);
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("trajectorypoint"))
        {
            if(obj["trajectorypoint"].is_array())
            {
                for (auto& element : obj["trajectorypoint"])
                {
                    msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(element));
                }
            }
            else
            {
                msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(obj["trajectorypoint"]));
            }
        }
        if(obj.contains("msfstatus"))
        {
            msg.msfstatus = from_json_ApollolocalizationMsfStatus(obj["msfstatus"]);
        }
        if(obj.contains("sensorstatus"))
        {
            msg.sensorstatus = from_json_ApollolocalizationMsfSensorMsgStatus(obj["sensorstatus"]);
        }
        return msg;
    }
    template <>
    ApollolocalizationLocalizationEstimate from_json<ApollolocalizationLocalizationEstimate>(nlohmann::json obj){
        return from_json_ApollolocalizationLocalizationEstimate(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationLocalizationEstimate &dt)
    {
        dt=from_json_ApollolocalizationLocalizationEstimate(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationLocalizationEstimate & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationLocalizationEstimate & dt)
    {
        os << to_json(dt);
        return os;
    }
}
