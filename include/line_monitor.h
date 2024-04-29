#pragma once

#include <memory>

#include "Zumo.h"

class LineMonitor {
    public:
        LineMonitor(std::shared_ptr<Zumo> zumo);
        bool isLeftSensorOnLine();
        bool isCenterSensorOnLine();
        bool isRightSensorOnLine();

    private:
        std::shared_ptr<Zumo> zumo;
        std::unique_ptr<IrBitField_T> irbits;
};
