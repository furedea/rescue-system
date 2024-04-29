#include "rescue_state.h"

#include <memory>

#include "i_state_manager.h"
#include "line_trace_manager.h"
#include "message_manager.h"

RescueState::RescueWaitState(
    std::shared_ptr<LineTraceManager> line_trace_manager,
    std::shared_ptr<MessageManager> message_manager)
    : State(line_trace_manager, message_manager), message_manager(message_manager) {}

void RescueState::process(IStateManager* state_manager) {
    message_manager->sendMessage();
    state_manager->setNextState();
}
