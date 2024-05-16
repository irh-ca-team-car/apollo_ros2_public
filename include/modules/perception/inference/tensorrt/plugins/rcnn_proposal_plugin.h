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

#pragma once

#include <vector>

#include "modules/perception/inference/tensorrt/rt_common.h"
namespace apollo
{
  namespace perception
  {
    namespace inference
    {

      // TODO(chenjiahao): complete member functions
      class RCNNProposalPlugin : public nvinfer1::IPlugin
      {
      public:
      #ifndef NVVC

        RCNNProposalPlugin(
            const BBoxRegParameter &bbox_reg_param,
            const apollo_msgs::msg::ApolloperceptioninferenceDetectionOutputSSDParameter &detection_output_ssd_param,
            nvinfer1::Dims *in_dims)
        {
          num_rois_ = in_dims[2].d[0];

          for (int i = 0; i < 4; ++i)
          {
            bbox_mean_[i] = bbox_reg_param.bboxmean.at(i);
            bbox_std_[i] = bbox_reg_param.bboxstd.at(i);
          }

          min_size_mode_ =
              static_cast<int>(detection_output_ssd_param.minsizemode);
          min_size_h_ = detection_output_ssd_param.minsizeh;
          min_size_w_ = detection_output_ssd_param.minsizew;

          num_class_ = detection_output_ssd_param.numclass;
          refine_out_of_map_bbox_ =
              detection_output_ssd_param.refineoutofmapbbox;
          regress_agnostic_ = detection_output_ssd_param.regressagnostic;
          rpn_proposal_output_score_ =
              detection_output_ssd_param.rpnproposaloutputscore;

          threshold_objectness_ = detection_output_ssd_param.thresholdobjectness;
          for (int i = 0; i < num_class_; ++i)
          {
            thresholds_.push_back(detection_output_ssd_param.threshold.at(i));
          }

          NMSSSDParameter nms_param = detection_output_ssd_param.nmsparam;
          max_candidate_n_ = nms_param.maxcandidaten.at(0);
          overlap_ratio_ = nms_param.overlapratio.at(0);
          top_n_ = nms_param.topn.at(0);

          out_channel_ = rpn_proposal_output_score_ ? 9 : 5;
        }
        #endif

        virtual ~RCNNProposalPlugin() {}

        virtual int initialize() { return 0; }
        virtual void terminate() {}
        int getNbOutputs() const override { return 1; }

        nvinfer1::Dims getOutputDimensions(int index, const nvinfer1::Dims *inputs,
                                           int nbInputDims) override
        {
          UNUSED(index);
          UNUSED(inputs);
          UNUSED(nbInputDims);

          // TODO(chenjiahao): complete input dims assertion
          // TODO(chenjiahao): batch size is hard coded to 1 here
          return nvinfer1::Dims4(top_n_ * 1, out_channel_, 1, 1);
        }

        void configure(const nvinfer1::Dims *inputDims, int nbInputs,
                       const nvinfer1::Dims *outputDims, int nbOutputs,
                       int maxBatchSize) override
        {
          UNUSED(inputDims);
          UNUSED(nbInputs);
          UNUSED(outputDims);
          UNUSED(nbOutputs);
          UNUSED(maxBatchSize);
        }

        size_t getWorkspaceSize(int maxBatchSize) const override
        {
          UNUSED(maxBatchSize);
          return 0;
        }

        virtual int enqueue(int batchSize, const void *const *inputs, void **outputs,
                            void *workspace, cudaStream_t stream);

        size_t getSerializationSize() override { return 0; }

        void serialize(void *buffer) override
        {
          char *d = reinterpret_cast<char *>(buffer), *a = d;
          size_t size = getSerializationSize();
          CHECK_EQ(d, a + size);
        }

      private:
        const int thread_size_ = 512;
        bool refine_out_of_map_bbox_ = true;
        // TODO(chenjiahao): implement class-agnostic regression option
        bool regress_agnostic_ = false;
        bool rpn_proposal_output_score_ = true;

        float bbox_mean_[4];
        float bbox_std_[4];
        float min_size_h_;
        float min_size_w_;
        float threshold_objectness_;
        float overlap_ratio_;
        int num_class_;
        int num_rois_;
        int max_candidate_n_;
        int min_size_mode_;
        int top_n_;
        int out_channel_;
        int acc_box_num_;

        std::vector<float> thresholds_{};
      };

    } // namespace inference
  }   // namespace perception
} // namespace apollo
