#pragma once

class IStateManager {
    public:
        virtual ~IStateManager() = default;
        virtual void processState() = 0;
        virtual void setNextState() = 0;
        virtual bool hasNextState() = 0;
};
