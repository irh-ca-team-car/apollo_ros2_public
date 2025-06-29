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

#include "modules/prediction/evaluator/vehicle/mlp_evaluator.h"

#include <limits>

#include "cyber/common/file.h"
#include "modules/prediction/common/feature_output.h"
#include "modules/prediction/common/prediction_constants.h"
#include "modules/prediction/common/prediction_gflags.h"
#include "modules/prediction/common/prediction_system_gflags.h"
#include "modules/prediction/common/prediction_util.h"
#include "modules/prediction/common/validation_checker.h"

namespace apollo
{
    namespace prediction
    {
        namespace
        {

            using apollo::common::math::Sigmoid;

            double ComputeMean(const std::vector<double> &nums, size_t start, size_t end)
            {
                int count = 0;
                double sum = 0.0;
                for (size_t i = start; i <= end && i < nums.size(); i++)
                {
                    sum += nums[i];
                    ++count;
                }
                return (count == 0) ? 0.0 : sum / count;
            }

        } // namespace

        MLPEvaluator::MLPEvaluator()
        {
            evaluator_type_ = ObstacleConf::MLP_EVALUATOR;
            LoadModel(FLAGS_evaluator_vehicle_mlp_file);
        }

        void MLPEvaluator::Clear() {}

        bool MLPEvaluator::Evaluate(Obstacle *obstacle_ptr,
                                    ObstaclesContainer *obstacles_container)
        {
            (void)obstacles_container;
            Clear();
            CHECK_NOTNULL(obstacle_ptr);
            CHECK_LE(LANE_FEATURE_SIZE, 4 * FLAGS_max_num_lane_point);

            obstacle_ptr->SetEvaluatorType(evaluator_type_);

            int id = obstacle_ptr->id();
            if (obstacle_ptr->latest_feature() == Feature())
            {
                AERROR << "Obstacle [" << id << "] has no latest feature.";
                return false;
            }

            Feature *latest_feature_ptr = obstacle_ptr->mutable_latest_feature();
           
            CHECK_NOTNULL(latest_feature_ptr);

            if ((latest_feature_ptr->lane == Lane()) ||
                (latest_feature_ptr->lane.lanegraph == LaneGraph()))
            {
                ADEBUG << "Obstacle [" << id << "] has no lane graph.";
                return false;
            }

            double speed = latest_feature_ptr->speed;
            (void)speed;
           
            LaneGraph *lane_graph_ptr =
                &latest_feature_ptr->lane.lanegraph;
            CHECK_NOTNULL(lane_graph_ptr);
            if (lane_graph_ptr->lanesequence.empty())
            {
                AERROR << "Obstacle [" << id << "] has no lane sequences.";
                return false;
            }

            std::vector<double> obstacle_feature_values;
            SetObstacleFeatureValues(obstacle_ptr, &obstacle_feature_values);
            if (obstacle_feature_values.size() != OBSTACLE_FEATURE_SIZE)
            {
                ADEBUG << "Obstacle [" << id << "] has fewer than "
                       << "expected obstacle feature_values "
                       << obstacle_feature_values.size() << ".";
                return false;
            }

            
            
            for (size_t i = 0; i < lane_graph_ptr->lanesequence.size(); ++i)
            {
                auto &lane_sequence_ptr = lane_graph_ptr->lanesequence.at(i);
                
                std::vector<double> lane_feature_values;
                SetLaneFeatureValues(obstacle_ptr, &lane_sequence_ptr, &lane_feature_values);
                if (lane_feature_values.size() != LANE_FEATURE_SIZE)
                {
                    ADEBUG << "Obstacle [" << id << "] has fewer than "
                           << "expected lane feature_values" << lane_feature_values.size()
                           << ".";
                    continue;
                }

                std::vector<double> feature_values;
                feature_values.insert(feature_values.end(), obstacle_feature_values.begin(),
                                      obstacle_feature_values.end());
                feature_values.insert(feature_values.end(), lane_feature_values.begin(),
                                      lane_feature_values.end());

                // Insert features to DataForLearning
                if (FLAGS_prediction_offline_mode ==
                        PredictionConstants::kDumpDataForLearning &&
                    !obstacle_ptr->IsNearJunction())
                {
                    FeatureOutput::InsertDataForLearning(*latest_feature_ptr, feature_values,
                                                         "mlp", &lane_sequence_ptr);
                    ADEBUG << "Save extracted features for learning locally.";
                    return true; // Skip Compute probability for offline mode
                }
                double probability = ComputeProbability(feature_values);

                double centripetal_acc_probability =
                    ValidationChecker::ProbabilityByCentripetalAcceleration(
                        lane_sequence_ptr, speed);
                probability *= centripetal_acc_probability;
                lane_sequence_ptr.set__probability(probability);
            }
            return true;
        }

