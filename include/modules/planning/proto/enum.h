#pragma once
namespace apollo::planning
{
    enum ObjectDecisionType
    {
        OBJECT_TAG_NOT_SET=0,
        kIgnore = 1,
        kStop = 2,
        kFollow = 3,
        kYield = 4,
        kOvertake = 5,
        kNudge = 6,
        kAvoid = 7,
        kSidePass = 8
    };
}