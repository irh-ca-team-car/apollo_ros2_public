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

#include "component/microphone.h"

namespace apollo
{
    namespace drivers
    {
        namespace microphone
        {

            bool MicrophoneComponent::Init()
            {

                MicrophoneConfig_ cfg;
                auto configFilePath = declare_parameter<std::string>("config_file", "microphone-config.json");
                apollo::cyber::common::GetProtoFromASCIIFile<MicrophoneConfig_>(configFilePath, &cfg);

                microphone_config_ptr_ = std::make_shared<MicrophoneConfig_>(cfg);

                AINFO << "Microphone config: " << *microphone_config_ptr_;

                // new microphone device
                microphone_device_ptr_.reset(new Respeaker());
                microphone_device_ptr_->init(microphone_config_ptr_);

                // dump config, calculate size and reserve buffer for audio
                n_channels_ = microphone_config_ptr_->channeltype.size();
                sample_width_ = microphone_config_ptr_->samplewidth;
                // chunk_: number of frames per chunk; chunk_size_: number of bytes per chunk
                chunk_ = microphone_config_ptr_->chunk;
                n_chunk_ = static_cast<int>(
                    std::ceil(microphone_config_ptr_->samplerate *
                              microphone_config_ptr_->recordseconds / chunk_));
                chunk_size_ = chunk_ * n_channels_ * sample_width_;
                buffer_ = new char[chunk_size_];
                if (buffer_ == nullptr)
                {
                    AERROR << "System new memory error, size:" << chunk_size_;
                    return false;
                }

                // assemble AudioData -- fill microphone_config, allocate memory for
                // channel_data
                audio_data_ptr_.reset(new AudioData());
                std::string config = apollo_msgs::msg::to_json(*microphone_config_ptr_);
                audio_data_ptr_->microphoneconfig = *microphone_config_ptr_;
                audio_data_ptr_->apolloheader.frameid=(
                    microphone_config_ptr_->frameid);

                ChannelData *channel_data = nullptr;
                int channel_size = n_chunk_ * chunk_ * sample_width_;
                for (int i = 0; i < n_channels_; ++i)
                {
                    channel_data = &audio_data_ptr_->channeldata.emplace_back();
                    channel_data->set__channeltype(microphone_config_ptr_->channeltype.at(i));
                    channel_data->data.data.resize(channel_size);
                    channel_data_ptrs_.push_back(channel_data->data);
                }

                writer_ptr_ =
                    node_->CreateWriter<AudioData>(microphone_config_ptr_->channelname);
                async_result_ = std::async(&MicrophoneComponent::run, this);
                return true;
            }

            void MicrophoneComponent::fill_channel_data(int chunk_i)
            {
                // next index of channel data to be filled
                int pos = chunk_i * chunk_ * sample_width_;
                for (int buff_i = 0; buff_i < chunk_size_; pos += sample_width_)
                {
                    for (int channel_i = 0; channel_i < n_channels_; ++channel_i)
                    {
                        for (int di = 0; di < sample_width_; ++di)
                        {
                            (channel_data_ptrs_[channel_i]).data[pos + di] = buffer_[buff_i++];
                        }
                    }
                }
            }

            void MicrophoneComponent::run()
            {
                int chunk_i;
                while (!cyber::IsShutdown())
                {
                    try
                    {
                        for (chunk_i = 0; chunk_i < n_chunk_; ++chunk_i)
                        {
                            microphone_device_ptr_->read_stream(chunk_, buffer_);
                            fill_channel_data(chunk_i);
                        }
                    }
                    catch (const std::exception &e)
                    {
                        return;
                    }
                    FillHeader(node_->get_name(), audio_data_ptr_.get());
                    writer_ptr_->Write(audio_data_ptr_);
                }
            }

            MicrophoneComponent::~MicrophoneComponent()
            {
                free(buffer_);
                if (running_.load())
                {
                    running_.exchange(false);
                    async_result_.wait();
                }
            }

        } // namespace microphone
    }     // namespace drivers
} // namespace apollo
CYBER_REGISTER_COMPONENT(MicrophoneComponent)