#include "adapter/serialization/apollo_msgs/apollodrivers_mobileye.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversMobileye &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["aftermarket669"] = to_json(msg.aftermarket669);
        obj["details737"] = to_json(msg.details737);
        obj["details738"] = to_json(msg.details738);
        nlohmann::json arr_details739;
        for (auto it = msg.details739.begin(); it != msg.details739.end(); ++it) {
            arr_details739.push_back(to_json(*it));
        }
        obj["details739"] = arr_details739;
        nlohmann::json arr_details73a;
        for (auto it = msg.details73a.begin(); it != msg.details73a.end(); ++it) {
            arr_details73a.push_back(to_json(*it));
        }
        obj["details73a"] = arr_details73a;
        nlohmann::json arr_details73b;
        for (auto it = msg.details73b.begin(); it != msg.details73b.end(); ++it) {
            arr_details73b.push_back(to_json(*it));
        }
        obj["details73b"] = arr_details73b;
        obj["lka766"] = to_json(msg.lka766);
        obj["lka767"] = to_json(msg.lka767);
        obj["lka768"] = to_json(msg.lka768);
        obj["lka769"] = to_json(msg.lka769);
        obj["reference76a"] = to_json(msg.reference76a);
        obj["num76b"] = to_json(msg.num76b);
        nlohmann::json arr_next76c;
        for (auto it = msg.next76c.begin(); it != msg.next76c.end(); ++it) {
            arr_next76c.push_back(to_json(*it));
        }
        obj["next76c"] = arr_next76c;
        nlohmann::json arr_next76d;
        for (auto it = msg.next76d.begin(); it != msg.next76d.end(); ++it) {
            arr_next76d.push_back(to_json(*it));
        }
        obj["next76d"] = arr_next76d;
        return obj;
    }
    ApollodriversMobileye from_json_ApollodriversMobileye (nlohmann::json obj) {
        ApollodriversMobileye msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("aftermarket669"))
        {
            msg.aftermarket669 = from_json_ApollodriversAftermarket669(obj["aftermarket669"]);
        }
        if(obj.contains("details737"))
        {
            msg.details737 = from_json_ApollodriversDetails737(obj["details737"]);
        }
        if(obj.contains("details738"))
        {
            msg.details738 = from_json_ApollodriversDetails738(obj["details738"]);
        }
        if(obj.contains("details739"))
        {
            if(obj["details739"].is_array())
            {
                for (auto& element : obj["details739"])
                {
                    msg.details739.push_back(from_json_ApollodriversDetails739(element));
                }
            }
            else
            {
                msg.details739.push_back(from_json_ApollodriversDetails739(obj["details739"]));
            }
        }
        if(obj.contains("details73a"))
        {
            if(obj["details73a"].is_array())
            {
                for (auto& element : obj["details73a"])
                {
                    msg.details73a.push_back(from_json_ApollodriversDetails73a(element));
                }
            }
            else
            {
                msg.details73a.push_back(from_json_ApollodriversDetails73a(obj["details73a"]));
            }
        }
        if(obj.contains("details73b"))
        {
            if(obj["details73b"].is_array())
            {
                for (auto& element : obj["details73b"])
                {
                    msg.details73b.push_back(from_json_ApollodriversDetails73b(element));
                }
            }
            else
            {
                msg.details73b.push_back(from_json_ApollodriversDetails73b(obj["details73b"]));
            }
        }
        if(obj.contains("lka766"))
        {
            msg.lka766 = from_json_ApollodriversLka766(obj["lka766"]);
        }
        if(obj.contains("lka767"))
        {
            msg.lka767 = from_json_ApollodriversLka767(obj["lka767"]);
        }
        if(obj.contains("lka768"))
        {
            msg.lka768 = from_json_ApollodriversLka768(obj["lka768"]);
        }
        if(obj.contains("lka769"))
        {
            msg.lka769 = from_json_ApollodriversLka769(obj["lka769"]);
        }
        if(obj.contains("reference76a"))
        {
            msg.reference76a = from_json_ApollodriversReference76a(obj["reference76a"]);
        }
        if(obj.contains("num76b"))
        {
            msg.num76b = from_json_ApollodriversNum76b(obj["num76b"]);
        }
        if(obj.contains("next76c"))
        {
            if(obj["next76c"].is_array())
            {
                for (auto& element : obj["next76c"])
                {
                    msg.next76c.push_back(from_json_ApollodriversNext76c(element));
                }
            }
            else
            {
                msg.next76c.push_back(from_json_ApollodriversNext76c(obj["next76c"]));
            }
        }
        if(obj.contains("next76d"))
        {
            if(obj["next76d"].is_array())
            {
                for (auto& element : obj["next76d"])
                {
                    msg.next76d.push_back(from_json_ApollodriversNext76d(element));
                }
            }
            else
            {
                msg.next76d.push_back(from_json_ApollodriversNext76d(obj["next76d"]));
            }
        }
        return msg;
    }
    template <>
    ApollodriversMobileye from_json<ApollodriversMobileye>(nlohmann::json obj){
        return from_json_ApollodriversMobileye(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversMobileye &dt)
    {
        dt=from_json_ApollodriversMobileye(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversMobileye & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversMobileye & dt)
    {
        os << to_json(dt);
        return os;
    }
}