        void MLPEvaluator::ExtractFeatureValues(Obstacle *obstacle_ptr,
                                                apollo_msgs::msg::ApollopredictionLaneSequence *lane_sequence_ptr,
                                                std::vector<double> *feature_values)
        {
            int id = obstacle_ptr->id();
            std::vector<double> obstacle_feature_values;

            SetObstacleFeatureValues(obstacle_ptr, &obstacle_feature_values);

            if (obstacle_feature_values.size() != OBSTACLE_FEATURE_SIZE)
            {
                ADEBUG << "Obstacle [" << id << "] has fewer than "
                       << "expected obstacle feature_values "
                       << obstacle_feature_values.size() << ".";
                return;
            }

            std::vector<double> lane_feature_values;
            SetLaneFeatureValues(obstacle_ptr, lane_sequence_ptr, &lane_feature_values);
            if (lane_feature_values.size() != LANE_FEATURE_SIZE)
            {
                ADEBUG << "Obstacle [" << id << "] has fewer than "
                       << "expected lane feature_values" << lane_feature_values.size()
                       << ".";
                return;
            }

            feature_values->insert(feature_values->end(), obstacle_feature_values.begin(),
                                   obstacle_feature_values.end());
            feature_values->insert(feature_values->end(), lane_feature_values.begin(),
                                   lane_feature_values.end());
        }

        void MLPEvaluator::SaveOfflineFeatures(
            apollo_msgs::msg::ApollopredictionLaneSequence *sequence, const std::vector<double> &feature_values)
        {
            for (double feature_value : feature_values)
            {
                sequence->features.mlpfeatures.push_back(feature_value);
            }
        }

