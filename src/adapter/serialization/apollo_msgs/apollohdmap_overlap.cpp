#include "adapter/serialization/apollo_msgs/apollohdmap_overlap.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapOverlap &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_object;
        for (auto it = msg.object.begin(); it != msg.object.end(); ++it) {
            arr_object.push_back(to_json(*it));
        }
        obj["object"] = arr_object;
        nlohmann::json arr_regionoverlap;
        for (auto it = msg.regionoverlap.begin(); it != msg.regionoverlap.end(); ++it) {
            arr_regionoverlap.push_back(to_json(*it));
        }
        obj["regionoverlap"] = arr_regionoverlap;
        return obj;
    }
    ApollohdmapOverlap from_json_ApollohdmapOverlap (nlohmann::json obj) {
        ApollohdmapOverlap msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("object"))
        {
            if(obj["object"].is_array())
            {
                for (auto& element : obj["object"])
                {
                    msg.object.push_back(from_json_ApollohdmapObjectOverlapInfo(element));
                }
            }
            else
            {
                msg.object.push_back(from_json_ApollohdmapObjectOverlapInfo(obj["object"]));
            }
        }
        if(obj.contains("regionoverlap"))
        {
            if(obj["regionoverlap"].is_array())
            {
                for (auto& element : obj["regionoverlap"])
                {
                    msg.regionoverlap.push_back(from_json_ApollohdmapRegionOverlapInfo(element));
                }
            }
            else
            {
                msg.regionoverlap.push_back(from_json_ApollohdmapRegionOverlapInfo(obj["regionoverlap"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapOverlap from_json<ApollohdmapOverlap>(nlohmann::json obj){
        return from_json_ApollohdmapOverlap(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapOverlap &dt)
    {
        dt=from_json_ApollohdmapOverlap(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapOverlap & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapOverlap & dt)
    {
        os << to_json(dt);
        return os;
    }
}
