#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_distance_weight.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfDistanceWeight &msg) {
        nlohmann::json obj;
        obj["sensornamepair"] = (msg.sensornamepair);
        obj["locationdistweight"] = (msg.locationdistweight);
        obj["directiondistweight"] = (msg.directiondistweight);
        obj["bboxsizedistweight"] = (msg.bboxsizedistweight);
        obj["pointnumdistweight"] = (msg.pointnumdistweight);
        obj["histogramdistweight"] = (msg.histogramdistweight);
        obj["centroidshiftdistweight"] = (msg.centroidshiftdistweight);
        obj["bboxioudistweight"] = (msg.bboxioudistweight);
        obj["semanticmapdistweight"] = (msg.semanticmapdistweight);
        return obj;
    }
    ApolloperceptionlidarMlfDistanceWeight from_json_ApolloperceptionlidarMlfDistanceWeight (nlohmann::json obj) {
        ApolloperceptionlidarMlfDistanceWeight msg;
        if(obj.contains("sensornamepair"))
        {
            msg.sensornamepair = (obj["sensornamepair"].is_string()?(obj["sensornamepair"].get<std::string>().c_str()):obj["sensornamepair"].get<std::string>());
        }
        if(obj.contains("locationdistweight"))
        {
            msg.locationdistweight = (obj["locationdistweight"].is_string()?(float)atof(obj["locationdistweight"].get<std::string>().c_str()):obj["locationdistweight"].get<float>());
        }
        if(obj.contains("directiondistweight"))
        {
            msg.directiondistweight = (obj["directiondistweight"].is_string()?(float)atof(obj["directiondistweight"].get<std::string>().c_str()):obj["directiondistweight"].get<float>());
        }
        if(obj.contains("bboxsizedistweight"))
        {
            msg.bboxsizedistweight = (obj["bboxsizedistweight"].is_string()?(float)atof(obj["bboxsizedistweight"].get<std::string>().c_str()):obj["bboxsizedistweight"].get<float>());
        }
        if(obj.contains("pointnumdistweight"))
        {
            msg.pointnumdistweight = (obj["pointnumdistweight"].is_string()?(float)atof(obj["pointnumdistweight"].get<std::string>().c_str()):obj["pointnumdistweight"].get<float>());
        }
        if(obj.contains("histogramdistweight"))
        {
            msg.histogramdistweight = (obj["histogramdistweight"].is_string()?(float)atof(obj["histogramdistweight"].get<std::string>().c_str()):obj["histogramdistweight"].get<float>());
        }
        if(obj.contains("centroidshiftdistweight"))
        {
            msg.centroidshiftdistweight = (obj["centroidshiftdistweight"].is_string()?(float)atof(obj["centroidshiftdistweight"].get<std::string>().c_str()):obj["centroidshiftdistweight"].get<float>());
        }
        if(obj.contains("bboxioudistweight"))
        {
            msg.bboxioudistweight = (obj["bboxioudistweight"].is_string()?(float)atof(obj["bboxioudistweight"].get<std::string>().c_str()):obj["bboxioudistweight"].get<float>());
        }
        if(obj.contains("semanticmapdistweight"))
        {
            msg.semanticmapdistweight = (obj["semanticmapdistweight"].is_string()?(float)atof(obj["semanticmapdistweight"].get<std::string>().c_str()):obj["semanticmapdistweight"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfDistanceWeight from_json<ApolloperceptionlidarMlfDistanceWeight>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfDistanceWeight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfDistanceWeight &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfDistanceWeight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfDistanceWeight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfDistanceWeight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
