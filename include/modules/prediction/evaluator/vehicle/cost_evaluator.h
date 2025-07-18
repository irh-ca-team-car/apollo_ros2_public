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

#pragma once

#include <string>

#include "modules/prediction/evaluator/evaluator.h"

#include "modules/prediction/container/obstacles/obstacles_container.h"

namespace apollo
{
    namespace prediction
    {

        class CostEvaluator : public Evaluator
        {
        public:
            /**
   * @brief Constructor
   */
            CostEvaluator();

            /**
   * @brief Destructor
   */
            virtual ~CostEvaluator() = default;

            /**
   * @brief Override Evaluate
   * @param Obstacle pointer
   * @param Obstacles container
   */
            bool Evaluate(Obstacle *obstacle_ptr,
                          ObstaclesContainer *obstacles_container) override;

            /**
   * @brief Get the name of evaluator.
   */
            std::string GetName() override { return "COST_EVALUATOR"; }

        private:
            double ComputeProbability(const double obstacle_length,
                                      const double obstacle_width,
                                      const apollo_msgs::msg::ApollopredictionLaneSequence &lane_sequence);

            double FrontLateralDistanceCost(const double obstacle_length,
                                            const double obstacle_width,
                                            const apollo_msgs::msg::ApollopredictionLaneSequence &lane_sequence);
        };

    } // namespace prediction
} // namespace apollo
