#include "adapter/serialization/apollo_msgs/apolloplanning_move_dest_lane_config_table.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMoveDestLaneConfigTable &msg) {
        nlohmann::json obj;
        nlohmann::json arr_lateralshift;
        for (auto it = msg.lateralshift.begin(); it != msg.lateralshift.end(); ++it) {
            arr_lateralshift.push_back(to_json(*it));
        }
        obj["lateralshift"] = arr_lateralshift;
        return obj;
    }
    ApolloplanningMoveDestLaneConfigTable from_json_ApolloplanningMoveDestLaneConfigTable (nlohmann::json obj) {
        ApolloplanningMoveDestLaneConfigTable msg;
        if(obj.contains("lateralshift"))
        {
            if(obj["lateralshift"].is_array())
            {
                for (auto& element : obj["lateralshift"])
                {
                    msg.lateralshift.push_back(from_json_ApolloplanningShiftConfig(element));
                }
            }
            else
            {
                msg.lateralshift.push_back(from_json_ApolloplanningShiftConfig(obj["lateralshift"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningMoveDestLaneConfigTable from_json<ApolloplanningMoveDestLaneConfigTable>(nlohmann::json obj){
        return from_json_ApolloplanningMoveDestLaneConfigTable(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMoveDestLaneConfigTable &dt)
    {
        dt=from_json_ApolloplanningMoveDestLaneConfigTable(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMoveDestLaneConfigTable & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMoveDestLaneConfigTable & dt)
    {
        os << to_json(dt);
        return os;
    }
}
