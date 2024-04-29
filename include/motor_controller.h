#pragma once

#include <memory>

#include "Zumo.h"

class MotorController {
    public:
        MotorController(std::shared_ptr<Zumo> zumo);
        void forward(int speed);
        void reverse(int speed);
        void hardRight(int speed);
        void hardLeft(int speed);
        void right(int speed);
        void left(int speed);
        void stop();
        void move(int left_speed, int right_speed);

    private:
        std::shared_ptr<Zumo> zumo;
};
