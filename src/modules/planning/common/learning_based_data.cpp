/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
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

#include "modules/planning/common/learning_based_data.h"

#include "cyber/common/log.h"

namespace apollo {
namespace planning {

void LearningBasedData::Clear() {
  learning_data_=apollo_msgs::msg::ApolloplanningLearningData();
}

void LearningBasedData::InsertLearningDataFrame(
    const LearningDataFrame& learning_data_frame) {
  learning_data_.learningdataframe.push_back(learning_data_frame);

  while (learning_data_.learningdataframe.size() > 10) {
    learning_data_.learningdataframe.pop_back();
  }
}
LearningDataFrame * LearningBasedData::GetLatestLearningDataFrame() {
  const int size = learning_data_.learningdataframe.size();
 
  return size > 0 ?& learning_data_.learningdataframe[size-1]
                  : nullptr;
}

}  // namespace planning
}  // namespace apollo