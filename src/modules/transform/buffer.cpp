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

#include "modules/transform/buffer.h"

#include "absl/strings/str_cat.h"
#include "cyber/cyber.h"
#include "cyber/time/clock.h"
#include "modules/common/adapters/adapter_gflags.h"

using Time = ::apollo::cyber::Time;
using Clock = ::apollo::cyber::Clock;

namespace
{
  constexpr float kSecondToNanoFactor = 1e9f;
} // namespace

namespace apollo
{
  namespace transform
  {

    Buffer::Buffer() : BufferCore() { Init(); }

    int Buffer::Init()
    {
      const std::string node_name =
          absl::StrCat("transform_listener_", Time::Now().ToNanosecond());
      message_subscriber_tf_ = apollo::cyber::ComponentBase::instance()->CreateReader<tf2_msgs::msg::TFMessage>(
          "/tf", [&](const std::shared_ptr<const tf2_msgs::msg::TFMessage> &msg_evt)
          { SubscriptionCallbackImpl(msg_evt, false); });

      message_subscriber_tf_static_ = apollo::cyber::ComponentBase::instance()->CreateReader<tf2_msgs::msg::TFMessage>(
          "/tf_static", [&](const std::shared_ptr<tf2_msgs::msg::TFMessage> &msg_evt)
          { SubscriptionCallbackImpl(msg_evt, true); });

      return true;
    }

    void Buffer::SubscriptionCallback(
        const std::shared_ptr<const TransformStampeds> &msg_evt)
    {
      SubscriptionCallbackImpl(msg_evt, false);
    }

    void Buffer::StaticSubscriptionCallback(
        const std::shared_ptr<const TransformStampeds> &msg_evt)
    {
      SubscriptionCallbackImpl(msg_evt, true);
    }

    void Buffer::SubscriptionCallbackImpl(
        const std::shared_ptr<const TransformStampeds> &msg_evt, bool is_static)
    {
      cyber::Time now = Clock::Now();
      std::string authority =
          "cyber_tf"; // msg_evt.getPublisherName(); // lookup the authority
      if (now.ToNanosecond() < last_update_.ToNanosecond())
      {
        AINFO << "Detected jump back in time. Clearing TF buffer.";
        //clear();
        // cache static transform stamped again.
        for (auto &msg : static_msgs_)
        {
          if(msg.child_frame_id != msg.header.frame_id)
          {
            AERROR << "Registering tranform "<<msg.header.frame_id << "->"<<msg.child_frame_id;
            msg.header.stamp = apollo::cyber::ComponentBase::instance()->get_clock()->now();
            setTransform(msg, authority, true);
          }
        }
      }
      last_update_ = now;

      for (size_t i = 0; i < msg_evt->transforms.size(); i++)
      {
        try
        {
          geometry_msgs::msg::TransformStamped trans_stamped =msg_evt->transforms[i];

          if (is_static)
          {
            static_msgs_.push_back(trans_stamped);
          }
          if(trans_stamped.child_frame_id != trans_stamped.header.frame_id)
          {
            trans_stamped.header.stamp = apollo::cyber::ComponentBase::instance()->get_clock()->now();
            setTransform(trans_stamped, authority, is_static || 
            trans_stamped.header.frame_id == "novatel"|| 
            trans_stamped.header.frame_id == "velodyne128"|| 
            trans_stamped.header.frame_id == "localization" );
          }
          else
          {
            AERROR << "Ignoring tranform "<<trans_stamped.header.frame_id << "->"<<trans_stamped.child_frame_id;
          }
        }
        catch (tf2::TransformException &ex)
        {
          std::string temp = ex.what();
          AERROR << "Failure to set received transform:" << temp.c_str();
        }
      }
    }

    bool Buffer::GetLatestStaticTF(const std::string &frame_id,
                                   const std::string &child_frame_id,
                                   TransformStamped *tf)
    {
      for (auto reverse_iter = static_msgs_.rbegin();
           reverse_iter != static_msgs_.rend(); ++reverse_iter)
      {
        if ((*reverse_iter).header.frame_id == frame_id &&
            (*reverse_iter).child_frame_id == child_frame_id)
        {
          TF2MsgToCyber((*reverse_iter), (*tf));
          return true;
        }
      }
      return false;
    }

