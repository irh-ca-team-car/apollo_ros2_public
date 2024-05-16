#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_n_cut_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNCutParam &msg) {
        nlohmann::json obj;
        obj["gridradius"] = (msg.gridradius);
        obj["connectradius"] = (msg.connectradius);
        obj["superpixelcellsize"] = (msg.superpixelcellsize);
        obj["numcuts"] = (msg.numcuts);
        obj["ncutsstopthreshold"] = (msg.ncutsstopthreshold);
        obj["ncutsenableclassifierthreshold"] = (msg.ncutsenableclassifierthreshold);
        obj["sigmaspace"] = (msg.sigmaspace);
        obj["sigmafeature"] = (msg.sigmafeature);
        obj["skeletoncellsize"] = (msg.skeletoncellsize);
        obj["patchsize"] = (msg.patchsize);
        obj["outlierwidththreshold"] = (msg.outlierwidththreshold);
        obj["outlierheightthreshold"] = (msg.outlierheightthreshold);
        obj["outliernumpointsthreshold"] = (msg.outliernumpointsthreshold);
        obj["overlapfactor"] = (msg.overlapfactor);
        obj["felzenszwalbsigma"] = (msg.felzenszwalbsigma);
        obj["felzenszwalbk"] = (msg.felzenszwalbk);
        obj["felzenszwalbminsize"] = (msg.felzenszwalbminsize);
        return obj;
    }
    ApolloperceptionlidarNCutParam from_json_ApolloperceptionlidarNCutParam (nlohmann::json obj) {
        ApolloperceptionlidarNCutParam msg;
        if(obj.contains("gridradius"))
        {
            msg.gridradius = (obj["gridradius"].is_string()?(float)atof(obj["gridradius"].get<std::string>().c_str()):obj["gridradius"].get<float>());
        }
        if(obj.contains("connectradius"))
        {
            msg.connectradius = (obj["connectradius"].is_string()?(float)atof(obj["connectradius"].get<std::string>().c_str()):obj["connectradius"].get<float>());
        }
        if(obj.contains("superpixelcellsize"))
        {
            msg.superpixelcellsize = (obj["superpixelcellsize"].is_string()?(float)atof(obj["superpixelcellsize"].get<std::string>().c_str()):obj["superpixelcellsize"].get<float>());
        }
        if(obj.contains("numcuts"))
        {
            msg.numcuts = (obj["numcuts"].is_string()?atoi(obj["numcuts"].get<std::string>().c_str()):obj["numcuts"].get<uint32_t>());
        }
        if(obj.contains("ncutsstopthreshold"))
        {
            msg.ncutsstopthreshold = (obj["ncutsstopthreshold"].is_string()?(float)atof(obj["ncutsstopthreshold"].get<std::string>().c_str()):obj["ncutsstopthreshold"].get<float>());
        }
        if(obj.contains("ncutsenableclassifierthreshold"))
        {
            msg.ncutsenableclassifierthreshold = (obj["ncutsenableclassifierthreshold"].is_string()?(float)atof(obj["ncutsenableclassifierthreshold"].get<std::string>().c_str()):obj["ncutsenableclassifierthreshold"].get<float>());
        }
        if(obj.contains("sigmaspace"))
        {
            msg.sigmaspace = (obj["sigmaspace"].is_string()?(float)atof(obj["sigmaspace"].get<std::string>().c_str()):obj["sigmaspace"].get<float>());
        }
        if(obj.contains("sigmafeature"))
        {
            msg.sigmafeature = (obj["sigmafeature"].is_string()?(float)atof(obj["sigmafeature"].get<std::string>().c_str()):obj["sigmafeature"].get<float>());
        }
        if(obj.contains("skeletoncellsize"))
        {
            msg.skeletoncellsize = (obj["skeletoncellsize"].is_string()?(float)atof(obj["skeletoncellsize"].get<std::string>().c_str()):obj["skeletoncellsize"].get<float>());
        }
        if(obj.contains("patchsize"))
        {
            msg.patchsize = (obj["patchsize"].is_string()?atoi(obj["patchsize"].get<std::string>().c_str()):obj["patchsize"].get<uint32_t>());
        }
        if(obj.contains("outlierwidththreshold"))
        {
            msg.outlierwidththreshold = (obj["outlierwidththreshold"].is_string()?(float)atof(obj["outlierwidththreshold"].get<std::string>().c_str()):obj["outlierwidththreshold"].get<float>());
        }
        if(obj.contains("outlierheightthreshold"))
        {
            msg.outlierheightthreshold = (obj["outlierheightthreshold"].is_string()?(float)atof(obj["outlierheightthreshold"].get<std::string>().c_str()):obj["outlierheightthreshold"].get<float>());
        }
        if(obj.contains("outliernumpointsthreshold"))
        {
            msg.outliernumpointsthreshold = (obj["outliernumpointsthreshold"].is_string()?atoi(obj["outliernumpointsthreshold"].get<std::string>().c_str()):obj["outliernumpointsthreshold"].get<uint32_t>());
        }
        if(obj.contains("overlapfactor"))
        {
            msg.overlapfactor = (obj["overlapfactor"].is_string()?(float)atof(obj["overlapfactor"].get<std::string>().c_str()):obj["overlapfactor"].get<float>());
        }
        if(obj.contains("felzenszwalbsigma"))
        {
            msg.felzenszwalbsigma = (obj["felzenszwalbsigma"].is_string()?(float)atof(obj["felzenszwalbsigma"].get<std::string>().c_str()):obj["felzenszwalbsigma"].get<float>());
        }
        if(obj.contains("felzenszwalbk"))
        {
            msg.felzenszwalbk = (obj["felzenszwalbk"].is_string()?(float)atof(obj["felzenszwalbk"].get<std::string>().c_str()):obj["felzenszwalbk"].get<float>());
        }
        if(obj.contains("felzenszwalbminsize"))
        {
            msg.felzenszwalbminsize = (obj["felzenszwalbminsize"].is_string()?atoi(obj["felzenszwalbminsize"].get<std::string>().c_str()):obj["felzenszwalbminsize"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarNCutParam from_json<ApolloperceptionlidarNCutParam>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarNCutParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNCutParam &dt)
    {
        dt=from_json_ApolloperceptionlidarNCutParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNCutParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNCutParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