        void MLPEvaluator::SetObstacleFeatureValues(
            Obstacle *obstacle_ptr, std::vector<double> *feature_values)
        {
            feature_values->clear();
            feature_values->reserve(OBSTACLE_FEATURE_SIZE);

            std::vector<double> thetas;
            std::vector<double> lane_ls;
            std::vector<double> dist_lbs;
            std::vector<double> dist_rbs;
            std::vector<int> lane_types;
            std::vector<double> speeds;
            std::vector<double> timestamps;

            double duration =
                obstacle_ptr->timestamp() - FLAGS_prediction_trajectory_time_length;
            int count = 0;
            for (std::size_t i = 0; i < obstacle_ptr->history_size(); ++i)
            {
                const Feature &feature = obstacle_ptr->feature(i);
                if (feature == Feature())
                {
                    continue;
                }
                if (feature.timestamp < duration)
                {
                    break;
                }
                if ((feature.lane == Lane()) || (feature.lane.lanefeature == LaneFeature()))
                {
                    thetas.push_back(feature.lane.lanefeature.anglediff);
                    lane_ls.push_back(feature.lane.lanefeature.lanel);
                    dist_lbs.push_back(feature.lane.lanefeature.disttoleftboundary);
                    dist_rbs.push_back(
                        feature.lane.lanefeature.disttorightboundary);
                    lane_types.push_back(feature.lane.lanefeature.laneturntype);
                    timestamps.push_back(feature.timestamp);
                    speeds.push_back(feature.speed);
                    ++count;
                }
            }
            if (count <= 0)
            {
                return;
            }
            size_t curr_size = 5;
            size_t hist_size = obstacle_ptr->history_size();
            double theta_mean = ComputeMean(thetas, 0, hist_size - 1);
            double theta_filtered = ComputeMean(thetas, 0, curr_size - 1);
            double lane_l_mean = ComputeMean(lane_ls, 0, hist_size - 1);
            double lane_l_filtered = ComputeMean(lane_ls, 0, curr_size - 1);
            double speed_mean = ComputeMean(speeds, 0, hist_size - 1);

            double time_diff = timestamps.front() - timestamps.back();
            double dist_lb_rate = (timestamps.size() > 1)
                                      ? (dist_lbs.front() - dist_lbs.back()) / time_diff
                                      : 0.0;
            double dist_rb_rate = (timestamps.size() > 1)
                                      ? (dist_rbs.front() - dist_rbs.back()) / time_diff
                                      : 0.0;

            double delta_t = 0.0;
            if (timestamps.size() > 1)
            {
                delta_t = (timestamps.front() - timestamps.back()) /
                          static_cast<double>(timestamps.size() - 1);
            }
            double angle_curr = ComputeMean(thetas, 0, curr_size - 1);
            double angle_prev = ComputeMean(thetas, curr_size, 2 * curr_size - 1);
            double angle_diff =
                (hist_size >= 2 * curr_size) ? angle_curr - angle_prev : 0.0;

            double lane_l_curr = ComputeMean(lane_ls, 0, curr_size - 1);
            double lane_l_prev = ComputeMean(lane_ls, curr_size, 2 * curr_size - 1);
            double lane_l_diff =
                (hist_size >= 2 * curr_size) ? lane_l_curr - lane_l_prev : 0.0;

            double angle_diff_rate = 0.0;
            double lane_l_diff_rate = 0.0;
            if (delta_t > std::numeric_limits<double>::epsilon())
            {
                angle_diff_rate = angle_diff / (delta_t * static_cast<double>(curr_size));
                lane_l_diff_rate = lane_l_diff / (delta_t * static_cast<float>(curr_size));
            }

            double acc = 0.0;
            if (speeds.size() >= 3 * curr_size &&
                delta_t > std::numeric_limits<double>::epsilon())
            {
                double speed_1 = ComputeMean(speeds, 0, curr_size - 1);
                double speed_2 = ComputeMean(speeds, curr_size, 2 * curr_size - 1);
                double speed_3 = ComputeMean(speeds, 2 * curr_size, 3 * curr_size - 1);
                acc = (speed_1 - 2 * speed_2 + speed_3) /
                      (static_cast<float>(curr_size) * static_cast<float>(curr_size) *
                       delta_t * delta_t);
            }

            double dist_lb_rate_curr = 0.0;
            if (hist_size >= 2 * curr_size &&
                delta_t > std::numeric_limits<double>::epsilon())
            {
                double dist_lb_curr = ComputeMean(dist_lbs, 0, curr_size - 1);
                double dist_lb_prev = ComputeMean(dist_lbs, curr_size, 2 * curr_size - 1);
                dist_lb_rate_curr = (dist_lb_curr - dist_lb_prev) /
                                    (static_cast<float>(curr_size) * delta_t);
            }

            double dist_rb_rate_curr = 0.0;
            if (hist_size >= 2 * curr_size &&
                delta_t > std::numeric_limits<double>::epsilon())
            {
                double dist_rb_curr = ComputeMean(dist_rbs, 0, curr_size - 1);
                double dist_rb_prev = ComputeMean(dist_rbs, curr_size, 2 * curr_size - 1);
                dist_rb_rate_curr = (dist_rb_curr - dist_rb_prev) /
                                    (static_cast<float>(curr_size) * delta_t);
            }

            // setup obstacle feature values
            feature_values->push_back(theta_filtered);
            feature_values->push_back(theta_mean);
            feature_values->push_back(theta_filtered - theta_mean);
            feature_values->push_back(angle_diff);
            feature_values->push_back(angle_diff_rate);

            feature_values->push_back(lane_l_filtered);
            feature_values->push_back(lane_l_mean);
            feature_values->push_back(lane_l_filtered - lane_l_mean);
            feature_values->push_back(lane_l_diff);
            feature_values->push_back(lane_l_diff_rate);

            feature_values->push_back(speed_mean);
            feature_values->push_back(acc);

            feature_values->push_back(dist_lbs.front());
            feature_values->push_back(dist_lb_rate);
            feature_values->push_back(dist_lb_rate_curr);

            feature_values->push_back(dist_rbs.front());
            feature_values->push_back(dist_rb_rate);
            feature_values->push_back(dist_rb_rate_curr);

            feature_values->push_back(lane_types.front() == 0 ? 1.0 : 0.0);
            feature_values->push_back(lane_types.front() == 1 ? 1.0 : 0.0);
            feature_values->push_back(lane_types.front() == 2 ? 1.0 : 0.0);
            feature_values->push_back(lane_types.front() == 3 ? 1.0 : 0.0);
        }

