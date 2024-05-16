#include "adapter/serialization/apollo_msgs/apolloprediction_lane_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneSegment &msg) {
        nlohmann::json obj;
        obj["laneid"] = (msg.laneid);
        obj["starts"] = (msg.starts);
        obj["ends"] = (msg.ends);
        obj["laneturntype"] = (msg.laneturntype);
        nlohmann::json arr_lanepoint;
        for (auto it = msg.lanepoint.begin(); it != msg.lanepoint.end(); ++it) {
            arr_lanepoint.push_back(to_json(*it));
        }
        obj["lanepoint"] = arr_lanepoint;
        obj["adcs"] = (msg.adcs);
        obj["adclanepointidx"] = (msg.adclanepointidx);
        obj["totallength"] = (msg.totallength);
        return obj;
    }
    ApollopredictionLaneSegment from_json_ApollopredictionLaneSegment (nlohmann::json obj) {
        ApollopredictionLaneSegment msg;
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<std::string>());
        }
        if(obj.contains("starts"))
        {
            msg.starts = (obj["starts"].is_string()?atof(obj["starts"].get<std::string>().c_str()):obj["starts"].get<double>());
        }
        if(obj.contains("ends"))
        {
            msg.ends = (obj["ends"].is_string()?atof(obj["ends"].get<std::string>().c_str()):obj["ends"].get<double>());
        }
        if(obj.contains("laneturntype"))
        {
            msg.laneturntype = (obj["laneturntype"].is_string()?atoi(obj["laneturntype"].get<std::string>().c_str()):obj["laneturntype"].get<uint32_t>());
        }
        if(obj.contains("lanepoint"))
        {
            if(obj["lanepoint"].is_array())
            {
                for (auto& element : obj["lanepoint"])
                {
                    msg.lanepoint.push_back(from_json_ApollopredictionLanePoint(element));
                }
            }
            else
            {
                msg.lanepoint.push_back(from_json_ApollopredictionLanePoint(obj["lanepoint"]));
            }
        }
        if(obj.contains("adcs"))
        {
            msg.adcs = (obj["adcs"].is_string()?atof(obj["adcs"].get<std::string>().c_str()):obj["adcs"].get<double>());
        }
        if(obj.contains("adclanepointidx"))
        {
            msg.adclanepointidx = (obj["adclanepointidx"].is_string()?atoi(obj["adclanepointidx"].get<std::string>().c_str()):obj["adclanepointidx"].get<int>());
        }
        if(obj.contains("totallength"))
        {
            msg.totallength = (obj["totallength"].is_string()?atof(obj["totallength"].get<std::string>().c_str()):obj["totallength"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionLaneSegment from_json<ApollopredictionLaneSegment>(nlohmann::json obj){
        return from_json_ApollopredictionLaneSegment(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneSegment &dt)
    {
        dt=from_json_ApollopredictionLaneSegment(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
}
