#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_shape_filter_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfShapeFilterConfig &msg) {
        nlohmann::json obj;
        obj["bottompointsignorethreshold"] = (msg.bottompointsignorethreshold);
        obj["toppointsignorethreshold"] = (msg.toppointsignorethreshold);
        return obj;
    }
    ApolloperceptionlidarMlfShapeFilterConfig from_json_ApolloperceptionlidarMlfShapeFilterConfig (nlohmann::json obj) {
        ApolloperceptionlidarMlfShapeFilterConfig msg;
        if(obj.contains("bottompointsignorethreshold"))
        {
            msg.bottompointsignorethreshold = (obj["bottompointsignorethreshold"].is_string()?atof(obj["bottompointsignorethreshold"].get<std::string>().c_str()):obj["bottompointsignorethreshold"].get<double>());
        }
        if(obj.contains("toppointsignorethreshold"))
        {
            msg.toppointsignorethreshold = (obj["toppointsignorethreshold"].is_string()?atof(obj["toppointsignorethreshold"].get<std::string>().c_str()):obj["toppointsignorethreshold"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfShapeFilterConfig from_json<ApolloperceptionlidarMlfShapeFilterConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfShapeFilterConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfShapeFilterConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfShapeFilterConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfShapeFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfShapeFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
