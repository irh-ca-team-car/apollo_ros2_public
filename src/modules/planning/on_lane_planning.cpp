  
/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

#include "modules/planning/on_lane_planning.h"

#include "adapter/serialization/std_msgs/header.hpp"
#include <algorithm>
#include <limits>
#include <list>
#include <utility>

#include "absl/strings/str_cat.h"
#include "cyber/common/file.h"
#include "cyber/common/log.h"
#include "cyber/time/clock.h"
// #include "gtest/gtest_prod.h"
#include "modules/common/math/quaternion.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/map/hdmap/hdmap_util.h"
#include "modules/planning/common/ego_info.h"
#include "modules/planning/common/history.h"
#include "modules/planning/common/planning_context.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/common/trajectory_stitcher.h"
#include "modules/planning/common/util/util.h"
#include "modules/planning/learning_based/img_feature_renderer/birdview_img_feature_renderer.h"
#include "modules/planning/planner/rtk/rtk_replay_planner.h"
#include "modules/planning/proto/planning_internal.pb.h"
#include "modules/planning/proto/planning_semantic_map_config.pb.h"
#include "modules/planning/reference_line/reference_line_provider.h"
#include "modules/planning/tasks/task_factory.h"
#include "modules/planning/traffic_rules/traffic_decider.h"
#include "modules/routing/proto/routing.pb.h"

