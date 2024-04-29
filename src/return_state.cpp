#include "return_state.h"

#include <memory>

#include "i_state_manager.h"
#include "line_trace_manager.h"
#include "message_manager.h"

ReturnState::ReturnState(
    std::shared_ptr<LineTraceManager> line_trace_manager,
    std::shared_ptr<MessageManager> message_manager)
    : State(trace_line_manager, message_manager), line_trace_manager(line_trace_manager) {}

void ReturnState::process(IStateManager* state_manager) {
    line_trace_manager->reverseRight();
    while (!line_trace_manager->isArrived() {
        line_trace_manager->traceLineRight();
    }
    state_manager->setNextState();
}
