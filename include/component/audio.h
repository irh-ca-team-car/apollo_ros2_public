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

/**
 * @file
 */

#pragma once

#include <memory>
#include <string>

#include "cyber/cyber.h"
#include "modules/audio/common/message_process.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/audio/common/audio_gflags.h"
/**
 * @namespace apollo::audio
 * @brief apollo::audio
 */
namespace apollo
{
    namespace audio
    {

        class AudioComponent
            : public cyber::Component
        {
        public:
            AudioComponent() : Component("AudioComponent") {}
            ~AudioComponent();

            std::string Name() const;

            bool Init() override;

            bool Proc(
                const apollo::audio::AudioData::SharedPtr);

        private:
            std::shared_ptr<cyber::Reader<apollo::localization::LocalizationEstimate>>
                localization_reader_;

            std::shared_ptr<cyber::Writer<apollo::audio::AudioDetection>> audio_writer_;
            std::shared_ptr<cyber::Reader<apollo::audio::AudioData>> mic_reader_;
            AudioInfo audio_info_;

            std::shared_ptr<DirectionDetection> direction_detection_;
            std::shared_ptr<MovingDetection> moving_detection_;
            std::shared_ptr<SirenDetection> siren_detection_;
            std::string respeaker_extrinsics_file_;
        };

    } // namespace audio
} // namespace apollo
