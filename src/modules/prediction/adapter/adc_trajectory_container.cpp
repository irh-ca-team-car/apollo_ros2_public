#include "adapter/serialization/internal/prediction/adc_trajectory_container.h"

namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::prediction::ADCTrajectoryContainer &msg){
        return msg.to_json();
    }
    apollo::prediction::ADCTrajectoryContainer from_json_ADCTrajectoryContainer(nlohmann::json obj)
    {
        apollo::prediction::ADCTrajectoryContainer msg;
        msg.load_json(obj);
        return msg;
    }
    template <>
    apollo::prediction::ADCTrajectoryContainer from_json<apollo::prediction::ADCTrajectoryContainer>(nlohmann::json obj){
        return from_json_ADCTrajectoryContainer(obj);
    }
    nlohmann::json &
    operator>>(nlohmann::json &os, apollo::prediction::ADCTrajectoryContainer &dt)
    {
        dt = from_json_ADCTrajectoryContainer(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const apollo::prediction::ADCTrajectoryContainer &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::prediction::ADCTrajectoryContainer &dt)
    {
        return os << to_json(dt).dump();
    }
}
