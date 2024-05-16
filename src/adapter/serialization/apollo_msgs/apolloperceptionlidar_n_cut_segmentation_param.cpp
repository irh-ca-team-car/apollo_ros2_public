#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_n_cut_segmentation_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNCutSegmentationParam &msg) {
        nlohmann::json obj;
        obj["gridradius"] = (msg.gridradius);
        obj["heightthreshold"] = (msg.heightthreshold);
        obj["partitioncellsize"] = (msg.partitioncellsize);
        obj["vehiclefiltercellsize"] = (msg.vehiclefiltercellsize);
        obj["pedestrianfiltercellsize"] = (msg.pedestrianfiltercellsize);
        obj["outlierlength"] = (msg.outlierlength);
        obj["outlierwidth"] = (msg.outlierwidth);
        obj["outlierheight"] = (msg.outlierheight);
        obj["outlierminnumpoints"] = (msg.outlierminnumpoints);
        obj["grounddetector"] = (msg.grounddetector);
        obj["roifilter"] = (msg.roifilter);
        obj["removegroundpoints"] = (msg.removegroundpoints);
        obj["removeroi"] = (msg.removeroi);
        obj["doclassification"] = (msg.doclassification);
        obj["ncutparam"] = to_json(msg.ncutparam);
        return obj;
    }
    ApolloperceptionlidarNCutSegmentationParam from_json_ApolloperceptionlidarNCutSegmentationParam (nlohmann::json obj) {
        ApolloperceptionlidarNCutSegmentationParam msg;
        if(obj.contains("gridradius"))
        {
            msg.gridradius = (obj["gridradius"].is_string()?(float)atof(obj["gridradius"].get<std::string>().c_str()):obj["gridradius"].get<float>());
        }
        if(obj.contains("heightthreshold"))
        {
            msg.heightthreshold = (obj["heightthreshold"].is_string()?(float)atof(obj["heightthreshold"].get<std::string>().c_str()):obj["heightthreshold"].get<float>());
        }
        if(obj.contains("partitioncellsize"))
        {
            msg.partitioncellsize = (obj["partitioncellsize"].is_string()?(float)atof(obj["partitioncellsize"].get<std::string>().c_str()):obj["partitioncellsize"].get<float>());
        }
        if(obj.contains("vehiclefiltercellsize"))
        {
            msg.vehiclefiltercellsize = (obj["vehiclefiltercellsize"].is_string()?(float)atof(obj["vehiclefiltercellsize"].get<std::string>().c_str()):obj["vehiclefiltercellsize"].get<float>());
        }
        if(obj.contains("pedestrianfiltercellsize"))
        {
            msg.pedestrianfiltercellsize = (obj["pedestrianfiltercellsize"].is_string()?(float)atof(obj["pedestrianfiltercellsize"].get<std::string>().c_str()):obj["pedestrianfiltercellsize"].get<float>());
        }
        if(obj.contains("outlierlength"))
        {
            msg.outlierlength = (obj["outlierlength"].is_string()?(float)atof(obj["outlierlength"].get<std::string>().c_str()):obj["outlierlength"].get<float>());
        }
        if(obj.contains("outlierwidth"))
        {
            msg.outlierwidth = (obj["outlierwidth"].is_string()?(float)atof(obj["outlierwidth"].get<std::string>().c_str()):obj["outlierwidth"].get<float>());
        }
        if(obj.contains("outlierheight"))
        {
            msg.outlierheight = (obj["outlierheight"].is_string()?(float)atof(obj["outlierheight"].get<std::string>().c_str()):obj["outlierheight"].get<float>());
        }
        if(obj.contains("outlierminnumpoints"))
        {
            msg.outlierminnumpoints = (obj["outlierminnumpoints"].is_string()?atoi(obj["outlierminnumpoints"].get<std::string>().c_str()):obj["outlierminnumpoints"].get<uint32_t>());
        }
        if(obj.contains("grounddetector"))
        {
            msg.grounddetector = (obj["grounddetector"].is_string()?(obj["grounddetector"].get<std::string>().c_str()):obj["grounddetector"].get<std::string>());
        }
        if(obj.contains("roifilter"))
        {
            msg.roifilter = (obj["roifilter"].is_string()?(obj["roifilter"].get<std::string>().c_str()):obj["roifilter"].get<std::string>());
        }
        if(obj.contains("removegroundpoints"))
        {
            msg.removegroundpoints = (obj["removegroundpoints"].is_string()?(bool)atoi(obj["removegroundpoints"].get<std::string>().c_str()):obj["removegroundpoints"].get<bool>());
        }
        if(obj.contains("removeroi"))
        {
            msg.removeroi = (obj["removeroi"].is_string()?(bool)atoi(obj["removeroi"].get<std::string>().c_str()):obj["removeroi"].get<bool>());
        }
        if(obj.contains("doclassification"))
        {
            msg.doclassification = (obj["doclassification"].is_string()?(bool)atoi(obj["doclassification"].get<std::string>().c_str()):obj["doclassification"].get<bool>());
        }
        if(obj.contains("ncutparam"))
        {
            msg.ncutparam = from_json_ApolloperceptionlidarNCutParam(obj["ncutparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarNCutSegmentationParam from_json<ApolloperceptionlidarNCutSegmentationParam>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarNCutSegmentationParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNCutSegmentationParam &dt)
    {
        dt=from_json_ApolloperceptionlidarNCutSegmentationParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNCutSegmentationParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNCutSegmentationParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
