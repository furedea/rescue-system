#include "state_factory.h"

StateFactory::StateFactory()
    : line_trace_manager(std::make_shared<LineTraceManager>()),
      message_manager(std::make_shared<MessageManager>()) {}
