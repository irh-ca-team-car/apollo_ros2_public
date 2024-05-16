#include "adapter/serialization/apollo_msgs/apolloprediction_lstm_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLSTMParameter &msg) {
        nlohmann::json obj;
        obj["units"] = (msg.units);
        obj["returnsequences"] = (msg.returnsequences);
        obj["stateful"] = (msg.stateful);
        obj["activation"] = (msg.activation);
        obj["recurrentactivation"] = (msg.recurrentactivation);
        obj["usebias"] = (msg.usebias);
        obj["unitforgetbias"] = (msg.unitforgetbias);
        obj["gobackwards"] = (msg.gobackwards);
        obj["unroll"] = (msg.unroll);
        obj["implementation"] = (msg.implementation);
        obj["weightsinput"] = to_json(msg.weightsinput);
        obj["weightsforget"] = to_json(msg.weightsforget);
        obj["weightscell"] = to_json(msg.weightscell);
        obj["weightsoutput"] = to_json(msg.weightsoutput);
        obj["biasinput"] = to_json(msg.biasinput);
        obj["biasforget"] = to_json(msg.biasforget);
        obj["biascell"] = to_json(msg.biascell);
        obj["biasoutput"] = to_json(msg.biasoutput);
        obj["recurrentweightsinput"] = to_json(msg.recurrentweightsinput);
        obj["recurrentweightsforget"] = to_json(msg.recurrentweightsforget);
        obj["recurrentweightscell"] = to_json(msg.recurrentweightscell);
        obj["recurrentweightsoutput"] = to_json(msg.recurrentweightsoutput);
        return obj;
    }
    ApollopredictionLSTMParameter from_json_ApollopredictionLSTMParameter (nlohmann::json obj) {
        ApollopredictionLSTMParameter msg;
        if(obj.contains("units"))
        {
            msg.units = (obj["units"].is_string()?atoi(obj["units"].get<std::string>().c_str()):obj["units"].get<int>());
        }
        if(obj.contains("returnsequences"))
        {
            msg.returnsequences = (obj["returnsequences"].is_string()?(bool)atoi(obj["returnsequences"].get<std::string>().c_str()):obj["returnsequences"].get<bool>());
        }
        if(obj.contains("stateful"))
        {
            msg.stateful = (obj["stateful"].is_string()?(bool)atoi(obj["stateful"].get<std::string>().c_str()):obj["stateful"].get<bool>());
        }
        if(obj.contains("activation"))
        {
            msg.activation = (obj["activation"].is_string()?(obj["activation"].get<std::string>().c_str()):obj["activation"].get<std::string>());
        }
        if(obj.contains("recurrentactivation"))
        {
            msg.recurrentactivation = (obj["recurrentactivation"].is_string()?(obj["recurrentactivation"].get<std::string>().c_str()):obj["recurrentactivation"].get<std::string>());
        }
        if(obj.contains("usebias"))
        {
            msg.usebias = (obj["usebias"].is_string()?(bool)atoi(obj["usebias"].get<std::string>().c_str()):obj["usebias"].get<bool>());
        }
        if(obj.contains("unitforgetbias"))
        {
            msg.unitforgetbias = (obj["unitforgetbias"].is_string()?(bool)atoi(obj["unitforgetbias"].get<std::string>().c_str()):obj["unitforgetbias"].get<bool>());
        }
        if(obj.contains("gobackwards"))
        {
            msg.gobackwards = (obj["gobackwards"].is_string()?(bool)atoi(obj["gobackwards"].get<std::string>().c_str()):obj["gobackwards"].get<bool>());
        }
        if(obj.contains("unroll"))
        {
            msg.unroll = (obj["unroll"].is_string()?(bool)atoi(obj["unroll"].get<std::string>().c_str()):obj["unroll"].get<bool>());
        }
        if(obj.contains("implementation"))
        {
            msg.implementation = (obj["implementation"].is_string()?atoi(obj["implementation"].get<std::string>().c_str()):obj["implementation"].get<int>());
        }
        if(obj.contains("weightsinput"))
        {
            msg.weightsinput = from_json_ApollopredictionTensorParameter(obj["weightsinput"]);
        }
        if(obj.contains("weightsforget"))
        {
            msg.weightsforget = from_json_ApollopredictionTensorParameter(obj["weightsforget"]);
        }
        if(obj.contains("weightscell"))
        {
            msg.weightscell = from_json_ApollopredictionTensorParameter(obj["weightscell"]);
        }
        if(obj.contains("weightsoutput"))
        {
            msg.weightsoutput = from_json_ApollopredictionTensorParameter(obj["weightsoutput"]);
        }
        if(obj.contains("biasinput"))
        {
            msg.biasinput = from_json_ApollopredictionTensorParameter(obj["biasinput"]);
        }
        if(obj.contains("biasforget"))
        {
            msg.biasforget = from_json_ApollopredictionTensorParameter(obj["biasforget"]);
        }
        if(obj.contains("biascell"))
        {
            msg.biascell = from_json_ApollopredictionTensorParameter(obj["biascell"]);
        }
        if(obj.contains("biasoutput"))
        {
            msg.biasoutput = from_json_ApollopredictionTensorParameter(obj["biasoutput"]);
        }
        if(obj.contains("recurrentweightsinput"))
        {
            msg.recurrentweightsinput = from_json_ApollopredictionTensorParameter(obj["recurrentweightsinput"]);
        }
        if(obj.contains("recurrentweightsforget"))
        {
            msg.recurrentweightsforget = from_json_ApollopredictionTensorParameter(obj["recurrentweightsforget"]);
        }
        if(obj.contains("recurrentweightscell"))
        {
            msg.recurrentweightscell = from_json_ApollopredictionTensorParameter(obj["recurrentweightscell"]);
        }
        if(obj.contains("recurrentweightsoutput"))
        {
            msg.recurrentweightsoutput = from_json_ApollopredictionTensorParameter(obj["recurrentweightsoutput"]);
        }
        return msg;
    }
    template <>
    ApollopredictionLSTMParameter from_json<ApollopredictionLSTMParameter>(nlohmann::json obj){
        return from_json_ApollopredictionLSTMParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLSTMParameter &dt)
    {
        dt=from_json_ApollopredictionLSTMParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLSTMParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLSTMParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
