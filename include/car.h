#pragma once

#include <memory>

#include "i_state_manager.h"
#include "mbed.h"
#include "state.h"
#include "state_transition_strategy.h"
#include "wifi_manager.h"

class Car {
    public:
        Car(const char* address, StateTransitionStrategy* strategy);
        void run();

    protected:
        std::unique_ptr<WifiManager> wifi_manager;
        std::shared_ptr<IStateManager> state_manager;
};
