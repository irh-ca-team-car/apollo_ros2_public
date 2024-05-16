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

#include "cyber/time/clock.h"

#include "cyber/common/log.h"
#include "cyber/common/util.h"

namespace apollo
{
    namespace cyber
    {
        using AtomicRWLock = ::apollo::cyber::base::AtomicRWLock;
        using AtomicWriteLockGuard =
            ::apollo::cyber::base::WriteLockGuard<AtomicRWLock>;
        using AtomicReadLockGuard = ::apollo::cyber::base::ReadLockGuard<AtomicRWLock>;

        Clock::Clock()
        {
            const auto &clock_mode = 0;
            mode_ = clock_mode;
            mock_now_ = Time(0);
        }

        Time Clock::Now()
        {
            auto clock = Instance();

            AtomicReadLockGuard lg(clock->rwlock_);
            switch (clock->mode_)
            {
            case 0:
                return Time::Now();
            case 1:
                return clock->mock_now_;
            default:
                AFATAL << "Unsupported clock mode: "
                       << (clock->mode_);
            }
            return Time::Now();
        }

        double Clock::NowInSeconds() { return Now().ToSecond(); }

        void Clock::SetMode(int mode)
        {
            auto clock = Instance();
            AtomicWriteLockGuard lg(clock->rwlock_);
            switch (mode)
            {
            case 0:
            {
                clock->mode_ = mode;
                break;
            }
            case 1:
            {
                clock->mode_ = mode;
                break;
            }
            default:
                AERROR << "Unknown ClockMode: " << mode;
            }
            clock->mock_now_ = Time(0);
        }

        int Clock::mode()
        {
            auto clock = Instance();
            AtomicReadLockGuard lg(clock->rwlock_);
            return clock->mode_;
        }

        void Clock::SetNow(const Time &now)
        {
            auto clock = Instance();
            AtomicWriteLockGuard lg(clock->rwlock_);
            if (clock->mode_ != 1)
            {
                AERROR << "SetSimNow only works for ClockMode::MOCK";
                return;
            }
            clock->mock_now_ = now;
        }

    } // namespace cyber
} // namespace apollo