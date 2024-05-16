#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dimension_statistics.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDimensionStatistics &msg) {
        nlohmann::json obj;
        obj["meanh"] = (msg.meanh);
        obj["meanw"] = (msg.meanw);
        obj["meanl"] = (msg.meanl);
        obj["stdh"] = (msg.stdh);
        obj["stdw"] = (msg.stdw);
        obj["stdl"] = (msg.stdl);
        return obj;
    }
    ApolloperceptioninferenceDimensionStatistics from_json_ApolloperceptioninferenceDimensionStatistics (nlohmann::json obj) {
        ApolloperceptioninferenceDimensionStatistics msg;
        if(obj.contains("meanh"))
        {
            msg.meanh = (obj["meanh"].is_string()?(float)atof(obj["meanh"].get<std::string>().c_str()):obj["meanh"].get<float>());
        }
        if(obj.contains("meanw"))
        {
            msg.meanw = (obj["meanw"].is_string()?(float)atof(obj["meanw"].get<std::string>().c_str()):obj["meanw"].get<float>());
        }
        if(obj.contains("meanl"))
        {
            msg.meanl = (obj["meanl"].is_string()?(float)atof(obj["meanl"].get<std::string>().c_str()):obj["meanl"].get<float>());
        }
        if(obj.contains("stdh"))
        {
            msg.stdh = (obj["stdh"].is_string()?(float)atof(obj["stdh"].get<std::string>().c_str()):obj["stdh"].get<float>());
        }
        if(obj.contains("stdw"))
        {
            msg.stdw = (obj["stdw"].is_string()?(float)atof(obj["stdw"].get<std::string>().c_str()):obj["stdw"].get<float>());
        }
        if(obj.contains("stdl"))
        {
            msg.stdl = (obj["stdl"].is_string()?(float)atof(obj["stdl"].get<std::string>().c_str()):obj["stdl"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDimensionStatistics from_json<ApolloperceptioninferenceDimensionStatistics>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDimensionStatistics(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDimensionStatistics &dt)
    {
        dt=from_json_ApolloperceptioninferenceDimensionStatistics(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDimensionStatistics & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDimensionStatistics & dt)
    {
        os << to_json(dt);
        return os;
    }
}
