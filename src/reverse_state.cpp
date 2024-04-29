#include "reverse_state.h"

#include <iostream>

void ReverseState::process(IStateManager* state_manager) {
    std::cout << "3 or 4" << std::endl;
    state_manager->setNextState();
}