        void MLPEvaluator::SetLaneFeatureValues(Obstacle *obstacle_ptr,
                                                apollo_msgs::msg::ApollopredictionLaneSequence *lane_sequence_ptr,
                                                std::vector<double> *feature_values)
        {
            feature_values->clear();
            feature_values->reserve(LANE_FEATURE_SIZE);
            const Feature &feature = obstacle_ptr->latest_feature();
            if (feature == Feature())
            {
                ADEBUG << "Obstacle [" << obstacle_ptr->id() << "] has no latest feature.";
                return;
            }
            // else if (!feature.has_position())
            // {
            //     ADEBUG << "Obstacle [" << obstacle_ptr->id() << "] has no position.";
            //     return;
            // }

            double heading = feature.velocityheading;
            for (size_t i = 0; i < lane_sequence_ptr->lanesegment.size(); ++i)
            {
                if (feature_values->size() >= LANE_FEATURE_SIZE)
                {
                    break;
                }
                const LaneSegment &lane_segment = lane_sequence_ptr->lanesegment.at(i);
                for (size_t j = 0; j < lane_segment.lanepoint.size(); ++j)
                {
                    if (feature_values->size() >= LANE_FEATURE_SIZE)
                    {
                        break;
                    }
                    const auto &lane_point = lane_segment.lanepoint.at(j);

                    double diff_x = lane_point.position.x - feature.position.x;
                    double diff_y = lane_point.position.y - feature.position.y;
                    double angle = std::atan2(diff_y, diff_x);
                    feature_values->push_back(std::sin(angle - heading));
                    feature_values->push_back(lane_point.relativel);
                    feature_values->push_back(lane_point.heading);
                    feature_values->push_back(lane_point.anglediff);
                }
            }

            std::size_t size = feature_values->size();
            while (size >= 4 && size < LANE_FEATURE_SIZE)
            {
                double heading_diff = feature_values->operator[](size - 4);
                double lane_l_diff = feature_values->operator[](size - 3);
                double heading = feature_values->operator[](size - 2);
                double angle_diff = feature_values->operator[](size - 1);
                feature_values->push_back(heading_diff);
                feature_values->push_back(lane_l_diff);
                feature_values->push_back(heading);
                feature_values->push_back(angle_diff);
                size = feature_values->size();
            }
        }

        void MLPEvaluator::LoadModel(const std::string &model_file)
        {
            model_ptr_.reset(new FnnVehicleModel());
            ACHECK(model_ptr_ != nullptr);
            ACHECK(cyber::common::GetProtoFromASCIIFile(model_file, model_ptr_.get()))
                << "Unable to load model file: [[" << model_file << "]].";
        
                    AINFO
                << "Succeeded in loading the model file: " << model_file << ".";
        }

        double MLPEvaluator::ComputeProbability(
            const std::vector<double> &feature_values)
        {
            CHECK_NOTNULL(model_ptr_.get());
            double probability = 0.0;

            if (model_ptr_->diminput != static_cast<int>(feature_values.size()))
            {
                ADEBUG << "Model feature size not consistent with model proto definition. "
                       << "model input dim = " << model_ptr_->diminput
                       << "; feature value size = " << feature_values.size();
                return probability;
            }
            std::vector<double> layer_input;
            layer_input.reserve(model_ptr_->diminput);
            std::vector<double> layer_output;

            // normalization
            for (int i = 0; i < model_ptr_->diminput; ++i)
            {
                double mean = model_ptr_->samplesmean.columns.at(i);
                double std = model_ptr_->samplesstd.columns.at(i);
                layer_input.push_back(
                    apollo::prediction::math_util::Normalize(feature_values[i], mean, std));
            }

            for (int i = 0; i < model_ptr_->numlayer; ++i)
            {
                if (i > 0)
                {
                    layer_input.swap(layer_output);
                    layer_output.clear();
                }
                const auto &layer = model_ptr_->layer.at(i);
                for (int col = 0; col < layer.layeroutputdim; ++col)
                {
                    double neuron_output = layer.layerbias.columns.at(col);
                    for (int row = 0; row < layer.layerinputdim; ++row)
                    {
                        double weight = layer.layerinputweight.rows.at(row).columns.at(col);
                        neuron_output += (layer_input[row] * weight);
                    }
                    if (layer.layeractivationfunc == Layer::RELU)
                    {
                        neuron_output = apollo::prediction::math_util::Relu(neuron_output);
                    }
                    else if (layer.layeractivationfunc == Layer::SIGMOID)
                    {
                        neuron_output = Sigmoid(neuron_output);
                    }
                    else if (layer.layeractivationfunc == Layer::TANH)
                    {
                        neuron_output = std::tanh(neuron_output);
                    }
                    else
                    {
                        AERROR << "Undefined activation function ["
                               << layer.layeractivationfunc
                               << "]. A default sigmoid will be used instead.";
                        neuron_output = Sigmoid(neuron_output);
                    }
                    layer_output.push_back(neuron_output);
                }
            }

            if (layer_output.size() != 1)
            {
                AERROR << "Model output layer has incorrect # outputs: "
                       << layer_output.size();
            }
            else
            {
                probability = layer_output[0];
            }

            return probability;
        }

    } // namespace prediction
} // namespace apollo
