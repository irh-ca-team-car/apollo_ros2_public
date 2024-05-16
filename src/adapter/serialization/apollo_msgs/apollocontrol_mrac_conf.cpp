#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMracConf &msg) {
        nlohmann::json obj;
        obj["mracmodelorder"] = (msg.mracmodelorder);
        obj["referencetimeconstant"] = (msg.referencetimeconstant);
        obj["referencenaturalfrequency"] = (msg.referencenaturalfrequency);
        obj["referencedampingratio"] = (msg.referencedampingratio);
        nlohmann::json arr_adaptionstategain;
        for (auto it = msg.adaptionstategain.begin(); it != msg.adaptionstategain.end(); ++it) {
            arr_adaptionstategain.push_back((*it));
        }
        obj["adaptionstategain"] = arr_adaptionstategain;
        obj["adaptiondesiredgain"] = (msg.adaptiondesiredgain);
        obj["adaptionnonlineargain"] = (msg.adaptionnonlineargain);
        nlohmann::json arr_adaptionmatrixp;
        for (auto it = msg.adaptionmatrixp.begin(); it != msg.adaptionmatrixp.end(); ++it) {
            arr_adaptionmatrixp.push_back((*it));
        }
        obj["adaptionmatrixp"] = arr_adaptionmatrixp;
        obj["mracsaturationlevel"] = (msg.mracsaturationlevel);
        nlohmann::json arr_antiwindupcompensationgain;
        for (auto it = msg.antiwindupcompensationgain.begin(); it != msg.antiwindupcompensationgain.end(); ++it) {
            arr_antiwindupcompensationgain.push_back((*it));
        }
        obj["antiwindupcompensationgain"] = arr_antiwindupcompensationgain;
        obj["clampingtimeconstant"] = (msg.clampingtimeconstant);
        return obj;
    }
    ApollocontrolMracConf from_json_ApollocontrolMracConf (nlohmann::json obj) {
        ApollocontrolMracConf msg;
        if(obj.contains("mracmodelorder"))
        {
            msg.mracmodelorder = (obj["mracmodelorder"].is_string()?atoi(obj["mracmodelorder"].get<std::string>().c_str()):obj["mracmodelorder"].get<int>());
        }
        if(obj.contains("referencetimeconstant"))
        {
            msg.referencetimeconstant = (obj["referencetimeconstant"].is_string()?atof(obj["referencetimeconstant"].get<std::string>().c_str()):obj["referencetimeconstant"].get<double>());
        }
        if(obj.contains("referencenaturalfrequency"))
        {
            msg.referencenaturalfrequency = (obj["referencenaturalfrequency"].is_string()?atof(obj["referencenaturalfrequency"].get<std::string>().c_str()):obj["referencenaturalfrequency"].get<double>());
        }
        if(obj.contains("referencedampingratio"))
        {
            msg.referencedampingratio = (obj["referencedampingratio"].is_string()?atof(obj["referencedampingratio"].get<std::string>().c_str()):obj["referencedampingratio"].get<double>());
        }
        if(obj.contains("adaptionstategain"))
        {
            if(obj["adaptionstategain"].is_array())
            {
                for (auto& element : obj["adaptionstategain"])
                {
                    msg.adaptionstategain.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.adaptionstategain.push_back((obj["adaptionstategain"].is_string()?atof(obj["adaptionstategain"].get<std::string>().c_str()):obj["adaptionstategain"].get<double>()));
            }
        }
        if(obj.contains("adaptiondesiredgain"))
        {
            msg.adaptiondesiredgain = (obj["adaptiondesiredgain"].is_string()?atof(obj["adaptiondesiredgain"].get<std::string>().c_str()):obj["adaptiondesiredgain"].get<double>());
        }
        if(obj.contains("adaptionnonlineargain"))
        {
            msg.adaptionnonlineargain = (obj["adaptionnonlineargain"].is_string()?atof(obj["adaptionnonlineargain"].get<std::string>().c_str()):obj["adaptionnonlineargain"].get<double>());
        }
        if(obj.contains("adaptionmatrixp"))
        {
            if(obj["adaptionmatrixp"].is_array())
            {
                for (auto& element : obj["adaptionmatrixp"])
                {
                    msg.adaptionmatrixp.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.adaptionmatrixp.push_back((obj["adaptionmatrixp"].is_string()?atof(obj["adaptionmatrixp"].get<std::string>().c_str()):obj["adaptionmatrixp"].get<double>()));
            }
        }
        if(obj.contains("mracsaturationlevel"))
        {
            msg.mracsaturationlevel = (obj["mracsaturationlevel"].is_string()?atof(obj["mracsaturationlevel"].get<std::string>().c_str()):obj["mracsaturationlevel"].get<double>());
        }
        if(obj.contains("antiwindupcompensationgain"))
        {
            if(obj["antiwindupcompensationgain"].is_array())
            {
                for (auto& element : obj["antiwindupcompensationgain"])
                {
                    msg.antiwindupcompensationgain.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.antiwindupcompensationgain.push_back((obj["antiwindupcompensationgain"].is_string()?atof(obj["antiwindupcompensationgain"].get<std::string>().c_str()):obj["antiwindupcompensationgain"].get<double>()));
            }
        }
        if(obj.contains("clampingtimeconstant"))
        {
            msg.clampingtimeconstant = (obj["clampingtimeconstant"].is_string()?atof(obj["clampingtimeconstant"].get<std::string>().c_str()):obj["clampingtimeconstant"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolMracConf from_json<ApollocontrolMracConf>(nlohmann::json obj){
        return from_json_ApollocontrolMracConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMracConf &dt)
    {
        dt=from_json_ApollocontrolMracConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMracConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMracConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
