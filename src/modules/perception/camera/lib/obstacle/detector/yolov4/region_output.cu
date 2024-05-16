/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <utility>
#include <vector>
#include "boost/iterator/counting_iterator.hpp"
#include "thrust/functional.h"
#include "thrust/sort.h"

#include "modules/perception/base/object_types.h"
#include "modules/perception/camera/lib/obstacle/detector/yolov4/object_maintainer.h"
#include "modules/perception/camera/lib/obstacle/detector/yolov4/region_output.h"

namespace apollo {
namespace perception {
namespace camera {

__host__ __device__ float sigmoid_gpu(float x) { return 1.0 / (1.0 + exp(-x)); }

__host__ __device__ float bbox_size_gpu(const float *bbox,
                                        const bool normalized) {
  if (bbox[2] <= bbox[0] || bbox[3] <= bbox[1]) {
    // If bbox is invalid (e.g. xmax < xmin or ymax < ymin), return 0.
    return 0.f;  // NOLINT
  } else {
    const float width = bbox[2] - bbox[0];
    const float height = bbox[3] - bbox[1];
    if (normalized) {
      return width * height;
    } else {
      // If bbox is not within range [0, 1].
      return (width + 1) * (height + 1);
    }
  }
}

__host__ __device__ float jaccard_overlap_gpu(const float *bbox1,
                                              const float *bbox2) {
  if (bbox2[0] > bbox1[2] || bbox2[2] < bbox1[0] || bbox2[1] > bbox1[3] ||
      bbox2[3] < bbox1[1]) {
    return float(0.);  // NOLINT
  } else {
    const float inter_xmin = max(bbox1[0], bbox2[0]);
    const float inter_ymin = max(bbox1[1], bbox2[1]);
    const float inter_xmax = min(bbox1[2], bbox2[2]);
    const float inter_ymax = min(bbox1[3], bbox2[3]);

    const float inter_width = inter_xmax - inter_xmin;
    const float inter_height = inter_ymax - inter_ymin;
    const float inter_size = inter_width * inter_height;

    const float bbox1_size = bbox_size_gpu(bbox1, true);
    const float bbox2_size = bbox_size_gpu(bbox2, true);

    return inter_size / (bbox1_size + bbox2_size - inter_size);
  }
}

__global__ void get_object_kernel(
    int n, const float *loc_data, const float *obj_data, const float *cls_data,
    const float *ori_data, const float *dim_data, const float *lof_data,
    const float *lor_data, const float *area_id_data,
    const float *visible_ratio_data, const float *cut_off_ratio_data,
    const float *brvis_data, const float *brswt_data, const float *ltvis_data,
    const float *ltswt_data, const float *rtvis_data, const float *rtswt_data,
    const float *anchor_data, const float *expand_data, int width, int height,
    int num_anchors, int num_classes, float confidence_threshold,
    float light_vis_conf_threshold, float light_swt_conf_threshold,
    bool with_box3d, bool with_frbox, bool with_lights, bool with_ratios,
    bool multi_scale, int num_areas, float *res_box_data, float *res_cls_data,
    int res_cls_offset, int all_scales_num_candidates) {
  for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < (n);
       i += blockDim.x * gridDim.x) {
    int box_block = kBoxBlockSize;

    int idx = i;
    int c = idx % num_anchors;
    idx = idx / num_anchors;
    int w = idx % width;
    idx = idx / width;
    int h = idx;
    int loc_index = (h * width + w) * num_anchors + c;
    int offset_loc = loc_index * 4;
    int offset_cls = loc_index * num_classes;
    float scale = obj_data[loc_index];
    float cx = (w + sigmoid_gpu(loc_data[offset_loc + 0])) / width;
    float cy = (h + sigmoid_gpu(loc_data[offset_loc + 1])) / height;
    float hw =
        exp(max(minExpPower, min(loc_data[offset_loc + 2], maxExpPower))) *
        anchor_data[2 * c] / width * 0.5;
    float hh =
        exp(max(minExpPower, min(loc_data[offset_loc + 3], maxExpPower))) *
        anchor_data[2 * c + 1] / height * 0.5;

    float max_prob = 0.f;
    int max_index = 0;
    for (int k = 0; k < num_classes; ++k) {
      float prob = cls_data[offset_cls + k] * scale;
      res_cls_data[k * all_scales_num_candidates + res_cls_offset + i] = prob;
      if (prob > max_prob) {
        max_prob = prob;
        max_index = k;
      }
    }
    res_cls_data[num_classes * all_scales_num_candidates + res_cls_offset + i] =
        max_prob;

    auto &&dst_ptr = res_box_data + i * box_block;
    hw += expand_data[max_index];
    dst_ptr[0] = cx - hw;
    dst_ptr[1] = cy - hh;
    dst_ptr[2] = cx + hw;
    dst_ptr[3] = cy + hh;

    if (with_box3d) {
      int offset_ori = loc_index * 2;
      dst_ptr[4] = atan2(ori_data[offset_ori + 1], ori_data[offset_ori]);

      int offset_dim = loc_index * 3;
      if (multi_scale) {
        offset_dim = loc_index * num_classes * 3 + max_index * 3;
      }
      dst_ptr[5] = dim_data[offset_dim + 0];
      dst_ptr[6] = dim_data[offset_dim + 1];
      dst_ptr[7] = dim_data[offset_dim + 2];
    }

    if (with_frbox) {
      {
        int offset_lof = loc_index * 4;
        auto &&src_ptr = lof_data + offset_lof;
        auto sb_x = src_ptr[0] * hw * 2 + cx;
        auto sb_y = src_ptr[1] * hh * 2 + cy;
        auto sb_hw = exp(src_ptr[2]) * hw;
        auto sb_hh = exp(src_ptr[3]) * hh;
        dst_ptr[8] = sb_x - sb_hw;
        dst_ptr[9] = sb_y - sb_hh;
        dst_ptr[10] = sb_x + sb_hw;
        dst_ptr[11] = sb_y + sb_hh;
      }

      {
        int offset_lor = loc_index * 4;
        auto &&src_ptr = lor_data + offset_lor;
        auto sb_x = src_ptr[0] * hw * 2 + cx;
        auto sb_y = src_ptr[1] * hh * 2 + cy;
        auto sb_hw = exp(src_ptr[2]) * hw;
        auto sb_hh = exp(src_ptr[3]) * hh;
        dst_ptr[12] = sb_x - sb_hw;
        dst_ptr[13] = sb_y - sb_hh;
        dst_ptr[14] = sb_x + sb_hw;
        dst_ptr[15] = sb_y + sb_hh;
      }
    }

    if (with_lights) {
      dst_ptr[16] = sigmoid_gpu(brvis_data[loc_index]);
      dst_ptr[17] = sigmoid_gpu(brswt_data[loc_index]);
      dst_ptr[18] = sigmoid_gpu(ltvis_data[loc_index]);
      dst_ptr[19] = sigmoid_gpu(ltswt_data[loc_index]);
      dst_ptr[20] = sigmoid_gpu(rtvis_data[loc_index]);
      dst_ptr[21] = sigmoid_gpu(rtswt_data[loc_index]);

      dst_ptr[16] = dst_ptr[16] > light_vis_conf_threshold ? dst_ptr[16] : 0;
      dst_ptr[18] = dst_ptr[18] > light_vis_conf_threshold ? dst_ptr[18] : 0;
      dst_ptr[20] = dst_ptr[20] > light_vis_conf_threshold ? dst_ptr[20] : 0;

      float swt_score = 0;
      swt_score = dst_ptr[16] * dst_ptr[17];
      dst_ptr[17] = swt_score > light_swt_conf_threshold ? swt_score : 0;

      swt_score = dst_ptr[18] * dst_ptr[19];
      dst_ptr[19] = swt_score > light_swt_conf_threshold ? swt_score : 0;

      swt_score = dst_ptr[20] * dst_ptr[21];
      dst_ptr[21] = swt_score > light_swt_conf_threshold ? swt_score : 0;
    }

    if (with_ratios) {
      // 0~3: cos2, left, visa, visb
      auto vis_pred = visible_ratio_data + loc_index * 4;
      auto vis_ptr = dst_ptr + 22;
      vis_ptr[0] = vis_ptr[1] = vis_ptr[2] = vis_ptr[3] = 0;
      const float hi_th = 0.75;
      const float lo_th = 1.f - hi_th;
      if (vis_pred[2] >= hi_th && vis_pred[3] >= hi_th) {  // 2 (1, 3)
        vis_ptr[0] = vis_pred[0];
        vis_ptr[1] = 1 - vis_pred[0];
      } else if (vis_pred[2] <= lo_th && vis_pred[3] >= hi_th) {  // 4 (3, 5)
        vis_ptr[2] = vis_pred[0];
        vis_ptr[1] = 1 - vis_pred[0];
      } else if (vis_pred[2] <= lo_th && vis_pred[3] <= lo_th) {  // 6 (5, 7)
        vis_ptr[2] = vis_pred[0];
        vis_ptr[3] = 1 - vis_pred[0];
      } else if (vis_pred[2] >= hi_th && vis_pred[3] <= lo_th) {  // 8 (7, 1)
        vis_ptr[0] = vis_pred[0];
        vis_ptr[3] = 1 - vis_pred[0];
      } else {
        vis_ptr[2] = vis_pred[0];
        if (vis_pred[1] > 0.5) {
          vis_ptr[1] = 1 - vis_pred[0];
        } else {
          vis_ptr[3] = 1 - vis_pred[0];
        }
      }

      int offset_cut = loc_index * 4;
      dst_ptr[26] = cut_off_ratio_data[offset_cut + 0];
      dst_ptr[27] = cut_off_ratio_data[offset_cut + 1];
      dst_ptr[28] = cut_off_ratio_data[offset_cut + 2];
      dst_ptr[29] = cut_off_ratio_data[offset_cut + 3];
    }

    if (num_areas > 0) {
      int offset_area_id = loc_index * num_areas;
      int max_area_id = 0;
      for (int area_id = 1; area_id < num_areas; ++area_id) {
        if (area_id_data[offset_area_id + area_id] >
            area_id_data[offset_area_id + max_area_id]) {
          max_area_id = area_id;
        }
      }
      dst_ptr[30] = max_area_id + 1;
      dst_ptr[31] = area_id_data[offset_area_id + max_area_id];
    }
  }
}

__global__ void get_rois_kernel(int num_bboxes, const float *loc_data,
                                const float *obj_data, const float *anchor_data,
                                int width, int height, int num_anchors,
                                float confidence_threshold, float *conf_data,
                                float *bbox_data) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  if (idx < num_bboxes) {
    int offset_obj = idx;
    int offset_loc = idx * 4;

    int c = idx % num_anchors;
    idx /= num_anchors;
    int w = idx % width;
    idx /= width;
    int h = idx;

    float cx = (w + sigmoid_gpu(loc_data[offset_loc + 0])) / width;
    float cy = (h + sigmoid_gpu(loc_data[offset_loc + 1])) / height;
    float hw =
        exp(loc_data[offset_loc + 2]) * anchor_data[2 * c + 0] / width * 0.5;
    float hh =
        exp(loc_data[offset_loc + 3]) * anchor_data[2 * c + 1] / height * 0.5;

    const float &conf = obj_data[offset_obj];
    conf_data[offset_obj] = conf > confidence_threshold ? conf : 0;

    auto &&curr_bbox = bbox_data + offset_loc;
    curr_bbox[0] = cx - hw;
    curr_bbox[1] = cy - hh;
    curr_bbox[2] = cx + hw;
    curr_bbox[3] = cy + hh;
  }
}

__global__ void compute_overlapped_by_idx_kernel(
    const int nthreads, const float *bbox_data, const int bbox_step,
    const float overlap_threshold, const int *idx, const int num_idx,
    bool *overlapped_data) {
  for (int index = blockIdx.x * blockDim.x + threadIdx.x; index < (nthreads);
       index += blockDim.x * gridDim.x) {
    const int j = index % num_idx;
    const int i = index / num_idx;
    if (i == j) {
      // Ignore same bbox.
      return;
    }
    // Compute overlap between i-th bbox and j-th bbox.
    const int start_loc_i = idx[i] * bbox_step;
    const int start_loc_j = idx[j] * bbox_step;
    const float overlap =
        jaccard_overlap_gpu(bbox_data + start_loc_i, bbox_data + start_loc_j);
    overlapped_data[index] = overlap > overlap_threshold;
  }
}

void compute_overlapped_by_idx_gpu(const int nthreads, const float *bbox_data,
                                   const int bbox_step,
                                   const float overlap_threshold,
                                   const int *idx, const int num_idx,
                                   bool *overlapped_data,
                                   const cudaStream_t &stream) {
  // NOLINT_NEXT_LINE(whitespace/operators)
  const int thread_size = 512;
  int block_size = (nthreads + thread_size - 1) / thread_size;
  compute_overlapped_by_idx_kernel<<<block_size, thread_size, 0, stream>>>(
      nthreads, bbox_data, bbox_step, overlap_threshold, idx, num_idx,
      overlapped_data);
}

void apply_nms_gpu(const float *bbox_data, const float *conf_data,
                   const std::vector<int> &origin_indices, const int bbox_step,
                   const float confidence_threshold, const int top_k,
                   const float nms_threshold, std::vector<int> *indices,
                   base::Blob<bool> *overlapped, base::Blob<int> *idx_sm,
                   const cudaStream_t &stream) {
  // Keep part of detections whose scores are higher than confidence threshold.
  std::vector<int> idx;
  std::vector<float> confidences;
  for (auto i : origin_indices) {
    if (conf_data[i] > confidence_threshold) {
      idx.push_back(i);
      confidences.push_back(conf_data[i]);
    }
  }
  int num_remain = confidences.size();
  if (num_remain == 0) {
    return;
  }
  // Sort detections based on score.
  thrust::sort_by_key(&confidences[0], &confidences[0] + num_remain, &idx[0],
                      thrust::greater<float>());
  if (top_k > -1 && top_k < num_remain) {
    num_remain = top_k;
  }
  int *idx_data = (idx_sm->mutable_cpu_data());
  std::copy(idx.begin(), idx.begin() + num_remain, idx_data);

  overlapped->Reshape(std::vector<int>{num_remain, num_remain});
  bool *overlapped_data = (overlapped->mutable_gpu_data());

  compute_overlapped_by_idx_gpu(overlapped->count(), bbox_data, bbox_step,
                                nms_threshold, idx_sm->gpu_data(), num_remain,
                                overlapped_data, stream);

  // Do non-maximum suppression based on overlapped results.
  const bool *overlapped_results = (const bool *)overlapped->cpu_data();
  std::vector<int> selected_indices;

  apply_nms(overlapped_results, num_remain, &selected_indices);
  // Put back the selected information.
  for (size_t i = 0; i < selected_indices.size(); ++i) {
    indices->push_back(idx[selected_indices[i]]);
  }
}

void apply_nms(const bool *overlapped, const int num,
               std::vector<int> *indices) {
  std::vector<int> index_vec(boost::counting_iterator<int>(0),
                             boost::counting_iterator<int>(num));
  // Do nms.
  indices->clear();
  while (index_vec.size() != 0) {
    // Get the current highest score box.
    int best_idx = index_vec.front();
    indices->push_back(best_idx);
    // Erase the best box.
    index_vec.erase(index_vec.begin());

    for (std::vector<int>::iterator it = index_vec.begin();
         it != index_vec.end();) {
      int cur_idx = *it;

      // Remove it if necessary
      if (overlapped[best_idx * num + cur_idx]) {
        it = index_vec.erase(it);
      } else {
        ++it;
      }
    }
  }
}

const float *get_gpu_data(bool flag, const base::Blob<float> &blob) {
  return flag ? blob.gpu_data() : nullptr;
}

void get_intersect_bbox(const NormalizedBBox &bbox1,
                        const NormalizedBBox &bbox2,
                        NormalizedBBox *intersect_bbox) {
  if (bbox2.xmin > bbox1.xmax || bbox2.xmax < bbox1.xmin ||
      bbox2.ymin > bbox1.ymax || bbox2.ymax < bbox1.ymin) {
    // Return [0, 0, 0, 0] if there is no intersection.
    intersect_bbox->xmin = 0;
    intersect_bbox->ymin = 0;
    intersect_bbox->xmax = 0;
    intersect_bbox->ymax = 0;
  } else {
    intersect_bbox->xmin = std::max(bbox1.xmin, bbox2.xmin);
    intersect_bbox->ymin = std::max(bbox1.ymin, bbox2.ymin);
    intersect_bbox->xmax = std::min(bbox1.xmax, bbox2.xmax);
    intersect_bbox->ymax = std::min(bbox1.ymax, bbox2.ymax);
  }
}

float get_bbox_size(const NormalizedBBox &bbox) {
  if (bbox.xmax < bbox.xmin || bbox.ymax < bbox.ymin) {
    // If bbox is invalid (e.g. xmax < xmin or ymax < ymin), return 0.
    return 0;
  } else {
    if (bbox.size >= 0) {
      return bbox.size;
    } else {
      float width = bbox.xmax - bbox.xmin;
      float height = bbox.ymax - bbox.ymin;
      return width * height;
    }
  }
}

float get_jaccard_overlap(const NormalizedBBox &bbox1,
                          const NormalizedBBox &bbox2) {
  NormalizedBBox intersect_bbox;
  get_intersect_bbox(bbox1, bbox2, &intersect_bbox);
  float intersect_width = 0.f;
  float intersect_height = 0.f;
  intersect_width = intersect_bbox.xmax - intersect_bbox.xmin;
  intersect_height = intersect_bbox.ymax - intersect_bbox.ymin;

  if (intersect_width > 0 && intersect_height > 0) {
    float intersect_size = intersect_width * intersect_height;
    float bbox1_size = get_bbox_size(bbox1);
    float bbox2_size = get_bbox_size(bbox2);
    return intersect_size / (bbox1_size + bbox2_size - intersect_size);
  } else {
    return 0.;
  }
}

void get_max_score_index(const std::vector<float> &scores,
                         const float threshold, const int top_k,
                         std::vector<std::pair<float, int>> *score_index_vec) {
  // Generate index score pairs.
  for (size_t i = 0; i < scores.size(); ++i) {
    if (scores[i] > threshold) {
      score_index_vec->push_back(std::make_pair(scores[i], i));
    }
  }

  // Sort the score pair according to the scores in descending order
  std::stable_sort(score_index_vec->begin(), score_index_vec->end(),
                   sort_score_pair_descend<int>);

  // Keep top_k scores if needed.
  if (top_k > -1 && top_k < static_cast<int>(score_index_vec->size())) {
    score_index_vec->resize(top_k);
  }
}

void apply_softnms_fast(const std::vector<NormalizedBBox> &bboxes,
                        std::vector<float> *scores, const float score_threshold,
                        const float nms_threshold, const int top_k,
                        std::vector<int> *indices, bool is_linear,
                        const float sigma) {
  // Sanity check.
  CHECK_EQ(bboxes.size(), scores->size())
      << "bboxes and scores have different size.";

  // Get top_k scores (with corresponding indices).
  std::vector<std::pair<float, int>> score_index_vec;
  get_max_score_index(*scores, score_threshold, top_k, &score_index_vec);

  // Do nms.
  indices->clear();
  while (score_index_vec.size() != 0) {
    auto best_it =
        max_element(std::begin(score_index_vec), std::end(score_index_vec));
    const int best_idx = (*best_it).second;
    score_index_vec.erase(best_it);
    const NormalizedBBox &best_bbox = bboxes[best_idx];
    indices->push_back(best_idx);
    for (std::vector<std::pair<float, int>>::iterator it =
             score_index_vec.begin();
         it != score_index_vec.end();) {
      int cur_idx = it->second;
      const NormalizedBBox &cur_bbox = bboxes[cur_idx];

      float cur_overlap = 0.;
      cur_overlap = get_jaccard_overlap(best_bbox, cur_bbox);
      if (is_linear) {
        (*scores)[cur_idx] *= (1.0 - cur_overlap);
      } else {
        (*scores)[cur_idx] *= exp(-1.0 * pow(cur_overlap, 2) / sigma);
      }
      ++it;
    }
  }
}

void apply_boxvoting_fast(std::vector<NormalizedBBox> *bboxes,
                          std::vector<float> *scores,
                          const float conf_threshold, const float nms_threshold,
                          const float sigma, std::vector<int> *indices) {
  if (bboxes->size() == 0) {
    return;
  }
  indices->clear();
  for (size_t i = 0; i < bboxes->size(); ++i) {
    (*bboxes)[i].mask = false;
    if ((*scores)[i] > conf_threshold) {
      indices->push_back(i);
    }
  }
  for (size_t count = 0; count < indices->size(); ++count) {
    int max_box_idx = 0;

    for (size_t i = 1; i < indices->size(); ++i) {
      int idx = indices->at(i);
      if ((*bboxes)[idx].mask) {
        continue;
      }
      if ((*scores)[idx] > (*scores)[max_box_idx]) {
        max_box_idx = idx;
      }
    }

    NormalizedBBox &best_bbox = (*bboxes)[max_box_idx];
    best_bbox.score = (*scores)[max_box_idx];
    best_bbox.mask = true;
    float s_vt = (*scores)[max_box_idx];
    float x1_vt = best_bbox.xmin * s_vt;
    float x2_vt = best_bbox.xmax * s_vt;
    float y1_vt = best_bbox.ymin * s_vt;
    float y2_vt = best_bbox.ymax * s_vt;
    for (size_t i = 0; i < indices->size(); ++i) {
      int sub_it = indices->at(i);
      if ((*bboxes)[sub_it].mask) {
        continue;
      }
      float cur_overlap = 0.;
      cur_overlap = get_jaccard_overlap(best_bbox, (*bboxes)[sub_it]);
      if (sigma == 0) {
        (*bboxes)[sub_it].mask = true;
      } else {
        (*scores)[sub_it] *= exp(-1.0 * pow(cur_overlap, 2) / sigma);
      }
      (*bboxes)[sub_it].score = (*scores)[sub_it];

      // Remove it if necessary
      if (cur_overlap > nms_threshold) {
        float s_vt_cur = (*bboxes)[sub_it].score;
        s_vt += s_vt_cur;
        x1_vt += (*bboxes)[sub_it].xmin * s_vt_cur;
        x2_vt += (*bboxes)[sub_it].xmax * s_vt_cur;
        y1_vt += (*bboxes)[sub_it].ymin * s_vt_cur;
        y2_vt += (*bboxes)[sub_it].ymax * s_vt_cur;
      }
    }
    if (s_vt > 0.0001) {
      (*bboxes)[max_box_idx].xmin = x1_vt / s_vt;
      (*bboxes)[max_box_idx].xmax = x2_vt / s_vt;
      (*bboxes)[max_box_idx].ymin = y1_vt / s_vt;
      (*bboxes)[max_box_idx].ymax = y2_vt / s_vt;
    }
  }
}

void apply_nms_fast(const std::vector<NormalizedBBox> &bboxes,
                    const std::vector<float> &scores,
                    const float score_threshold, const float nms_threshold,
                    const float eta, const int top_k,
                    std::vector<int> *indices) {
  // Sanity check.
  CHECK_EQ(bboxes.size(), scores.size())
      << "bboxes and scores have different size.";

  // Get top_k scores (with corresponding indices).
  std::vector<std::pair<float, int>> score_index_vec;
  get_max_score_index(scores, score_threshold, top_k, &score_index_vec);

  // Do nms.
  float adaptive_threshold = nms_threshold;
  indices->clear();
  while (score_index_vec.size() != 0) {
    const int idx = score_index_vec.front().second;
    bool keep = true;
    for (size_t k = 0; k < indices->size(); ++k) {
      if (keep) {
        const int kept_idx = (*indices)[k];
        float overlap = get_jaccard_overlap(bboxes[idx], bboxes[kept_idx]);
        keep = overlap <= adaptive_threshold;
      } else {
        break;
      }
    }
    if (keep) {
      indices->push_back(idx);
    }
    score_index_vec.erase(score_index_vec.begin());
    if (keep && eta < 1 && adaptive_threshold > 0.5) {
      adaptive_threshold *= eta;
    }
  }
}

void filter_bbox(const MinDims &min_dims,
                 std::vector<base::ObjectPtr> *objects) {
  size_t valid_obj_idx = 0;
  size_t total_obj_idx = 0;
  while (total_obj_idx < objects->size()) {
    const auto &obj = (*objects)[total_obj_idx];
    if ((obj->camera_supplement.box.ymax - obj->camera_supplement.box.ymin) >=
            min_dims.min_2d_height &&
        (min_dims.min_3d_height <= 0 ||
         obj->size[2] >= min_dims.min_3d_height) &&
        (min_dims.min_3d_width <= 0 || obj->size[1] >= min_dims.min_3d_width) &&
        (min_dims.min_3d_length <= 0 ||
         obj->size[0] >= min_dims.min_3d_length)) {
      (*objects)[valid_obj_idx] = (*objects)[total_obj_idx];
      ++valid_obj_idx;
    }
    ++total_obj_idx;
  }
  objects->resize(valid_obj_idx);
}
void recover_bbox(int roi_w, int roi_h, int offset_y,
                  std::vector<base::ObjectPtr> *objects) {
  for (auto &obj : *objects) {
    float xmin = obj->camera_supplement.box.xmin;
    float ymin = obj->camera_supplement.box.ymin;
    float xmax = obj->camera_supplement.box.xmax;
    float ymax = obj->camera_supplement.box.ymax;
    int x = xmin * roi_w;
    int w = (xmax - xmin) * roi_w;
    int y = ymin * roi_h + offset_y;
    int h = (ymax - ymin) * roi_h;
    base::RectF rect_det(x, y, w, h);
    base::RectF rect_img(0, 0, roi_w, roi_h + offset_y);
    base::RectF rect = rect_det & rect_img;
    obj->camera_supplement.box = rect;

    double eps = 1e-2;

    // Truncation assignment based on bbox positions
    if ((ymin < eps) || (ymax >= 1.0 - eps)) {
      obj->camera_supplement.truncated_vertical = 0.5;
    } else {
      obj->camera_supplement.truncated_vertical = 0.0;
    }
    if ((xmin < eps) || (xmax >= 1.0 - eps)) {
      obj->camera_supplement.truncated_horizontal = 0.5;
    } else {
      obj->camera_supplement.truncated_horizontal = 0.0;
    }

    obj->camera_supplement.front_box.xmin *= roi_w;
    obj->camera_supplement.front_box.ymin *= roi_h;
    obj->camera_supplement.front_box.xmax *= roi_w;
    obj->camera_supplement.front_box.ymax *= roi_h;

    obj->camera_supplement.back_box.xmin *= roi_w;
    obj->camera_supplement.back_box.ymin *= roi_h;
    obj->camera_supplement.back_box.xmax *= roi_w;
    obj->camera_supplement.back_box.ymax *= roi_h;

    obj->camera_supplement.front_box.ymin += offset_y;
    obj->camera_supplement.front_box.ymax += offset_y;
    obj->camera_supplement.back_box.ymin += offset_y;
    obj->camera_supplement.back_box.ymax += offset_y;
  }
}

void fill_base(base::ObjectPtr obj, const float *bbox) {
  obj->camera_supplement.box.xmin = bbox[0];
  obj->camera_supplement.box.ymin = bbox[1];
  obj->camera_supplement.box.xmax = bbox[2];
  obj->camera_supplement.box.ymax = bbox[3];
}

void fill_bbox3d(bool with_box3d, base::ObjectPtr obj, const float *bbox) {
  if (with_box3d) {
    obj->camera_supplement.alpha = bbox[0];
    obj->size[2] = bbox[1];
    obj->size[1] = bbox[2];
    obj->size[0] = bbox[3];
  }
}

void fill_frbox(bool with_frbox, base::ObjectPtr obj, const float *bbox) {
  if (with_frbox) {
    obj->camera_supplement.front_box.xmin = bbox[0];
    obj->camera_supplement.front_box.ymin = bbox[1];
    obj->camera_supplement.front_box.xmax = bbox[2];
    obj->camera_supplement.front_box.ymax = bbox[3];

    obj->camera_supplement.back_box.xmin = bbox[4];
    obj->camera_supplement.back_box.ymin = bbox[5];
    obj->camera_supplement.back_box.xmax = bbox[6];
    obj->camera_supplement.back_box.ymax = bbox[7];
  }
}

void fill_lights(bool with_lights, base::ObjectPtr obj, const float *bbox) {
  if (with_lights) {
    obj->car_light.brake_visible = bbox[0];
    obj->car_light.brake_switch_on = bbox[1];
    obj->car_light.left_turn_visible = bbox[2];
    obj->car_light.left_turn_switch_on = bbox[3];
    obj->car_light.right_turn_visible = bbox[4];
    obj->car_light.right_turn_switch_on = bbox[5];
  }
}

void fill_ratios(bool with_ratios, base::ObjectPtr obj, const float *bbox) {
  if (with_ratios) {
    // visible ratios of face a/b/c/d
    obj->camera_supplement.visible_ratios[0] = bbox[0];
    obj->camera_supplement.visible_ratios[1] = bbox[1];
    obj->camera_supplement.visible_ratios[2] = bbox[2];
    obj->camera_supplement.visible_ratios[3] = bbox[3];

    // cut off on width and length (3D)
    obj->camera_supplement.cut_off_ratios[0] = bbox[4];
    obj->camera_supplement.cut_off_ratios[1] = bbox[5];
    // cut off on left and right side (2D)
    obj->camera_supplement.cut_off_ratios[2] = bbox[6];
    obj->camera_supplement.cut_off_ratios[3] = bbox[7];
  }
}

void fill_area_id(bool with_flag, base::ObjectPtr obj, const float *data) {
  if (with_flag) {
    obj->camera_supplement.area_id = static_cast<int>(data[0]);
    // obj->camera_supplement.area_id_prob = data[1];
  }
}

int get_area_id(float visible_ratios[4]) {
  int area_id = 0;
  int max_face = 0;
  for (int i = 1; i < 4; ++i) {
    if (visible_ratios[i] > visible_ratios[max_face]) {
      max_face = i;
    }
  }
  int left_face = (max_face + 1) % 4;
  int right_face = (max_face + 3) % 4;
  const float eps = 1e-3;
  float max_ratio = visible_ratios[max_face];
  float left_ratio = visible_ratios[left_face];
  float right_ratio = visible_ratios[right_face];
  memset(visible_ratios, 0, 4 * sizeof(visible_ratios[0]));
  if (left_ratio < eps && right_ratio < eps) {
    area_id = (max_face * 2 + 1);
    visible_ratios[max_face] = 1.f;
  } else if (left_ratio > right_ratio) {
    area_id = (max_face * 2 + 2);
    auto &&sum_ratio = left_ratio + max_ratio;
    visible_ratios[max_face] = max_ratio / sum_ratio;
    visible_ratios[left_face] = left_ratio / sum_ratio;
  } else {
    area_id = (max_face * 2);
    if (area_id == 0) {
      area_id = 8;
    }
    auto &&sum_ratio = right_ratio + max_ratio;
    visible_ratios[max_face] = max_ratio / sum_ratio;
    visible_ratios[right_face] = right_ratio / sum_ratio;
  }
  return area_id;
}

}  // namespace camera
}  // namespace perception
}  // namespace apollo
