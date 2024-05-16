#include "adapter/serialization/apollo_msgs/apolloperceptioninference_convolution_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceConvolutionParameter &msg) {
        nlohmann::json obj;
        obj["numoutput"] = (msg.numoutput);
        obj["biasterm"] = (msg.biasterm);
        nlohmann::json arr_pad;
        for (auto it = msg.pad.begin(); it != msg.pad.end(); ++it) {
            arr_pad.push_back((*it));
        }
        obj["pad"] = arr_pad;
        nlohmann::json arr_kernelsize;
        for (auto it = msg.kernelsize.begin(); it != msg.kernelsize.end(); ++it) {
            arr_kernelsize.push_back((*it));
        }
        obj["kernelsize"] = arr_kernelsize;
        nlohmann::json arr_stride;
        for (auto it = msg.stride.begin(); it != msg.stride.end(); ++it) {
            arr_stride.push_back((*it));
        }
        obj["stride"] = arr_stride;
        nlohmann::json arr_dilation;
        for (auto it = msg.dilation.begin(); it != msg.dilation.end(); ++it) {
            arr_dilation.push_back((*it));
        }
        obj["dilation"] = arr_dilation;
        obj["padh"] = (msg.padh);
        obj["padw"] = (msg.padw);
        obj["kernelh"] = (msg.kernelh);
        obj["kernelw"] = (msg.kernelw);
        obj["strideh"] = (msg.strideh);
        obj["stridew"] = (msg.stridew);
        obj["group"] = (msg.group);
        obj["weightfiller"] = to_json(msg.weightfiller);
        obj["biasfiller"] = to_json(msg.biasfiller);
        obj["engine"] = (msg.engine);
        obj["axis"] = (msg.axis);
        obj["forcendim2col"] = (msg.forcendim2col);
        return obj;
    }
    ApolloperceptioninferenceConvolutionParameter from_json_ApolloperceptioninferenceConvolutionParameter (nlohmann::json obj) {
        ApolloperceptioninferenceConvolutionParameter msg;
        if(obj.contains("numoutput"))
        {
            msg.numoutput = (obj["numoutput"].is_string()?atoi(obj["numoutput"].get<std::string>().c_str()):obj["numoutput"].get<uint32_t>());
        }
        if(obj.contains("biasterm"))
        {
            msg.biasterm = (obj["biasterm"].is_string()?(bool)atoi(obj["biasterm"].get<std::string>().c_str()):obj["biasterm"].get<bool>());
        }
        if(obj.contains("pad"))
        {
            if(obj["pad"].is_array())
            {
                for (auto& element : obj["pad"])
                {
                    msg.pad.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.pad.push_back((obj["pad"].is_string()?atoi(obj["pad"].get<std::string>().c_str()):obj["pad"].get<uint32_t>()));
            }
        }
        if(obj.contains("kernelsize"))
        {
            if(obj["kernelsize"].is_array())
            {
                for (auto& element : obj["kernelsize"])
                {
                    msg.kernelsize.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.kernelsize.push_back((obj["kernelsize"].is_string()?atoi(obj["kernelsize"].get<std::string>().c_str()):obj["kernelsize"].get<uint32_t>()));
            }
        }
        if(obj.contains("stride"))
        {
            if(obj["stride"].is_array())
            {
                for (auto& element : obj["stride"])
                {
                    msg.stride.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.stride.push_back((obj["stride"].is_string()?atoi(obj["stride"].get<std::string>().c_str()):obj["stride"].get<uint32_t>()));
            }
        }
        if(obj.contains("dilation"))
        {
            if(obj["dilation"].is_array())
            {
                for (auto& element : obj["dilation"])
                {
                    msg.dilation.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.dilation.push_back((obj["dilation"].is_string()?atoi(obj["dilation"].get<std::string>().c_str()):obj["dilation"].get<uint32_t>()));
            }
        }
        if(obj.contains("padh"))
        {
            msg.padh = (obj["padh"].is_string()?atoi(obj["padh"].get<std::string>().c_str()):obj["padh"].get<uint32_t>());
        }
        if(obj.contains("padw"))
        {
            msg.padw = (obj["padw"].is_string()?atoi(obj["padw"].get<std::string>().c_str()):obj["padw"].get<uint32_t>());
        }
        if(obj.contains("kernelh"))
        {
            msg.kernelh = (obj["kernelh"].is_string()?atoi(obj["kernelh"].get<std::string>().c_str()):obj["kernelh"].get<uint32_t>());
        }
        if(obj.contains("kernelw"))
        {
            msg.kernelw = (obj["kernelw"].is_string()?atoi(obj["kernelw"].get<std::string>().c_str()):obj["kernelw"].get<uint32_t>());
        }
        if(obj.contains("strideh"))
        {
            msg.strideh = (obj["strideh"].is_string()?atoi(obj["strideh"].get<std::string>().c_str()):obj["strideh"].get<uint32_t>());
        }
        if(obj.contains("stridew"))
        {
            msg.stridew = (obj["stridew"].is_string()?atoi(obj["stridew"].get<std::string>().c_str()):obj["stridew"].get<uint32_t>());
        }
        if(obj.contains("group"))
        {
            msg.group = (obj["group"].is_string()?atoi(obj["group"].get<std::string>().c_str()):obj["group"].get<uint32_t>());
        }
        if(obj.contains("weightfiller"))
        {
            msg.weightfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["weightfiller"]);
        }
        if(obj.contains("biasfiller"))
        {
            msg.biasfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["biasfiller"]);
        }
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("forcendim2col"))
        {
            msg.forcendim2col = (obj["forcendim2col"].is_string()?(bool)atoi(obj["forcendim2col"].get<std::string>().c_str()):obj["forcendim2col"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceConvolutionParameter from_json<ApolloperceptioninferenceConvolutionParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceConvolutionParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceConvolutionParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceConvolutionParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceConvolutionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceConvolutionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
