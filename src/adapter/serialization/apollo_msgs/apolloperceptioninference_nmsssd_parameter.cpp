#include "adapter/serialization/apollo_msgs/apolloperceptioninference_nmsssd_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNMSSSDParameter &msg) {
        nlohmann::json obj;
        obj["neednms"] = (msg.neednms);
        nlohmann::json arr_overlapratio;
        for (auto it = msg.overlapratio.begin(); it != msg.overlapratio.end(); ++it) {
            arr_overlapratio.push_back((*it));
        }
        obj["overlapratio"] = arr_overlapratio;
        nlohmann::json arr_topn;
        for (auto it = msg.topn.begin(); it != msg.topn.end(); ++it) {
            arr_topn.push_back((*it));
        }
        obj["topn"] = arr_topn;
        obj["addscore"] = (msg.addscore);
        nlohmann::json arr_maxcandidaten;
        for (auto it = msg.maxcandidaten.begin(); it != msg.maxcandidaten.end(); ++it) {
            arr_maxcandidaten.push_back((*it));
        }
        obj["maxcandidaten"] = arr_maxcandidaten;
        nlohmann::json arr_usesoftnms;
        for (auto it = msg.usesoftnms.begin(); it != msg.usesoftnms.end(); ++it) {
            arr_usesoftnms.push_back((*it));
        }
        obj["usesoftnms"] = arr_usesoftnms;
        obj["nmsamongclasses"] = (msg.nmsamongclasses);
        nlohmann::json arr_voting;
        for (auto it = msg.voting.begin(); it != msg.voting.end(); ++it) {
            arr_voting.push_back((*it));
        }
        obj["voting"] = arr_voting;
        nlohmann::json arr_voteiou;
        for (auto it = msg.voteiou.begin(); it != msg.voteiou.end(); ++it) {
            arr_voteiou.push_back((*it));
        }
        obj["voteiou"] = arr_voteiou;
        obj["forceidentityiouthr"] = (msg.forceidentityiouthr);
        obj["forceimparityiouthr"] = (msg.forceimparityiouthr);
        obj["nmsgpumaxnpertime"] = (msg.nmsgpumaxnpertime);
        return obj;
    }
    ApolloperceptioninferenceNMSSSDParameter from_json_ApolloperceptioninferenceNMSSSDParameter (nlohmann::json obj) {
        ApolloperceptioninferenceNMSSSDParameter msg;
        if(obj.contains("neednms"))
        {
            msg.neednms = (obj["neednms"].is_string()?(bool)atoi(obj["neednms"].get<std::string>().c_str()):obj["neednms"].get<bool>());
        }
        if(obj.contains("overlapratio"))
        {
            if(obj["overlapratio"].is_array())
            {
                for (auto& element : obj["overlapratio"])
                {
                    msg.overlapratio.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.overlapratio.push_back((obj["overlapratio"].is_string()?(float)atof(obj["overlapratio"].get<std::string>().c_str()):obj["overlapratio"].get<float>()));
            }
        }
        if(obj.contains("topn"))
        {
            if(obj["topn"].is_array())
            {
                for (auto& element : obj["topn"])
                {
                    msg.topn.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.topn.push_back((obj["topn"].is_string()?atoi(obj["topn"].get<std::string>().c_str()):obj["topn"].get<uint32_t>()));
            }
        }
        if(obj.contains("addscore"))
        {
            msg.addscore = (obj["addscore"].is_string()?(bool)atoi(obj["addscore"].get<std::string>().c_str()):obj["addscore"].get<bool>());
        }
        if(obj.contains("maxcandidaten"))
        {
            if(obj["maxcandidaten"].is_array())
            {
                for (auto& element : obj["maxcandidaten"])
                {
                    msg.maxcandidaten.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.maxcandidaten.push_back((obj["maxcandidaten"].is_string()?atoi(obj["maxcandidaten"].get<std::string>().c_str()):obj["maxcandidaten"].get<int>()));
            }
        }
        if(obj.contains("usesoftnms"))
        {
            if(obj["usesoftnms"].is_array())
            {
                for (auto& element : obj["usesoftnms"])
                {
                    msg.usesoftnms.push_back((element.is_string()?(bool)atoi(element.get<std::string>().c_str()):element.get<bool>()));
                }
            }
            else
            {
                msg.usesoftnms.push_back((obj["usesoftnms"].is_string()?(bool)atoi(obj["usesoftnms"].get<std::string>().c_str()):obj["usesoftnms"].get<bool>()));
            }
        }
        if(obj.contains("nmsamongclasses"))
        {
            msg.nmsamongclasses = (obj["nmsamongclasses"].is_string()?(bool)atoi(obj["nmsamongclasses"].get<std::string>().c_str()):obj["nmsamongclasses"].get<bool>());
        }
        if(obj.contains("voting"))
        {
            if(obj["voting"].is_array())
            {
                for (auto& element : obj["voting"])
                {
                    msg.voting.push_back((element.is_string()?(bool)atoi(element.get<std::string>().c_str()):element.get<bool>()));
                }
            }
            else
            {
                msg.voting.push_back((obj["voting"].is_string()?(bool)atoi(obj["voting"].get<std::string>().c_str()):obj["voting"].get<bool>()));
            }
        }
        if(obj.contains("voteiou"))
        {
            if(obj["voteiou"].is_array())
            {
                for (auto& element : obj["voteiou"])
                {
                    msg.voteiou.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.voteiou.push_back((obj["voteiou"].is_string()?(float)atof(obj["voteiou"].get<std::string>().c_str()):obj["voteiou"].get<float>()));
            }
        }
        if(obj.contains("forceidentityiouthr"))
        {
            msg.forceidentityiouthr = (obj["forceidentityiouthr"].is_string()?(float)atof(obj["forceidentityiouthr"].get<std::string>().c_str()):obj["forceidentityiouthr"].get<float>());
        }
        if(obj.contains("forceimparityiouthr"))
        {
            msg.forceimparityiouthr = (obj["forceimparityiouthr"].is_string()?(float)atof(obj["forceimparityiouthr"].get<std::string>().c_str()):obj["forceimparityiouthr"].get<float>());
        }
        if(obj.contains("nmsgpumaxnpertime"))
        {
            msg.nmsgpumaxnpertime = (obj["nmsgpumaxnpertime"].is_string()?atoi(obj["nmsgpumaxnpertime"].get<std::string>().c_str()):obj["nmsgpumaxnpertime"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNMSSSDParameter from_json<ApolloperceptioninferenceNMSSSDParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNMSSSDParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNMSSSDParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceNMSSSDParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNMSSSDParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNMSSSDParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
