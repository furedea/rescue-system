#include "private_car_strategy.h"

#include <memory>

#include "collision_state.h"
#include "line_trace_state.h"
#include "return_state.h"

void PrivateCarStrategy::setup_states(std::shared_ptr<StateCollection> state_collection) {
    state_collection->addState<LineTraceState>();
    state_collection->addState<CollisionState>();
    state_collection->addState<ReturnState>();
}
