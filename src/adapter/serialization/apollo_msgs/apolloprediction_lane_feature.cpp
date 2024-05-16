#include "adapter/serialization/apollo_msgs/apolloprediction_lane_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneFeature &msg) {
        nlohmann::json obj;
        obj["laneid"] = (msg.laneid);
        obj["laneturntype"] = (msg.laneturntype);
        obj["lanes"] = (msg.lanes);
        obj["lanel"] = (msg.lanel);
        obj["anglediff"] = (msg.anglediff);
        obj["disttoleftboundary"] = (msg.disttoleftboundary);
        obj["disttorightboundary"] = (msg.disttorightboundary);
        obj["laneheading"] = (msg.laneheading);
        obj["lanetype"] = (msg.lanetype);
        return obj;
    }
    ApollopredictionLaneFeature from_json_ApollopredictionLaneFeature (nlohmann::json obj) {
        ApollopredictionLaneFeature msg;
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<std::string>());
        }
        if(obj.contains("laneturntype"))
        {
            msg.laneturntype = (obj["laneturntype"].is_string()?atoi(obj["laneturntype"].get<std::string>().c_str()):obj["laneturntype"].get<uint32_t>());
        }
        if(obj.contains("lanes"))
        {
            msg.lanes = (obj["lanes"].is_string()?atof(obj["lanes"].get<std::string>().c_str()):obj["lanes"].get<double>());
        }
        if(obj.contains("lanel"))
        {
            msg.lanel = (obj["lanel"].is_string()?atof(obj["lanel"].get<std::string>().c_str()):obj["lanel"].get<double>());
        }
        if(obj.contains("anglediff"))
        {
            msg.anglediff = (obj["anglediff"].is_string()?atof(obj["anglediff"].get<std::string>().c_str()):obj["anglediff"].get<double>());
        }
        if(obj.contains("disttoleftboundary"))
        {
            msg.disttoleftboundary = (obj["disttoleftboundary"].is_string()?atof(obj["disttoleftboundary"].get<std::string>().c_str()):obj["disttoleftboundary"].get<double>());
        }
        if(obj.contains("disttorightboundary"))
        {
            msg.disttorightboundary = (obj["disttorightboundary"].is_string()?atof(obj["disttorightboundary"].get<std::string>().c_str()):obj["disttorightboundary"].get<double>());
        }
        if(obj.contains("laneheading"))
        {
            msg.laneheading = (obj["laneheading"].is_string()?atof(obj["laneheading"].get<std::string>().c_str()):obj["laneheading"].get<double>());
        }
        if(obj.contains("lanetype"))
        {
            msg.lanetype = (obj["lanetype"].is_string()?atoi(obj["lanetype"].get<std::string>().c_str()):obj["lanetype"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionLaneFeature from_json<ApollopredictionLaneFeature>(nlohmann::json obj){
        return from_json_ApollopredictionLaneFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneFeature &dt)
    {
        dt=from_json_ApollopredictionLaneFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
