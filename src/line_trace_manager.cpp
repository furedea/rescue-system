#include "line_trace_manager.h"

#include <kernel.h>

#include <memory>

#include "collision_detector.h"
#include "kernel_cfg.h"
#include "line_monitor.h"
#include "motor_controller.h"
#include "zumo.h"

LineTraceManager::LineTraceManager(std::shared_ptr<Zumo> zumo)
    : line_monitor(std::make_unique<LineMonitor>(zumo)),
      motor_controller(std::make_unique<MotorController>(zumo)),
      collision_detector(std::make_unique<CollisionDetector>(zumo)),
      base_speed(120) {}  // TODO: なぜ120?

void LineTraceManager::traceLineRight() {
    if (line_monitor->isCenterSensorOnLine()) {
        motor_controller->forward(base_speed);
        return;
    }
    if (line_monitor->isRightSensorOnLine()) {
        motor_controller->right(base_speed);
        return;
    }
    motor_controller->left(base_speed);
}

void LineTraceManager::traceLineLeft() {
    if (line_monitor->isCenterSensorOnLine()) {
        motor_controller->forward(base_speed);
        return;
    }
    if (line_monitor->isLeftSensorOnLine()) {
        motor_controller->left(base_speed);
        return;
    }
    motor_controller->right(base_speed);
}

void LineTraceManager::reverseRight() {
    while (line_monitor->isRightSensorOnLine()) {
        motor_controller->hardRight(base_speed);
    }
    while (!line_monitor->isRightSensorOnLine()) {
        motor_controller->hardRight(base_speed);
    }
    motor_controller->stop();
}

void LineTraceManager::reverseLeft() {
    while (line_monitor->isRightSensorOnLine()) {
        motor_controller->hardLeft(base_speed);
    }
    while (!line_monitor->isRightSensorOnLine() && !line_monitor->isCenterSensorOnLine()) {
        motor_controller->hardLeft(base_speed);
    }
}

void LineTraceManager::stop() {
    motor_controller->stop();
    dly_tsk(3000);
}

bool LineTraceManager::isReversed() {
    motor_controller->move(-16, -160);  // TODO: 数値の意味
    dly_tsk(600);
    motor_controller->move(240, -24);
    dly_tsk(300);
    while (!line_monitor.isCenterSensorOnLine()) {
        motor_controller->move(240, -24);
    }
    while (line_monitor->isCenterSensorOnLine() && line_monitor->isLeftSensorOnLine()) {
        motor_controller->move(240, -24);
    }
    motor_controller->stop();
}

bool LineTraceManager::isArrived() {
    if (line_monitor->isLeftSensorOnLine() && line_monitor->isCenterSensorOnLine() && line_monitor->isRightSensorOnLine()) {
        motor_controller->stop();
        return true;
    }
    return false;
}

bool LineTraceManager::isCollided() {
    return collision_detector->isCollided();
}
