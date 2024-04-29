#pragma once

#include <memory>

#include "state_collection.h"

class StateTransitionStrategy {
    public:
        virtual ~StateTransitionStrategy() = default;
        virtual void setup_states(std::shared_ptr<StateCollection> state_collection) = 0;
};
