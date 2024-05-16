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
#include "modules/perception/lib/config_manager/config_manager.h"

#include "cyber/cyber.h"
#include "cyber/common/environment.h"
#include "modules/perception/common/io/io_util.h"
#include "modules/perception/common/perception_gflags.h"

namespace apollo
{
  namespace perception
  {
    namespace lib
    {

      using cyber::common::GetAbsolutePath;
      using cyber::common::GetProtoFromASCIIFile;

      ConfigManager::ConfigManager()
      {
        work_root_ = FLAGS_work_root;

        // For start at arbitrary path
        if (work_root_.empty())
        {
          work_root_ = cyber::common::GetEnv("MODULE_PATH");
          if (work_root_.empty())
          {
            work_root_ = cyber::common::GetEnv("CYBER_PATH");
          }
        }
      }

      bool ConfigManager::Init()
      {
        std::lock_guard<std::mutex> fuse_lock(mutex_);
        return InitInternal();
      }

      bool ConfigManager::InitInternal()
      {
        if (inited_)
        {
          return true;
        }
        for (auto iter = model_config_map_.begin(); iter != model_config_map_.end();
             ++iter)
        {
          delete iter->second;
        }
        model_config_map_.clear();

        std::string config_module_path =
            GetAbsolutePath(work_root_, FLAGS_config_manager_path);
        AINFO_EVERY(60000) << "WORK_ROOT: " << work_root_
              << " config_root_path: " << config_module_path;

        std::vector<std::string> model_config_files;
        if (!common::GetFileList(config_module_path, "config_manager.json",
                                 &model_config_files))
        {
          AERROR_EVERY(60000) << "config_root_path : " << config_module_path
                 << " get file list error.";
          return false;
        }
        ADEBUG << "model_config_files " << model_config_files.size();

        for (const auto &model_config_file : model_config_files)
        {
          ModelConfigFileListProto file_list_proto;
          if (!GetProtoFromASCIIFile(model_config_file, &file_list_proto))
          {
            AERROR_EVERY(60000) << "Invalid ModelConfigFileListProto file: " << model_config_file;
            return false;
          }
          ADEBUG << "model_config_file " << model_config_file;

          if (file_list_proto.modelconfigpath.size() == 0)
            file_list_proto.modelconfigpath.push_back(model_config_file);

          for (const std::string &model_config_path :
               file_list_proto.modelconfigpath)
          {
            const std::string abs_path =
                GetAbsolutePath(work_root_, model_config_path);
            MultiModelConfigProto multi_model_config_proto;
            if (!GetProtoFromASCIIFile(abs_path, &multi_model_config_proto))
            {
              AERROR_EVERY(60000) << "Invalid MultiModelConfigProto file: " << abs_path;
              return false;
            }

            for (const ModelConfigProto &model_config_proto :
                 multi_model_config_proto.modelconfigs)
            {
              ModelConfig *model_config = new ModelConfig();
              if (!model_config->Reset(model_config_proto))
              {
                return false;
              }

              AINFO_EVERY(60000) << "load ModelConfig succ. name: " << model_config->name();

              auto result =
                  model_config_map_.emplace(model_config->name(), model_config);
              if (!result.second)
              {
                AWARN << "duplicate ModelConfig, name: " << model_config->name();
                return false;
              }
            }
          }
        }

        AINFO_EVERY(60000) << "finish to load ModelConfigs. NumModels: "
              << model_config_map_.size();

        inited_ = true;

        return true;
      }

      bool ConfigManager::Reset()
      {
        std::lock_guard<std::mutex> fuse_lock(mutex_);
        inited_ = false;
        return InitInternal();
      }

      bool ConfigManager::GetModelConfig(const std::string &model_name,
                                         const ModelConfig **model_config)
      {
        if (!inited_ && !Init())
        {
          return false;
        }

        auto citer = model_config_map_.find(model_name);
        if (citer == model_config_map_.end())
        {
          return false;
        }
        *model_config = citer->second;
        return true;
      }

