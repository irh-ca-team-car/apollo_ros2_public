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

#include "modules/control/common/control_gflags.h"

DEFINE_string(control_conf_file,
              "<root>/conf/control/control_conf.json",
              "default control conf data file");

DEFINE_string(control_common_conf_file,
              "<root>/conf/control/control_common_conf.json",
              "common control conf data file");

DEFINE_string(mpc_controller_conf_file,
              "<root>/conf/mpc_controller_conf.json",
              "mpc controller conf data file");

DEFINE_string(lateral_controller_conf_file,
              "<root>/conf/lateral_controller_conf.json",
              "lateral controller conf data file");

DEFINE_string(
    longitudinal_controller_conf_file,
    "<root>/conf/longitudinal_controller_conf.json",
    "longitudinal controller conf data file");

DEFINE_string(calibration_table_file,
              "<root>/conf/control/calibration_table.json",
              "calibration table file");

DEFINE_bool(enable_csv_debug, false, "True to write out csv debug file.");
DEFINE_bool(enable_speed_station_preview, true, "enable speed/station preview");

DEFINE_string(control_node_name, "control", "The control node name in proto");

DEFINE_string(mpc_controller_submodule_name, "MPCControllerSubmodule",
              "MPC controller node name in proto");

DEFINE_string(lat_lon_controller_submodule_name, "LatLonControllerSubmodule",
              "lateral+longitudinal controller node name in proto");

DEFINE_string(preprocessor_submodule_name, "PreprocessorSubmodule",
              "preprocessor submodule name in proto");

DEFINE_string(postprocessor_submodule_name, "PostprocessorSubmodule",
              "postprocessor submodule name in proto");

DEFINE_bool(is_control_test_mode, false, "True to run control in test mode");
DEFINE_bool(use_preview_speed_for_table, false,
            "True to use preview speed for table lookup");
DEFINE_double(control_test_duration, -1,
              "Steer angle change rate in percentage.");
DEFINE_double(steer_angle_rate, 100.0,
              "Steer angle change rate in percentage.");
DEFINE_bool(enable_gain_scheduler, false,
            "Enable gain scheduler for higher vehicle speed");
DEFINE_bool(set_steer_limit, false, "Set steer limit");

DEFINE_bool(enable_slope_offset, false, "Enable slope offset compensation");

DEFINE_double(lock_steer_speed, 0.081,
              "Minimum speed to lock the steer, in m/s");

DEFINE_bool(enable_navigation_mode_error_filter, false,
            "Enable error_filter for navigation mode");

DEFINE_bool(enable_navigation_mode_position_update, true,
            "Enable position update for navigation mode");

DEFINE_int32(chassis_pending_queue_size, 10, "Max chassis pending queue size");
DEFINE_int32(planning_pending_queue_size, 10,
             "Max planning pending queue size");
DEFINE_int32(localization_pending_queue_size, 10,
             "Max localization pending queue size");
DEFINE_int32(pad_msg_pending_queue_size, 10,
             "Max pad message pending queue size");

DEFINE_bool(reverse_heading_control, false, "test vehicle reverse control");

DEFINE_bool(
    trajectory_transform_to_com_reverse, false,
    "Enable planning trajectory coordinate transformation from center of "
    "rear-axis to center of mass, during reverse driving");
DEFINE_bool(
    trajectory_transform_to_com_drive, false,
    "Enable planning trajectory coordinate transformation from center of "
    "rear-axis to center of mass, during forward driving");

DEFINE_bool(enable_maximum_steer_rate_limit, false,
            "Enable steer rate limit obtained from vehicle_param.json");

DEFINE_bool(query_time_nearest_point_only, false,
            "only use the trajectory point at nearest time as target point");

DEFINE_bool(query_forward_time_point_only, false,
            "only use the trajectory point in future");

DEFINE_bool(enable_feedback_augment_on_high_speed, false,
            "Enable augmented control on lateral error on high speed");

DEFINE_bool(
    enable_gear_drive_negative_speed_protection, false,
    "Enable estop to prevent following negative speed during gear drive");

DEFINE_bool(use_control_submodules, false,
            "use control submodules instead of controller agent");

apollo::cyber::ComponentBase *ptr_control_component;

