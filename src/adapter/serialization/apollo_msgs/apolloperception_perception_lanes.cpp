#include "adapter/serialization/apollo_msgs/apolloperception_perception_lanes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionPerceptionLanes &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["sourcetopic"] = (msg.sourcetopic);
        obj["errorcode"] = (msg.errorcode);
        obj["cameracalibrator"] = to_json(msg.cameracalibrator);
        nlohmann::json arr_cameralaneline;
        for (auto it = msg.cameralaneline.begin(); it != msg.cameralaneline.end(); ++it) {
            arr_cameralaneline.push_back(to_json(*it));
        }
        obj["cameralaneline"] = arr_cameralaneline;
        return obj;
    }
    ApolloperceptionPerceptionLanes from_json_ApolloperceptionPerceptionLanes (nlohmann::json obj) {
        ApolloperceptionPerceptionLanes msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("sourcetopic"))
        {
            msg.sourcetopic = (obj["sourcetopic"].is_string()?(obj["sourcetopic"].get<std::string>().c_str()):obj["sourcetopic"].get<std::string>());
        }
        if(obj.contains("errorcode"))
        {
            msg.errorcode = (obj["errorcode"].is_string()?atoi(obj["errorcode"].get<std::string>().c_str()):obj["errorcode"].get<int>());
        }
        if(obj.contains("cameracalibrator"))
        {
            msg.cameracalibrator = from_json_ApolloperceptioncameraCameraCalibrator(obj["cameracalibrator"]);
        }
        if(obj.contains("cameralaneline"))
        {
            if(obj["cameralaneline"].is_array())
            {
                for (auto& element : obj["cameralaneline"])
                {
                    msg.cameralaneline.push_back(from_json_ApolloperceptioncameraCameraLaneLine(element));
                }
            }
            else
            {
                msg.cameralaneline.push_back(from_json_ApolloperceptioncameraCameraLaneLine(obj["cameralaneline"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionPerceptionLanes from_json<ApolloperceptionPerceptionLanes>(nlohmann::json obj){
        return from_json_ApolloperceptionPerceptionLanes(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionPerceptionLanes &dt)
    {
        dt=from_json_ApolloperceptionPerceptionLanes(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionPerceptionLanes & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionPerceptionLanes & dt)
    {
        os << to_json(dt);
        return os;
    }
}
