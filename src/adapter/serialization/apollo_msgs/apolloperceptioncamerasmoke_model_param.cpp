#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_model_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeModelParam &msg) {
        nlohmann::json obj;
        obj["modelname"] = (msg.modelname);
        obj["protofile"] = (msg.protofile);
        obj["weightfile"] = (msg.weightfile);
        obj["stage1pt"] = (msg.stage1pt);
        obj["stage1md"] = (msg.stage1md);
        obj["stage2pt"] = (msg.stage2pt);
        obj["stage2md"] = (msg.stage2md);
        obj["anchorsfile"] = (msg.anchorsfile);
        obj["typesfile"] = (msg.typesfile);
        obj["featurefile"] = (msg.featurefile);
        obj["offsetratio"] = (msg.offsetratio);
        obj["croppedratio"] = (msg.croppedratio);
        obj["resizedwidth"] = (msg.resizedwidth);
        obj["alignedpixel"] = (msg.alignedpixel);
        obj["confidencethreshold"] = (msg.confidencethreshold);
        obj["lightvisconfthreshold"] = (msg.lightvisconfthreshold);
        obj["lightswtconfthreshold"] = (msg.lightswtconfthreshold);
        obj["roiconfthreshold"] = (msg.roiconfthreshold);
        obj["boxconfthreshold"] = (msg.boxconfthreshold);
        obj["stage2nmsthreshold"] = (msg.stage2nmsthreshold);
        obj["min2dheight"] = (msg.min2dheight);
        obj["min3dheight"] = (msg.min3dheight);
        obj["min3dwidth"] = (msg.min3dwidth);
        obj["min3dlength"] = (msg.min3dlength);
        obj["calibratetableroot"] = (msg.calibratetableroot);
        obj["modeltype"] = (msg.modeltype);
        obj["oricycle"] = (msg.oricycle);
        obj["perclsreg"] = (msg.perclsreg);
        nlohmann::json arr_dimensionstatistics;
        for (auto it = msg.dimensionstatistics.begin(); it != msg.dimensionstatistics.end(); ++it) {
            arr_dimensionstatistics.push_back(to_json(*it));
        }
        obj["dimensionstatistics"] = arr_dimensionstatistics;
        nlohmann::json arr_bboxstatistics;
        for (auto it = msg.bboxstatistics.begin(); it != msg.bboxstatistics.end(); ++it) {
            arr_bboxstatistics.push_back(to_json(*it));
        }
        obj["bboxstatistics"] = arr_bboxstatistics;
        obj["expandfile"] = (msg.expandfile);
        obj["withbox3d"] = (msg.withbox3d);
        obj["withfrbox"] = (msg.withfrbox);
        obj["withlights"] = (msg.withlights);
        obj["withratios"] = (msg.withratios);
        obj["numareas"] = (msg.numareas);
        obj["borderratio"] = (msg.borderratio);
        return obj;
    }
    ApolloperceptioncamerasmokeModelParam from_json_ApolloperceptioncamerasmokeModelParam (nlohmann::json obj) {
        ApolloperceptioncamerasmokeModelParam msg;
        if(obj.contains("modelname"))
        {
            msg.modelname = (obj["modelname"].is_string()?(obj["modelname"].get<std::string>().c_str()):obj["modelname"].get<std::string>());
        }
        if(obj.contains("protofile"))
        {
            msg.protofile = (obj["protofile"].is_string()?(obj["protofile"].get<std::string>().c_str()):obj["protofile"].get<std::string>());
        }
        if(obj.contains("weightfile"))
        {
            msg.weightfile = (obj["weightfile"].is_string()?(obj["weightfile"].get<std::string>().c_str()):obj["weightfile"].get<std::string>());
        }
        if(obj.contains("stage1pt"))
        {
            msg.stage1pt = (obj["stage1pt"].is_string()?(obj["stage1pt"].get<std::string>().c_str()):obj["stage1pt"].get<std::string>());
        }
        if(obj.contains("stage1md"))
        {
            msg.stage1md = (obj["stage1md"].is_string()?(obj["stage1md"].get<std::string>().c_str()):obj["stage1md"].get<std::string>());
        }
        if(obj.contains("stage2pt"))
        {
            msg.stage2pt = (obj["stage2pt"].is_string()?(obj["stage2pt"].get<std::string>().c_str()):obj["stage2pt"].get<std::string>());
        }
        if(obj.contains("stage2md"))
        {
            msg.stage2md = (obj["stage2md"].is_string()?(obj["stage2md"].get<std::string>().c_str()):obj["stage2md"].get<std::string>());
        }
        if(obj.contains("anchorsfile"))
        {
            msg.anchorsfile = (obj["anchorsfile"].is_string()?(obj["anchorsfile"].get<std::string>().c_str()):obj["anchorsfile"].get<std::string>());
        }
        if(obj.contains("typesfile"))
        {
            msg.typesfile = (obj["typesfile"].is_string()?(obj["typesfile"].get<std::string>().c_str()):obj["typesfile"].get<std::string>());
        }
        if(obj.contains("featurefile"))
        {
            msg.featurefile = (obj["featurefile"].is_string()?(obj["featurefile"].get<std::string>().c_str()):obj["featurefile"].get<std::string>());
        }
        if(obj.contains("offsetratio"))
        {
            msg.offsetratio = (obj["offsetratio"].is_string()?(float)atof(obj["offsetratio"].get<std::string>().c_str()):obj["offsetratio"].get<float>());
        }
        if(obj.contains("croppedratio"))
        {
            msg.croppedratio = (obj["croppedratio"].is_string()?(float)atof(obj["croppedratio"].get<std::string>().c_str()):obj["croppedratio"].get<float>());
        }
        if(obj.contains("resizedwidth"))
        {
            msg.resizedwidth = (obj["resizedwidth"].is_string()?atoi(obj["resizedwidth"].get<std::string>().c_str()):obj["resizedwidth"].get<int>());
        }
        if(obj.contains("alignedpixel"))
        {
            msg.alignedpixel = (obj["alignedpixel"].is_string()?atoi(obj["alignedpixel"].get<std::string>().c_str()):obj["alignedpixel"].get<int>());
        }
        if(obj.contains("confidencethreshold"))
        {
            msg.confidencethreshold = (obj["confidencethreshold"].is_string()?(float)atof(obj["confidencethreshold"].get<std::string>().c_str()):obj["confidencethreshold"].get<float>());
        }
        if(obj.contains("lightvisconfthreshold"))
        {
            msg.lightvisconfthreshold = (obj["lightvisconfthreshold"].is_string()?(float)atof(obj["lightvisconfthreshold"].get<std::string>().c_str()):obj["lightvisconfthreshold"].get<float>());
        }
        if(obj.contains("lightswtconfthreshold"))
        {
            msg.lightswtconfthreshold = (obj["lightswtconfthreshold"].is_string()?(float)atof(obj["lightswtconfthreshold"].get<std::string>().c_str()):obj["lightswtconfthreshold"].get<float>());
        }
        if(obj.contains("roiconfthreshold"))
        {
            msg.roiconfthreshold = (obj["roiconfthreshold"].is_string()?(float)atof(obj["roiconfthreshold"].get<std::string>().c_str()):obj["roiconfthreshold"].get<float>());
        }
        if(obj.contains("boxconfthreshold"))
        {
            msg.boxconfthreshold = (obj["boxconfthreshold"].is_string()?(float)atof(obj["boxconfthreshold"].get<std::string>().c_str()):obj["boxconfthreshold"].get<float>());
        }
        if(obj.contains("stage2nmsthreshold"))
        {
            msg.stage2nmsthreshold = (obj["stage2nmsthreshold"].is_string()?(float)atof(obj["stage2nmsthreshold"].get<std::string>().c_str()):obj["stage2nmsthreshold"].get<float>());
        }
        if(obj.contains("min2dheight"))
        {
            msg.min2dheight = (obj["min2dheight"].is_string()?(float)atof(obj["min2dheight"].get<std::string>().c_str()):obj["min2dheight"].get<float>());
        }
        if(obj.contains("min3dheight"))
        {
            msg.min3dheight = (obj["min3dheight"].is_string()?(float)atof(obj["min3dheight"].get<std::string>().c_str()):obj["min3dheight"].get<float>());
        }
        if(obj.contains("min3dwidth"))
        {
            msg.min3dwidth = (obj["min3dwidth"].is_string()?(float)atof(obj["min3dwidth"].get<std::string>().c_str()):obj["min3dwidth"].get<float>());
        }
        if(obj.contains("min3dlength"))
        {
            msg.min3dlength = (obj["min3dlength"].is_string()?(float)atof(obj["min3dlength"].get<std::string>().c_str()):obj["min3dlength"].get<float>());
        }
        if(obj.contains("calibratetableroot"))
        {
            msg.calibratetableroot = (obj["calibratetableroot"].is_string()?(obj["calibratetableroot"].get<std::string>().c_str()):obj["calibratetableroot"].get<std::string>());
        }
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<std::string>());
        }
        if(obj.contains("oricycle"))
        {
            msg.oricycle = (obj["oricycle"].is_string()?atoi(obj["oricycle"].get<std::string>().c_str()):obj["oricycle"].get<int>());
        }
        if(obj.contains("perclsreg"))
        {
            msg.perclsreg = (obj["perclsreg"].is_string()?(bool)atoi(obj["perclsreg"].get<std::string>().c_str()):obj["perclsreg"].get<bool>());
        }
        if(obj.contains("dimensionstatistics"))
        {
            if(obj["dimensionstatistics"].is_array())
            {
                for (auto& element : obj["dimensionstatistics"])
                {
                    msg.dimensionstatistics.push_back(from_json_ApolloperceptioncamerasmokeDimensionStatistics(element));
                }
            }
            else
            {
                msg.dimensionstatistics.push_back(from_json_ApolloperceptioncamerasmokeDimensionStatistics(obj["dimensionstatistics"]));
            }
        }
        if(obj.contains("bboxstatistics"))
        {
            if(obj["bboxstatistics"].is_array())
            {
                for (auto& element : obj["bboxstatistics"])
                {
                    msg.bboxstatistics.push_back(from_json_ApolloperceptioncamerasmokeBBoxStatistics(element));
                }
            }
            else
            {
                msg.bboxstatistics.push_back(from_json_ApolloperceptioncamerasmokeBBoxStatistics(obj["bboxstatistics"]));
            }
        }
        if(obj.contains("expandfile"))
        {
            msg.expandfile = (obj["expandfile"].is_string()?(obj["expandfile"].get<std::string>().c_str()):obj["expandfile"].get<std::string>());
        }
        if(obj.contains("withbox3d"))
        {
            msg.withbox3d = (obj["withbox3d"].is_string()?(bool)atoi(obj["withbox3d"].get<std::string>().c_str()):obj["withbox3d"].get<bool>());
        }
        if(obj.contains("withfrbox"))
        {
            msg.withfrbox = (obj["withfrbox"].is_string()?(bool)atoi(obj["withfrbox"].get<std::string>().c_str()):obj["withfrbox"].get<bool>());
        }
        if(obj.contains("withlights"))
        {
            msg.withlights = (obj["withlights"].is_string()?(bool)atoi(obj["withlights"].get<std::string>().c_str()):obj["withlights"].get<bool>());
        }
        if(obj.contains("withratios"))
        {
            msg.withratios = (obj["withratios"].is_string()?(bool)atoi(obj["withratios"].get<std::string>().c_str()):obj["withratios"].get<bool>());
        }
        if(obj.contains("numareas"))
        {
            msg.numareas = (obj["numareas"].is_string()?atoi(obj["numareas"].get<std::string>().c_str()):obj["numareas"].get<int>());
        }
        if(obj.contains("borderratio"))
        {
            msg.borderratio = (obj["borderratio"].is_string()?(float)atof(obj["borderratio"].get<std::string>().c_str()):obj["borderratio"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncamerasmokeModelParam from_json<ApolloperceptioncamerasmokeModelParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncamerasmokeModelParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeModelParam &dt)
    {
        dt=from_json_ApolloperceptioncamerasmokeModelParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeModelParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeModelParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
