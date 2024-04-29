#include "state_collection.h"

#include <memory>
#include <vector>

StateCollection::StateCollection() : state_factory(std::make_unique<StateFactory>()) {}

std::shared_ptr<State> StateCollection::getState(int index) {
    if (index >= 0 && index < size()) {
        return states[index];
    }
    std::exit(EXIT_FAILURE);
}

int StateCollection::size() {
    return states.size();
}
