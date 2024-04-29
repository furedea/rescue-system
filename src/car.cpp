#include "car.h"

#include "state_manager.h"
#include "state_transition_strategy.h"

Car::Car(const char* address, StateTransitionStrategy* strategy)
    : wifi_manager(std::make_unique<WifiManager>(address)),
      state_manager(std::make_shared<StateManager>(strategy)) {
    wifi_manager.connect();
}

void Car::run() {
    while (state_manager->hasNextState()) {
        state_manager->processState();
    }
}
