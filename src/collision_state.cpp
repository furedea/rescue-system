#include "collision_state.h"

#include "message_manager.h"

CollisionState::CollisionState(
    std::shared_ptr<LineTraceManager> line_trace_manager,
    std::shared_ptr<MessageManager> message_manager)
    : State(line_trace_manager, message_manager), message_manager(message_manager) {}

void CollisionState::process(IStateManager* state_manager) {
    message_manager->connectWithServer();
    message_manager->sendMessage();
    if (message_manager->isReceivedMessage()) {
        state_manager->setNextState();
    }
}
