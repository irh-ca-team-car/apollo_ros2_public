#include "adapter/serialization/apollo_msgs/apollolocalization_gnss_pnt_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationGnssPntResult &msg) {
        nlohmann::json obj;
        obj["receiverid"] = (msg.receiverid);
        obj["timetype"] = (msg.timetype);
        obj["gnssweek"] = (msg.gnssweek);
        obj["gnssseconds"] = (msg.gnssseconds);
        obj["pnttype"] = (msg.pnttype);
        obj["posxm"] = (msg.posxm);
        obj["posym"] = (msg.posym);
        obj["poszm"] = (msg.poszm);
        obj["stdposxm"] = (msg.stdposxm);
        obj["stdposym"] = (msg.stdposym);
        obj["stdposzm"] = (msg.stdposzm);
        obj["velxm"] = (msg.velxm);
        obj["velym"] = (msg.velym);
        obj["velzm"] = (msg.velzm);
        obj["stdvelxm"] = (msg.stdvelxm);
        obj["stdvelym"] = (msg.stdvelym);
        obj["stdvelzm"] = (msg.stdvelzm);
        obj["sovledsatnum"] = (msg.sovledsatnum);
        nlohmann::json arr_satdircosine;
        for (auto it = msg.satdircosine.begin(); it != msg.satdircosine.end(); ++it) {
            arr_satdircosine.push_back(to_json(*it));
        }
        obj["satdircosine"] = arr_satdircosine;
        obj["pdop"] = (msg.pdop);
        obj["hdop"] = (msg.hdop);
        obj["vdop"] = (msg.vdop);
        return obj;
    }
    ApollolocalizationGnssPntResult from_json_ApollolocalizationGnssPntResult (nlohmann::json obj) {
        ApollolocalizationGnssPntResult msg;
        if(obj.contains("receiverid"))
        {
            msg.receiverid = (obj["receiverid"].is_string()?atoi(obj["receiverid"].get<std::string>().c_str()):obj["receiverid"].get<uint32_t>());
        }
        if(obj.contains("timetype"))
        {
            msg.timetype = (obj["timetype"].is_string()?atoi(obj["timetype"].get<std::string>().c_str()):obj["timetype"].get<int>());
        }
        if(obj.contains("gnssweek"))
        {
            msg.gnssweek = (obj["gnssweek"].is_string()?atoi(obj["gnssweek"].get<std::string>().c_str()):obj["gnssweek"].get<uint32_t>());
        }
        if(obj.contains("gnssseconds"))
        {
            msg.gnssseconds = (obj["gnssseconds"].is_string()?atof(obj["gnssseconds"].get<std::string>().c_str()):obj["gnssseconds"].get<double>());
        }
        if(obj.contains("pnttype"))
        {
            msg.pnttype = (obj["pnttype"].is_string()?atoi(obj["pnttype"].get<std::string>().c_str()):obj["pnttype"].get<int>());
        }
        if(obj.contains("posxm"))
        {
            msg.posxm = (obj["posxm"].is_string()?atof(obj["posxm"].get<std::string>().c_str()):obj["posxm"].get<double>());
        }
        if(obj.contains("posym"))
        {
            msg.posym = (obj["posym"].is_string()?atof(obj["posym"].get<std::string>().c_str()):obj["posym"].get<double>());
        }
        if(obj.contains("poszm"))
        {
            msg.poszm = (obj["poszm"].is_string()?atof(obj["poszm"].get<std::string>().c_str()):obj["poszm"].get<double>());
        }
        if(obj.contains("stdposxm"))
        {
            msg.stdposxm = (obj["stdposxm"].is_string()?atof(obj["stdposxm"].get<std::string>().c_str()):obj["stdposxm"].get<double>());
        }
        if(obj.contains("stdposym"))
        {
            msg.stdposym = (obj["stdposym"].is_string()?atof(obj["stdposym"].get<std::string>().c_str()):obj["stdposym"].get<double>());
        }
        if(obj.contains("stdposzm"))
        {
            msg.stdposzm = (obj["stdposzm"].is_string()?atof(obj["stdposzm"].get<std::string>().c_str()):obj["stdposzm"].get<double>());
        }
        if(obj.contains("velxm"))
        {
            msg.velxm = (obj["velxm"].is_string()?atof(obj["velxm"].get<std::string>().c_str()):obj["velxm"].get<double>());
        }
        if(obj.contains("velym"))
        {
            msg.velym = (obj["velym"].is_string()?atof(obj["velym"].get<std::string>().c_str()):obj["velym"].get<double>());
        }
        if(obj.contains("velzm"))
        {
            msg.velzm = (obj["velzm"].is_string()?atof(obj["velzm"].get<std::string>().c_str()):obj["velzm"].get<double>());
        }
        if(obj.contains("stdvelxm"))
        {
            msg.stdvelxm = (obj["stdvelxm"].is_string()?atof(obj["stdvelxm"].get<std::string>().c_str()):obj["stdvelxm"].get<double>());
        }
        if(obj.contains("stdvelym"))
        {
            msg.stdvelym = (obj["stdvelym"].is_string()?atof(obj["stdvelym"].get<std::string>().c_str()):obj["stdvelym"].get<double>());
        }
        if(obj.contains("stdvelzm"))
        {
            msg.stdvelzm = (obj["stdvelzm"].is_string()?atof(obj["stdvelzm"].get<std::string>().c_str()):obj["stdvelzm"].get<double>());
        }
        if(obj.contains("sovledsatnum"))
        {
            msg.sovledsatnum = (obj["sovledsatnum"].is_string()?atoi(obj["sovledsatnum"].get<std::string>().c_str()):obj["sovledsatnum"].get<uint32_t>());
        }
        if(obj.contains("satdircosine"))
        {
            if(obj["satdircosine"].is_array())
            {
                for (auto& element : obj["satdircosine"])
                {
                    msg.satdircosine.push_back(from_json_ApollolocalizationSatDirCosine(element));
                }
            }
            else
            {
                msg.satdircosine.push_back(from_json_ApollolocalizationSatDirCosine(obj["satdircosine"]));
            }
        }
        if(obj.contains("pdop"))
        {
            msg.pdop = (obj["pdop"].is_string()?atof(obj["pdop"].get<std::string>().c_str()):obj["pdop"].get<double>());
        }
        if(obj.contains("hdop"))
        {
            msg.hdop = (obj["hdop"].is_string()?atof(obj["hdop"].get<std::string>().c_str()):obj["hdop"].get<double>());
        }
        if(obj.contains("vdop"))
        {
            msg.vdop = (obj["vdop"].is_string()?atof(obj["vdop"].get<std::string>().c_str()):obj["vdop"].get<double>());
        }
        return msg;
    }
    template <>
    ApollolocalizationGnssPntResult from_json<ApollolocalizationGnssPntResult>(nlohmann::json obj){
        return from_json_ApollolocalizationGnssPntResult(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationGnssPntResult &dt)
    {
        dt=from_json_ApollolocalizationGnssPntResult(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationGnssPntResult & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationGnssPntResult & dt)
    {
        os << to_json(dt);
        return os;
    }
}
