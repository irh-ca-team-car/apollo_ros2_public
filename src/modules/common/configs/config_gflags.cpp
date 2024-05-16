/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/common/configs/config_gflags.h"

DEFINE_string(map_dir, "<root>/data/map/demo",
              "Directory which contains a group of related maps.");
DEFINE_int32(local_utm_zone_id, 10, "UTM zone id.");

DEFINE_string(test_base_map_filename, "",
              "If not empty, use this test base map files.");

DEFINE_string(base_map_filename, "base_map.bin|base_map.xml|base_map.txt",
              "Base map files in the map_dir, search in order.");
DEFINE_string(sim_map_filename, "sim_map.bin|sim_map.txt",
              "Simulation map files in the map_dir, search in order.");
DEFINE_string(routing_map_filename, "routing_map.bin|routing_map.txt",
              "Routing map files in the map_dir, search in order.");
DEFINE_string(end_way_point_filename, "default_end_way_point.txt",
              "End way point of the map, will be sent in RoutingRequest.");
DEFINE_string(default_routing_filename, "default_cycle_routing.txt",
              "Default cycle routing of the map, will be sent in Task to Task "
              "Manager Module.");
DEFINE_string(vehicle_config_path,
              "<root>/data/common/vehicle_param.json",
              "the file path of vehicle config file");

DEFINE_string(
    vehicle_model_config_filename,
    "<root>/conf/vehicle_model_config.json",
    "the file path of vehicle model config file");

DEFINE_bool(use_cyber_time, false,
            "Whether Clock::Now() gets time from system_clock::now() or from "
            "Cyber.");

DEFINE_string(localization_tf2_frame_id, "world", "the tf2 transform frame id");
DEFINE_string(localization_tf2_child_frame_id, "localization",
              "the tf2 transform child frame id");

DEFINE_bool(use_navigation_mode, false,
            "Use relative position in navigation mode");
DEFINE_string(
    navigation_mode_end_way_point_file,
    "modules/dreamview/conf/navigation_mode_default_end_way_point.txt",
    "end_way_point file used if navigation mode is set.");

DEFINE_double(half_vehicle_width, 1.05, "half vehicle width");

DEFINE_double(look_forward_time_sec, 8.0,
              "look forward time times adc speed to calculate this distance "
              "when creating reference line from routing");

DEFINE_bool(use_sim_time, false, "Use bag time in mock time mode.");

DEFINE_bool(reverse_heading_vehicle_state, false,
            "test flag for reverse driving.");

DEFINE_bool(state_transform_to_com_reverse, false,
            "Enable vehicle states coordinate transformation from center of "
            "rear-axis to center of mass, during reverse driving");
DEFINE_bool(state_transform_to_com_drive, true,
            "Enable vehicle states coordinate transformation from center of "
            "rear-axis to center of mass, during forward driving");
DEFINE_bool(multithread_run, false,
            "multi-thread run flag mainly used by simulation");
            
extern apollo::cyber::ComponentBase *ptr_global;
namespace apollo::common::gflags
{
    

    template <typename T>
    T declare_parameter(std::string name, T defval)
    {
        return ptr_global->declare_parameter(name, defval);
    }
    bool common_init=false;
    bool init_common(apollo::cyber::ComponentBase *ptr)
    {

        AINFO << "init_common" << ptr;
        if(common_init)
        { 
            //AWARN << "Double init_common" << ptr;

            return true;
        }
        ptr_global = ptr;
        
        INIT_FLAG_string(map_dir, "<root>/data/map",
                         "Directory which contains a group of related maps.");
       
        INIT_FLAG_int32(local_utm_zone_id, 10, "UTM zone id.");

        INIT_FLAG_string(test_base_map_filename, "",
                         "If not empty, use this test base map files.");
        
        INIT_FLAG_string(base_map_filename, "base_map.bin|base_map.xml|base_map.txt",
                         "Base map files in the map_dir, search in order.");
        
        INIT_FLAG_string(sim_map_filename, "sim_map.bin|sim_map.txt",
                         "Simulation map files in the map_dir, search in order.");
        
        INIT_FLAG_string(routing_map_filename, "routing_map.bin|routing_map.txt",
                         "Routing map files in the map_dir, search in order.");
        
        INIT_FLAG_string(end_way_point_filename, "default_end_way_point.txt",
                         "End way point of the map, will be sent in RoutingRequest.");
        
        INIT_FLAG_string(default_routing_filename, "default_cycle_routing.txt",
                         "Default cycle routing of the map, will be sent in Task to Task "
                         "Manager Module.");
        
        INIT_FLAG_string(vehicle_config_path,
                         "<root>/data/common/vehicle_param.json",
                         "the file path of vehicle config file");

        INIT_FLAG_string(
            vehicle_model_config_filename,
            "<root>/conf/vehicle_model_config.json",
            "the file path of vehicle model config file");
        
        INIT_FLAG_bool(use_cyber_time, false,
                       "Whether Clock::Now() gets time from system_clock::now() or from "
                       "Cyber.");
        
        INIT_FLAG_string(localization_tf2_frame_id, "world", "the tf2 transform frame id");
        
        INIT_FLAG_string(localization_tf2_child_frame_id, "localization",
                         "the tf2 transform child frame id");
        
        INIT_FLAG_bool(use_navigation_mode, false,
                       "Use relative position in navigation mode");
        
        INIT_FLAG_string(
            navigation_mode_end_way_point_file,
            "modules/dreamview/conf/navigation_mode_default_end_way_point.txt",
            "end_way_point file used if navigation mode is set.");
        
        INIT_FLAG_double(half_vehicle_width, 1.05, "half vehicle width");
        
        INIT_FLAG_double(look_forward_time_sec, 8.0,
                         "look forward time times adc speed to calculate this distance "
                         "when creating reference line from routing");
        
        //INIT_FLAG_bool(use_sim_time, false, "Use bag time in mock time mode.");
        
        INIT_FLAG_bool(reverse_heading_vehicle_state, false,
                       "test flag for reverse driving.");
        
        INIT_FLAG_bool(state_transform_to_com_reverse, false,
                       "Enable vehicle states coordinate transformation from center of "
                       "rear-axis to center of mass, during reverse driving");
        
        INIT_FLAG_bool(state_transform_to_com_drive, true,
                       "Enable vehicle states coordinate transformation from center of "
                       "rear-axis to center of mass, during forward driving");
        INIT_FLAG_bool(multithread_run, false,
                       "multi-thread run flag mainly used by simulation");
        return common_init=true;
    }
}