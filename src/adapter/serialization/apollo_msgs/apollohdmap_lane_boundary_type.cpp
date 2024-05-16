#include "adapter/serialization/apollo_msgs/apollohdmap_lane_boundary_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneBoundaryType &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        nlohmann::json arr_types;
        for (auto it = msg.types.begin(); it != msg.types.end(); ++it) {
            arr_types.push_back((*it));
        }
        obj["types"] = arr_types;
        return obj;
    }
    ApollohdmapLaneBoundaryType from_json_ApollohdmapLaneBoundaryType (nlohmann::json obj) {
        ApollohdmapLaneBoundaryType msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("types"))
        {
            if(obj["types"].is_array())
            {
                for (auto& element : obj["types"])
                {
                    msg.types.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.types.push_back((obj["types"].is_string()?atoi(obj["types"].get<std::string>().c_str()):obj["types"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapLaneBoundaryType from_json<ApollohdmapLaneBoundaryType>(nlohmann::json obj){
        return from_json_ApollohdmapLaneBoundaryType(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneBoundaryType &dt)
    {
        dt=from_json_ApollohdmapLaneBoundaryType(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneBoundaryType & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneBoundaryType & dt)
    {
        os << to_json(dt);
        return os;
    }
}
