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

/**
 * @file
 **/

#pragma once

#include "modules/common/status/status.h"
#include "modules/planning/common/speed/speed_data.h"
#include "modules/planning/common/st_graph_data.h"
#include "modules/planning/tasks/task.h"

namespace apollo
{
    namespace planning
    {

        class SpeedOptimizer : public Task
        {
        public:
            explicit SpeedOptimizer(const apollo_msgs::msg::ApolloplanningTaskConfig &config);

            virtual ~SpeedOptimizer() = default;
            common::Status Execute(Frame *frame,
                                   ReferenceLineInfo *reference_line_info) override;

        protected:
            virtual common::Status Process(const PathData &path_data,
                                           const common::TrajectoryPoint &init_point,
                                           SpeedData *const speed_data) = 0;

            void RecordDebugInfo(const SpeedData &speed_data);
            void RecordDebugInfo(const SpeedData &speed_data,
                                 planningInternal::STGraphDebug *st_graph_debug);
        };

    } // namespace planning
} // namespace apollo