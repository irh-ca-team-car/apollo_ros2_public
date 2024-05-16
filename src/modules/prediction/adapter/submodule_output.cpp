#include "adapter/serialization/internal/prediction/submodule_output.h"
#include "adapter/serialization/internal/prediction/obstacle.h"

namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::prediction::SubmoduleOutput &msg)
    {
        nlohmann::json obj;

        nlohmann::json lst_curr_frame_obstacles_;
        for (auto &&i : msg.curr_frame_obstacles_)
        {
            lst_curr_frame_obstacles_.push_back(to_json(i));
        }
        obj["curr_frame_obstacles_"] = lst_curr_frame_obstacles_;

        obj["ego_vehicle_"] = to_json(msg.ego_vehicle_);

        nlohmann::json curr_frame_movable_obstacle_ids_;
        for (auto &&i : msg.curr_frame_movable_obstacle_ids_)
        {
            curr_frame_movable_obstacle_ids_.push_back((i));
        }
        obj["curr_frame_movable_obstacle_ids_"] = curr_frame_movable_obstacle_ids_;

        nlohmann::json curr_frame_unmovable_obstacle_ids_;
        for (auto &&i : msg.curr_frame_unmovable_obstacle_ids_)
        {
            curr_frame_unmovable_obstacle_ids_.push_back((i));
        }
        obj["curr_frame_unmovable_obstacle_ids_"] = curr_frame_unmovable_obstacle_ids_;

        nlohmann::json curr_frame_considered_obstacle_ids_;
        for (auto &&i : msg.curr_frame_considered_obstacle_ids_)
        {
            curr_frame_considered_obstacle_ids_.push_back((i));
        }
        obj["curr_frame_considered_obstacle_ids_"] = curr_frame_considered_obstacle_ids_;

        obj["frame_start_time_"] = msg.frame_start_time_.ToMicrosecond();
        obj["curr_scenario_"] = to_json(msg.curr_scenario_);

        return obj;
    }
    apollo::prediction::SubmoduleOutput from_json_SubmoduleOutput(nlohmann::json obj)
    {
        apollo::prediction::SubmoduleOutput msg;

        if (obj.contains("curr_frame_obstacles_"))
            for (auto &&i : obj["curr_frame_obstacles_"])
            {
                msg.curr_frame_obstacles_.push_back(from_json_Obstacle(i));
            }
        if (obj.contains("ego_vehicle_"))
            msg.ego_vehicle_ = from_json_Obstacle(obj["ego_vehicle_"]);

        if (obj.contains("curr_frame_movable_obstacle_ids_"))
            for (auto &&i : obj["curr_frame_movable_obstacle_ids_"])
            {
                msg.curr_frame_movable_obstacle_ids_.push_back((i));
            }

        if (obj.contains("curr_frame_unmovable_obstacle_ids_"))
            for (auto &&i : obj["curr_frame_unmovable_obstacle_ids_"])
            {
                msg.curr_frame_unmovable_obstacle_ids_.push_back((i));
            }

        if (obj.contains("curr_frame_considered_obstacle_ids_"))
            for (auto &&i : obj["curr_frame_considered_obstacle_ids_"])
            {
                msg.curr_frame_considered_obstacle_ids_.push_back((i));
            }
        if (obj.contains("frame_start_time_"))
            msg.frame_start_time_.nanoseconds_ = obj["frame_start_time_"] ;
        if (obj.contains("curr_scenario_"))
            msg.curr_scenario_= from_json_ApollopredictionScenario(obj["curr_scenario_"]);

        return msg;
    }
    template <>
    apollo::prediction::SubmoduleOutput from_json<apollo::prediction::SubmoduleOutput>(nlohmann::json obj)
    {
        return from_json_SubmoduleOutput(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, apollo::prediction::SubmoduleOutput &dt)
    {
        dt = from_json_SubmoduleOutput(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const apollo::prediction::SubmoduleOutput &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::prediction::SubmoduleOutput &dt)
    {
        return os << to_json(dt).dump();
    }
}
