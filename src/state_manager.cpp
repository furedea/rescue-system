#include "state_manager.h"

#include <memory>

#include "state_collection.h"
#include "state_transition_strategy.h"

StateManager::StateManager(StateTransitionStrategy* strategy)
    : state_collection(std::make_shared<StateCollection>), current_index(0) {
    strategy->setup_states(state_collection);
    current_state = state_collection->getState(current_index);
}

void StateManager::processState() {
    if (current_state) {
        current_state->process(this);
    }
}

void StateManager::setNextState() {
    current_index++;
    current_state = state_collection->getState(current_index);
}

bool StateManager::hasNextState() {
    return current_index < state_collection->size();
}
