#pragma once

#include <memory>

#include "line_trace_manager.h"
#include "message_manager.h"
#include "state.h"
#include "zumo.h"

class StateFactory {
    public:
        StateFactory();

        template <typename T>
        static std::shared_ptr<State> createState() {
            return std::make_shared<T>(line_trace_manager, message_manager);
        };

    private:
        std::shared_ptr<LineTraceManager> line_trace_manager;
        std::shared_ptr<MessageManager> message_manager;
};
