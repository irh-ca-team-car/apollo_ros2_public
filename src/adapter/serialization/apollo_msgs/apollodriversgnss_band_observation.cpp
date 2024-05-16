#include "adapter/serialization/apollo_msgs/apollodriversgnss_band_observation.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssBandObservation &msg) {
        nlohmann::json obj;
        obj["bandid"] = (msg.bandid);
        obj["frequencyvalue"] = (msg.frequencyvalue);
        obj["pseudotype"] = (msg.pseudotype);
        obj["pseudorange"] = (msg.pseudorange);
        obj["carrierphase"] = (msg.carrierphase);
        obj["losslockindex"] = (msg.losslockindex);
        obj["doppler"] = (msg.doppler);
        obj["snr"] = (msg.snr);
        return obj;
    }
    ApollodriversgnssBandObservation from_json_ApollodriversgnssBandObservation (nlohmann::json obj) {
        ApollodriversgnssBandObservation msg;
        if(obj.contains("bandid"))
        {
            msg.bandid = (obj["bandid"].is_string()?atoi(obj["bandid"].get<std::string>().c_str()):obj["bandid"].get<int>());
        }
        if(obj.contains("frequencyvalue"))
        {
            msg.frequencyvalue = (obj["frequencyvalue"].is_string()?atof(obj["frequencyvalue"].get<std::string>().c_str()):obj["frequencyvalue"].get<double>());
        }
        if(obj.contains("pseudotype"))
        {
            msg.pseudotype = (obj["pseudotype"].is_string()?atoi(obj["pseudotype"].get<std::string>().c_str()):obj["pseudotype"].get<int>());
        }
        if(obj.contains("pseudorange"))
        {
            msg.pseudorange = (obj["pseudorange"].is_string()?atof(obj["pseudorange"].get<std::string>().c_str()):obj["pseudorange"].get<double>());
        }
        if(obj.contains("carrierphase"))
        {
            msg.carrierphase = (obj["carrierphase"].is_string()?atof(obj["carrierphase"].get<std::string>().c_str()):obj["carrierphase"].get<double>());
        }
        if(obj.contains("losslockindex"))
        {
            msg.losslockindex = (obj["losslockindex"].is_string()?atoi(obj["losslockindex"].get<std::string>().c_str()):obj["losslockindex"].get<uint32_t>());
        }
        if(obj.contains("doppler"))
        {
            msg.doppler = (obj["doppler"].is_string()?atof(obj["doppler"].get<std::string>().c_str()):obj["doppler"].get<double>());
        }
        if(obj.contains("snr"))
        {
            msg.snr = (obj["snr"].is_string()?(float)atof(obj["snr"].get<std::string>().c_str()):obj["snr"].get<float>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssBandObservation from_json<ApollodriversgnssBandObservation>(nlohmann::json obj){
        return from_json_ApollodriversgnssBandObservation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssBandObservation &dt)
    {
        dt=from_json_ApollodriversgnssBandObservation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssBandObservation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssBandObservation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
