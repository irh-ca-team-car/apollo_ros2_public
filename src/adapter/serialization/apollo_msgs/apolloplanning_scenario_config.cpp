#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioConfig &msg) {
        nlohmann::json obj;
        obj["scenariotype"] = (msg.scenariotype);
        obj["scenarioconfig"] = to_json(msg.scenarioconfig);
        nlohmann::json arr_stagetype;
        for (auto it = msg.stagetype.begin(); it != msg.stagetype.end(); ++it) {
            arr_stagetype.push_back((*it));
        }
        obj["stagetype"] = arr_stagetype;
        nlohmann::json arr_stageconfig;
        for (auto it = msg.stageconfig.begin(); it != msg.stageconfig.end(); ++it) {
            arr_stageconfig.push_back(to_json(*it));
        }
        obj["stageconfig"] = arr_stageconfig;
        return obj;
    }
    ApolloplanningScenarioConfig from_json_ApolloplanningScenarioConfig (nlohmann::json obj) {
        ApolloplanningScenarioConfig msg;
        if(obj.contains("scenariotype"))
        {
            msg.scenariotype = (obj["scenariotype"].is_string()?atoi(obj["scenariotype"].get<std::string>().c_str()):obj["scenariotype"].get<int>());
        }
        if(obj.contains("scenarioconfig"))
        {
            msg.scenarioconfig = from_json_ApolloplanningScenarioConfigscenarioConfig(obj["scenarioconfig"]);
        }
        if(obj.contains("stagetype"))
        {
            if(obj["stagetype"].is_array())
            {
                for (auto& element : obj["stagetype"])
                {
                    msg.stagetype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.stagetype.push_back((obj["stagetype"].is_string()?atoi(obj["stagetype"].get<std::string>().c_str()):obj["stagetype"].get<int>()));
            }
        }
        if(obj.contains("stageconfig"))
        {
            if(obj["stageconfig"].is_array())
            {
                for (auto& element : obj["stageconfig"])
                {
                    msg.stageconfig.push_back(from_json_ApolloplanningStageConfig(element));
                }
            }
            else
            {
                msg.stageconfig.push_back(from_json_ApolloplanningStageConfig(obj["stageconfig"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioConfig from_json<ApolloplanningScenarioConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
