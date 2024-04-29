#include "motor_controller.h"

#include <kernel.h>

#include "kernel_cfg.h"

MotorController::MotorController(std::shared_ptr<Zumo> zumo) : zumo(zumo) {}

void MotorController::forward(int speed) {
    move(speed, speed);
}

void MotorController::reverse(int speed) {
    move(-speed, -speed);
    dly_tsk(100);
}

void MotorController::hardRight(int speed) {
    move(speed, -speed);
    dly_tsk(100);
}

void MotorController::hardLeft(int speed) {
    move(-speed, speed);
    dly_tsk(100);
}

void MotorController::right(int speed) {
    move(speed, 0);
    dly_tsk(100);
}

void MotorController::left(int speed) {
    move(0, speed);
    dly_tsk(100);
}

void MotorController::stop() {
    move(0, 0);
}

void MotorController::move(int left_speed, int right_speed) {
    zumo.driveTank(left_speed, right_speed);
}
