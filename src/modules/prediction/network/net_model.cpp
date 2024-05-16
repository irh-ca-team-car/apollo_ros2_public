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

#include "modules/prediction/network/net_model.h"

#include <utility>

#include "cyber/common/log.h"

namespace apollo
{
    namespace prediction
    {
        namespace network
        {

            bool NetModel::LoadModel(const NetParameter &net_parameter)
            {
                net_parameter_ = (net_parameter);
                layers_.clear();

                for (size_t i = 0; i < net_parameter_.layers.size(); ++i)
                {
                    auto layer_pb = net_parameter_.layers.at(i);
                    ADEBUG << i << "-th layer name: " << layer_pb.name.c_str();
                    std::unique_ptr<Layer> layer(nullptr);

                    {
                        if (layer_pb.oneoflayers.input != InputParameter())
                        {
                            layer = std::unique_ptr<Layer>(new Input());
                        }
                        else if (layer_pb.oneoflayers.activation != ActivationParameter())
                        {
                            layer = std::unique_ptr<Layer>(new Activation());
                        }
                        else if (layer_pb.oneoflayers.dense != DenseParameter())
                        {
                            layer = std::unique_ptr<Layer>(new Dense());
                        }
                        else if (layer_pb.oneoflayers.batchnormalization != BatchNormalizationParameter())
                        {
                            layer = std::unique_ptr<Layer>(new BatchNormalization());
                        }
                        else if (layer_pb.oneoflayers.lstm != LSTMParameter())
                        {
                            layer = std::unique_ptr<Layer>(new LSTM());
                        }
                        else if (layer_pb.oneoflayers.flatten != 0)
                        {
                            layer = std::unique_ptr<Layer>(new Flatten());
                        }
                        else if (layer_pb.oneoflayers.concatenate != ConcatenateParameter())
                        {
                            layer = std::unique_ptr<Layer>(new Concatenate());
                        }
                        else
                        {
                            AERROR << "Failed to load layer: " << layer_pb.type.c_str();
                        }
                    }
                    if (!layer->Load(layer_pb))
                    {
                        AERROR << "Failed to load " << i << "-layer: " << layer_pb.name.c_str();
                        return false;
                    }
                    layers_.push_back(std::move(layer));
                }
                ok_ = true;
                AINFO << "Success in loading the model!";
                ADEBUG << "Its Performance:" << PerformanceString().c_str();
                return true;
            }

            std::string NetModel::PerformanceString() const
            {
                std::stringstream ss;
                if (net_parameter_.performance== Performance())
                {
                    AWARN << "The protobuf does not contain performance values!";
                    return " ";
                }
                ss << "\n test: accuracy = ";
                for (size_t i = 0; i < net_parameter_.performance.accuracy.size(); ++i)
                {
                    ss << net_parameter_.performance.accuracy.at(i) << ",  ";
                }
                ss << "\n recall = ";
                for (size_t i = 0; i < net_parameter_.performance.recall.size(); ++i)
                {
                    ss << net_parameter_.performance.recall.at(i) << ",  ";
                }
                ss << "\n precision = ";
                for (size_t i = 0; i < net_parameter_.performance.precision.size(); ++i)
                {
                    ss << net_parameter_.performance.precision.at(i) << ",  ";
                }
                ss << std::endl;
                return ss.str();
            }

            const std::string &NetModel::Name() const { return net_parameter_.name; }

            int NetModel::Id() const { return net_parameter_.id; }

            bool NetModel::IsOk() const { return ok_; }

        } // namespace network
    }     // namespace prediction
} // namespace apollo
