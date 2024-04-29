#include "rescue_wait_state.h"

#include <memory>

#include "i_state_manager.h"
#include "line_trace_manager.h"
#include "message_manager.h"

RescueWaitState::RescueWaitState(
    std::shared_ptr<LineTraceManager> line_trace_manager,
    std::shared_ptr<MessageManager> message_manager)
    : State(line_trace_manager, message_manager), message_manager(message_manager) {}

void RescueWaitState::process(IStateManager* state_manager) {
    message_manager->waitForConnecting();
    if (message_manager->isReceivedMessage()) {
        state_manager->setNextState();
    }
}
