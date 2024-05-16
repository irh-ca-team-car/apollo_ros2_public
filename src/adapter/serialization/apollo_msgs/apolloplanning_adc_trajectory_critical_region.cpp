#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory_critical_region.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningADCTrajectoryCriticalRegion &msg) {
        nlohmann::json obj;
        nlohmann::json arr_region;
        for (auto it = msg.region.begin(); it != msg.region.end(); ++it) {
            arr_region.push_back(to_json(*it));
        }
        obj["region"] = arr_region;
        return obj;
    }
    ApolloplanningADCTrajectoryCriticalRegion from_json_ApolloplanningADCTrajectoryCriticalRegion (nlohmann::json obj) {
        ApolloplanningADCTrajectoryCriticalRegion msg;
        if(obj.contains("region"))
        {
            if(obj["region"].is_array())
            {
                for (auto& element : obj["region"])
                {
                    msg.region.push_back(from_json_ApollocommonPolygon(element));
                }
            }
            else
            {
                msg.region.push_back(from_json_ApollocommonPolygon(obj["region"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningADCTrajectoryCriticalRegion from_json<ApolloplanningADCTrajectoryCriticalRegion>(nlohmann::json obj){
        return from_json_ApolloplanningADCTrajectoryCriticalRegion(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningADCTrajectoryCriticalRegion &dt)
    {
        dt=from_json_ApolloplanningADCTrajectoryCriticalRegion(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningADCTrajectoryCriticalRegion & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningADCTrajectoryCriticalRegion & dt)
    {
        os << to_json(dt);
        return os;
    }
}
