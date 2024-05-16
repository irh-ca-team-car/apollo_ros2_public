#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_speed_point_raw_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningSpeedPointRawFeature &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["t"] = (msg.t);
        obj["v"] = (msg.v);
        obj["a"] = (msg.a);
        obj["j"] = (msg.j);
        obj["speedlimit"] = (msg.speedlimit);
        nlohmann::json arr_follow;
        for (auto it = msg.follow.begin(); it != msg.follow.end(); ++it) {
            arr_follow.push_back(to_json(*it));
        }
        obj["follow"] = arr_follow;
        nlohmann::json arr_overtake;
        for (auto it = msg.overtake.begin(); it != msg.overtake.end(); ++it) {
            arr_overtake.push_back(to_json(*it));
        }
        obj["overtake"] = arr_overtake;
        nlohmann::json arr_virtualdecision;
        for (auto it = msg.virtualdecision.begin(); it != msg.virtualdecision.end(); ++it) {
            arr_virtualdecision.push_back(to_json(*it));
        }
        obj["virtualdecision"] = arr_virtualdecision;
        nlohmann::json arr_stop;
        for (auto it = msg.stop.begin(); it != msg.stop.end(); ++it) {
            arr_stop.push_back(to_json(*it));
        }
        obj["stop"] = arr_stop;
        nlohmann::json arr_collision;
        for (auto it = msg.collision.begin(); it != msg.collision.end(); ++it) {
            arr_collision.push_back(to_json(*it));
        }
        obj["collision"] = arr_collision;
        nlohmann::json arr_nudge;
        for (auto it = msg.nudge.begin(); it != msg.nudge.end(); ++it) {
            arr_nudge.push_back(to_json(*it));
        }
        obj["nudge"] = arr_nudge;
        nlohmann::json arr_sidepassfront;
        for (auto it = msg.sidepassfront.begin(); it != msg.sidepassfront.end(); ++it) {
            arr_sidepassfront.push_back(to_json(*it));
        }
        obj["sidepassfront"] = arr_sidepassfront;
        nlohmann::json arr_sidepassrear;
        for (auto it = msg.sidepassrear.begin(); it != msg.sidepassrear.end(); ++it) {
            arr_sidepassrear.push_back(to_json(*it));
        }
        obj["sidepassrear"] = arr_sidepassrear;
        nlohmann::json arr_keepclear;
        for (auto it = msg.keepclear.begin(); it != msg.keepclear.end(); ++it) {
            arr_keepclear.push_back(to_json(*it));
        }
        obj["keepclear"] = arr_keepclear;
        return obj;
    }
    ApolloplanningautotuningSpeedPointRawFeature from_json_ApolloplanningautotuningSpeedPointRawFeature (nlohmann::json obj) {
        ApolloplanningautotuningSpeedPointRawFeature msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("t"))
        {
            msg.t = (obj["t"].is_string()?atof(obj["t"].get<std::string>().c_str()):obj["t"].get<double>());
        }
        if(obj.contains("v"))
        {
            msg.v = (obj["v"].is_string()?atof(obj["v"].get<std::string>().c_str()):obj["v"].get<double>());
        }
        if(obj.contains("a"))
        {
            msg.a = (obj["a"].is_string()?atof(obj["a"].get<std::string>().c_str()):obj["a"].get<double>());
        }
        if(obj.contains("j"))
        {
            msg.j = (obj["j"].is_string()?atof(obj["j"].get<std::string>().c_str()):obj["j"].get<double>());
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        if(obj.contains("follow"))
        {
            if(obj["follow"].is_array())
            {
                for (auto& element : obj["follow"])
                {
                    msg.follow.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.follow.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["follow"]));
            }
        }
        if(obj.contains("overtake"))
        {
            if(obj["overtake"].is_array())
            {
                for (auto& element : obj["overtake"])
                {
                    msg.overtake.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.overtake.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["overtake"]));
            }
        }
        if(obj.contains("virtualdecision"))
        {
            if(obj["virtualdecision"].is_array())
            {
                for (auto& element : obj["virtualdecision"])
                {
                    msg.virtualdecision.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.virtualdecision.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["virtualdecision"]));
            }
        }
        if(obj.contains("stop"))
        {
            if(obj["stop"].is_array())
            {
                for (auto& element : obj["stop"])
                {
                    msg.stop.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.stop.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["stop"]));
            }
        }
        if(obj.contains("collision"))
        {
            if(obj["collision"].is_array())
            {
                for (auto& element : obj["collision"])
                {
                    msg.collision.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.collision.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["collision"]));
            }
        }
        if(obj.contains("nudge"))
        {
            if(obj["nudge"].is_array())
            {
                for (auto& element : obj["nudge"])
                {
                    msg.nudge.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.nudge.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["nudge"]));
            }
        }
        if(obj.contains("sidepassfront"))
        {
            if(obj["sidepassfront"].is_array())
            {
                for (auto& element : obj["sidepassfront"])
                {
                    msg.sidepassfront.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.sidepassfront.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["sidepassfront"]));
            }
        }
        if(obj.contains("sidepassrear"))
        {
            if(obj["sidepassrear"].is_array())
            {
                for (auto& element : obj["sidepassrear"])
                {
                    msg.sidepassrear.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.sidepassrear.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["sidepassrear"]));
            }
        }
        if(obj.contains("keepclear"))
        {
            if(obj["keepclear"].is_array())
            {
                for (auto& element : obj["keepclear"])
                {
                    msg.keepclear.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(element));
                }
            }
            else
            {
                msg.keepclear.push_back(from_json_ApolloplanningautotuningObjectDecisionFeature(obj["keepclear"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningSpeedPointRawFeature from_json<ApolloplanningautotuningSpeedPointRawFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningSpeedPointRawFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningSpeedPointRawFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningSpeedPointRawFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningSpeedPointRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningSpeedPointRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
