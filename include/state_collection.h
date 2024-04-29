#pragma once

#include <memory>
#include <vector>

#include "state.h"
#include "state_factory.h"

class StateCollection {
    public:
        StateCollection();

        template <typename T>
        void addState() {
            states.emplace_back(StateFactory::createState<T>());
        };

        std::shared_ptr<State> getState(int index);
        int size();

    private:
        std::vector<std::shared_ptr<State>> states;
        std::unique_ptr<StateFactory> state_factory;
};
