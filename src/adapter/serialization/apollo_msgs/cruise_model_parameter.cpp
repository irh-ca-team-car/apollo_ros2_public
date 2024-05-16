#include "adapter/serialization/apollo_msgs/cruise_model_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const CruiseModelParameter &msg) {
        nlohmann::json obj;
        obj["lanefeatureconv"] = to_json(msg.lanefeatureconv);
        obj["lanefeaturemaxpool"] = to_json(msg.lanefeaturemaxpool);
        obj["lanefeatureavgpool"] = to_json(msg.lanefeatureavgpool);
        obj["obsfeaturefc"] = to_json(msg.obsfeaturefc);
        obj["classify"] = to_json(msg.classify);
        obj["regress"] = to_json(msg.regress);
        return obj;
    }
    CruiseModelParameter from_json_CruiseModelParameter (nlohmann::json obj) {
        CruiseModelParameter msg;
        if(obj.contains("lanefeatureconv"))
        {
            msg.lanefeatureconv = from_json_LaneFeatureConvParameter(obj["lanefeatureconv"]);
        }
        if(obj.contains("lanefeaturemaxpool"))
        {
            msg.lanefeaturemaxpool = from_json_MaxPool1dParameter(obj["lanefeaturemaxpool"]);
        }
        if(obj.contains("lanefeatureavgpool"))
        {
            msg.lanefeatureavgpool = from_json_AvgPool1dParameter(obj["lanefeatureavgpool"]);
        }
        if(obj.contains("obsfeaturefc"))
        {
            msg.obsfeaturefc = from_json_ObsFeatureFCParameter(obj["obsfeaturefc"]);
        }
        if(obj.contains("classify"))
        {
            msg.classify = from_json_ClassifyParameter(obj["classify"]);
        }
        if(obj.contains("regress"))
        {
            msg.regress = from_json_RegressParameter(obj["regress"]);
        }
        return msg;
    }
    template <>
    CruiseModelParameter from_json<CruiseModelParameter>(nlohmann::json obj){
        return from_json_CruiseModelParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, CruiseModelParameter &dt)
    {
        dt=from_json_CruiseModelParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const CruiseModelParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const CruiseModelParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
