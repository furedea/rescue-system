#include "rescue_car_strategy.h"

#include <memory>

#include "rescue_move_state.h"
#include "rescue_state.h"
#include "rescue_wait_state.h"
#include "return_state.h"

void RescueCarStrategy::setup_states(std::shared_ptr<StateCollection> state_collection) {
    state_collection->addState<RescueWaitState>();
    state_collection->addState<RescueMoveState>();
    state_collection->addState<RescueState>();
    state_collection->addState<ReturnState>();
}