template <typename T>
T declare_parameter(std::string name, T defval)
{
    return ptr_control_component->declare_parameter(name, defval);
}
void InitControlGFlags(apollo::cyber::ComponentBase *ptr)
{
    ptr_control_component = ptr;

    INIT_FLAG_string(control_conf_file,
                     "<root>/conf/control.json",
                     "default control conf data file");

    INIT_FLAG_string(control_common_conf_file,
                     "<root>/conf/control/control_common_conf.json",
                     "common control conf data file");

    INIT_FLAG_string(mpc_controller_conf_file,
                     "<root>/conf/mpc_controller_conf.json",
                     "mpc controller conf data file");

    INIT_FLAG_string(lateral_controller_conf_file,
                     "<root>/conf/lateral_controller_conf.json",
                     "lateral controller conf data file");

    INIT_FLAG_string(
        longitudinal_controller_conf_file,
        "<root>/conf/longitudinal_controller_conf.json",
        "longitudinal controller conf data file");

    INIT_FLAG_string(calibration_table_file,
                     "<root>/conf/control/calibration_table.json",
                     "calibration table file");
    INIT_FLAG_double(control_test_duration, 0.0, "True to write out csv debug file.");
    INIT_FLAG_bool(enable_csv_debug, false, "True to write out csv debug file.");
    INIT_FLAG_bool(enable_speed_station_preview, true, "enable speed/station preview");

    INIT_FLAG_string(control_node_name, "control", "The control node name in proto");

    INIT_FLAG_string(mpc_controller_submodule_name, "MPCControllerSubmodule",
                     "MPC controller node name in proto");

    INIT_FLAG_string(lat_lon_controller_submodule_name, "LatLonControllerSubmodule",
                     "lateral+longitudinal controller node name in proto");

    INIT_FLAG_string(preprocessor_submodule_name, "PreprocessorSubmodule",
                     "preprocessor submodule name in proto");

    INIT_FLAG_string(postprocessor_submodule_name, "PostprocessorSubmodule",
                     "postprocessor submodule name in proto");

    INIT_FLAG_bool(is_control_test_mode, false, "True to run control in test mode");
    INIT_FLAG_bool(use_preview_speed_for_table, false,
                   "True to use preview speed for table lookup");

    INIT_FLAG_double(steer_angle_rate, 100.0,
                     "Steer angle change rate in percentage.");
    INIT_FLAG_bool(enable_gain_scheduler, false,
                   "Enable gain scheduler for higher vehicle speed");
    INIT_FLAG_bool(set_steer_limit, false, "Set steer limit");

    INIT_FLAG_bool(enable_slope_offset, false, "Enable slope offset compensation");

    INIT_FLAG_double(lock_steer_speed, 0.081,
                     "Minimum speed to lock the steer, in m/s");

    INIT_FLAG_bool(enable_navigation_mode_error_filter, false,
                   "Enable error_filter for navigation mode");

    INIT_FLAG_bool(enable_navigation_mode_position_update, true,
                   "Enable position update for navigation mode");

    INIT_FLAG_int32(chassis_pending_queue_size, 10, "Max chassis pending queue size");
    INIT_FLAG_int32(planning_pending_queue_size, 10,
                    "Max planning pending queue size");
    INIT_FLAG_int32(localization_pending_queue_size, 10,
                    "Max localization pending queue size");
    INIT_FLAG_int32(pad_msg_pending_queue_size, 10,
                    "Max pad message pending queue size");

    INIT_FLAG_bool(reverse_heading_control, false, "test vehicle reverse control");

    INIT_FLAG_bool(
        trajectory_transform_to_com_reverse, false,
        "Enable planning trajectory coordinate transformation from center of "
        "rear-axis to center of mass, during reverse driving");
    INIT_FLAG_bool(
        trajectory_transform_to_com_drive, false,
        "Enable planning trajectory coordinate transformation from center of "
        "rear-axis to center of mass, during forward driving");

    INIT_FLAG_bool(enable_maximum_steer_rate_limit, false,
                   "Enable steer rate limit obtained from vehicle_param.json");

    INIT_FLAG_bool(query_time_nearest_point_only, false,
                   "only use the trajectory point at nearest time as target point");

    INIT_FLAG_bool(query_forward_time_point_only, false,
                   "only use the trajectory point in future");

    INIT_FLAG_bool(enable_feedback_augment_on_high_speed, false,
                   "Enable augmented control on lateral error on high speed");

    INIT_FLAG_bool(
        enable_gear_drive_negative_speed_protection, false,
        "Enable estop to prevent following negative speed during gear drive");

    INIT_FLAG_bool(use_control_submodules, false,
                   "use control submodules instead of controller agent");
    }