namespace apollo {
namespace planning {
using apollo_msgs::msg::ApollocanbusChassis;
using apollo_msgs::msg::ApollocommonEngageAdvice;
using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::TrajectoryPoint;
using apollo::common::VehicleState;
using apollo::common::VehicleStateProvider;
using apollo::common::math::Vec2d;
using apollo::cyber::Clock;
// using apollo::dreamview::Chart;
using apollo::hdmap::HDMapUtil;
using apollo::planningInternal::SLFrameDebug;
using apollo::planningInternal::SpeedPlan;

OnLanePlanning::~OnLanePlanning()
{
  if (reference_line_provider_)
  {
    reference_line_provider_->Stop();
  }
  planner_->Stop();
  injector_->frame_history()->Clear();
  injector_->history()->Clear();
  *injector_->planning_context()->mutable_planning_status() = apollo::planning::PlanningStatus();
  last_routing_=apollo::routing::RoutingResponse();
  injector_->ego_info()->Clear();
}

std::string OnLanePlanning::Name() const { return "on_lane_planning"; }

Status OnLanePlanning::Init(const apollo_msgs::msg::ApolloplanningPlanningConfig &config)
{
  config_ = config;
  if (!CheckPlanningConfig(config_))
  {
    return Status(ErrorCode::PLANNING_ERROR,
                  "planning config error: " + apollo_msgs::msg::to_json(config_).dump());
  }

  PlanningBase::Init(config_);

  planner_dispatcher_->Init();

  ACHECK(apollo::cyber::common::GetProtoFromFile(
      FLAGS_traffic_rule_config_filename, &traffic_rule_configs_))
      << "Failed to load traffic rule config file "
      << FLAGS_traffic_rule_config_filename;

  // clear planning history
  injector_->history()->Clear();

  // clear planning status
  *injector_->planning_context()->mutable_planning_status() = apollo::planning::PlanningStatus();

  // load map
  hdmap_ = HDMapUtil::BaseMapPtr();
  ACHECK(hdmap_) << "Failed to load map";

  // instantiate reference line provider
  reference_line_provider_ = std::make_unique<ReferenceLineProvider>(
      injector_->vehicle_state(), hdmap_);
  reference_line_provider_->Start();

  // dispatch planner
  planner_ = planner_dispatcher_->DispatchPlanner(config_, injector_);
  if (!planner_)
  {
    return Status(
        ErrorCode::PLANNING_ERROR,
        "planning is not initialized with config : " + apollo_msgs::msg::to_json(config_).dump());
  }

  if (config_.learningmode != PlanningConfig::NO_LEARNING)
  {
    PlanningSemanticMapConfig renderer_config;
    ACHECK(apollo::cyber::common::GetProtoFromFile(
        FLAGS_planning_birdview_img_feature_renderer_config_file,
        &renderer_config))
        << "Failed to load renderer config"
        << FLAGS_planning_birdview_img_feature_renderer_config_file;

    BirdviewImgFeatureRenderer::Instance()->Init(renderer_config);
  }

  start_time_ = Clock::NowInSeconds();
  return planner_->Init(config_);
}

Status OnLanePlanning::InitFrame(const uint32_t sequence_num,
                                 const TrajectoryPoint &planning_start_point,
                                 const VehicleState &vehicle_state)
{
  frame_.reset(new Frame(sequence_num, local_view_, planning_start_point,
                         vehicle_state, reference_line_provider_.get()));

  if (frame_ == nullptr)
  {
    return Status(ErrorCode::PLANNING_ERROR, "Fail to init frame: nullptr.");
  }

  std::list<ReferenceLine> reference_lines;
  std::list<hdmap::RouteSegments> segments;
  if (!reference_line_provider_->GetReferenceLines(&reference_lines,
                                                   &segments))
  {
    const std::string msg = "Failed to create reference line";
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }
  CHECK_EQ(reference_lines.size(), segments.size());

  auto forward_limit =
      hdmap::PncMap::LookForwardDistance(vehicle_state.linearvelocity);

  for (auto &ref_line : reference_lines)
  {
    if (!ref_line.Segment(Vec2d(vehicle_state.x, vehicle_state.y),
                          FLAGS_look_backward_distance, forward_limit))
    {
      const std::string msg = "Fail to shrink reference line.";
      AERROR << msg;
      return Status(ErrorCode::PLANNING_ERROR, msg);
    }
  }
  for (auto &seg : segments)
  {
    if (!seg.Shrink(Vec2d(vehicle_state.x, vehicle_state.y),
                    FLAGS_look_backward_distance, forward_limit))
    {
      const std::string msg = "Fail to shrink routing segments.";
      AERROR << msg;
      return Status(ErrorCode::PLANNING_ERROR, msg);
    }
  }

  auto status = frame_->Init(
      injector_->vehicle_state(), reference_lines, segments,
      reference_line_provider_->FutureRouteWaypoints(), injector_->ego_info());
  if (!status.ok())
  {
    AERROR << "failed to init frame:" << status.ToString();
    return status;
  }
  return Status::OK();
}

// TODO(all): fix this! this will cause unexpected behavior from controller
void OnLanePlanning::GenerateStopTrajectory(apollo_msgs::msg::ApolloplanningADCTrajectory *ptr_trajectory_pb)
{
  ptr_trajectory_pb->trajectorypoint.clear();

  const auto &vehicle_state = injector_->vehicle_state()->vehicle_state();
  const double max_t = FLAGS_fallback_total_time;
  const double unit_t = FLAGS_fallback_time_unit;

  TrajectoryPoint tp;
  auto *path_point = &tp.pathpoint;
  path_point->set__x(vehicle_state.x);
  path_point->set__y(vehicle_state.y);
  path_point->set__theta(vehicle_state.heading);
  path_point->set__s(0.0);
  tp.set__v(0.0);
  tp.set__a(0.0);
  for (double t = 0.0; t < max_t; t += unit_t)
  {
    tp.set__relativetime(t);
    ptr_trajectory_pb->trajectorypoint.push_back(tp);
  }
}

void OnLanePlanning::RunOnce(const LocalView &local_view,
                             apollo_msgs::msg::ApolloplanningADCTrajectory *const ptr_trajectory_pb)
{
  // when rerouting, reference line might not be updated. In this case, planning
  // module maintains not-ready until be restarted.
  static bool failed_to_update_reference_line = false;
  local_view_ = local_view;
  const double start_timestamp = Clock::NowInSeconds();
  const double start_system_timestamp =
      std::chrono::duration<double>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

  // localization
  ADEBUG << "Get localization:"
         << *local_view_.localization_estimate;

  // chassis
  ADEBUG << "Get chassis:" << *local_view_.chassis;

  Status status = injector_->vehicle_state()->Update(
      *local_view_.localization_estimate, *local_view_.chassis);

  VehicleState vehicle_state = injector_->vehicle_state()->vehicle_state();
  const double vehicle_state_timestamp = vehicle_state.timestamp;
  CHECK_GE(start_timestamp, vehicle_state_timestamp)
      << "start_timestamp is behind vehicle_state_timestamp by "
      << start_timestamp - vehicle_state_timestamp << " secs";

  if (!status.ok() || !util::IsVehicleStateValid(vehicle_state))
  {
    const std::string msg =
        "Update VehicleStateProvider failed "
        "or the vehicle state is out dated.";
    AERROR << msg;
    ptr_trajectory_pb->decision.maindecision.task.notready.set__reason(msg);
    //status.Save(ptr_trajectory_pb->mutable_header()->mutable_status());
    // TODO(all): integrate reverse gear
    ptr_trajectory_pb->set__gear(canbus::Chassis::GEAR_DRIVE);
    FillPlanningPb(start_timestamp, ptr_trajectory_pb);
    GenerateStopTrajectory(ptr_trajectory_pb);
    return;
  }

  if (start_timestamp - vehicle_state_timestamp <
      FLAGS_message_latency_threshold)
  {
    vehicle_state = AlignTimeStamp(vehicle_state, start_timestamp);
  }

  if (util::IsDifferentRouting(last_routing_, *local_view_.routing))
  {
    last_routing_ = *local_view_.routing;
    ADEBUG << "last_routing_:" << last_routing_;
    injector_->history()->Clear();
    *injector_->planning_context()->mutable_planning_status() = apollo::planning::PlanningStatus();
    reference_line_provider_->UpdateRoutingResponse(*local_view_.routing);
    planner_->Init(config_);
  }

  failed_to_update_reference_line =
      (!reference_line_provider_->UpdatedReferenceLine());

  // early return when reference line fails to update after rerouting
  if (failed_to_update_reference_line)
  {
    const std::string msg = "Failed to update reference line after rerouting.";
    AERROR << msg;
    ptr_trajectory_pb->decision.maindecision.task.notready.set__reason(msg);
    //status.Save(ptr_trajectory_pb->mutable_header()->mutable_status());
    ptr_trajectory_pb->set__gear(canbus::Chassis::GEAR_DRIVE);
    FillPlanningPb(start_timestamp, ptr_trajectory_pb);
    GenerateStopTrajectory(ptr_trajectory_pb);
    return;
  }

  // Update reference line provider and reset pull over if necessary
  reference_line_provider_->UpdateVehicleState(vehicle_state);

  // planning is triggered by prediction data, but we can still use an estimated
  // cycle time for stitching
  const double planning_cycle_time =
      1.0 / static_cast<double>(FLAGS_planning_loop_rate);

  std::string replan_reason;
  std::vector<TrajectoryPoint> stitching_trajectory =
      TrajectoryStitcher::ComputeStitchingTrajectory(
          vehicle_state, start_timestamp, planning_cycle_time,
          FLAGS_trajectory_stitching_preserved_length, true,
          last_publishable_trajectory_.get(), &replan_reason);

  injector_->ego_info()->Update(stitching_trajectory.back(), vehicle_state);
  const uint32_t frame_num = static_cast<uint32_t>(seq_num_++);
  status = InitFrame(frame_num, stitching_trajectory.back(), vehicle_state);

  if (status.ok())
  {
    injector_->ego_info()->CalculateFrontObstacleClearDistance(
        frame_->obstacles());
  }

 
  ptr_trajectory_pb->latencystats.set__initframetimems(
      Clock::NowInSeconds() - start_timestamp);

  if (!status.ok())
  {
    AERROR << status.ToString();
    if (FLAGS_publish_estop)
    {
      // "estop" signal check in function "Control::ProduceControlCommand()"
      // estop_ = estop_ || local_view_.trajectory.estop().is_estop();
      // we should add more information to ensure the estop being triggered.
      apollo_msgs::msg::ApolloplanningADCTrajectory estop_trajectory;
      EStop *estop = &estop_trajectory.estop;
      estop->set__isestop(true);
      estop->set__reason(status.error_message());
      //status.Save(estop_trajectory.mutable_header()->mutable_status());
      *ptr_trajectory_pb=(estop_trajectory);
    }
    else
    {
      ptr_trajectory_pb->decision.maindecision.task.notready.set__reason(status.ToString());
      //status.Save(ptr_trajectory_pb->mutable_header()->mutable_status());
      GenerateStopTrajectory(ptr_trajectory_pb);
    }
    // TODO(all): integrate reverse gear
    ptr_trajectory_pb->set__gear(canbus::Chassis::GEAR_DRIVE);
    FillPlanningPb(start_timestamp, ptr_trajectory_pb);
    frame_->set_current_frame_planned_trajectory(*ptr_trajectory_pb);
    const uint32_t n = frame_->SequenceNum();
    injector_->frame_history()->Add(n, std::move(frame_));
    return;
  }

  for (auto &ref_line_info : *frame_->mutable_reference_line_info())
  {
    TrafficDecider traffic_decider;
    traffic_decider.Init(traffic_rule_configs_);
    auto traffic_status =
        traffic_decider.Execute(frame_.get(), &ref_line_info, injector_);
    if (!traffic_status.ok() || !ref_line_info.IsDrivable())
    {
      ref_line_info.SetDrivable(false);
      AWARN << "Reference line " << ref_line_info.Lanes().Id()
            << " traffic decider failed";
    }
  }

  status = Plan(start_timestamp, stitching_trajectory, ptr_trajectory_pb);

  for (const auto &p : ptr_trajectory_pb->trajectorypoint)
  {
    ADEBUG << p;
  }
  const auto end_system_timestamp =
      std::chrono::duration<double>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();
  const auto time_diff_ms =
      (end_system_timestamp - start_system_timestamp) * 1000;
  ADEBUG << "total planning time spend: " << time_diff_ms << " ms.";

  ptr_trajectory_pb->latencystats.set__totaltimems(time_diff_ms);
  ADEBUG << "Planning latency: "
         << ptr_trajectory_pb->latencystats;

  if (!status.ok())
  {
    //status.Save(ptr_trajectory_pb->mutable_header()->mutable_status());
    AERROR << "Planning failed:" << status.ToString();
    if (FLAGS_publish_estop)
    {
      AERROR << "Planning failed and set estop";
      // "estop" signal check in function "Control::ProduceControlCommand()"
      // estop_ = estop_ || local_view_.trajectory.estop().is_estop();
      // we should add more information to ensure the estop being triggered.
      EStop *estop = &ptr_trajectory_pb->estop;
      estop->set__isestop(true);
      estop->set__reason(status.error_message());
    }
  }

  ptr_trajectory_pb->set__isreplan(stitching_trajectory.size() == 1);
  if (ptr_trajectory_pb->isreplan)
  {
    ptr_trajectory_pb->set__replanreason(replan_reason);
  }

  if (frame_->open_space_info().is_on_open_space_trajectory())
  {
    FillPlanningPb(start_timestamp, ptr_trajectory_pb);
    frame_->set_current_frame_planned_trajectory(*ptr_trajectory_pb);
  }
  else
  {
    auto *ref_line_task =
        &ptr_trajectory_pb->latencystats.taskstats.emplace_back();
    ref_line_task->set__timems(reference_line_provider_->LastTimeDelay() *
                               1000.0);
    ref_line_task->set__name("ReferenceLineProvider");
    // TODO(all): integrate reverse gear
    ptr_trajectory_pb->set__gear(canbus::Chassis::GEAR_DRIVE);
    FillPlanningPb(start_timestamp, ptr_trajectory_pb);

    frame_->set_current_frame_planned_trajectory(*ptr_trajectory_pb);
    if (FLAGS_enable_planning_smoother)
    {
      planning_smoother_.Smooth(injector_->frame_history(), frame_.get(),
                                ptr_trajectory_pb);
    }
  }

  const uint32_t n = frame_->SequenceNum();
  injector_->frame_history()->Add(n, std::move(frame_));
}

void OnLanePlanning::ExportReferenceLineDebug(planningInternal::Debug *debug)
{
  if (!FLAGS_enable_record_debug)
  {
    return;
  }
  for (auto &reference_line_info : *frame_->mutable_reference_line_info())
  {
    auto rl_debug = &debug->planningdata.referenceline.emplace_back();
    rl_debug->set__id(reference_line_info.Lanes().Id());
    rl_debug->set__length(reference_line_info.reference_line().Length());
    rl_debug->set__cost(reference_line_info.Cost());
    rl_debug->set__ischangelanepath(reference_line_info.IsChangeLanePath());
    rl_debug->set__isdrivable(reference_line_info.IsDrivable());
    rl_debug->set__isprotected(reference_line_info.GetRightOfWayStatus() ==
                               ADCTrajectory::PROTECTED);

    // store kappa and dkappa for performance evaluation
    const auto &reference_points =
        reference_line_info.reference_line().reference_points();
    double kappa_rms = 0.0;
    double dkappa_rms = 0.0;
    double kappa_max_abs = std::numeric_limits<double>::lowest();
    double dkappa_max_abs = std::numeric_limits<double>::lowest();
    for (const auto &reference_point : reference_points)
    {
      double kappa_sq = reference_point.kappa() * reference_point.kappa();
      double dkappa_sq = reference_point.dkappa() * reference_point.dkappa();
      kappa_rms += kappa_sq;
      dkappa_rms += dkappa_sq;
      kappa_max_abs = kappa_max_abs < kappa_sq ? kappa_sq : kappa_max_abs;
      dkappa_max_abs = dkappa_max_abs < dkappa_sq ? dkappa_sq : dkappa_max_abs;
    }
    double reference_points_size = static_cast<double>(reference_points.size());
    kappa_rms /= reference_points_size;
    dkappa_rms /= reference_points_size;
    kappa_rms = std::sqrt(kappa_rms);
    dkappa_rms = std::sqrt(dkappa_rms);
    rl_debug->set__kapparms(kappa_rms);
    rl_debug->set__dkapparms(dkappa_rms);
    rl_debug->set__kappamaxabs(kappa_max_abs);
    rl_debug->set__dkappamaxabs(dkappa_max_abs);

    bool is_off_road = false;
    double minimum_boundary = std::numeric_limits<double>::infinity();

    const double adc_half_width =
        common::VehicleConfigHelper::GetConfig().vehicleparam.width / 2.0;
    const auto &reference_line_path =
        reference_line_info.reference_line().GetMapPath();
    const auto sample_s = 0.1;
    const auto reference_line_length =
        reference_line_info.reference_line().Length();
    double average_offset = 0.0;
    double sample_count = 0.0;
    for (double s = 0.0; s < reference_line_length; s += sample_s)
    {
      double left_width = reference_line_path.GetLaneLeftWidth(s);
      double right_width = reference_line_path.GetLaneRightWidth(s);
      average_offset += 0.5 * std::abs(left_width - right_width);
      if (left_width < adc_half_width || right_width < adc_half_width)
      {
        is_off_road = true;
      }
      if (left_width < minimum_boundary)
      {
        minimum_boundary = left_width;
      }
      if (right_width < minimum_boundary)
      {
        minimum_boundary = right_width;
      }
      ++sample_count;
    }
    rl_debug->set__isoffroad(is_off_road);
    rl_debug->set__minimumboundary(minimum_boundary);
    rl_debug->set__averageoffset(average_offset / sample_count);
  }
}

Status OnLanePlanning::Plan(
    const double current_time_stamp,
    const std::vector<TrajectoryPoint> &stitching_trajectory,
    apollo_msgs::msg::ApolloplanningADCTrajectory *const ptr_trajectory_pb)
{
 
  auto status = planner_->Plan(stitching_trajectory.back(), frame_.get(),
                               ptr_trajectory_pb);

  if (frame_->open_space_info().is_on_open_space_trajectory())
  {
    frame_->mutable_open_space_info()->sync_debug_instance();
    const auto &publishable_trajectory =
        frame_->open_space_info().publishable_trajectory_data().first;
    const auto &publishable_trajectory_gear =
        frame_->open_space_info().publishable_trajectory_data().second;
    publishable_trajectory.PopulateTrajectoryProtobuf(ptr_trajectory_pb);
    ptr_trajectory_pb->set__gear(publishable_trajectory_gear);

    // TODO(QiL): refine engage advice in open space trajectory optimizer.
    auto *engage_advice = &ptr_trajectory_pb->engageadvice;

    // enable start auto from open_space planner.
    if (injector_->vehicle_state()->vehicle_state().drivingmode !=
        apollo::canbus::Chassis::DrivingMode::COMPLETE_AUTO_DRIVE)
    {
      engage_advice->set__advice(apollo::common::EngageAdvice::READY_TO_ENGAGE);
      engage_advice->set__reason(
          "Ready to engage when staring with OPEN_SPACE_PLANNER");
    }
    else
    {
      engage_advice->set__advice(apollo::common::EngageAdvice::KEEP_ENGAGED);
      engage_advice->set__reason("Keep engage while in parking");
    }
    // TODO(QiL): refine the export decision in open space info
    ptr_trajectory_pb->decision.maindecision.task.parking.set__status(MainParking::IN_PARKING);

  }
  else
  {
    const auto *best_ref_info = frame_->FindDriveReferenceLineInfo();
    const auto *target_ref_info = frame_->FindTargetReferenceLineInfo();
    if (!best_ref_info)
    {
      const std::string msg = "planner failed to make a driving plan";
      AERROR << msg;
      if (last_publishable_trajectory_)
      {
        last_publishable_trajectory_->Clear();
      }
      return Status(ErrorCode::PLANNING_ERROR, msg);
    }
    // Store current frame stitched path for possible speed fallback in next
    // frames
    DiscretizedPath current_frame_planned_path;
    for (const auto &trajectory_point : stitching_trajectory)
    {
      current_frame_planned_path.push_back(trajectory_point.pathpoint);
    }
    const auto &best_ref_path = best_ref_info->path_data().discretized_path();
    std::copy(best_ref_path.begin() + 1, best_ref_path.end(),
              std::back_inserter(current_frame_planned_path));
    frame_->set_current_frame_planned_path(current_frame_planned_path);

   
    ptr_trajectory_pb->latencystats =
        best_ref_info->latency_stats();
    // set right of way status
    ptr_trajectory_pb->set__rightofwaystatus(
        best_ref_info->GetRightOfWayStatus());

    for (const auto &id : best_ref_info->TargetLaneId())
    {
      ptr_trajectory_pb->laneid.push_back(id);
    }

    for (const auto &id : target_ref_info->TargetLaneId())
    {
      ptr_trajectory_pb->targetlaneid.push_back(id);
    }

    ptr_trajectory_pb->set__trajectorytype(best_ref_info->trajectory_type());

    if (FLAGS_enable_rss_info)
    {
      ptr_trajectory_pb->rssinfo = best_ref_info->rss_info();
    }

    best_ref_info->ExportDecision(&ptr_trajectory_pb->decision,
                                  injector_->planning_context());

    last_publishable_trajectory_.reset(new PublishableTrajectory(
        current_time_stamp, best_ref_info->trajectory()));

    ADEBUG << "current_time_stamp: " << current_time_stamp;

    last_publishable_trajectory_->PrependTrajectoryPoints(
        std::vector<TrajectoryPoint>(stitching_trajectory.begin(),
                                     stitching_trajectory.end() - 1));

    last_publishable_trajectory_->PopulateTrajectoryProtobuf(ptr_trajectory_pb);

    best_ref_info->ExportEngageAdvice(
        &ptr_trajectory_pb->engageadvice,
        injector_->planning_context());
  }

  return status;
}

bool OnLanePlanning::CheckPlanningConfig(const apollo_msgs::msg::ApolloplanningPlanningConfig &config)
{
  if (config.planningconfig.standardplanningconfig == apollo_msgs::msg::ApolloplanningStandardPlanningConfig())
  {
    return false;
  }
  if (config.planningconfig.standardplanningconfig.plannerpublicroadconfig != 0)
  {
    return false;
  }
  // TODO(All): check other config params
  return true;
}



VehicleState OnLanePlanning::AlignTimeStamp(const VehicleState &vehicle_state,
                                            const double curr_timestamp) const
{
  // TODO(Jinyun): use the same method in trajectory stitching
  //               for forward prediction
  auto future_xy = injector_->vehicle_state()->EstimateFuturePosition(
      curr_timestamp - vehicle_state.timestamp);

  VehicleState aligned_vehicle_state = vehicle_state;
  aligned_vehicle_state.set__x(future_xy.x());
  aligned_vehicle_state.set__y(future_xy.y());
  aligned_vehicle_state.set__timestamp(curr_timestamp);
  return aligned_vehicle_state;
}

}  // namespace planning
}  // namespace apollo