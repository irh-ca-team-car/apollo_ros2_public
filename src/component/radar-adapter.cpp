#include "component/radar-adapter.h"

#include <exception>
#include <vector>

namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {

      bool RadarAdapterComponent::Init()
      {
        auto input_topic = declare_parameter<std::string>("input_topic", "/apollo/sensor/radar/ros");
        auto input_topic_radar_state = declare_parameter<std::string>("input_topic_radar_state", "/apollo/sensor/radar/ros/state");
        auto input_topic_cluster_status = declare_parameter<std::string>("input_topic_cluster_status", "/apollo/sensor/radar/ros/cluster_status");
        auto output_topic = declare_parameter<std::string>("output_topic", "/apollo/sensor/radar/apollo");

        reader_state_ = this->CreateReader<RadarState>(input_topic_radar_state, std::bind(&RadarAdapterComponent::ProcState, this, std::placeholders::_1));
        reader_ = this->CreateReader<ObjectList>(input_topic, std::bind(&RadarAdapterComponent::Proc, this, std::placeholders::_1));
        reader_cluster_ = this->CreateReader<ClusterStatus>(input_topic_cluster_status, [this](const std::shared_ptr<ClusterStatus> m)
                                                            { 
                                                              msg.clusterliststatus.near = m->cluster_nofclustersnear.data;
                                                              msg.clusterliststatus.far = m->cluster_nofclustersfar.data;
                                                              msg.clusterliststatus.interfaceversion = m->cluster_interfaceversion.data;
                                                              msg.clusterliststatus.meascounter = m->cluster_meascounter.data;
                                                            });
        reader_object_ = this->CreateReader<ObjectStatus>(input_topic_cluster_status, [this](const std::shared_ptr<ObjectStatus> m)
                                                          { 
                                                            msg.objectliststatus.interfaceversion = m->obj_interfaceversion.data;
                                                            msg.objectliststatus.meascounter = m->obj_meascounter.data;
                                                            msg.objectliststatus.nofobjects = m->obj_nofobjects.data;
                                                          });

        writer_ = this->CreateWriter<apollo::drivers::ContiRadar>(output_topic);

        return true;
      }
      void RadarAdapterComponent::ProcState(const std::shared_ptr<RadarState> obj_list)
      {
        if(obj_list->header.stamp.sec < this->get_clock()->now().seconds() - 1800) return;

        state = *obj_list;

        msg.radarstate.maxdistance = state.radarstate_maxdistancecfg.data;
        msg.radarstate.radarpower = state.radarstate_radarpowercfg.data;
        msg.radarstate.outputtype = state.radarstate_outputtypecfg.data;
        msg.radarstate.rcsthreshold = state.radarstate_rcs_threshold.data;
        msg.radarstate.sendquality = state.radarstate_sendqualitycfg.data;
        msg.radarstate.sendextinfo = state.radarstate_sendextinfocfg.data;
      }
      void RadarAdapterComponent::Proc(const std::shared_ptr<ObjectList> obj_list)
      {
        if(obj_list->header.stamp.sec < this->get_clock()->now().seconds() - 1800) return;
        
        msg.contiobs.clear();

        msg.apolloheader.frameid = obj_list->header.frame_id;
        msg.apolloheader.timestampsec = obj_list->header.stamp.sec;

        for (auto &&i : obj_list->objects)
        {
          auto output = msg.contiobs.emplace_back();
        
          output.clusterortrack = msg.radarstate.outputtype == 2;
          output.obstacleid = i.obj_id.data;
          output.longitudedist = i.object_general.obj_distlong.data;
          output.lateraldist = i.object_general.obj_distlat.data;
          output.longitudevel = i.object_general.obj_vrellong.data;
          output.lateralvel = i.object_general.obj_vrellat.data;
          output.rcs = i.object_general.obj_rcs.data;
          output.dynprop = i.object_general.obj_dynprop.data;
          output.longitudedistrms = i.object_quality.obj_distlong_rms.data;
          output.lateraldistrms = i.object_quality.obj_distlat_rms.data;
          output.longitudevelrms = i.object_quality.obj_vrellong_rms.data;
          output.lateralvelrms = i.object_quality.obj_vrellat_rms.data;
          output.probexist = i.object_quality.obj_probofexist.data;
          output.measstate = i.object_quality.obj_measstate.data;
          output.longitudeaccel = i.object_extended.obj_arellong.data;
          output.lateralaccel = i.object_extended.obj_arellat.data;
          output.oritationangle = i.object_extended.obj_orientationangle.data;
          output.longitudeaccelrms = i.object_quality.obj_arellong_rms.data;
          output.lateralaccelrms = i.object_quality.obj_arellat_rms.data;
          output.oritationanglerms = i.object_quality.obj_orientation_rms.data;
          output.length = i.object_extended.obj_length.data;
          output.width = i.object_extended.obj_width.data;
          output.obstacleclass = i.object_extended.obj_class.data;
        }

        writer_->Write(msg);
      }
    } // namespace camera
  }   // namespace drivers
} // namespace apollo