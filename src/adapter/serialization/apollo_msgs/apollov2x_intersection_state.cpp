#include "adapter/serialization/apollo_msgs/apollov2x_intersection_state.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xIntersectionState &msg) {
        nlohmann::json obj;
        obj["intersectionid"] = (msg.intersectionid);
        nlohmann::json arr_phases;
        for (auto it = msg.phases.begin(); it != msg.phases.end(); ++it) {
            arr_phases.push_back(to_json(*it));
        }
        obj["phases"] = arr_phases;
        obj["moy"] = (msg.moy);
        obj["timestampdsecond"] = (msg.timestampdsecond);
        return obj;
    }
    Apollov2xIntersectionState from_json_Apollov2xIntersectionState (nlohmann::json obj) {
        Apollov2xIntersectionState msg;
        if(obj.contains("intersectionid"))
        {
            msg.intersectionid = (obj["intersectionid"].is_string()?atoi(obj["intersectionid"].get<std::string>().c_str()):obj["intersectionid"].get<int>());
        }
        if(obj.contains("phases"))
        {
            if(obj["phases"].is_array())
            {
                for (auto& element : obj["phases"])
                {
                    msg.phases.push_back(from_json_Apollov2xPhase(element));
                }
            }
            else
            {
                msg.phases.push_back(from_json_Apollov2xPhase(obj["phases"]));
            }
        }
        if(obj.contains("moy"))
        {
            msg.moy = (obj["moy"].is_string()?atoi(obj["moy"].get<std::string>().c_str()):obj["moy"].get<int>());
        }
        if(obj.contains("timestampdsecond"))
        {
            msg.timestampdsecond = (obj["timestampdsecond"].is_string()?atoi(obj["timestampdsecond"].get<std::string>().c_str()):obj["timestampdsecond"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xIntersectionState from_json<Apollov2xIntersectionState>(nlohmann::json obj){
        return from_json_Apollov2xIntersectionState(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xIntersectionState &dt)
    {
        dt=from_json_Apollov2xIntersectionState(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xIntersectionState & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xIntersectionState & dt)
    {
        os << to_json(dt);
        return os;
    }
}
