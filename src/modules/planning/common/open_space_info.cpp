/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 **/

#include "modules/planning/common/open_space_info.h"

namespace apollo {
namespace planning {

void CopyTrajectory(const DiscretizedTrajectory trajectory_src,
                    apollo::common::Trajectory* trajectory_tgt_ptr) {
  const size_t horizon = trajectory_src.NumOfPoints();
  for (size_t i = 0; i < horizon; ++i) {
    trajectory_tgt_ptr->trajectorypoint.push_back(
        trajectory_src.TrajectoryPointAt(i));
  }
}

// record more trajectory information to info debug
void OpenSpaceInfo::RecordDebug(apollo::planningInternal::Debug* ptr_debug) {
  // 1, Copy info into ptr_debug
  *ptr_debug = debug_instance_;

  // 2, record partitioned trajectories into ptr_debug
  auto* ptr_partitioned_trajectories = &ptr_debug->planningdata
                                           .openspace.partitionedtrajectories
                                           ;

  for (auto& iter : partitioned_trajectories_) {
    const auto& picked_trajectory = iter.first;
    auto* ptr_added_trajectory = &ptr_partitioned_trajectories->trajectory.emplace_back();
    CopyTrajectory(picked_trajectory, ptr_added_trajectory);
  }

  // 3, record chosen partitioned into ptr_debug
  auto *ptr_chosen_trajectory = &ptr_debug->planningdata
                                     .openspace
                                     .chosentrajectory.trajectory.emplace_back();
  const auto &chosen_trajectory = chosen_partitioned_trajectory_.first;
  CopyTrajectory(chosen_trajectory, ptr_chosen_trajectory);

  // 4, record if the trajectory is fallback trajectory
  ptr_debug->planningdata
      .openspace
      .isfallbacktrajectory=(fallback_flag_);

  // 5, record fallback trajectory if needed
  if (fallback_flag_) {
    auto* ptr_fallback_trajectory = &ptr_debug->planningdata
                                        .openspace
                                        .fallbacktrajectory.trajectory.emplace_back()
                                        ;
    const auto& fallback_trajectory = fallback_trajectory_.first;
    CopyTrajectory(fallback_trajectory, ptr_fallback_trajectory);
    ptr_debug->planningdata
        .openspace
        .futurecollisionpoint
        =(future_collision_point_);
  }

  auto open_space = ptr_debug->planningdata.openspace;
  open_space.timelatency=(time_latency_);

  open_space.originpoint.x=(origin_point_.x());
  open_space.originpoint.y=(origin_point_.y());
  open_space.originpoint.z=(0.0);

  open_space.originheadingrad=(origin_heading_);
}

}  // namespace planning
}  // namespace apollo