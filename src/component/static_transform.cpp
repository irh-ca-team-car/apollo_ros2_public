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

#include "component/static_transform.h"

#include "yaml-cpp/yaml.h"

#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/util/message_util.h"

namespace apollo
{
  namespace transform
  {

    bool StaticTransformComponent::Init()
    {
      auto configFilePath = declare_parameter<std::string>("config_file", "<root>/conf/transform.json");
      FLAGS_tf_static_topic = declare_parameter<std::string>("FLAGS_tf_static_topic", "/tf_static");
      FLAGS_tf_topic = declare_parameter<std::string>("FLAGS_tf_topic", "/tf");
      replaceRoot(configFilePath);
      apollo::cyber::common::GetProtoFromASCIIFile(configFilePath, &conf_);
      AINFO << FLAGS_tf_static_topic;
      AINFO << FLAGS_tf_topic;
      writer_ = node_->CreateWriter<TransformStampeds>(FLAGS_tf_static_topic);
      writer2_ = node_->CreateWriter<TransformStampeds>(FLAGS_tf_topic);
      SendTransforms();
      return true;
    }

    void StaticTransformComponent::SendTransforms()
    {
      std::vector<TransformStamped> tranform_stamped_vec;
      for (auto &extrinsic_file : conf_.extrinsicfile)
      {
        if (extrinsic_file.enable)
        {
          ADEBUG << "Broadcast static transform, frame id ["
                << extrinsic_file.frameid << "], child frame id ["
                << extrinsic_file.childframeid << "]";
          TransformStamped transform;
          
          if (ParseFromYaml(extrinsic_file.filepath, &transform))
          {
            transform.header.stamp = node_->get_clock()->now();
            tranform_stamped_vec.emplace_back(transform);
          }
        }
      }
      SendTransform(tranform_stamped_vec);
    }
    bool StaticTransformComponent::Proc()
    {
      SendTransforms();
      return true;
    }
    bool StaticTransformComponent::ParseFromYaml(
        const std::string &file_path, TransformStamped *transform_stamped)
    {
      if (!cyber::common::PathExists(file_path))
      {
        AERROR << "Extrinsic yaml file does not exist: " << file_path;
        return false;
      }
      YAML::Node tf = YAML::LoadFile(file_path);
      try
      {

        transform_stamped->header.frame_id = (tf["header"]["frame_id"].as<std::string>());
        transform_stamped->header.stamp.sec = 0;// cyber::Clock::NowInSeconds();
        transform_stamped->child_frame_id = (tf["child_frame_id"].as<std::string>());
        // translation

        transform_stamped->transform.translation.x = (tf["transform"]["translation"]["x"].as<double>());
        transform_stamped->transform.translation.y = (tf["transform"]["translation"]["y"].as<double>());
        transform_stamped->transform.translation.z = (tf["transform"]["translation"]["z"].as<double>());
        // rotation

        transform_stamped->transform.rotation.x = (tf["transform"]["rotation"]["x"].as<double>());
        transform_stamped->transform.rotation.y = (tf["transform"]["rotation"]["y"].as<double>());
        transform_stamped->transform.rotation.z = (tf["transform"]["rotation"]["z"].as<double>());
        transform_stamped->transform.rotation.w = (tf["transform"]["rotation"]["w"].as<double>());
      }
      catch (...)
      {
        AERROR << "Extrinsic yaml file parse failed: " << file_path;
        return false;
      }
      return true;
    }

    void StaticTransformComponent::SendTransform(
        const std::vector<TransformStamped> &msgtf)
    {
      for (auto it_in = msgtf.begin(); it_in != msgtf.end(); ++it_in)
      {
        bool match_found = false;
        for (auto &it_msg : transform_stampeds_.transforms)
        {
          if (it_in->child_frame_id == it_msg.child_frame_id)
          {
            it_msg = *it_in;
            match_found = true;
            break;
          }
        }

        if (!match_found)
        {
          transform_stampeds_.transforms.push_back(*it_in);
        }
      }

      // node_->FillHeader(node_->get_name () ,transform_stampeds_.header);
      writer2_->Write(transform_stampeds_);
      writer_->Write(transform_stampeds_);
    }

  } // namespace transform
} // namespace apollo
CYBER_REGISTER_COMPONENT(StaticTransformComponent)