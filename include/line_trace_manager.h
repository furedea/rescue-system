#pragma once

#include <memory>

#include "collision_detector.h"
#include "line_monitor.h"
#include "motor_controller.h"

class LineTraceManager {
    public:
        LineTraceManager(std::shared_ptr<Zumo> zumo);
        void traceLineRight();
        void traceLineLeft();
        void reverseRight();
        void reverseLeft();
        bool isReversed();
        bool isArrived();
        bool isCollided();

    private:
        std::unique_ptr<LineMonitor> monitor_line;
        std::unique_ptr<MotorController> motor_controller;
        std::unique_ptr<CollisionDetector> collision_detector;
        const int base_speed;
};
