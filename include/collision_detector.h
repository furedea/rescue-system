#pragma once

#include <memory>

#include "Zumo.h"

class CollisionDetector {
    public:
        bool isCollided();

    private:
        std::shared_ptr<Zumo> zumo;
};
