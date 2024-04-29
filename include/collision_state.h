#pragma once

#include <memory>

#include "line_trace_manager.h"
#include "message_manager.h"
#include "state.h"

class CollisionState : public State {
    public:
        CollisionState(
            std::shared_ptr<LineTraceManager> line_trace_manager,
            std::shared_ptr<MessageManager> message_manager);
        void process(IStateManager* state_manager) override;

    private:
        std::shared_ptr<MessageManager> message_manager;
};
