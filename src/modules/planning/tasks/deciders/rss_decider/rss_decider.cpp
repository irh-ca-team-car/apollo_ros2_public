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

/**
 * @file
 **/

#include "modules/planning/tasks/deciders/rss_decider/rss_decider.h"

#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/proto/planning.pb.h"

namespace apollo
{
    namespace planning
    {

        using apollo::common::ErrorCode;
        using apollo::common::Status;

        using ad::physics::Distance;
        using ad::physics::ParametricValue;
        using ad::physics::Speed;
        using ad::rss::situation::VehicleState;
        using ad::rss::world::Object;
        using ad::rss::world::RoadArea;
        using ad::rss::world::Scene;

        RssDecider::RssDecider(const apollo_msgs::msg::ApolloplanningTaskConfig &config) : Task(config) {}

        apollo::common::Status RssDecider::Execute(
            Frame *frame, ReferenceLineInfo *reference_line_info)
        {
            return Process(frame, reference_line_info);
        }

        Status RssDecider::Process(Frame *frame,
                                   ReferenceLineInfo *reference_line_info)
        {
            CHECK_NOTNULL(frame);
            CHECK_NOTNULL(reference_line_info);

            if (reference_line_info->path_data().Empty() ||
                reference_line_info->speed_data().empty())
            {
                const std::string msg = "Empty path or speed data";
                AERROR << msg;
                return Status(ErrorCode::PLANNING_ERROR, msg);
            }

            double adc_velocity = frame->vehicle_state().linearvelocity;
            const PathDecision *path_decision = reference_line_info->path_decision();
            const double ego_v_s_start = reference_line_info->AdcSlBoundary().starts;
            const double ego_v_s_end = reference_line_info->AdcSlBoundary().ends;
            const double ego_v_l_start = reference_line_info->AdcSlBoundary().startl;
            const double ego_v_l_end = reference_line_info->AdcSlBoundary().endl;
            double nearest_obs_s_start = 0.0;
            double nearest_obs_s_end = 0.0;
            double nearest_obs_l_start = 0.0;
            double nearest_obs_l_end = 0.0;
            double nearest_obs_speed = 0.0;

            double front_obstacle_distance = FLAGS_rss_max_front_obstacle_distance;
            for (const auto *obstacle : path_decision->obstacles().Items())
            {
                if (obstacle->IsVirtual())
                {
                    continue;
                }
                bool is_on_road = reference_line_info->reference_line().HasOverlap(
                    obstacle->PerceptionBoundingBox());
                if (!is_on_road)
                {
                    continue;
                }
                const auto &obstacle_sl = obstacle->PerceptionSLBoundary();
                if (obstacle_sl.ends <= ego_v_s_start)
                {
                    continue;
                }
                double distance = obstacle_sl.starts - ego_v_s_end;
                if (distance > 0 && distance < front_obstacle_distance)
                {
                    front_obstacle_distance = distance;
                    nearest_obs_s_start = obstacle_sl.starts;
                    nearest_obs_s_end = obstacle_sl.ends;
                    nearest_obs_l_start = obstacle_sl.startl;
                    nearest_obs_l_end = obstacle_sl.endl;
                    nearest_obs_speed = obstacle->speed();
                }
            }

            // there is no obstacle in front of adc
            if (front_obstacle_distance >= FLAGS_rss_max_front_obstacle_distance)
            {
                ad::rss::world::RssDynamics dynamics;
                rss_config_default_dynamics(&dynamics);

                reference_line_info->mutable_rss_info()->set__isrsssafe(true);
                reference_line_info->mutable_rss_info()->set__curdistlon(
                    front_obstacle_distance);
                reference_line_info->mutable_rss_info()->set__rsssafedistlon(
                    front_obstacle_distance);

                reference_line_info->mutable_rss_info()->set__acclonrangeminimum(
                    -1 * static_cast<double>(dynamics.alphaLon.brakeMax));
                reference_line_info->mutable_rss_info()->set__acclonrangemaximum(
                    static_cast<double>(dynamics.alphaLon.accelMax));
                reference_line_info->mutable_rss_info()->set__acclatleftrangeminimum(
                    -1 * static_cast<double>(dynamics.alphaLat.brakeMin));
                reference_line_info->mutable_rss_info()->set__acclatleftrangemaximum(
                    static_cast<double>(dynamics.alphaLat.accelMax));
                reference_line_info->mutable_rss_info()->set__acclatrightrangeminimum(
                    -1 * static_cast<double>(dynamics.alphaLat.brakeMin));
                reference_line_info->mutable_rss_info()->set__acclatrightrangemaximum(
                    static_cast<double>(dynamics.alphaLat.accelMax));

                return Status::OK();
            }

#if RSS_FAKE_INPUT
            nearest_obs_l_start = -4.2608;
            nearest_obs_l_end = -1.42591;
            ego_v_l_start = -1.05554;
            ego_v_l_end = 1.08416;
#endif
            double lane_leftmost = std::max(ego_v_l_end, nearest_obs_l_end);
            double lane_rightmost = std::min(ego_v_l_start, nearest_obs_l_start);
            double lane_width = std::abs(lane_leftmost - lane_rightmost);
            double lane_length = std::max(nearest_obs_s_end, ego_v_s_end);

            rss_world_info.front_obs_dist = front_obstacle_distance;
            rss_world_info.obs_s_start = nearest_obs_s_start;
            rss_world_info.obs_s_end = nearest_obs_s_end;
            rss_world_info.obs_l_start = nearest_obs_l_start;
            rss_world_info.obs_l_end = nearest_obs_l_end;
            rss_world_info.obs_speed = nearest_obs_speed;
            rss_world_info.ego_v_s_start = ego_v_s_start;
            rss_world_info.ego_v_s_end = ego_v_s_end;
            rss_world_info.ego_v_l_start = ego_v_l_start;
            rss_world_info.ego_v_l_end = ego_v_l_end;
            rss_world_info.lane_leftmost = lane_leftmost;
            rss_world_info.lane_rightmost = lane_rightmost;
            rss_world_info.lane_width = lane_width;
            rss_world_info.lane_length = lane_length;

            Object followingObject;
            Object leadingObject;
            RoadArea roadArea;
            Scene scene;

            scene.situationType = ad::rss::situation::SituationType::SameDirection;

            rss_create_other_object(&leadingObject, nearest_obs_speed, 0);

            ad::rss::world::OccupiedRegion occupiedRegion_leading;
            occupiedRegion_leading.segmentId = 0;
            occupiedRegion_leading.lonRange.minimum =
                ParametricValue(nearest_obs_s_start / lane_length);
            occupiedRegion_leading.lonRange.maximum =
                ParametricValue(nearest_obs_s_end / lane_length);
            occupiedRegion_leading.latRange.minimum =
                ParametricValue(std::abs(ego_v_l_end - lane_leftmost) / lane_width);
            occupiedRegion_leading.latRange.maximum =
                ParametricValue(std::abs(ego_v_l_start - lane_leftmost) / lane_width);

            leadingObject.occupiedRegions.push_back(occupiedRegion_leading);

            rss_world_info.OR_front_lon_min =
                static_cast<double>(occupiedRegion_leading.lonRange.minimum);
            rss_world_info.OR_front_lon_max =
                static_cast<double>(occupiedRegion_leading.lonRange.maximum);
            rss_world_info.OR_front_lat_min =
                static_cast<double>(occupiedRegion_leading.latRange.minimum);
            rss_world_info.OR_front_lat_max =
                static_cast<double>(occupiedRegion_leading.latRange.maximum);

            RssDecider::rss_create_ego_object(&followingObject, adc_velocity, 0.0);

            ad::rss::world::OccupiedRegion occupiedRegion_following;
            occupiedRegion_following.segmentId = 0;
            occupiedRegion_following.lonRange.minimum =
                ParametricValue(ego_v_s_start / lane_length);
            occupiedRegion_following.lonRange.maximum =
                ParametricValue(ego_v_s_end / lane_length);
            occupiedRegion_following.latRange.minimum =
                ParametricValue(std::abs(nearest_obs_l_end - lane_leftmost) / lane_width);
            occupiedRegion_following.latRange.maximum = ParametricValue(
                std::abs(nearest_obs_l_start - lane_leftmost) / lane_width);

            followingObject.occupiedRegions.push_back(occupiedRegion_following);

            rss_world_info.adc_vel = adc_velocity;
            rss_world_info.OR_rear_lon_min =
                static_cast<double>(occupiedRegion_following.lonRange.minimum);
            rss_world_info.OR_rear_lon_max =
                static_cast<double>(occupiedRegion_following.lonRange.maximum);
            rss_world_info.OR_rear_lat_min =
                static_cast<double>(occupiedRegion_following.latRange.minimum);
            rss_world_info.OR_rear_lat_max =
                static_cast<double>(occupiedRegion_following.latRange.maximum);

            ad::rss::world::RoadSegment roadSegment;
            ad::rss::world::LaneSegment laneSegment;

            laneSegment.id = 0;
            laneSegment.length.minimum = ad::physics::Distance(lane_length);
            laneSegment.length.maximum = ad::physics::Distance(lane_length);
            laneSegment.width.minimum = ad::physics::Distance(lane_width);
            laneSegment.width.maximum = ad::physics::Distance(lane_width);

            roadSegment.push_back(laneSegment);
            roadArea.push_back(roadSegment);

            rss_world_info.laneSeg_len_min =
                static_cast<double>(laneSegment.length.minimum);
            rss_world_info.laneSeg_len_max =
                static_cast<double>(laneSegment.length.maximum);
            rss_world_info.laneSeg_width_min =
                static_cast<double>(laneSegment.width.minimum);
            rss_world_info.laneSeg_width_max =
                static_cast<double>(laneSegment.width.maximum);

            ad::rss::world::WorldModel worldModel;
            rss_config_default_dynamics(&worldModel.defaultEgoVehicleRssDynamics);
            scene.egoVehicle = followingObject;
            scene.object = leadingObject;
            scene.egoVehicleRoad = roadArea;
            worldModel.scenes.push_back(scene);
            worldModel.timeIndex = frame->SequenceNum();

            ad::rss::situation::SituationSnapshot situationVector;
            ::ad::rss::core::RssSituationExtraction extraction;
            bool rss_result = extraction.extractSituations(
                worldModel, situationVector);
            if (!rss_result)
            {
                rss_world_info.err_code = "ad_rss::extractSituation failed";
                rss_dump_world_info(rss_world_info);
                return Status(ErrorCode::PLANNING_ERROR, rss_world_info.err_code);
            }

            if (situationVector.situations.empty())
            {
                rss_world_info.err_code = "situationVector unexpected empty";
                rss_dump_world_info(rss_world_info);
                return Status(ErrorCode::PLANNING_ERROR, rss_world_info.err_code);
            }

            ::ad::rss::state::RssStateSnapshot responseStateVector;
            ::ad::rss::core::RssSituationChecking RssCheck;
            rss_result = RssCheck.checkSituations(situationVector, responseStateVector);

            if (!rss_result)
            {
                rss_world_info.err_code = "ad_rss::checkSituation failed";
                rss_dump_world_info(rss_world_info);
                return Status(ErrorCode::PLANNING_ERROR, rss_world_info.err_code);
            }

            if (responseStateVector.individualResponses.empty())
            {
                rss_world_info.err_code = "responseStateVector unexpected empty";
                rss_dump_world_info(rss_world_info);
                return Status(ErrorCode::PLANNING_ERROR, rss_world_info.err_code);
            }

            ::ad::rss::state::ProperResponse properResponse;
            ::ad::rss::core::RssResponseResolving RssResponse;
            rss_result =
                RssResponse.provideProperResponse(responseStateVector, properResponse);

            if (!rss_result)
            {
                rss_world_info.err_code = "ad_rss::provideProperResponse failed";
                rss_dump_world_info(rss_world_info);
                return Status(ErrorCode::PLANNING_ERROR, rss_world_info.err_code);
            }

            ::ad::rss::state::AccelerationRestriction accelerationRestriction = properResponse.accelerationRestrictions;

            auto const currentLonDistance =
                situationVector.situations[0].relativePosition.longitudinalDistance;
            ad::physics::Distance safeLonDistance;
            auto const &leadingVehicleState =
                situationVector.situations[0].otherVehicleState;
            auto const &followingVehicleState =
                situationVector.situations[0].egoVehicleState;

            rss_result =
                ::ad::rss::situation::calculateSafeLongitudinalDistanceSameDirection(
                    leadingVehicleState, followingVehicleState, safeLonDistance);
            if (!rss_result)
            {
                rss_world_info.err_code =
                    ("ad_rss::calculateSafeLongitudinalDistanceSameDirection failed");
                rss_dump_world_info(rss_world_info);
                return Status(ErrorCode::PLANNING_ERROR, rss_world_info.err_code);
            }

            if (responseStateVector.individualResponses[0].longitudinalState.isSafe)
            {
                ADEBUG << "Task " << Name() << " Distance is RSS-Safe";
                reference_line_info->mutable_rss_info()->set__isrsssafe(true);
            }
            else
            {
                ADEBUG << "Task " << Name() << " Distance is not RSS-Safe";
                reference_line_info->mutable_rss_info()->set__isrsssafe(false);
                if (FLAGS_enable_rss_fallback)
                {
                    reference_line_info->mutable_speed_data()->clear();
                }
            }

            reference_line_info->mutable_rss_info()->set__curdistlon(
                static_cast<double>(currentLonDistance));
            reference_line_info->mutable_rss_info()->set__rsssafedistlon(
                static_cast<double>(safeLonDistance));
            reference_line_info->mutable_rss_info()->set__acclonrangeminimum(
                static_cast<double>(accelerationRestriction.longitudinalRange.minimum));
            reference_line_info->mutable_rss_info()->set__acclonrangemaximum(
                static_cast<double>(accelerationRestriction.longitudinalRange.maximum));
            reference_line_info->mutable_rss_info()->set__acclatleftrangeminimum(
                static_cast<double>(accelerationRestriction.lateralLeftRange.minimum));
            reference_line_info->mutable_rss_info()->set__acclatleftrangemaximum(
                static_cast<double>(accelerationRestriction.lateralLeftRange.maximum));
            reference_line_info->mutable_rss_info()->set__acclatrightrangeminimum(
                static_cast<double>(accelerationRestriction.lateralRightRange.minimum));
            reference_line_info->mutable_rss_info()->set__acclatrightrangemaximum(
                static_cast<double>(accelerationRestriction.lateralRightRange.maximum));

            ADEBUG << " longitudinalState.isSafe: "
                   << responseStateVector.individualResponses[0].longitudinalState.isSafe;
            ADEBUG << " lateralStateLeft.isSafe: "
                   << responseStateVector.individualResponses[0].lateralStateLeft.isSafe;
            ADEBUG << " lateralStateRight.isSafe: "
                   << responseStateVector.individualResponses[0].lateralStateRight.isSafe;
            ADEBUG << " is_rss_safe : " << reference_line_info->rss_info().isrsssafe;
            ADEBUG << " cur_dist_lon: " << reference_line_info->rss_info().curdistlon;
            ADEBUG << " is_rss_safe : " << reference_line_info->rss_info().isrsssafe;
            ADEBUG << " cur_dist_lon: " << reference_line_info->rss_info().curdistlon;
            ADEBUG << " rss_safe_dist_lon: "
                   << reference_line_info->rss_info().rsssafedistlon;
            ADEBUG << " acc_longitudianlRange_minimum: "
                   << reference_line_info->rss_info().acclonrangeminimum;
            ADEBUG << " acc_longitudinalRange_maximum: "
                   << reference_line_info->rss_info().acclonrangemaximum;
            ADEBUG << " acc_lateralLeftRange_minimum: "
                   << reference_line_info->rss_info().acclatleftrangeminimum;
            ADEBUG << " acc_lateralLeftRange_maximum: "
                   << reference_line_info->rss_info().acclatleftrangemaximum;
            ADEBUG << " acc_lateralRightRange: "
                   << reference_line_info->rss_info().acclatrightrangeminimum;
            ADEBUG << " acc_lateralRightRange_maximum: "
                   << reference_line_info->rss_info().acclatrightrangemaximum;

            return Status::OK();
        }

