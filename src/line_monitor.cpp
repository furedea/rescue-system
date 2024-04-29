#include "line_monitor.h"

#include <memory>

#include "zumo.h"

LineMonitor::LineMonitor(std::shared_ptr<Zumo> zumo) : zumo(zumo), irbits(std::make_unique<IrBitField_T>() {
    irbits->left = 0;
    irbits->center = 1;
    irbits->right = 0;
}

bool LineMonitor::isLeftSensorOnLine() {
    zumo->readIr(irbits);
    if ((irbits->left) == -1) {
        return true;
    }
    return false;
}

bool LineMonitor::isCenterSensorOnLine() {
    zumo.readIr(irbits);
    if ((irbits->center) == -1) {
        return true;
    }
    return false;
}

bool LineMonitor::isRightSensorOnLine() {
    zumo.readIr(irbits);
    if ((irbits->right) == -1) {
        return true;
    }
}
