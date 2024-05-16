#include "adapter/serialization/apollo_msgs/apolloplanning_path_lane_borrow_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathLaneBorrowDeciderConfig &msg) {
        nlohmann::json obj;
        obj["allowlaneborrowing"] = (msg.allowlaneborrowing);
        return obj;
    }
    ApolloplanningPathLaneBorrowDeciderConfig from_json_ApolloplanningPathLaneBorrowDeciderConfig (nlohmann::json obj) {
        ApolloplanningPathLaneBorrowDeciderConfig msg;
        if(obj.contains("allowlaneborrowing"))
        {
            msg.allowlaneborrowing = (obj["allowlaneborrowing"].is_string()?(bool)atoi(obj["allowlaneborrowing"].get<std::string>().c_str()):obj["allowlaneborrowing"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningPathLaneBorrowDeciderConfig from_json<ApolloplanningPathLaneBorrowDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPathLaneBorrowDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathLaneBorrowDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningPathLaneBorrowDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathLaneBorrowDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathLaneBorrowDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
