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

#include "modules/audio/common/message_process.h"

namespace apollo {
namespace audio {

void MessageProcess::OnMicrophone(
    const AudioData& audio_data,
    const std::string& respeaker_extrinsics_file,
    AudioInfo* audio_info,
    DirectionDetection* direction_detection,
    MovingDetection* moving_detection,
    SirenDetection* siren_detection,
    AudioDetection* audio_detection) {
  audio_info->Insert(audio_data);
  auto direction_result =
      direction_detection->EstimateSoundSource(
          audio_info->GetSignals(audio_data.microphoneconfig.chunk),
          respeaker_extrinsics_file,
          audio_data.microphoneconfig.samplerate,
          audio_data.microphoneconfig.micdistance);
  audio_detection->position = direction_result.first;
  audio_detection->sourcedegree = (direction_result.second);

  bool is_siren = siren_detection->Evaluate(audio_info->GetSignals(72000));
  audio_detection->issiren=(is_siren);
  auto signals =
      audio_info->GetSignals(audio_data.microphoneconfig.chunk);
  MovingResult moving_result = moving_detection->Detect(signals);
  audio_detection->movingresult=(moving_result);
}

}  // namespace audio
}  // namespace apollo
