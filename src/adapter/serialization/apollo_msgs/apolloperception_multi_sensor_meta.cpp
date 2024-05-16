#include "adapter/serialization/apollo_msgs/apolloperception_multi_sensor_meta.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMultiSensorMeta &msg) {
        nlohmann::json obj;
        nlohmann::json arr_sensormeta;
        for (auto it = msg.sensormeta.begin(); it != msg.sensormeta.end(); ++it) {
            arr_sensormeta.push_back(to_json(*it));
        }
        obj["sensormeta"] = arr_sensormeta;
        return obj;
    }
    ApolloperceptionMultiSensorMeta from_json_ApolloperceptionMultiSensorMeta (nlohmann::json obj) {
        ApolloperceptionMultiSensorMeta msg;
        if(obj.contains("sensormeta"))
        {
            if(obj["sensormeta"].is_array())
            {
                for (auto& element : obj["sensormeta"])
                {
                    msg.sensormeta.push_back(from_json_ApolloperceptionSensorMeta(element));
                }
            }
            else
            {
                msg.sensormeta.push_back(from_json_ApolloperceptionSensorMeta(obj["sensormeta"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionMultiSensorMeta from_json<ApolloperceptionMultiSensorMeta>(nlohmann::json obj){
        return from_json_ApolloperceptionMultiSensorMeta(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMultiSensorMeta &dt)
    {
        dt=from_json_ApolloperceptionMultiSensorMeta(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMultiSensorMeta & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMultiSensorMeta & dt)
    {
        os << to_json(dt);
        return os;
    }
}
