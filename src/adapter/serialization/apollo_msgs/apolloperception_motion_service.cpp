#include "adapter/serialization/apollo_msgs/apolloperception_motion_service.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMotionService &msg) {
        nlohmann::json obj;
        nlohmann::json arr_vehiclestatus;
        for (auto it = msg.vehiclestatus.begin(); it != msg.vehiclestatus.end(); ++it) {
            arr_vehiclestatus.push_back(to_json(*it));
        }
        obj["vehiclestatus"] = arr_vehiclestatus;
        obj["apolloheader"] = to_json(msg.apolloheader);
        return obj;
    }
    ApolloperceptionMotionService from_json_ApolloperceptionMotionService (nlohmann::json obj) {
        ApolloperceptionMotionService msg;
        if(obj.contains("vehiclestatus"))
        {
            if(obj["vehiclestatus"].is_array())
            {
                for (auto& element : obj["vehiclestatus"])
                {
                    msg.vehiclestatus.push_back(from_json_ApolloperceptionVehicleStatus(element));
                }
            }
            else
            {
                msg.vehiclestatus.push_back(from_json_ApolloperceptionVehicleStatus(obj["vehiclestatus"]));
            }
        }
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionMotionService from_json<ApolloperceptionMotionService>(nlohmann::json obj){
        return from_json_ApolloperceptionMotionService(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMotionService &dt)
    {
        dt=from_json_ApolloperceptionMotionService(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMotionService & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMotionService & dt)
    {
        os << to_json(dt);
        return os;
    }
}
