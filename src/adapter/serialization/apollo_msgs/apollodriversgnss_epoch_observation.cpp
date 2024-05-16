#include "adapter/serialization/apollo_msgs/apollodriversgnss_epoch_observation.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssEpochObservation &msg) {
        nlohmann::json obj;
        obj["receiverid"] = (msg.receiverid);
        obj["gnsstimetype"] = (msg.gnsstimetype);
        obj["gnssweek"] = (msg.gnssweek);
        obj["gnssseconds"] = (msg.gnssseconds);
        obj["positionx"] = (msg.positionx);
        obj["positiony"] = (msg.positiony);
        obj["positionz"] = (msg.positionz);
        obj["healthflag"] = (msg.healthflag);
        obj["satobsnum"] = (msg.satobsnum);
        nlohmann::json arr_satobs;
        for (auto it = msg.satobs.begin(); it != msg.satobs.end(); ++it) {
            arr_satobs.push_back(to_json(*it));
        }
        obj["satobs"] = arr_satobs;
        return obj;
    }
    ApollodriversgnssEpochObservation from_json_ApollodriversgnssEpochObservation (nlohmann::json obj) {
        ApollodriversgnssEpochObservation msg;
        if(obj.contains("receiverid"))
        {
            msg.receiverid = (obj["receiverid"].is_string()?atoi(obj["receiverid"].get<std::string>().c_str()):obj["receiverid"].get<uint32_t>());
        }
        if(obj.contains("gnsstimetype"))
        {
            msg.gnsstimetype = (obj["gnsstimetype"].is_string()?atoi(obj["gnsstimetype"].get<std::string>().c_str()):obj["gnsstimetype"].get<int>());
        }
        if(obj.contains("gnssweek"))
        {
            msg.gnssweek = (obj["gnssweek"].is_string()?atoi(obj["gnssweek"].get<std::string>().c_str()):obj["gnssweek"].get<uint32_t>());
        }
        if(obj.contains("gnssseconds"))
        {
            msg.gnssseconds = (obj["gnssseconds"].is_string()?atof(obj["gnssseconds"].get<std::string>().c_str()):obj["gnssseconds"].get<double>());
        }
        if(obj.contains("positionx"))
        {
            msg.positionx = (obj["positionx"].is_string()?atof(obj["positionx"].get<std::string>().c_str()):obj["positionx"].get<double>());
        }
        if(obj.contains("positiony"))
        {
            msg.positiony = (obj["positiony"].is_string()?atof(obj["positiony"].get<std::string>().c_str()):obj["positiony"].get<double>());
        }
        if(obj.contains("positionz"))
        {
            msg.positionz = (obj["positionz"].is_string()?atof(obj["positionz"].get<std::string>().c_str()):obj["positionz"].get<double>());
        }
        if(obj.contains("healthflag"))
        {
            msg.healthflag = (obj["healthflag"].is_string()?atoi(obj["healthflag"].get<std::string>().c_str()):obj["healthflag"].get<uint32_t>());
        }
        if(obj.contains("satobsnum"))
        {
            msg.satobsnum = (obj["satobsnum"].is_string()?atoi(obj["satobsnum"].get<std::string>().c_str()):obj["satobsnum"].get<uint32_t>());
        }
        if(obj.contains("satobs"))
        {
            if(obj["satobs"].is_array())
            {
                for (auto& element : obj["satobs"])
                {
                    msg.satobs.push_back(from_json_ApollodriversgnssSatelliteObservation(element));
                }
            }
            else
            {
                msg.satobs.push_back(from_json_ApollodriversgnssSatelliteObservation(obj["satobs"]));
            }
        }
        return msg;
    }
    template <>
    ApollodriversgnssEpochObservation from_json<ApollodriversgnssEpochObservation>(nlohmann::json obj){
        return from_json_ApollodriversgnssEpochObservation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssEpochObservation &dt)
    {
        dt=from_json_ApollodriversgnssEpochObservation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssEpochObservation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssEpochObservation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
