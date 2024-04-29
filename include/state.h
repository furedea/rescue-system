#pragma once

#include "i_state_manager.h"

class State {
    public:
        virtual ~State() = default;
        virtual void process(IStateManager* state_manager) = 0;
        State(std::shared_ptr<LineTraceManager> line_trace_manager, std::shared_ptr<MessageManager> message_manager);
};
