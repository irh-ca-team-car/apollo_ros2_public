#include "adapter/serialization/internal/prediction/obstacle.h"
#include "adapter/serialization/internal/hdmap/laneinfo.h"
#include "adapter/serialization/internal/hdmap/junctioninfo.h"
namespace apollo_msgs::msg
{
    using apollo::hdmap::LaneInfo;
    nlohmann::json to_json(const apollo::prediction::Obstacle &msg)
    {
        nlohmann::json obj;

        obj["id_"] = msg.id_;

        nlohmann::json feature_history_;
        for (auto &&i : msg.feature_history_)
        {
            feature_history_.push_back(to_json(i));
        }
        obj["feature_history_"] = feature_history_;

        nlohmann::json current_lanes_;
        for (auto &&i : msg.current_lanes_)
        {
            if (i != nullptr)
                current_lanes_.push_back(to_json(*i));
            else
                current_lanes_.push_back(nullptr);
        }
        obj["current_lanes_"] = current_lanes_;

        obj["obstacle_conf_"] = to_json(msg.obstacle_conf_);
        obj["type_"] = (int)msg.type_;

   /*   if (msg.clusters_ptr_ != nullptr)
        {
            nlohmann::json clusters_ptr_;
            nlohmann::json lane_obstacles_;
            for (auto &&exits : msg.clusters_ptr_->lane_obstacles_)
            {
                nlohmann::json lane_list;
                for (auto &&laneobs : exits.second)
                {
                    lane_list.push_back(to_json(laneobs));
                }

                lane_obstacles_[exits.first] = lane_list;
            }
            clusters_ptr_["lane_obstacles_"] = lane_obstacles_;
            nlohmann::json lane_id_stop_sign_map_;
            for (auto &&exits : msg.clusters_ptr_->lane_id_stop_sign_map_)
            {
                lane_id_stop_sign_map_[exits.first] = to_json(exits.second);
            }
            clusters_ptr_["lane_id_stop_sign_map_"] = lane_id_stop_sign_map_;

            obj["clusters_ptr_"] = clusters_ptr_;
        }
        if (msg.junction_analyzer_ != nullptr)
        {
            nlohmann::json junction_analyzer_;
            if (msg.junction_analyzer_->junction_info_ptr_ != nullptr)
            {
                junction_analyzer_["junction_info_ptr_"] = to_json(*msg.junction_analyzer_->junction_info_ptr_);
            }
            nlohmann::json junction_exits_;
            for (auto &&exits : msg.junction_analyzer_->junction_exits_)
            {
                junction_exits_[exits.first] = to_json(exits.second);
            }
            junction_analyzer_["junction_exits_"] = junction_exits_;

            nlohmann::json junction_features_;
            for (auto &&exits : msg.junction_analyzer_->junction_features_)
            {
                junction_features_[exits.first] = to_json(exits.second);
            }
            junction_analyzer_["junction_features_"] = junction_features_;

            obj["junction_analyzer_"] = junction_analyzer_;
        }
        */
        return obj;
    }
    apollo::prediction::Obstacle from_json_Obstacle(nlohmann::json obj)
    {
        apollo::prediction::Obstacle msg;
        if (obj.contains("id_"))
            msg.id_ = (obj["id_"].is_string() ? atoi(obj["id_"].get<std::string>().c_str()) : obj["id_"].get<int>());
        std::deque<apollo::prediction::Feature> feature_history_;
        if (obj.contains("feature_history_"))
        {
            for (auto &&i : obj["feature_history_"])
            {
                feature_history_.push_back(from_json_ApollopredictionFeature(i));
            }
        }
        msg.feature_history_ = feature_history_;
        std::vector<std::shared_ptr<const apollo::hdmap::LaneInfo>> current_lanes_;
        if (obj.contains("current_lanes_"))
        {
            for (auto &&i : obj["current_lanes_"])
            {
                if (i.is_null())
                    current_lanes_.push_back(nullptr);
                else
                    current_lanes_.push_back(std::make_shared<LaneInfo>(from_json_LaneInfo(i)));
            }
        }
        msg.current_lanes_ = current_lanes_;

        if (obj.contains("obstacle_conf_"))
            msg.obstacle_conf_ = from_json_ApollopredictionObstacleConf(obj["obstacle_conf_"]);
        if (obj.contains("type_"))
            msg.id_ = (apollo::perception::PerceptionObstacle::Type)(obj["type_"].is_string() ? atoi(obj["type_"].get<std::string>().c_str()) : obj["type_"].get<int>());
        if (obj.contains("clusters_ptr_"))
        {
            nlohmann::json clusters_ptr_ = obj["clusters_ptr_"];
            //TODO cluster, maybe ignore cluster
            /* nlohmann::json clusters_ptr_;
            nlohmann::json lane_obstacles_;
            for (auto &&exits : msg.clusters_ptr_->lane_obstacles_)
            {
                nlohmann::json lane_list;
                for (auto &&laneobs : exits.second)
                {
                    lane_list.push_back(to_json(laneobs));
                }

                lane_obstacles_[exits.first] = lane_list;
            }
            clusters_ptr_["lane_obstacles_"] = lane_obstacles_;
            nlohmann::json lane_id_stop_sign_map_;
            for (auto &&exits : msg.clusters_ptr_->lane_id_stop_sign_map_)
            {
                lane_id_stop_sign_map_[exits.first] = to_json(exits.second);
            }
            clusters_ptr_["lane_id_stop_sign_map_"] = lane_id_stop_sign_map_;

            obj["clusters_ptr_"] = clusters_ptr_;*/
        }
        if (obj.contains("junction_analyzer_"))
        {
            //TODO junction_analyzer_ should we ignore
        }

        return msg;
    }
    template <>
    apollo::prediction::Obstacle from_json<apollo::prediction::Obstacle>(nlohmann::json obj)
    {
        return from_json_Obstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, apollo::prediction::Obstacle &dt)
    {
        dt = from_json_Obstacle(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const apollo::prediction::Obstacle &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::prediction::Obstacle &dt)
    {
        return os << to_json(dt).dump();
    }
}
