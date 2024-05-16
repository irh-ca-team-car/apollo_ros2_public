#include "adapter/serialization/apollo_msgs/apolloplanning_sl_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSLBoundary &msg) {
        nlohmann::json obj;
        obj["starts"] = (msg.starts);
        obj["ends"] = (msg.ends);
        obj["startl"] = (msg.startl);
        obj["endl"] = (msg.endl);
        nlohmann::json arr_boundarypoint;
        for (auto it = msg.boundarypoint.begin(); it != msg.boundarypoint.end(); ++it) {
            arr_boundarypoint.push_back(to_json(*it));
        }
        obj["boundarypoint"] = arr_boundarypoint;
        return obj;
    }
    ApolloplanningSLBoundary from_json_ApolloplanningSLBoundary (nlohmann::json obj) {
        ApolloplanningSLBoundary msg;
        if(obj.contains("starts"))
        {
            msg.starts = (obj["starts"].is_string()?atof(obj["starts"].get<std::string>().c_str()):obj["starts"].get<double>());
        }
        if(obj.contains("ends"))
        {
            msg.ends = (obj["ends"].is_string()?atof(obj["ends"].get<std::string>().c_str()):obj["ends"].get<double>());
        }
        if(obj.contains("startl"))
        {
            msg.startl = (obj["startl"].is_string()?atof(obj["startl"].get<std::string>().c_str()):obj["startl"].get<double>());
        }
        if(obj.contains("endl"))
        {
            msg.endl = (obj["endl"].is_string()?atof(obj["endl"].get<std::string>().c_str()):obj["endl"].get<double>());
        }
        if(obj.contains("boundarypoint"))
        {
            if(obj["boundarypoint"].is_array())
            {
                for (auto& element : obj["boundarypoint"])
                {
                    msg.boundarypoint.push_back(from_json_ApollocommonSLPoint(element));
                }
            }
            else
            {
                msg.boundarypoint.push_back(from_json_ApollocommonSLPoint(obj["boundarypoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningSLBoundary from_json<ApolloplanningSLBoundary>(nlohmann::json obj){
        return from_json_ApolloplanningSLBoundary(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSLBoundary &dt)
    {
        dt=from_json_ApolloplanningSLBoundary(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSLBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSLBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
}
