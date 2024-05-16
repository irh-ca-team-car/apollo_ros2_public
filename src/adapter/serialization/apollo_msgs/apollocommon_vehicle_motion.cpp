#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_motion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleMotion &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_vehiclemotionpoint;
        for (auto it = msg.vehiclemotionpoint.begin(); it != msg.vehiclemotionpoint.end(); ++it) {
            arr_vehiclemotionpoint.push_back(to_json(*it));
        }
        obj["vehiclemotionpoint"] = arr_vehiclemotionpoint;
        return obj;
    }
    ApollocommonVehicleMotion from_json_ApollocommonVehicleMotion (nlohmann::json obj) {
        ApollocommonVehicleMotion msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("vehiclemotionpoint"))
        {
            if(obj["vehiclemotionpoint"].is_array())
            {
                for (auto& element : obj["vehiclemotionpoint"])
                {
                    msg.vehiclemotionpoint.push_back(from_json_ApollocommonVehicleMotionPoint(element));
                }
            }
            else
            {
                msg.vehiclemotionpoint.push_back(from_json_ApollocommonVehicleMotionPoint(obj["vehiclemotionpoint"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonVehicleMotion from_json<ApollocommonVehicleMotion>(nlohmann::json obj){
        return from_json_ApollocommonVehicleMotion(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleMotion &dt)
    {
        dt=from_json_ApollocommonVehicleMotion(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleMotion & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleMotion & dt)
    {
        os << to_json(dt);
        return os;
    }
}
