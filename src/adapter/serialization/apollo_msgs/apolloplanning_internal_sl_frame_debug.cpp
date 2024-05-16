#include "adapter/serialization/apollo_msgs/apolloplanning_internal_sl_frame_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSLFrameDebug &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_sampleds;
        for (auto it = msg.sampleds.begin(); it != msg.sampleds.end(); ++it) {
            arr_sampleds.push_back((*it));
        }
        obj["sampleds"] = arr_sampleds;
        nlohmann::json arr_staticobstaclelowerbound;
        for (auto it = msg.staticobstaclelowerbound.begin(); it != msg.staticobstaclelowerbound.end(); ++it) {
            arr_staticobstaclelowerbound.push_back((*it));
        }
        obj["staticobstaclelowerbound"] = arr_staticobstaclelowerbound;
        nlohmann::json arr_dynamicobstaclelowerbound;
        for (auto it = msg.dynamicobstaclelowerbound.begin(); it != msg.dynamicobstaclelowerbound.end(); ++it) {
            arr_dynamicobstaclelowerbound.push_back((*it));
        }
        obj["dynamicobstaclelowerbound"] = arr_dynamicobstaclelowerbound;
        nlohmann::json arr_staticobstacleupperbound;
        for (auto it = msg.staticobstacleupperbound.begin(); it != msg.staticobstacleupperbound.end(); ++it) {
            arr_staticobstacleupperbound.push_back((*it));
        }
        obj["staticobstacleupperbound"] = arr_staticobstacleupperbound;
        nlohmann::json arr_dynamicobstacleupperbound;
        for (auto it = msg.dynamicobstacleupperbound.begin(); it != msg.dynamicobstacleupperbound.end(); ++it) {
            arr_dynamicobstacleupperbound.push_back((*it));
        }
        obj["dynamicobstacleupperbound"] = arr_dynamicobstacleupperbound;
        nlohmann::json arr_maplowerbound;
        for (auto it = msg.maplowerbound.begin(); it != msg.maplowerbound.end(); ++it) {
            arr_maplowerbound.push_back((*it));
        }
        obj["maplowerbound"] = arr_maplowerbound;
        nlohmann::json arr_mapupperbound;
        for (auto it = msg.mapupperbound.begin(); it != msg.mapupperbound.end(); ++it) {
            arr_mapupperbound.push_back((*it));
        }
        obj["mapupperbound"] = arr_mapupperbound;
        nlohmann::json arr_slpath;
        for (auto it = msg.slpath.begin(); it != msg.slpath.end(); ++it) {
            arr_slpath.push_back(to_json(*it));
        }
        obj["slpath"] = arr_slpath;
        nlohmann::json arr_aggregatedboundarys;
        for (auto it = msg.aggregatedboundarys.begin(); it != msg.aggregatedboundarys.end(); ++it) {
            arr_aggregatedboundarys.push_back((*it));
        }
        obj["aggregatedboundarys"] = arr_aggregatedboundarys;
        nlohmann::json arr_aggregatedboundarylow;
        for (auto it = msg.aggregatedboundarylow.begin(); it != msg.aggregatedboundarylow.end(); ++it) {
            arr_aggregatedboundarylow.push_back((*it));
        }
        obj["aggregatedboundarylow"] = arr_aggregatedboundarylow;
        nlohmann::json arr_aggregatedboundaryhigh;
        for (auto it = msg.aggregatedboundaryhigh.begin(); it != msg.aggregatedboundaryhigh.end(); ++it) {
            arr_aggregatedboundaryhigh.push_back((*it));
        }
        obj["aggregatedboundaryhigh"] = arr_aggregatedboundaryhigh;
        return obj;
    }
    ApolloplanningInternalSLFrameDebug from_json_ApolloplanningInternalSLFrameDebug (nlohmann::json obj) {
        ApolloplanningInternalSLFrameDebug msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("sampleds"))
        {
            if(obj["sampleds"].is_array())
            {
                for (auto& element : obj["sampleds"])
                {
                    msg.sampleds.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.sampleds.push_back((obj["sampleds"].is_string()?atof(obj["sampleds"].get<std::string>().c_str()):obj["sampleds"].get<double>()));
            }
        }
        if(obj.contains("staticobstaclelowerbound"))
        {
            if(obj["staticobstaclelowerbound"].is_array())
            {
                for (auto& element : obj["staticobstaclelowerbound"])
                {
                    msg.staticobstaclelowerbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.staticobstaclelowerbound.push_back((obj["staticobstaclelowerbound"].is_string()?atof(obj["staticobstaclelowerbound"].get<std::string>().c_str()):obj["staticobstaclelowerbound"].get<double>()));
            }
        }
        if(obj.contains("dynamicobstaclelowerbound"))
        {
            if(obj["dynamicobstaclelowerbound"].is_array())
            {
                for (auto& element : obj["dynamicobstaclelowerbound"])
                {
                    msg.dynamicobstaclelowerbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.dynamicobstaclelowerbound.push_back((obj["dynamicobstaclelowerbound"].is_string()?atof(obj["dynamicobstaclelowerbound"].get<std::string>().c_str()):obj["dynamicobstaclelowerbound"].get<double>()));
            }
        }
        if(obj.contains("staticobstacleupperbound"))
        {
            if(obj["staticobstacleupperbound"].is_array())
            {
                for (auto& element : obj["staticobstacleupperbound"])
                {
                    msg.staticobstacleupperbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.staticobstacleupperbound.push_back((obj["staticobstacleupperbound"].is_string()?atof(obj["staticobstacleupperbound"].get<std::string>().c_str()):obj["staticobstacleupperbound"].get<double>()));
            }
        }
        if(obj.contains("dynamicobstacleupperbound"))
        {
            if(obj["dynamicobstacleupperbound"].is_array())
            {
                for (auto& element : obj["dynamicobstacleupperbound"])
                {
                    msg.dynamicobstacleupperbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.dynamicobstacleupperbound.push_back((obj["dynamicobstacleupperbound"].is_string()?atof(obj["dynamicobstacleupperbound"].get<std::string>().c_str()):obj["dynamicobstacleupperbound"].get<double>()));
            }
        }
        if(obj.contains("maplowerbound"))
        {
            if(obj["maplowerbound"].is_array())
            {
                for (auto& element : obj["maplowerbound"])
                {
                    msg.maplowerbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.maplowerbound.push_back((obj["maplowerbound"].is_string()?atof(obj["maplowerbound"].get<std::string>().c_str()):obj["maplowerbound"].get<double>()));
            }
        }
        if(obj.contains("mapupperbound"))
        {
            if(obj["mapupperbound"].is_array())
            {
                for (auto& element : obj["mapupperbound"])
                {
                    msg.mapupperbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.mapupperbound.push_back((obj["mapupperbound"].is_string()?atof(obj["mapupperbound"].get<std::string>().c_str()):obj["mapupperbound"].get<double>()));
            }
        }
        if(obj.contains("slpath"))
        {
            if(obj["slpath"].is_array())
            {
                for (auto& element : obj["slpath"])
                {
                    msg.slpath.push_back(from_json_ApollocommonSLPoint(element));
                }
            }
            else
            {
                msg.slpath.push_back(from_json_ApollocommonSLPoint(obj["slpath"]));
            }
        }
        if(obj.contains("aggregatedboundarys"))
        {
            if(obj["aggregatedboundarys"].is_array())
            {
                for (auto& element : obj["aggregatedboundarys"])
                {
                    msg.aggregatedboundarys.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.aggregatedboundarys.push_back((obj["aggregatedboundarys"].is_string()?atof(obj["aggregatedboundarys"].get<std::string>().c_str()):obj["aggregatedboundarys"].get<double>()));
            }
        }
        if(obj.contains("aggregatedboundarylow"))
        {
            if(obj["aggregatedboundarylow"].is_array())
            {
                for (auto& element : obj["aggregatedboundarylow"])
                {
                    msg.aggregatedboundarylow.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.aggregatedboundarylow.push_back((obj["aggregatedboundarylow"].is_string()?atof(obj["aggregatedboundarylow"].get<std::string>().c_str()):obj["aggregatedboundarylow"].get<double>()));
            }
        }
        if(obj.contains("aggregatedboundaryhigh"))
        {
            if(obj["aggregatedboundaryhigh"].is_array())
            {
                for (auto& element : obj["aggregatedboundaryhigh"])
                {
                    msg.aggregatedboundaryhigh.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.aggregatedboundaryhigh.push_back((obj["aggregatedboundaryhigh"].is_string()?atof(obj["aggregatedboundaryhigh"].get<std::string>().c_str()):obj["aggregatedboundaryhigh"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSLFrameDebug from_json<ApolloplanningInternalSLFrameDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSLFrameDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSLFrameDebug &dt)
    {
        dt=from_json_ApolloplanningInternalSLFrameDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSLFrameDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSLFrameDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
