#include "adapter/serialization/apollo_msgs/apollocommon_latency_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyParam &msg) {
        nlohmann::json obj;
        obj["deadtime"] = (msg.deadtime);
        obj["risetime"] = (msg.risetime);
        obj["peaktime"] = (msg.peaktime);
        obj["settlingtime"] = (msg.settlingtime);
        return obj;
    }
    ApollocommonLatencyParam from_json_ApollocommonLatencyParam (nlohmann::json obj) {
        ApollocommonLatencyParam msg;
        if(obj.contains("deadtime"))
        {
            msg.deadtime = (obj["deadtime"].is_string()?atof(obj["deadtime"].get<std::string>().c_str()):obj["deadtime"].get<double>());
        }
        if(obj.contains("risetime"))
        {
            msg.risetime = (obj["risetime"].is_string()?atof(obj["risetime"].get<std::string>().c_str()):obj["risetime"].get<double>());
        }
        if(obj.contains("peaktime"))
        {
            msg.peaktime = (obj["peaktime"].is_string()?atof(obj["peaktime"].get<std::string>().c_str()):obj["peaktime"].get<double>());
        }
        if(obj.contains("settlingtime"))
        {
            msg.settlingtime = (obj["settlingtime"].is_string()?atof(obj["settlingtime"].get<std::string>().c_str()):obj["settlingtime"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonLatencyParam from_json<ApollocommonLatencyParam>(nlohmann::json obj){
        return from_json_ApollocommonLatencyParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyParam &dt)
    {
        dt=from_json_ApollocommonLatencyParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