        void RssDecider::rss_config_default_dynamics(
            ::ad::rss::world::RssDynamics *dynamics)
        {
            dynamics->alphaLon.accelMax = ::ad::physics::Acceleration(3.5);
            dynamics->alphaLon.brakeMax = ::ad::physics::Acceleration(8);
            dynamics->alphaLon.brakeMin = ::ad::physics::Acceleration(4.);
            dynamics->alphaLon.brakeMinCorrect = ::ad::physics::Acceleration(3.);
            dynamics->alphaLat.accelMax = ::ad::physics::Acceleration(0.2);
            dynamics->alphaLat.brakeMin = ::ad::physics::Acceleration(0.8);
        }

        void RssDecider::rss_create_ego_object(::ad::rss::world::Object *ego,
                                               double vel_lon, double vel_lat)
        {
            ego->objectId = 1;
            ego->objectType = ::ad::rss::world::ObjectType::EgoVehicle;
            ego->velocity.speedLonMin = ad::physics::Speed(vel_lon);
            ego->velocity.speedLonMax = ad::physics::Speed(vel_lon);
            ego->velocity.speedLatMin = ad::physics::Speed(vel_lat);
            ego->velocity.speedLatMax = ad::physics::Speed(vel_lat);

            //rss_config_default_dynamics(&(ego->dynamics));
            //ego->responseTime = ::ad::physics::Duration(1.);
        }

