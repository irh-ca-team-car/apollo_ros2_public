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
 * @brief Use predictor submodule to manage all predictors
 */

#pragma once

#include <memory>
#include <string>

#include "cyber/cyber.h"
#include "modules/prediction/common/message_process.h"
#include "modules/prediction/container/adc_trajectory/adc_trajectory_container.h"
#include "modules/prediction/predictor/predictor_manager.h"
#include "modules/prediction/submodules/submodule_output.h"

namespace apollo
{
  namespace prediction
  {
    typedef apollo::cyber::adapter::Sync<apollo_msgs::msg::ApolloperceptionPerceptionObstacles, ADCTrajectoryContainer, SubmoduleOutput> __sync__;

    class PredictorSubmodule
        : public cyber::Component
    {
      public:
      /**
   * @brief Destructor
   */
      PredictorSubmodule():cyber::Component("PredictorSubmodule"){}
       ~PredictorSubmodule() = default;

      /**
   * @brief Get name of the node
   * @return Name of the node
   */
      std::string Name() const;

      /**
   * @brief Initialize the node
   * @return If initialized
   */
      bool Init() override;

      /**
   * @brief Data callback upon receiving a prediction evaluator output.
   * @param Prediction adc trajectory container.
   * @param Prediction evaluator output.
   */
      bool Proc(const std::shared_ptr<apollo_msgs::msg::ApolloperceptionPerceptionObstacles>,
                const std::shared_ptr<ADCTrajectoryContainer>,
                const std::shared_ptr<SubmoduleOutput>);

    private:
      std::shared_ptr<cyber::Writer<PredictionObstacles>> predictor_writer_;

      std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApolloperceptionPerceptionObstacles>> proc_reader1_;
      std::shared_ptr<cyber::ReaderJson<ADCTrajectoryContainer>> proc_reader2_;
      std::shared_ptr<cyber::ReaderJson<SubmoduleOutput>> proc_reader3_;

      std::unique_ptr<PredictorManager> predictor_manager_;
      __sync__ sync_;
    };
  } // namespace prediction
} // namespace apollo