    void Buffer::TF2MsgToCyber(
        const geometry_msgs::msg::TransformStamped &tf2_trans_stamped,
        TransformStamped &trans_stamped) const
    {
      // trans_stamped=tf2_trans_stamped;
      //  header
      trans_stamped.header.stamp.sec = (tf2_trans_stamped.header.stamp.sec);
      trans_stamped.header.frame_id = (tf2_trans_stamped.header.frame_id);

      // child_frame_id
      trans_stamped.set__child_frame_id(tf2_trans_stamped.child_frame_id);

      // translation
      trans_stamped.transform.translation.x = (tf2_trans_stamped.transform.translation.x);
      trans_stamped.transform.translation.y = (tf2_trans_stamped.transform.translation.y);
      trans_stamped.transform.translation.z = (tf2_trans_stamped.transform.translation.z);

      // rotation
      trans_stamped.transform.rotation.x = (tf2_trans_stamped.transform.rotation.x);
      trans_stamped.transform.rotation.y = (tf2_trans_stamped.transform.rotation.y);
      trans_stamped.transform.rotation.z = (tf2_trans_stamped.transform.rotation.z);
      trans_stamped.transform.rotation.w = (tf2_trans_stamped.transform.rotation.w);
    }
    tf2::TimePoint toTf2(const cyber::Time &time)
    {
      UNUSED(time);
      return tf2::TimePoint(std::chrono::nanoseconds(0));
      //return tf2::TimePoint(
      //   std::chrono::nanoseconds(time.ToNanosecond()));
    }
    TransformStamped Buffer::lookupTransform(const std::string &target_frame,
                                             const std::string &source_frame,
                                             const cyber::Time &time,
                                             const float timeout_second) const
    {
      UNUSED(timeout_second);
      tf2::TimePoint tf2_time = toTf2(time);
      geometry_msgs::msg::TransformStamped tf2_trans_stamped =
          tf2::BufferCore::lookupTransform(target_frame, source_frame, tf2_time);
      return tf2_trans_stamped;
    }

    TransformStamped Buffer::lookupTransform(const std::string &target_frame,
                                             const cyber::Time &target_time,
                                             const std::string &source_frame,
                                             const cyber::Time &source_time,
                                             const std::string &fixed_frame,
                                             const float timeout_second) const
    {
      UNUSED(fixed_frame);
      UNUSED(source_time);
      UNUSED(timeout_second);
      geometry_msgs::msg::TransformStamped tf2_trans_stamped =
          tf2::BufferCore::lookupTransform(target_frame, toTf2(target_time),
                                           source_frame, toTf2(source_time),
                                           fixed_frame);
      return tf2_trans_stamped;
    }

    bool Buffer::canTransform(const std::string &target_frame,
                              const std::string &source_frame,
                              const cyber::Time &time, const float timeout_second,
                              std::string *errstr) const
    {
      UNUSED(timeout_second);

      //uint64_t timeout_ns =
      //    static_cast<uint64_t>(timeout_second * kSecondToNanoFactor);
      //uint64_t start_time = Clock::Now().ToNanosecond(); // time.ToNanosecond();
      rclcpp::Rate rate(300);
      //while (Clock::Now().ToNanosecond() < start_time + timeout_ns &&
      //       !cyber::IsShutdown())
      {
        errstr->clear();
        bool retval = tf2::BufferCore::canTransform(target_frame, source_frame,
                                                    toTf2(time), errstr);
        if (retval)
        {
          return true;
        }
        else
        {
          AWARN << "BufferCore::canTransform failed: " << *errstr;
          //rate.sleep();
          // std::this_thread::sleep_for(std::chrono::milliseconds(3));
        }
      }
      *errstr = *errstr + ":timeout";
      return false;
    }

    bool Buffer::canTransform(const std::string &target_frame,
                              const cyber::Time &target_time,
                              const std::string &source_frame,
                              const cyber::Time &source_time,
                              const std::string &fixed_frame,
                              const float timeout_second,
                              std::string *errstr) const
    {
      UNUSED(timeout_second);
      // poll for transform if timeout is set
      //uint64_t timeout_ns =
      //    static_cast<uint64_t>(timeout_second * kSecondToNanoFactor);
      rclcpp::Rate rate(300);
      //uint64_t start_time = Clock::Now().ToNanosecond();
      //while (Clock::Now().ToNanosecond() < start_time + timeout_ns &&
      //       !cyber::IsShutdown())
      { // Make sure we haven't been stopped
        errstr->clear();
        bool retval = tf2::BufferCore::canTransform(
            target_frame, toTf2(target_time), source_frame,
            toTf2(source_time), fixed_frame, errstr);
        if (retval)
        {
          return true;
        }
        else
        {
          AWARN << "BufferCore::canTransform failed: " << *errstr;
          // std::this_thread::sleep_for(std::chrono::milliseconds(3));
          //rate.sleep();
        }
      }
      *errstr = *errstr + ":timeout";
      return false;
    }

  } // namespace transform
} // namespace apollo