        void RssDecider::rss_create_other_object(::ad::rss::world::Object *other,
                                                 double vel_lon, double vel_lat)
        {
            other->objectId = 0;
            other->objectType = ::ad::rss::world::ObjectType::OtherVehicle;
            other->velocity.speedLonMin = ad::physics::Speed(vel_lon);
            other->velocity.speedLonMax = ad::physics::Speed(vel_lon);
            other->velocity.speedLatMin = ad::physics::Speed(vel_lat);
            other->velocity.speedLatMax = ad::physics::Speed(vel_lat);

            //rss_config_default_dynamics(&(other->dynamics));
            //other->responseTime = ::ad::physics::Duration(2.);
        }

        void RssDecider::rss_dump_world_info(
            const struct rss_world_model_struct &rss_info)
        {
            AERROR << " RSS_INFO :"
                   << " front_obs_dist: " << rss_info.front_obs_dist
                   << " obs_s_start: " << rss_info.obs_s_start
                   << " obs_s_end: " << rss_info.obs_s_end
                   << " obs_l_start: " << rss_info.obs_l_start
                   << " obs_l_end: " << rss_info.obs_l_end
                   << " obs_speed: " << rss_info.obs_speed
                   << " ego_v_s_start: " << rss_info.ego_v_s_start
                   << " ego_v_s_end: " << rss_info.ego_v_s_end
                   << " ego_v_l_start: " << rss_info.ego_v_l_start
                   << " ego_v_l_end: " << rss_info.ego_v_l_end
                   << " lane_leftmost: " << rss_info.lane_leftmost
                   << " lane_rightmost: " << rss_info.lane_rightmost
                   << " lane_width: " << rss_info.lane_width
                   << " lane_length: " << rss_info.lane_length
                   << " OR_front_lon_min: " << rss_info.OR_front_lon_min
                   << " OR_front_lon_max: " << rss_info.OR_front_lon_max
                   << " OR_front_lat_min: " << rss_info.OR_front_lat_min
                   << " OR_front_lat_max: " << rss_info.OR_front_lat_max
                   << " OR_rear_lon_min: " << rss_info.OR_rear_lon_min
                   << " OR_rear_lon_max: " << rss_info.OR_rear_lon_max
                   << " OR_rear_lat_min: " << rss_info.OR_rear_lat_min
                   << " OR_rear_lat_max: " << rss_info.OR_rear_lat_max
                   << " adc_vel: " << rss_info.adc_vel
                   << " laneSeg_len_min: " << rss_info.laneSeg_len_min
                   << " laneSeg_len_max: " << rss_info.laneSeg_len_max
                   << " laneSeg_width_min: " << rss_info.laneSeg_width_min
                   << " laneSeg_width_max: " << rss_info.laneSeg_width_max;
        }

    } //  namespace planning
} //  namespace apollo
