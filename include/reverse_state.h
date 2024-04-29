#pragma once

#include "state.h"

class ReverseState : public State {
    public:
        void process(IStateManager* state_manager) override;
};
