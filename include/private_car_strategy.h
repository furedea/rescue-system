#pragma once

#include <memory>

#include "state_collection.h"
#include "state_transition_strategy.h"

class PrivateCarStrategy : public StateTransitionStrategy {
    public:
        void setup_states(std::shared_ptr<StateCollection> state_collection) override;
};
