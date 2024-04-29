#pragma once

#include <memory>

#include "line_trace_manager.h"
#include "mbed.h"
#include "message_manager.h"
#include "state.h"
#include "state_manager.h"

class LineTraceState : public State {
    public:
        LineTraceState(
            std::shared_ptr<LineTraceManager> line_trace_manager,
            std::shared_ptr<MessageManager> message_manager);
        void process(IStateManager* state_manager) override;

    private:
        std::shared_ptr<LineTraceManager> line_trace_manager;
        std::unique_ptr<Timer> timer;
};
