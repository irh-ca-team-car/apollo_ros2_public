#include "adapter/serialization/apollo_msgs/apolloplanning_internal_planning_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalPlanningData &msg) {
        nlohmann::json obj;
        obj["adcposition"] = to_json(msg.adcposition);
        obj["chassis"] = to_json(msg.chassis);
        obj["routing"] = to_json(msg.routing);
        obj["initpoint"] = to_json(msg.initpoint);
        nlohmann::json arr_path;
        for (auto it = msg.path.begin(); it != msg.path.end(); ++it) {
            arr_path.push_back(to_json(*it));
        }
        obj["path"] = arr_path;
        nlohmann::json arr_speedplan;
        for (auto it = msg.speedplan.begin(); it != msg.speedplan.end(); ++it) {
            arr_speedplan.push_back(to_json(*it));
        }
        obj["speedplan"] = arr_speedplan;
        nlohmann::json arr_stgraph;
        for (auto it = msg.stgraph.begin(); it != msg.stgraph.end(); ++it) {
            arr_stgraph.push_back(to_json(*it));
        }
        obj["stgraph"] = arr_stgraph;
        nlohmann::json arr_slframe;
        for (auto it = msg.slframe.begin(); it != msg.slframe.end(); ++it) {
            arr_slframe.push_back(to_json(*it));
        }
        obj["slframe"] = arr_slframe;
        obj["predictionheader"] = to_json(msg.predictionheader);
        obj["signallight"] = to_json(msg.signallight);
        nlohmann::json arr_obstacle;
        for (auto it = msg.obstacle.begin(); it != msg.obstacle.end(); ++it) {
            arr_obstacle.push_back(to_json(*it));
        }
        obj["obstacle"] = arr_obstacle;
        nlohmann::json arr_referenceline;
        for (auto it = msg.referenceline.begin(); it != msg.referenceline.end(); ++it) {
            arr_referenceline.push_back(to_json(*it));
        }
        obj["referenceline"] = arr_referenceline;
        obj["dppolygraph"] = to_json(msg.dppolygraph);
        obj["latticestimage"] = to_json(msg.latticestimage);
        obj["relativemap"] = to_json(msg.relativemap);
        obj["autotuningtrainingdata"] = to_json(msg.autotuningtrainingdata);
        obj["frontcleardistance"] = (msg.frontcleardistance);
        nlohmann::json arr_chart;
        for (auto it = msg.chart.begin(); it != msg.chart.end(); ++it) {
            arr_chart.push_back((*it));
        }
        obj["chart"] = arr_chart;
        obj["scenario"] = to_json(msg.scenario);
        obj["openspace"] = to_json(msg.openspace);
        obj["smoother"] = to_json(msg.smoother);
        obj["pullover"] = to_json(msg.pullover);
        obj["hybridmodel"] = to_json(msg.hybridmodel);
        return obj;
    }
    ApolloplanningInternalPlanningData from_json_ApolloplanningInternalPlanningData (nlohmann::json obj) {
        ApolloplanningInternalPlanningData msg;
        if(obj.contains("adcposition"))
        {
            msg.adcposition = from_json_ApollolocalizationLocalizationEstimate(obj["adcposition"]);
        }
        if(obj.contains("chassis"))
        {
            msg.chassis = from_json_ApollocanbusChassis(obj["chassis"]);
        }
        if(obj.contains("routing"))
        {
            msg.routing = from_json_ApolloroutingRoutingResponse(obj["routing"]);
        }
        if(obj.contains("initpoint"))
        {
            msg.initpoint = from_json_ApollocommonTrajectoryPoint(obj["initpoint"]);
        }
        if(obj.contains("path"))
        {
            if(obj["path"].is_array())
            {
                for (auto& element : obj["path"])
                {
                    msg.path.push_back(from_json_ApollocommonPath(element));
                }
            }
            else
            {
                msg.path.push_back(from_json_ApollocommonPath(obj["path"]));
            }
        }
        if(obj.contains("speedplan"))
        {
            if(obj["speedplan"].is_array())
            {
                for (auto& element : obj["speedplan"])
                {
                    msg.speedplan.push_back(from_json_ApolloplanningInternalSpeedPlan(element));
                }
            }
            else
            {
                msg.speedplan.push_back(from_json_ApolloplanningInternalSpeedPlan(obj["speedplan"]));
            }
        }
        if(obj.contains("stgraph"))
        {
            if(obj["stgraph"].is_array())
            {
                for (auto& element : obj["stgraph"])
                {
                    msg.stgraph.push_back(from_json_ApolloplanningInternalSTGraphDebug(element));
                }
            }
            else
            {
                msg.stgraph.push_back(from_json_ApolloplanningInternalSTGraphDebug(obj["stgraph"]));
            }
        }
        if(obj.contains("slframe"))
        {
            if(obj["slframe"].is_array())
            {
                for (auto& element : obj["slframe"])
                {
                    msg.slframe.push_back(from_json_ApolloplanningInternalSLFrameDebug(element));
                }
            }
            else
            {
                msg.slframe.push_back(from_json_ApolloplanningInternalSLFrameDebug(obj["slframe"]));
            }
        }
        if(obj.contains("predictionheader"))
        {
            msg.predictionheader = from_json_ApollocommonHeader(obj["predictionheader"]);
        }
        if(obj.contains("signallight"))
        {
            msg.signallight = from_json_ApolloplanningInternalSignalLightDebug(obj["signallight"]);
        }
        if(obj.contains("obstacle"))
        {
            if(obj["obstacle"].is_array())
            {
                for (auto& element : obj["obstacle"])
                {
                    msg.obstacle.push_back(from_json_ApolloplanningInternalObstacleDebug(element));
                }
            }
            else
            {
                msg.obstacle.push_back(from_json_ApolloplanningInternalObstacleDebug(obj["obstacle"]));
            }
        }
        if(obj.contains("referenceline"))
        {
            if(obj["referenceline"].is_array())
            {
                for (auto& element : obj["referenceline"])
                {
                    msg.referenceline.push_back(from_json_ApolloplanningInternalReferenceLineDebug(element));
                }
            }
            else
            {
                msg.referenceline.push_back(from_json_ApolloplanningInternalReferenceLineDebug(obj["referenceline"]));
            }
        }
        if(obj.contains("dppolygraph"))
        {
            msg.dppolygraph = from_json_ApolloplanningInternalDpPolyGraphDebug(obj["dppolygraph"]);
        }
        if(obj.contains("latticestimage"))
        {
            msg.latticestimage = from_json_ApolloplanningInternalLatticeStTraining(obj["latticestimage"]);
        }
        if(obj.contains("relativemap"))
        {
            msg.relativemap = from_json_ApollorelativeMapMapMsg(obj["relativemap"]);
        }
        if(obj.contains("autotuningtrainingdata"))
        {
            msg.autotuningtrainingdata = from_json_ApolloplanningInternalAutoTuningTrainingData(obj["autotuningtrainingdata"]);
        }
        if(obj.contains("frontcleardistance"))
        {
            msg.frontcleardistance = (obj["frontcleardistance"].is_string()?atof(obj["frontcleardistance"].get<std::string>().c_str()):obj["frontcleardistance"].get<double>());
        }
        if(obj.contains("chart"))
        {
            if(obj["chart"].is_array())
            {
                for (auto& element : obj["chart"])
                {
                    msg.chart.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.chart.push_back((obj["chart"].is_string()?atoi(obj["chart"].get<std::string>().c_str()):obj["chart"].get<int>()));
            }
        }
        if(obj.contains("scenario"))
        {
            msg.scenario = from_json_ApolloplanningInternalScenarioDebug(obj["scenario"]);
        }
        if(obj.contains("openspace"))
        {
            msg.openspace = from_json_ApolloplanningInternalOpenSpaceDebug(obj["openspace"]);
        }
        if(obj.contains("smoother"))
        {
            msg.smoother = from_json_ApolloplanningInternalSmootherDebug(obj["smoother"]);
        }
        if(obj.contains("pullover"))
        {
            msg.pullover = from_json_ApolloplanningInternalPullOverDebug(obj["pullover"]);
        }
        if(obj.contains("hybridmodel"))
        {
            msg.hybridmodel = from_json_ApolloplanningInternalHybridModelDebug(obj["hybridmodel"]);
        }
        return msg;
    }
    template <>
    ApolloplanningInternalPlanningData from_json<ApolloplanningInternalPlanningData>(nlohmann::json obj){
        return from_json_ApolloplanningInternalPlanningData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalPlanningData &dt)
    {
        dt=from_json_ApolloplanningInternalPlanningData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalPlanningData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalPlanningData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