      ConfigManager::~ConfigManager()
      {
        for (auto iter = model_config_map_.begin(); iter != model_config_map_.end();
             ++iter)
        {
          delete iter->second;
        }
      }

      bool ModelConfig::Reset(const ModelConfigProto &proto)
      {
        name_ = proto.name;
        version_ = proto.version;

        integer_param_map_.clear();
        string_param_map_.clear();
        double_param_map_.clear();
        float_param_map_.clear();
        bool_param_map_.clear();
        array_integer_param_map_.clear();
        array_string_param_map_.clear();
        array_double_param_map_.clear();
        array_float_param_map_.clear();
        array_bool_param_map_.clear();

        for (const KeyValueInt &pair : proto.integerparams)
        {
          AINFO_EVERY(60000) << "Loading [ Int  ]" << pair.name << "=" << pair.value;
          integer_param_map_.emplace(pair.name, pair.value);
        }

        for (const KeyValueString &pair : proto.stringparams)
        {
          std::string s(pair.value.data.begin(), pair.value.data.end());
          AINFO_EVERY(60000) << "Loading [String]" << pair.name << "=" << pair.value;
          string_param_map_.emplace(pair.name, s);
        }

        for (const KeyValueDouble &pair : proto.doubleparams)
        {
          AINFO_EVERY(60000) << "Loading [Double]" << pair.name << "=" << pair.value;
          double_param_map_.emplace(pair.name, pair.value);
        }

        for (const KeyValueFloat &pair : proto.floatparams)
        {
          AINFO_EVERY(60000) << "Loading [Float ]" << pair.name << "=" << pair.value;
          float_param_map_.emplace(pair.name, pair.value);
        }

        for (const KeyValueBool &pair : proto.boolparams)
        {
          AINFO_EVERY(60000) << "Loading [ Bool ]" << pair.name << "=" << pair.value;
          bool_param_map_.emplace(pair.name, pair.value);
        }

        for (const KeyValueArrayInt &pair : proto.arrayintegerparams)
        {
          std::vector<int> values;
          RepeatedToVector(pair.values, &values);
          array_integer_param_map_.emplace(pair.name, values);
        }

        for (const KeyValueArrayString &pair : proto.arraystringparams)
        {
          std::vector<std::string> values;
          values.reserve(pair.values.size());
          for (const apollo_msgs::msg::Bytes &value : pair.values)
          {
            std::string str(value.data.begin(), value.data.end());
            values.push_back(str);
          }
          array_string_param_map_.emplace(pair.name, values);
        }

        for (const KeyValueArrayDouble &pair : proto.arraydoubleparams)
        {
          std::vector<double> values;
          RepeatedToVector(pair.values, &values);
          array_double_param_map_.emplace(pair.name, values);
        }

        for (const KeyValueArrayFloat &pair : proto.arrayfloatparams)
        {
          std::vector<float> values;
          RepeatedToVector(pair.values, &values);
          array_float_param_map_.emplace(pair.name, values);
        }

        for (const KeyValueArrayBool &pair : proto.arrayboolparams)
        {
          std::vector<bool> values;
          RepeatedToVector(pair.values, &values);
          array_bool_param_map_.emplace(pair.name, values);
        }

        /*AINFO_EVERY(60000) << "reset ModelConfig. model_name: " << name_
              << " integer_param_map's size: " << integer_param_map_.size()
              << " string_param_map's size: " << string_param_map_.size()
              << " double_param_map's size: " << double_param_map_.size()
              << " float_param_map's size: " << float_param_map_.size()
              << " bool_param_map's size: " << bool_param_map_.size()
              << " array_integer_param_map's size: "
              << array_integer_param_map_.size()
              << " array_string_param_map's size: " << array_string_param_map_.size()
              << " array_double_param_map's size: " << array_double_param_map_.size()
              << " array_float_param_map's size: " << array_float_param_map_.size()
              << " array_bool_param_map's size: " << array_bool_param_map_.size();*/

        return true;
      }

    } // namespace lib
  }   // namespace perception
} // namespace apollo
