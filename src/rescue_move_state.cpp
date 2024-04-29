#include "rescue_move_state.h"

#include <kernel.h>

#include <memory>

#include "i_state_manager.h"
#include "kernel_cfg.h"
#include "line_trace_manager.h"
#include "message_manager.h"

RescueMoveState::RescueWaitState(
    std::shared_ptr<LineTraceManager> line_trace_manager,
    std::shared_ptr<MessageManager> message_manager)
    : State(line_trace_manager, message_manager), line_trace_manager(line_trace_manager) {}

void RescueMoveState::process(IStateManager* state_manager) {
    while (!line_trace_manager->isArrived() {
        line_trace_manager->traceLineRight();
    }
    dly_tsk(3000);
    state_manager->setNextState();
}
