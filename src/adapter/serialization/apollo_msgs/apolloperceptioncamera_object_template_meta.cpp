#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_object_template_meta.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraObjectTemplateMeta &msg) {
        nlohmann::json obj;
        obj["unknown"] = to_json(msg.unknown);
        obj["unknownmovable"] = to_json(msg.unknownmovable);
        obj["unknownunmovable"] = to_json(msg.unknownunmovable);
        obj["car"] = to_json(msg.car);
        obj["van"] = to_json(msg.van);
        obj["truck"] = to_json(msg.truck);
        obj["bus"] = to_json(msg.bus);
        obj["cyclist"] = to_json(msg.cyclist);
        obj["motorcyclist"] = to_json(msg.motorcyclist);
        obj["tricyclist"] = to_json(msg.tricyclist);
        obj["pedestrian"] = to_json(msg.pedestrian);
        obj["trafficcone"] = to_json(msg.trafficcone);
        obj["maxdimchangeratio"] = (msg.maxdimchangeratio);
        return obj;
    }
    ApolloperceptioncameraObjectTemplateMeta from_json_ApolloperceptioncameraObjectTemplateMeta (nlohmann::json obj) {
        ApolloperceptioncameraObjectTemplateMeta msg;
        if(obj.contains("unknown"))
        {
            msg.unknown = from_json_ApolloperceptioncameraObjectTemplate(obj["unknown"]);
        }
        if(obj.contains("unknownmovable"))
        {
            msg.unknownmovable = from_json_ApolloperceptioncameraObjectTemplate(obj["unknownmovable"]);
        }
        if(obj.contains("unknownunmovable"))
        {
            msg.unknownunmovable = from_json_ApolloperceptioncameraObjectTemplate(obj["unknownunmovable"]);
        }
        if(obj.contains("car"))
        {
            msg.car = from_json_ApolloperceptioncameraObjectTemplate(obj["car"]);
        }
        if(obj.contains("van"))
        {
            msg.van = from_json_ApolloperceptioncameraObjectTemplate(obj["van"]);
        }
        if(obj.contains("truck"))
        {
            msg.truck = from_json_ApolloperceptioncameraObjectTemplate(obj["truck"]);
        }
        if(obj.contains("bus"))
        {
            msg.bus = from_json_ApolloperceptioncameraObjectTemplate(obj["bus"]);
        }
        if(obj.contains("cyclist"))
        {
            msg.cyclist = from_json_ApolloperceptioncameraObjectTemplate(obj["cyclist"]);
        }
        if(obj.contains("motorcyclist"))
        {
            msg.motorcyclist = from_json_ApolloperceptioncameraObjectTemplate(obj["motorcyclist"]);
        }
        if(obj.contains("tricyclist"))
        {
            msg.tricyclist = from_json_ApolloperceptioncameraObjectTemplate(obj["tricyclist"]);
        }
        if(obj.contains("pedestrian"))
        {
            msg.pedestrian = from_json_ApolloperceptioncameraObjectTemplate(obj["pedestrian"]);
        }
        if(obj.contains("trafficcone"))
        {
            msg.trafficcone = from_json_ApolloperceptioncameraObjectTemplate(obj["trafficcone"]);
        }
        if(obj.contains("maxdimchangeratio"))
        {
            msg.maxdimchangeratio = (obj["maxdimchangeratio"].is_string()?(float)atof(obj["maxdimchangeratio"].get<std::string>().c_str()):obj["maxdimchangeratio"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraObjectTemplateMeta from_json<ApolloperceptioncameraObjectTemplateMeta>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraObjectTemplateMeta(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraObjectTemplateMeta &dt)
    {
        dt=from_json_ApolloperceptioncameraObjectTemplateMeta(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraObjectTemplateMeta & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraObjectTemplateMeta & dt)
    {
        os << to_json(dt);
        return os;
    }
}
