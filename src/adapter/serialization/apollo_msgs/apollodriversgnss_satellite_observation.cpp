#include "adapter/serialization/apollo_msgs/apollodriversgnss_satellite_observation.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssSatelliteObservation &msg) {
        nlohmann::json obj;
        obj["satprn"] = (msg.satprn);
        obj["satsys"] = (msg.satsys);
        obj["bandobsnum"] = (msg.bandobsnum);
        nlohmann::json arr_bandobs;
        for (auto it = msg.bandobs.begin(); it != msg.bandobs.end(); ++it) {
            arr_bandobs.push_back(to_json(*it));
        }
        obj["bandobs"] = arr_bandobs;
        return obj;
    }
    ApollodriversgnssSatelliteObservation from_json_ApollodriversgnssSatelliteObservation (nlohmann::json obj) {
        ApollodriversgnssSatelliteObservation msg;
        if(obj.contains("satprn"))
        {
            msg.satprn = (obj["satprn"].is_string()?atoi(obj["satprn"].get<std::string>().c_str()):obj["satprn"].get<uint32_t>());
        }
        if(obj.contains("satsys"))
        {
            msg.satsys = (obj["satsys"].is_string()?atoi(obj["satsys"].get<std::string>().c_str()):obj["satsys"].get<int>());
        }
        if(obj.contains("bandobsnum"))
        {
            msg.bandobsnum = (obj["bandobsnum"].is_string()?atoi(obj["bandobsnum"].get<std::string>().c_str()):obj["bandobsnum"].get<uint32_t>());
        }
        if(obj.contains("bandobs"))
        {
            if(obj["bandobs"].is_array())
            {
                for (auto& element : obj["bandobs"])
                {
                    msg.bandobs.push_back(from_json_ApollodriversgnssBandObservation(element));
                }
            }
            else
            {
                msg.bandobs.push_back(from_json_ApollodriversgnssBandObservation(obj["bandobs"]));
            }
        }
        return msg;
    }
    template <>
    ApollodriversgnssSatelliteObservation from_json<ApollodriversgnssSatelliteObservation>(nlohmann::json obj){
        return from_json_ApollodriversgnssSatelliteObservation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssSatelliteObservation &dt)
    {
        dt=from_json_ApollodriversgnssSatelliteObservation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssSatelliteObservation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssSatelliteObservation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
