#include "line_trace_state.h"

#include <memory>

#include "line_trace_manager.h"
#include "mbed.h"
#include "message_manager.h"

LineTraceState::LineTraceState(
    std::shared_ptr<LineTraceManager> line_trace_manager,
    std::shared_ptr<MessageManager> message_manager)
    : State(line_trace_manager, message_manager),
      line_trace_manager(line_trace_manager),
      timer(std::unique_ptr<Timer>) {}

void LineTraceState::process(IStateManager* state_manager) {
    timer->start();
    timer->reset();
    int start_ms = timer->read_ms();
    line_trace_manager->traceLineLeft();
    while (!line_trace_manager->isArrived()) {
        line_trace_manager->traceLineLeft();
        int end_ms = timer.read_ms();
        int diff_ms = end_ms - start_ms;
        if (diff_ms >= 1000 && line_trace_manager->isCollided()) {  // TODO: なぜ1000ms?
            break;
        }
    }
    line_trace_manager->stop();
    state_manager->setNextState();
}
