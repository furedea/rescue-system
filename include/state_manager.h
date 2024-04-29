#pragma once

#include <memory>

#include "i_state_manager.h"
#include "state.h"
#include "state_collection.h"
#include "state_transition_strategy.h"

class StateManager : public IStateManager {
    public:
        StateManager(StateTransitionStrategy* strategy);
        void processState() override;
        void setNextState() override;
        bool hasNextState() override;

    private:
        std::shared_ptr<StateCollection> state_collection;
        std::shared_ptr<State> current_state;
        int current_index;
};
