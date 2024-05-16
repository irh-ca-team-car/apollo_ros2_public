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

#include "modules/prediction/container/pose/pose_container.h"

#include "cyber/common/log.h"
#include "modules/common/math/quaternion.h"
#include "modules/prediction/common/prediction_gflags.h"

namespace apollo
{
    namespace prediction
    {

        using apollo::localization::LocalizationEstimate;
        using apollo_msgs::msg::ApolloperceptionPerceptionObstacle;
        using Point = apollo::common::Point3D;

        void PoseContainer::Insert(const void *message)
        {
            localization::LocalizationEstimate localization;
            localization = *((LocalizationEstimate *)message);
            // localization=(reinterpret_cast<const LocalizationEstimate &>(message));
            Update(localization);
        }

        void PoseContainer::Update(
            const localization::LocalizationEstimate &localization)
        {
            obstacle_ptr_.reset(new ApolloperceptionPerceptionObstacle());

            obstacle_ptr_->set__id(FLAGS_ego_vehicle_id);
            Point position;
            position.set__x(localization.pose.position.x);
            position.set__y(localization.pose.position.y);
            position.set__z(localization.pose.position.z);
            obstacle_ptr_->position = (position);

            double theta = 0.0;

            double qw = localization.pose.orientation.qw;
            double qx = localization.pose.orientation.qx;
            double qy = localization.pose.orientation.qy;
            double qz = localization.pose.orientation.qz;
            theta = common::math::QuaternionToHeading(qw, qx, qy, qz);

            obstacle_ptr_->set__theta(theta);

            Point velocity;
            velocity.set__x(localization.pose.linearvelocity.x);
            velocity.set__y(localization.pose.linearvelocity.y);
            velocity.set__z(localization.pose.linearvelocity.z);
            obstacle_ptr_->velocity = (velocity);

            obstacle_ptr_->set__type(type_);
            obstacle_ptr_->set__timestamp(localization.apolloheader.timestampsec);

            ADEBUG << "ADC obstacle [" << *obstacle_ptr_ << "].";
        }

        double PoseContainer::GetTimestamp()
        {
            if (obstacle_ptr_ != nullptr)
            {
                return obstacle_ptr_->timestamp;
            }
            else
            {
                return 0.0;
            }
        }

        const ApolloperceptionPerceptionObstacle *PoseContainer::ToPerceptionObstacle()
        {
            return obstacle_ptr_.get();
        }

    } // namespace prediction
} // namespace apollo
