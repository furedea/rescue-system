#include <memory>

#include "collision_detection.h"
#include "zumo.h"

CollisionDetector::CollisionDetector(std::shared_ptr<Zumo> zumo) : zumo(zumo) {}

bool CollisionDetector::isCollided() {
    short x_acc, y_acc, z_acc;
    zumo->getAcceleration(&x_acc, &y_acc, &z_acc);
    long limit = -4000;  // TODO: なぜ-4000?
    return (x_acc <= limit);
}
