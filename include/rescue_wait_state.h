#pragma once

#include <memory>

#include "i_state_manager.h"
#include "line_trace_manager.h"
#include "message_manager.h"
#include "state.h"

class RescueWaitState : public State {
    public:
        RescueWaitState(
            std::shared_ptr<LineTraceManager> trace_line_controller,
            std::shared_ptr<MessageManager> message_manager);
        void process(IStateManager* state_manager) override;

    private:
        std::shared_ptr<MessageManager> message_manager;
};
